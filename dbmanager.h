#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <vector>
#include "scientist.h"
#include "computer.h"
#include <iostream> // Temporary

using namespace std;

class DbManager
{
public:

    DbManager();

    vector<Scientist> getScientists(QString QSorder, QString QSfilter);

    vector<Computer> getComputers(QString QSorder, QString QSfilter);

    string addScientist(const Scientist& scientist);

    bool scientistExists(const string& searchData) const;

    bool computerExists(const string& searchData) const;

    vector<Scientist> searchScientist(const string& searchData);

    vector<Computer> searchComputer(string& searchData);

    vector<Computer> intersectScientists();

private:

    QSqlDatabase db;
};

#endif // DBMANAGER_H
