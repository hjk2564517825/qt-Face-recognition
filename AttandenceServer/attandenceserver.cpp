#include "attandenceserver.h"
#include "ui_attandenceserver.h"
#include <attandenceregister.h>

AttandenceServer::AttandenceServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AttandenceServer)
{
    ui->setupUi(this);

    recvFacePtr = new UdpTransfer(UdpTransfer::RECV,9527);
    connect(recvFacePtr, &UdpTransfer::recviceFinished, this, &AttandenceServer::recvface);


    sendJson = new UdpTransfer();//发送json数据
    sendHeader = new UdpTransfer(); //发送头像数据
    //json数据发送完毕后再发送头像信息
    connect(sendJson, &UdpTransfer::transferFinished, this, &AttandenceServer::send_header);


    seeta::ModelSetting::Device device = seeta::ModelSetting::CPU;
    int id = 0;
    seeta::ModelSetting FD_model( "./model/fd_2_00.dat", device, id );
    seeta::ModelSetting PD_model( "./model/pd_2_00_pts5.dat", device, id );
    seeta::ModelSetting FR_model( "./model/fr_2_10.dat", device, id );
    engine = new seeta::FaceEngine ( FD_model, PD_model, FR_model);
    engine->Load("./face.db"); //导入已有的人脸数据
}

AttandenceServer::~AttandenceServer()
{
    delete ui;
}

void AttandenceServer::recvface(QByteArray &array)
{
    QPixmap mmp;
    mmp.loadFromData(array);
    mmp = mmp.scaled(ui->label->size());
    ui->label->setPixmap(mmp);



    //把  QByteArray格式-->Mat格式
    cv::Mat face;
    std::vector<unsigned char > arr;
    arr.assign(array.begin(), array.end());
    cv::imdecode(arr, cv::IMREAD_COLOR, &face);

    SeetaImageData image;
    image.data = face.data ;
    image.width = face.cols;
    image.height = face.rows;
    image.channels = face.channels();//像素
    int64_t faceid;
    float sim;
    int ret = engine->QueryTop(image,1, &faceid, &sim);
    if(ret < 0)
    {
        QString str = "{\"type\":\"2\"}";
        QByteArray strarray = str.toUtf8();
        sendJson->send_data(strarray, "192.168.56.1", 9525);
        qDebug()<<"1-调试:"<<str<<faceid<<sim;
    }

    //查询到人脸数据faceid---》查询员工表格--员工id， 员工id--》人事 表格-获取人事数据打开 json发送
    //获取员工编号--通过人脸id获取员工编号
    QSqlTableModel model;
    model.setTable("employee");
    model.setFilter(QString("faceid='%1'").arg(faceid)) ;
    model.select();
    int employeeid = model.record(0).value("employeeid").toInt();
    name = model.record(0).value("name").toString();
    address = model.record(0).value("address").toString();
    phone = model.record(0).value("phone").toString();
    sex = model.record(0).value("sex").toString();
    birthday = model.record(0).value("birthday").toString();
    // 人事数据
    model.setTable("person");//设置模型的表格名
    model.setFilter(QString("employeeid = %1 ").arg(employeeid));
    model.select();
    QSqlRecord recd = model.record(0);//获取  第一条记录
    QString departmet = recd.value("department").toString();
    QString jop = recd.value("jop").toString();


    //把员工id插入到考勤数据
    QString insertsql=QString("insert into attendance(employeeid) values(%1)").arg(employeeid);
    QSqlQuery query;
    QString time_card = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    if(!query.exec(insertsql))
    {
        qDebug()<<query.lastError().text();
    }
    QString jsonstr = QString("{\"type\":\"0\",\"name\":\"%1\", \"department\":\"%2\",\"jop\":\"%3\",\"att_time\":\"%4\",\"employeeid\":\"%5\"}")
            .arg(name).arg(departmet).arg(jop).arg(time_card).arg(employeeid);
    QByteArray jsonarray = jsonstr.toUtf8();
    sendJson->send_data(jsonarray, "192.168.56.1", 9525);
    ui->nameEdit->setText(name);
    ui->sexEdit->setText(sex);
    ui->addressEdit->setText(address);
    ui->phoneEdit->setText(phone);
    ui->birthdayEdit->setText(birthday);
    ui->kaoqingEdit->setText("考勤成功");
    //ui->lineEdit->setText(jsonstr);

}


void AttandenceServer::send_header()
{
    //发送头像
    QString facepath = name.toUtf8().toBase64();
    facepath.append(".jpg");
    QFile file(facepath);
    file.open(QIODevice::ReadOnly);
    QByteArray filearray = file.readAll();
    sendHeader->send_data(filearray,"192.168.56.1",9526);
    file.close();
}



void AttandenceServer::on_registerBt_clicked()
{
    AttandenceRegister *reg =  new AttandenceRegister();
    reg->show();
}
