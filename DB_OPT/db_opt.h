#ifndef DB_OPT_H
#define DB_OPT_H

#include "DB_OPT_global.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DB_OPT_EXPORT DB_OPT
{
public:
    DB_OPT();
    ~DB_OPT();
    int test(int a, int b);
    bool CreateTable();
    bool InsertDB(QString name, int level, int score);
    bool IsTableExist(QString tableName);
private:
    QSqlDatabase db;
};

#endif // DB_OPT_H
