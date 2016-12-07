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
    Computer getComputer(int index);
    vector<Computer> getComputerVector();
    // Fetches table of scientists from SQL database
    void retrieveComputers();
    // Returns the size of the computer vector
    int getSize() const;

private:
    vector<Computer> _computers;
    DbManager data;
};

#endif // COMPUTERSERVICE_H
