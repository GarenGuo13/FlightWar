#include "db_opt.h"
#include <iostream>
#include <QDebug>
DB_OPT::DB_OPT()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
        std::cout << "this is DB_OPT qt_sql_default_connection" << std::endl;
    }else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("FlightWarGame.db");
        db.setUserName("admin");
        db.setPassword("123456");
        std::cout << "this is DB_OPT FlightWarGame.db" << std::endl;
    }
    std::cout << "this is DB_OPT debug" << std::endl;
}

DB_OPT::~DB_OPT()
{
    db.close();
}

int DB_OPT::test(int a, int b)
{
    return a+b;
}

bool DB_OPT::CreateTable()
{
    if(!db.open())
    {
        qDebug() << "CreateTable is err:" << db.lastError();
        return false;
    }else{
        QSqlQuery query;
        QString sql("create table game "
                    "(id int primary key, name varchar(30), level int, score int)");
        query.prepare(sql);
        if(!query.exec()){
            qDebug() << "query.exec1 is err:" << db.lastError();
            return false;
        }
        else{
            qDebug() << "query.exec is ok:";
        }
    }
    return true;
}

bool DB_OPT::InsertDB(QString name, int level, int score)
{
    QSqlQuery query;
    query.prepare("INSERT INTO game (level) "
                  "VALUES  (:level)");

    query.bindValue(":level", level);
    if(!query.exec())
    {
        qDebug() << "query.exec2 is err:" << db.lastError();
        return false;
    }
    else{
        qDebug() << "query.exec is ok:";
    }
//    db.commit();
    return true;
}

bool DB_OPT::IsTableExist(QString tableName)
{
    QString sql = QString("select * from sqlite_master where name='%1'").arg(tableName);
    QSqlQuery query;
    query.exec(sql);
    return query.next();
}
