/********************************************************************************
** Form generated from reading UI file 'attandenceregister.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTANDENCEREGISTER_H
#define UI_ATTANDENCEREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttandenceRegister
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *videoLb;
    QLabel *headerLb;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *sexcbb;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *bdayEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *departmentEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *jopEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *phoneEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *addressEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDateEdit *endayEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *ptelEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *openBt;
    QPushButton *cap_closeBt;
    QPushButton *capBt;
    QPushButton *regBt;

    void setupUi(QWidget *AttandenceRegister)
    {
        if (AttandenceRegister->objectName().isEmpty())
            AttandenceRegister->setObjectName(QString::fromUtf8("AttandenceRegister"));
        AttandenceRegister->resize(742, 476);
        AttandenceRegister->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 250,0, 234);\n"
"}\n"
"QWidget{\n"
"background-color: rgba(49, 49, 49,0.8);\n"
"}\n"
"QLabel{\n"
"border-color: rgb(255, 255, 0);\n"
"border : none;\n"
"border-radius:15px;\n"
"	\n"
"}\n"
"QLabel#label,QLabel#label_2,QLabel#label_3,\n"
"QLabel#label_4,QLabel#label_5,QLabel#label_6,\n"
"QLabel#label_7,QLabel#label_8,QLabel#label_9\n"
"{\n"
"	\n"
"	color: rgb(250,250,5,250);\n"
"}\n"
"\n"
"QPushButton#capBt,QPushButton#cap_closeBt,\n"
"QPushButton#openBt,QPushButton#regBt\n"
"{\n"
"	\n"
"	color: rgb(250,250,5,250);\n"
"}"));
        layoutWidget = new QWidget(AttandenceRegister);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 322, 461));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        videoLb = new QLabel(layoutWidget);
        videoLb->setObjectName(QString::fromUtf8("videoLb"));
        videoLb->setMinimumSize(QSize(320, 240));
        videoLb->setMaximumSize(QSize(320, 240));
        videoLb->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));

        verticalLayout_3->addWidget(videoLb);

        headerLb = new QLabel(layoutWidget);
        headerLb->setObjectName(QString::fromUtf8("headerLb"));
        headerLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250,0, 234);"));

        verticalLayout_3->addWidget(headerLb);

        layoutWidget1 = new QWidget(AttandenceRegister);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(350, 10, 381, 431));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(layoutWidget1);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);
        nameEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        sexcbb = new QComboBox(layoutWidget1);
        sexcbb->addItem(QString());
        sexcbb->addItem(QString());
        sexcbb->setObjectName(QString::fromUtf8("sexcbb"));
        sizePolicy.setHeightForWidth(sexcbb->sizePolicy().hasHeightForWidth());
        sexcbb->setSizePolicy(sizePolicy);
        sexcbb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(sexcbb);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        bdayEdit = new QDateEdit(layoutWidget1);
        bdayEdit->setObjectName(QString::fromUtf8("bdayEdit"));
        sizePolicy.setHeightForWidth(bdayEdit->sizePolicy().hasHeightForWidth());
        bdayEdit->setSizePolicy(sizePolicy);
        bdayEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(bdayEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        departmentEdit = new QLineEdit(layoutWidget1);
        departmentEdit->setObjectName(QString::fromUtf8("departmentEdit"));
        sizePolicy.setHeightForWidth(departmentEdit->sizePolicy().hasHeightForWidth());
        departmentEdit->setSizePolicy(sizePolicy);
        departmentEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(departmentEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        jopEdit = new QLineEdit(layoutWidget1);
        jopEdit->setObjectName(QString::fromUtf8("jopEdit"));
        sizePolicy.setHeightForWidth(jopEdit->sizePolicy().hasHeightForWidth());
        jopEdit->setSizePolicy(sizePolicy);
        jopEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(jopEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        phoneEdit = new QLineEdit(layoutWidget1);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        sizePolicy.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy);
        phoneEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(phoneEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        addressEdit = new QLineEdit(layoutWidget1);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
        sizePolicy.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy);
        addressEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(addressEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        endayEdit = new QDateEdit(layoutWidget1);
        endayEdit->setObjectName(QString::fromUtf8("endayEdit"));
        sizePolicy.setHeightForWidth(endayEdit->sizePolicy().hasHeightForWidth());
        endayEdit->setSizePolicy(sizePolicy);
        endayEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(endayEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        ptelEdit = new QLineEdit(layoutWidget1);
        ptelEdit->setObjectName(QString::fromUtf8("ptelEdit"));
        sizePolicy.setHeightForWidth(ptelEdit->sizePolicy().hasHeightForWidth());
        ptelEdit->setSizePolicy(sizePolicy);
        ptelEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_9->addWidget(ptelEdit);


        verticalLayout->addLayout(horizontalLayout_9);

        layoutWidget2 = new QWidget(AttandenceRegister);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(350, 440, 381, 31));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        openBt = new QPushButton(layoutWidget2);
        openBt->setObjectName(QString::fromUtf8("openBt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openBt->sizePolicy().hasHeightForWidth());
        openBt->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(openBt);

        cap_closeBt = new QPushButton(layoutWidget2);
        cap_closeBt->setObjectName(QString::fromUtf8("cap_closeBt"));
        sizePolicy1.setHeightForWidth(cap_closeBt->sizePolicy().hasHeightForWidth());
        cap_closeBt->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(cap_closeBt);

        capBt = new QPushButton(layoutWidget2);
        capBt->setObjectName(QString::fromUtf8("capBt"));
        sizePolicy1.setHeightForWidth(capBt->sizePolicy().hasHeightForWidth());
        capBt->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(capBt);

        regBt = new QPushButton(layoutWidget2);
        regBt->setObjectName(QString::fromUtf8("regBt"));
        sizePolicy1.setHeightForWidth(regBt->sizePolicy().hasHeightForWidth());
        regBt->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(regBt);


        retranslateUi(AttandenceRegister);

        QMetaObject::connectSlotsByName(AttandenceRegister);
    } // setupUi

    void retranslateUi(QWidget *AttandenceRegister)
    {
        AttandenceRegister->setWindowTitle(QCoreApplication::translate("AttandenceRegister", "Form", nullptr));
        videoLb->setText(QString());
        headerLb->setText(QString());
        label->setText(QCoreApplication::translate("AttandenceRegister", "\345\247\223\345\220\215:", nullptr));
        label_2->setText(QCoreApplication::translate("AttandenceRegister", "\346\200\247\345\210\253:", nullptr));
        sexcbb->setItemText(0, QCoreApplication::translate("AttandenceRegister", "\347\224\267", nullptr));
        sexcbb->setItemText(1, QCoreApplication::translate("AttandenceRegister", "\345\245\263", nullptr));

        label_3->setText(QCoreApplication::translate("AttandenceRegister", "\347\224\237\346\227\245:", nullptr));
        label_4->setText(QCoreApplication::translate("AttandenceRegister", "\351\203\250\351\227\250:", nullptr));
        label_5->setText(QCoreApplication::translate("AttandenceRegister", "\350\201\214\344\275\215:", nullptr));
        label_6->setText(QCoreApplication::translate("AttandenceRegister", "\347\224\265\350\257\235:", nullptr));
        label_7->setText(QCoreApplication::translate("AttandenceRegister", "\345\234\260\345\235\200:", nullptr));
        label_8->setText(QCoreApplication::translate("AttandenceRegister", "\345\205\245\350\201\214\346\227\266\351\227\264:", nullptr));
        label_9->setText(QCoreApplication::translate("AttandenceRegister", "\347\264\247\346\200\245\350\201\224\347\263\273:", nullptr));
        openBt->setText(QCoreApplication::translate("AttandenceRegister", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        cap_closeBt->setText(QCoreApplication::translate("AttandenceRegister", "\345\205\263\351\227\255\347\233\270\346\234\272", nullptr));
        capBt->setText(QCoreApplication::translate("AttandenceRegister", "\346\213\215\347\205\247", nullptr));
        regBt->setText(QCoreApplication::translate("AttandenceRegister", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttandenceRegister: public Ui_AttandenceRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTANDENCEREGISTER_H
