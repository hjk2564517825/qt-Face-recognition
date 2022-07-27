/********************************************************************************
** Form generated from reading UI file 'attandenceserver.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTANDENCESERVER_H
#define UI_ATTANDENCESERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttandenceServer
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *registerBt;
    QLineEdit *nameEdit;
    QLineEdit *sexEdit;
    QLineEdit *addressEdit;
    QLineEdit *phoneEdit;
    QLineEdit *birthdayEdit;
    QLineEdit *kaoqingEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AttandenceServer)
    {
        if (AttandenceServer->objectName().isEmpty())
            AttandenceServer->setObjectName(QString::fromUtf8("AttandenceServer"));
        AttandenceServer->resize(810, 480);
        AttandenceServer->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QMainWindow{\n"
"background-color: rgba(49, 49, 49,0.8);\n"
"}\n"
"QLabel{\n"
"border : none;\n"
"border-radius:15px;\n"
"	\n"
"}"));
        centralwidget = new QWidget(AttandenceServer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 251, 231));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250,0, 234);"));
        registerBt = new QPushButton(centralwidget);
        registerBt->setObjectName(QString::fromUtf8("registerBt"));
        registerBt->setGeometry(QRect(440, 400, 361, 51));
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(435, 24, 371, 41));
        nameEdit->setLayoutDirection(Qt::LeftToRight);
        nameEdit->setCursorPosition(0);
        nameEdit->setAlignment(Qt::AlignCenter);
        sexEdit = new QLineEdit(centralwidget);
        sexEdit->setObjectName(QString::fromUtf8("sexEdit"));
        sexEdit->setGeometry(QRect(435, 84, 371, 41));
        sexEdit->setAlignment(Qt::AlignCenter);
        addressEdit = new QLineEdit(centralwidget);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
        addressEdit->setGeometry(QRect(435, 144, 371, 41));
        addressEdit->setAlignment(Qt::AlignCenter);
        phoneEdit = new QLineEdit(centralwidget);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        phoneEdit->setGeometry(QRect(435, 204, 371, 41));
        phoneEdit->setAlignment(Qt::AlignCenter);
        birthdayEdit = new QLineEdit(centralwidget);
        birthdayEdit->setObjectName(QString::fromUtf8("birthdayEdit"));
        birthdayEdit->setGeometry(QRect(435, 264, 371, 41));
        birthdayEdit->setAlignment(Qt::AlignCenter);
        kaoqingEdit = new QLineEdit(centralwidget);
        kaoqingEdit->setObjectName(QString::fromUtf8("kaoqingEdit"));
        kaoqingEdit->setGeometry(QRect(435, 324, 371, 41));
        kaoqingEdit->setAlignment(Qt::AlignCenter);
        AttandenceServer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AttandenceServer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AttandenceServer->setStatusBar(statusbar);

        retranslateUi(AttandenceServer);

        QMetaObject::connectSlotsByName(AttandenceServer);
    } // setupUi

    void retranslateUi(QMainWindow *AttandenceServer)
    {
        AttandenceServer->setWindowTitle(QCoreApplication::translate("AttandenceServer", "AttandenceServer", nullptr));
        label->setText(QString());
        registerBt->setText(QCoreApplication::translate("AttandenceServer", "\345\221\230\345\267\245\346\263\250\345\206\214", nullptr));
        nameEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AttandenceServer: public Ui_AttandenceServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTANDENCESERVER_H
