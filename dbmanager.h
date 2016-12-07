#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
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

private:

    QSqlDatabase db;
};

#endif // DBMANAGER_H
