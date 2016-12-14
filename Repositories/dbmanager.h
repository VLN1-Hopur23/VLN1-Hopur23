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

    vector<Scientist> getScientists();

    vector<Computer> getComputers(QString QSorder, QString QSfilter);

    bool addScientist(const Scientist& scientist, int& id) const;

    void deleteScientist(const int ID);

    void deleteComputer(const int ID);

    bool scientistExists(const string& searchData) const;

    bool addComputer(const Computer& computer, int& id) const;

    bool computerExists(const string& searchData) const;

    vector<Scientist> searchScientist(const string& searchData);

    vector<Computer> searchComputer(string& searchData);

    vector<Computer> searchComputerPeriod(int yearFrom, int yearTo);

    vector<Computer> intersectScientist(const string& id);

    vector<Scientist> intersectComputer(const string& id);

    vector<Scientist> filterScientist(const string& Command, const string& searchData);

    vector<Computer> filterComputer(const string& Command, const string& searchData);

    bool addIntersect(const int& param1, const int& param2);

    // Edit:
    string editScientistName(const int& id, const string& newName);

    string editScientistGender(const int& id, const string& newGender);

    string editScientistBirthYear(const int& id, const string& newBirthYear);

    string editScientistDeathYear(const int& id, const string& newDeathYear);

    string editComputerName(const int& id, const string& newName);

    string editComputerYearBuilt(const int& id, const string& newName);

    string editComputerType(const int& id, const string& newName);

    string stringToLower(string str);

private:

    QSqlDatabase _db;

    QString dbName;

    QString connName;
};

#endif // DBMANAGER_H
