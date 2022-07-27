#include "attandenceserver.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
        return -1;
    }

    //创建表格
    QString createSql = "create table if not exists employee(employeeid integer primary key autoincrement,"
                        "name varchar(32),sex varchar(8), birthday text, address text,"
                        " phone text, faceid varchar(8) unique, headpath text)";
    QSqlQuery query;
    if(!query.exec(createSql))
    {
        qDebug()<<"1"<<query.lastError().text();
        return -1;
    }

    createSql = "create table if not exists person(personid integer primary key autoincrement,"
                "employeeid integer ,department text, jop text, enter text, emergencyCall text)";
    if(!query.exec(createSql))
    {
        qDebug()<<"2"<<query.lastError().text();
        return -1;
    }

    createSql = "create table if not exists attendance(attendanceid integer primary key autoincrement,"
                "attendancetime TimeStamp NOT NULL DEFAULT (datetime('now','localtime')), employeeid integer)";
    if(!query.exec(createSql))
    {
        qDebug()<<"3"<<query.lastError().text();
        return -1;
    }

    AttandenceServer w;
    w.show();
    return a.exec();
}
