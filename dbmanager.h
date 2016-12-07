#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QDebug>
#include <vector>
#include "scientist.h"
#include "computer.h"

using namespace std;

class DbManager
{
public:

    DbManager();

    vector<Scientist> getScientists(QString order, QString filter);
    vector<Computer> getComputers();

private:

    QSqlDatabase db;
};

#endif // DBMANAGER_H
