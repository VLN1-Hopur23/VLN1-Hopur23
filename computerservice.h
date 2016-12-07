#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "computer.h"
#include "dbmanager.h"
#include <vector>

using namespace std;

class ComputerService
{
public:
    ComputerService();
    Computer getComputer(int index);
    vector<Computer> getComputerVector();
    void retrieveComputers();
    int getSize() const;

private:
    vector<Computer> _computers;
    DbManager data;
};

#endif // COMPUTERSERVICE_H
