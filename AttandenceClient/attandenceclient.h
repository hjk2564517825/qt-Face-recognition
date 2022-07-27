#ifndef ATTANDENCECLIENT_H
#define ATTANDENCECLIENT_H

#include <QWidget>
#include <opencv.hpp>
#include <QDebug>
#include <seeta/FaceTracker.h>
#include <udptransfer.h>
using namespace  cv;
using namespace  seeta;
using namespace  seeta::v2;
QT_BEGIN_NAMESPACE
namespace Ui { class AttandenceClient; }
QT_END_NAMESPACE

class AttandenceClient : public QWidget
{
    Q_OBJECT

public:
    AttandenceClient(QWidget *parent = nullptr);
    ~AttandenceClient();
    void timerEvent(QTimerEvent *e);
private slots:
    void recvjson(QByteArray &array);
    void recvheader(QByteArray &array);
private:
    Ui::AttandenceClient *ui;
    VideoCapture  cap;
    FaceTracker *fTracker;
    int facePid;
    int times;

    //发送数据接收数据
    UdpTransfer *sendPtr;
    UdpTransfer *recvHeaderPtr;
    UdpTransfer *recvJsonPtr;
};
#endif // ATTANDENCECLIENT_H
