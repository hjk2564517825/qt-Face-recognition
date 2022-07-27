#ifndef ATTANDENCESERVER_H
#define ATTANDENCESERVER_H

#include <QMainWindow>
#include <udptransfer.h>
#include <QFile>
#include <opencv.hpp>
#include <QSqlTableModel>
#include <seeta/FaceEngine.h>
#include <seeta/Struct_cv.h>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class AttandenceServer; }
QT_END_NAMESPACE

class AttandenceServer : public QMainWindow
{
    Q_OBJECT

public:
    AttandenceServer(QWidget *parent = nullptr);
    ~AttandenceServer();

private slots:
    void recvface(QByteArray &array);


    void on_registerBt_clicked();

    void send_header();
private:
    Ui::AttandenceServer *ui;
    UdpTransfer *recvFacePtr;
    UdpTransfer *sendJson;
    UdpTransfer *sendHeader;
    QString  name;
    QString  address;
    QString  phone;
    QString  sex;
    QString  birthday;
    seeta::FaceEngine *engine;
};
#endif // ATTANDENCESERVER_H
