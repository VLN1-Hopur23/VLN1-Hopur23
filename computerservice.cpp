#include "computerservice.h"

using namespace std;

ComputerService::ComputerService()
{

}

Computer ComputerService::getComputer(size_t index)
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

size_t ComputerService::getSize() const
{
    return _computers.size();
}
