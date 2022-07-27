#include "attandenceregister.h"
#include "ui_attandenceregister.h"
#include <QMessageBox>
#include <seeta/FaceEngine.h>
#include <seeta/Struct_cv.h>

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>

int ret;
AttandenceRegister::AttandenceRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttandenceRegister)
{
    ui->setupUi(this);
    // 拍照  标示
    camflag = false;
    seeta::ModelSetting::Device device = seeta::ModelSetting::CPU;
    int id = 0;
    seeta::ModelSetting FD_model( "./model/fd_2_00.dat", device, id );
    fDetector = new seeta::FaceDetector ( FD_model );
}

AttandenceRegister::~AttandenceRegister()
{
    delete ui;
}

void AttandenceRegister::timerEvent(QTimerEvent *e)
{
    //采集一帧数据
    Mat videoImage ;
    cap>>videoImage;

    SeetaImageData image;
    image.data = videoImage.data ;
    image.width = videoImage.cols;
    image.height = videoImage.rows;
    image.channels = videoImage.channels();
    SeetaFaceInfoArray infoarray = fDetector->detect(image);

    if(infoarray.size > 0)
    {
        SeetaRect pos = infoarray.data[0].pos;
        rectangle(videoImage, cv::Rect(pos.x,pos.y, pos.width, pos.height),cv::Scalar(0,255,255,0));
        if(camflag)
        {
            //存储照片
            QString name = ui->nameEdit->text().toUtf8().toBase64();
            name.append(".jpg");
            cv::Mat saveFace = videoImage(cv::Rect(pos.x,pos.y, pos.width, pos.height));
            cv::imwrite(name.toUtf8().data(), saveFace);
            camflag = false;
            QPixmap mmp(name);
            mmp = mmp.scaled(ui->headerLb->size());
            ui->headerLb->setPixmap(mmp);
        }
    }


    //显示Mat--》QImage
    Mat rgbImage;
    cvtColor(videoImage, rgbImage, COLOR_BGR2RGB);
    QImage img(rgbImage.data, rgbImage.cols, rgbImage.rows, QImage::Format_RGB888);
    QPixmap mmp = QPixmap::fromImage(img);
    mmp = mmp.scaled(ui->videoLb->size());
    ui->videoLb->setPixmap(mmp);
}

void AttandenceRegister::on_openBt_clicked()
{
   if( !cap.open(0))
   {
       QMessageBox::warning(this, "提示","打开摄像头失败");
       return ;
   }
    ret = startTimer(100);
}

void AttandenceRegister::on_capBt_clicked()
{
    if(ui->nameEdit->text().isEmpty() ||
       ui->departmentEdit->text().isEmpty()||
       ui->jopEdit->text().isEmpty()||
       ui->phoneEdit->text().isEmpty()||
       ui->addressEdit->text().isEmpty() ||
       ui->ptelEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "提示","请输入员工信息");
        return;
    }

    camflag = true;

}

void AttandenceRegister::on_regBt_clicked()
{
    //注册1. 获取员工信息， 注册人脸-faceid， 插入数据库
    QString name, sex, department, jop, phone, address, emergencyCall;
    name = ui->nameEdit->text();
    sex = ui->sexcbb->currentText();
    department = ui->departmentEdit->text();
    jop = ui->jopEdit->text();
    phone = ui->phoneEdit->text();
    address = ui->addressEdit->text();
    emergencyCall=ui->ptelEdit->text();
    QString birthday = ui->bdayEdit->text();
    QString enday = ui->endayEdit->text();
    phone_now = phone;
    if(name.isEmpty() || department.isEmpty()||
            jop.isEmpty()||phone.isEmpty()||address.isEmpty()||
            emergencyCall.isEmpty())
    {
        QMessageBox::warning(this, "提示","请输入员工信息");
        return;
    }


    seeta::ModelSetting::Device device = seeta::ModelSetting::CPU;
    int id = 0;
    seeta::ModelSetting FD_model( "./model/fd_2_00.dat", device, id );
    seeta::ModelSetting PD_model( "./model/pd_2_00_pts5.dat", device, id );
    seeta::ModelSetting FR_model( "./model/fr_2_10.dat", device, id );
    seeta::FaceEngine engine( FD_model, PD_model, FR_model);
    engine.Load("./face.db"); //导入已有的人脸数据
    QString facename = ui->nameEdit->text().toUtf8().toBase64();
    facename.append(".jpg");
    cv::Mat faceImage = imread(facename.toUtf8().data());
    seeta::cv::ImageData image = faceImage;
    int64_t faceid = engine.Register(image);

    if(faceid < 0)
    {
        QMessageBox::warning(this, "提示","注册失败");
        return;
    }
    //导出人脸数据
    engine.Save("./face.db");

    // 打包插入员工数据的指令
    QString insertsql=QString("insert into employee(name,sex,birthday, address, phone, faceid, headpath) values"
                              "('%1','%2','%3','%4','%5','%6','%7')")
            .arg(name).arg(sex).arg(birthday).arg(address).arg(phone).arg(faceid).arg(facename);

    //执行sql语句
    QSqlQuery query;
    if(!query.exec(insertsql))
    {
        qDebug()<<query.lastError().text();
    }

    //获取员工编号--通过人脸id获取员工编号
    QSqlTableModel model;
    model.setTable("employee");
    model.setFilter(QString("faceid='%1'").arg(faceid)) ;
    model.select();
    int employeeid = model.record(0).value("employeeid").toInt();

    // 人事数据
    model.setTable("person");//设置模型的表格名
    model.select();
    QSqlRecord recd = model.record();//获取一条空记录
    recd.setValue("employeeid", employeeid);
    recd.setValue("department", department);
    recd.setValue("jop",jop);
    recd.setValue("enter", enday);
    recd.setValue("emergencyCall",emergencyCall);
    model.insertRecord(0,recd);//插入到数据表

    //关闭摄像头
    killTimer(ret);
    cap.release();
}

void AttandenceRegister::on_cap_closeBt_clicked()
{
    killTimer(ret);
    cap.release();
}
