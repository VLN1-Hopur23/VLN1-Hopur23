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
    Computer getComputer(size_t index);
    vector<Computer> getComputerVector();
    // Fetches table of scientists from SQL database
    bool retrieveComputers(string order, string filter);
    // Returns the size of the computer vector
    size_t getSize() const;
    void getVectorFoundComputer(string& searchData);

private:
    vector<Computer> _computers;
    DbManager _data;
};

#endif // COMPUTERSERVICE_H
