#ifndef ATTANDENCEREGISTER_H
#define ATTANDENCEREGISTER_H

#include <QWidget>
#include <opencv.hpp>
#include <seeta/FaceDetector.h>
using namespace cv;
namespace Ui {
class AttandenceRegister;
}

class AttandenceRegister : public QWidget
{
    Q_OBJECT

public:
    explicit AttandenceRegister(QWidget *parent = nullptr);
    ~AttandenceRegister();
    void timerEvent(QTimerEvent* e);//定时器 事件
    QString phone_now;
private slots:
    void on_openBt_clicked();
    void on_capBt_clicked();
    void on_regBt_clicked();
    void on_cap_closeBt_clicked();

private:
    Ui::AttandenceRegister *ui;
    VideoCapture cap;
    bool camflag;
    seeta::FaceDetector *fDetector;
    int time_ret;

};

#endif // ATTANDENCEREGISTER_H
