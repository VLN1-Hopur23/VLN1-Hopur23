#include "computerservice.h"
#include <algorithm>

using namespace std;

ComputerService::ComputerService()
{

}

Computer ComputerService::getComputer(int index)
{
    return _computers[index];
}

vector<Computer> ComputerService::getComputerVector()
{
    return _computers;
}

// Fetches table of scientists from SQL database
void ComputerService::retrieveComputers()
{
    _computers = data.getComputers();
}

int ComputerService::getSize() const
{
    return _computers.size();
}
