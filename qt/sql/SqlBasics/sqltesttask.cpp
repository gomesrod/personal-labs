#include "sqltesttask.h"

#include <iostream>

#include <QtSql/QtSql>

using namespace std;

SqlTestTask::SqlTestTask(QObject *parent) :
    QObject(parent)
{
}

void SqlTestTask::run()
{
    cout << "Iniciando..." << endl;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("root");
    if (db.open()) {
        QSqlQuery query;
        query.exec("select 'IN MYSQL'");
        query.next();
        cout << "Result: " << query.value(0).toString().toStdString() << endl;

    } else {
        cout << "FALHA: " << db.lastError().databaseText().toStdString() << endl;
    }

    qApp->exit(0);
}
