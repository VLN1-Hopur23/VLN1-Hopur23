#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "computer.h"
#include "dbmanager.h"
#include <algorithm>
#include <vector>

using namespace std;

class ComputerService
{
public:

    ComputerService();

    bool addComputer(Computer computer, int& id);

    Computer getComputer(size_t index);

    vector<Computer> getComputerVector();

    // Fetches table of scientists from SQL database
    void retrieveComputers();

    // Returns the size of the computer vector
    size_t getSize() const;

    void retrieveIntersectScientist(const QString& param);

    void getVectorFoundComputer(string& searchData);

    bool deleteComputer(int index);

    //Searching computer list
    vector<Computer> searchingComputerByFilter(string command, string searchData);

    bool addIntersectScientist(const int& scientistID, const int& computerID);

    string editComputer(int index, string change, string input);

    bool searchComputersByPeriod(int yearFrom, int yearTo);

    QString deleteConnection(const int &scientistID, const int &computerID);

private slots:

private:

    vector<Computer> _computers;

    DbManager _data;

    LocalTime _time;
};

#endif // COMPUTERSERVICE_H
