#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <vector>
#include "scientist.h"

using namespace std;

class DbManager
{
public:
    DbManager();

    vector<Scientist> getScientists();

private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
