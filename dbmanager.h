#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
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

    vector<Scientist> getScientists();
    vector<Computer> getComputers();

private:

    QSqlDatabase db;
};

#endif // DBMANAGER_H
