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
    bool retrieveComputers(string order, string filter);

    // Returns the size of the computer vector
    size_t getSize() const;

    void retrieveIntersectScientist(const string& param);

    void getVectorFoundComputer(string& searchData);

    void deleteComputer(int index);

    // Function called in consoleUI, returns 1/true if the input is correct and 0/false otherwise
    bool searchingComputerByFilter(string command, string searchData);

    bool addIntersectScientist(const int& scientistID, const int& computerID);

    string editComputer(int index, string change, string input);

    bool searchComputersByPeriod(int yearFrom, int yearTo);

private:

    vector<Computer> _computers;

    DbManager _data;

    LocalTime _time;
};

#endif // COMPUTERSERVICE_H
