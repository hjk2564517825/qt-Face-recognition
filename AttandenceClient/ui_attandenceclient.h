/********************************************************************************
** Form generated from reading UI file 'attandenceclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTANDENCECLIENT_H
#define UI_ATTANDENCECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttandenceClient
{
public:
    QLabel *videoLb;
    QLabel *timeLb;
    QLabel *headerLb;
    QLabel *nameLb;
    QLabel *departmentLb;
    QLabel *jopLb;
    QLabel *idLb;
    QLabel *cardLb;

    void setupUi(QWidget *AttandenceClient)
    {
        if (AttandenceClient->objectName().isEmpty())
            AttandenceClient->setObjectName(QString::fromUtf8("AttandenceClient"));
        AttandenceClient->resize(800, 480);
        AttandenceClient->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QWidget{\n"
"background-color: rgba(49, 49, 49,0.8);\n"
"}\n"
"QLabel{\n"
"border : none;\n"
"border-radius:15px;\n"
"	\n"
"}"));
        videoLb = new QLabel(AttandenceClient);
        videoLb->setObjectName(QString::fromUtf8("videoLb"));
        videoLb->setGeometry(QRect(0, 0, 540, 471));
        videoLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 176, 207);"));
        timeLb = new QLabel(AttandenceClient);
        timeLb->setObjectName(QString::fromUtf8("timeLb"));
        timeLb->setGeometry(QRect(540, 10, 260, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        timeLb->setFont(font);
        timeLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 225);"));
        timeLb->setAlignment(Qt::AlignCenter);
        headerLb = new QLabel(AttandenceClient);
        headerLb->setObjectName(QString::fromUtf8("headerLb"));
        headerLb->setGeometry(QRect(580, 50, 180, 171));
        headerLb->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 255, 190);\n"
"border-radius:90px"));
        nameLb = new QLabel(AttandenceClient);
        nameLb->setObjectName(QString::fromUtf8("nameLb"));
        nameLb->setGeometry(QRect(540, 230, 260, 41));
        nameLb->setFont(font);
        nameLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 225);"));
        nameLb->setAlignment(Qt::AlignCenter);
        departmentLb = new QLabel(AttandenceClient);
        departmentLb->setObjectName(QString::fromUtf8("departmentLb"));
        departmentLb->setGeometry(QRect(540, 280, 260, 41));
        departmentLb->setFont(font);
        departmentLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 225);"));
        departmentLb->setAlignment(Qt::AlignCenter);
        jopLb = new QLabel(AttandenceClient);
        jopLb->setObjectName(QString::fromUtf8("jopLb"));
        jopLb->setGeometry(QRect(540, 330, 261, 41));
        jopLb->setFont(font);
        jopLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 225);"));
        jopLb->setAlignment(Qt::AlignCenter);
        idLb = new QLabel(AttandenceClient);
        idLb->setObjectName(QString::fromUtf8("idLb"));
        idLb->setGeometry(QRect(540, 380, 260, 41));
        idLb->setFont(font);
        idLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 225);"));
        idLb->setAlignment(Qt::AlignCenter);
        cardLb = new QLabel(AttandenceClient);
        cardLb->setObjectName(QString::fromUtf8("cardLb"));
        cardLb->setGeometry(QRect(540, 430, 260, 41));
        cardLb->setFont(font);
        cardLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 225);"));
        cardLb->setAlignment(Qt::AlignCenter);

        retranslateUi(AttandenceClient);

        QMetaObject::connectSlotsByName(AttandenceClient);
    } // setupUi

    void retranslateUi(QWidget *AttandenceClient)
    {
        AttandenceClient->setWindowTitle(QCoreApplication::translate("AttandenceClient", "AttandenceClient", nullptr));
        videoLb->setText(QString());
        timeLb->setText(QCoreApplication::translate("AttandenceClient", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        headerLb->setText(QString());
        nameLb->setText(QCoreApplication::translate("AttandenceClient", "\345\247\223\345\220\215", nullptr));
        departmentLb->setText(QCoreApplication::translate("AttandenceClient", "\351\203\250\351\227\250", nullptr));
        jopLb->setText(QCoreApplication::translate("AttandenceClient", "\350\201\214\344\275\215", nullptr));
        idLb->setText(QCoreApplication::translate("AttandenceClient", "\345\221\230\345\267\245\347\274\226\345\217\267", nullptr));
        cardLb->setText(QCoreApplication::translate("AttandenceClient", "\346\211\223\345\215\241\347\212\266\346\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttandenceClient: public Ui_AttandenceClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTANDENCECLIENT_H
