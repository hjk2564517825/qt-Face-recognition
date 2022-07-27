#include "attandenceclient.h"
#include "ui_attandenceclient.h"

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonValue>


#include <QTime>


AttandenceClient::AttandenceClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AttandenceClient)
{
    ui->setupUi(this);

    //初始化发送对象
    sendPtr = new UdpTransfer();
    recvHeaderPtr = new UdpTransfer(UdpTransfer::RECV,9526);
    recvJsonPtr = new UdpTransfer(UdpTransfer::RECV,9525);

    connect(recvJsonPtr, &UdpTransfer::recviceFinished, this, &AttandenceClient::recvjson);
    connect(recvHeaderPtr, &UdpTransfer::recviceFinished,this, &AttandenceClient::recvheader);

    facePid = -1;
    times = 0;
#if WIN32
    //打开摄像头
    cap.open(0);
#else
    //cap.open("/dev/video7");
#endif
    //初始化人脸跟踪对象
    seeta::ModelSetting::Device device = seeta::ModelSetting::CPU;
    int id = 0;
    seeta::ModelSetting FT_model( "./model/fd_2_00.dat", device, id );
    fTracker = new FaceTracker(FT_model);

    //开启定时器事件-每隔100毫秒就发送一次定时器事件
    startTimer(100);

}

AttandenceClient::~AttandenceClient()
{
    delete ui;
}

void AttandenceClient::timerEvent(QTimerEvent *e)
{
    //获取系统时间
    ui->timeLb->setText(QTime::currentTime().toString("hh:mm:ss"));
    Mat videoImage; //图像数据--矩阵数据
    cap>>videoImage;  //开始采集一帧数据
    if(videoImage.data == nullptr)
    {
        return;
    }
    //人脸跟踪
    SeetaImageData seetimage;
    seetimage.data = videoImage.data;
    seetimage.width = videoImage.cols;
    seetimage.height = videoImage.rows;
    seetimage.channels = videoImage.channels();
    SeetaTrackingFaceInfoArray infoArray  = fTracker->track(seetimage);
    if(infoArray.size>0)
    {
        //取出第一个人脸信息
        SeetaTrackingFaceInfo faceinfo = infoArray.data[0];
        SeetaRect pos = faceinfo.pos;
        //绘制人脸区域
        cv::Rect faceRect(pos.x, pos.y, pos.width, pos.height);
        rectangle(videoImage, faceRect,cv::Scalar(255,0,0,0));

        if(faceinfo.score > 0.9 && facePid != faceinfo.PID) //人脸质量
        {
            if(times == 5)
            {
                times=0;
                facePid = faceinfo.PID;
                //提取人脸
                Mat faceImage = videoImage(faceRect);
                //压缩人脸为jpeg
                std::vector<uchar> buf;
                std::vector<int> parm = std::vector<int>(2);
                parm[0] = IMWRITE_JPEG_OPTIMIZE;
                parm[1] = 95;
                cv::imencode(".jpg",faceImage,buf, parm);
                //上传人脸数据
                QByteArray array((char*)buf.data(),buf.size());
                sendPtr->send_data(array,"192.168.56.1",9527);
            }
            times++;
        }
    }

    //把BGR--》RGB格式
    Mat rgbImage;
    cvtColor(videoImage, rgbImage,COLOR_BGR2RGB);
    //把Mat数据转为QImage
    QImage img = QImage(rgbImage.data, rgbImage.cols, rgbImage.rows,QImage::Format_RGB888);
    //显示
    ui->videoLb->setPixmap(QPixmap::fromImage(img));
}

void AttandenceClient::recvjson(QByteArray& array)
{
    //在界面上显示个人信息
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(array,&err);
    if(err.error != QJsonParseError::NoError)
    {
        qDebug()<<"json err";
        return ;
    }
    QJsonObject obj = doc.object();
    if(obj.value("type").toString() == "0")
    {
        qDebug()<<"考勤成功";
        ui->nameLb->setText(obj.value("name").toString());
        ui->departmentLb->setText(obj.value("department").toString());
        ui->jopLb->setText(obj.value("jop").toString());
        ui->idLb->setText(obj.value("employeeid").toString());
        ui->cardLb->setText("打卡成功");
    }

}

void AttandenceClient::recvheader(QByteArray& array)
{
    //在界面上显示头像
    ui->headerLb->clear();
    QPixmap mmp;
    mmp.loadFromData(array);
    mmp = mmp.scaled(180,180);
    mmp.save("./1.jpg");
    ui->headerLb->setPixmap(mmp);
    //ui->headerLb->setStyleSheet("background-color: rgb(194, 255, 190);\
                                border-radius:90px; border-image:url(./tmp.jpg)");
}
