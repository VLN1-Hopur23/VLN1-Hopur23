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


private:

    vector<Computer> _computers;

    DbManager _data;
};

#endif // COMPUTERSERVICE_H
