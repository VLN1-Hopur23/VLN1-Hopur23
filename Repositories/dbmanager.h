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

    vector<Computer> getComputers();

    // Add:
    bool addScientist(const Scientist& scientist, int& id);

    bool addComputer(const Computer& computer, int& id);

    bool addIntersect(const int& param1, const int& param2);

    // Delete:
    bool deleteScientist(const int ID);

    bool deleteComputer(const int ID);

    void deleteConnection(const int ID);

    void addConnection(const int ScientistID, const int ComputerID);

    // Connection:
    vector<Computer> intersectScientist(const QString& id);

    vector<Scientist> intersectComputer(const QString& id);

    QString deleteConnection(const int& scientistID, const int& computerID);

    // Search:
    vector<Scientist> searchScientist(const string& searchData);

    vector<Computer> searchComputer(string& searchData);

    vector<Computer> searchComputerPeriod(int yearFrom, int yearTo);

    vector<Scientist> filterScientist(const string& Command, const string& searchData);

    vector<Computer> filterComputer(const string& Command, const string& searchData);

    // Edit:
    string editScientistName(const int& id, const string& newName);

    string editScientistGender(const int& id, const string& newGender);

    string editScientistBirthYear(const int& id, const string& newBirthYear);

    string editScientistDeathYear(const int& id, const string& newDeathYear);

    string editComputerName(const int& id, const string& newName);

    string editComputerYearBuilt(const int& id, const string& newName);

    string editComputerType(const int& id, const string& newName);

    string editComputeBuilt(const int& id, bool newWasBuilt);

    string stringToLower(string str);

private:

    QSqlDatabase _db;

    QString dbName;

    QString connName;
};

#endif // DBMANAGER_H
