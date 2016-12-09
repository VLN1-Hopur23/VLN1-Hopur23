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

    bool addComputer(Computer computer);

    Computer getComputer(size_t index);

    vector<Computer> getComputerVector();

    // Fetches table of scientists from SQL database
    bool retrieveComputers(string order, string filter);

    // Returns the size of the computer vector
    size_t getSize() const;

    void retrieveIntersectScientist(const string& param);

    void getVectorFoundComputer(string& searchData);

    void deleteComputer(int index);

    bool searchingComputerByFilter(string command, string searchData); //fall sem er kallad a i consoleUI, skilar 1/true ef input er rett annars 0/false

    bool addIntersectScientist(const int& scientistID, const int& computerID);

    string editComputer(int index, string change, string input);

    bool searchComputersByPeriod(int yearFrom, int yearTo);

private:

    vector<Computer> _computers;

    DbManager _data;

    LocalTime _time;
};

#endif // COMPUTERSERVICE_H
