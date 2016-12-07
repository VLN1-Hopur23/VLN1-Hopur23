#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QtSql>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>
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
    string addScientist(const Scientist& scientist);
    bool scientistExists(const string& searchData) const;
    bool computerExists(const string& searchData) const;
    vector<Scientist> searchScientist(string& searchData);
    vector<Computer> searchComputer(string& searchData);

private:

    QSqlDatabase db;
};

#endif // DBMANAGER_H
