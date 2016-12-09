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

    ~DbManager();

    vector<Scientist> getScientists(QString QSorder, QString QSfilter);

    vector<Computer> getComputers(QString QSorder, QString QSfilter);

    bool addScientist(const Scientist& scientist, int& id) const;

    void deleteScientist(const int& ID);

    void deleteComputer(const int& ID);

    bool scientistExists(const string& searchData) const;

    bool addComputer(const Computer& computer) const;

    bool computerExists(const string& searchData) const;

    vector<Scientist> searchScientist(const string& searchData);

    vector<Computer> searchComputer(string& searchData);

    vector<Computer> intersectScientist(const string& id);

    vector<Scientist> intersectComputer(const string& id);

    vector<Scientist> filterScientist(const string& Command, const string& searchData);

    vector<Computer> filterComputer(const string& Command, const string& searchData);

    // Edit:
    string editScientistName(const int& id, const string& newName);

    string editScientistGender(const int& id, const string& newGender);

    string editScientistBirthYear(const int& id, const string& newBirthYear);

    string editScientistDeathYear(const int& id, const string& newDeathYear);

    bool addIntersectScientist(const int& param1, const int& param2);

private:

    QSqlDatabase _db;

};

#endif // DBMANAGER_H
