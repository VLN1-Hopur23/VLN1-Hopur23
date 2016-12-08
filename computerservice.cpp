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
void ComputerService::retrieveComputers(string order, string filter)
{
    QString QSorder;
    QString QSfilter = QString::fromStdString(filter);

    if(order == "Name" || order == "name" || order == "n" || order =="N"){
        QSorder = QString::fromStdString("Name");
        _computers = _data.getComputers(QSorder, QSfilter);
    }
    _computers = _data.getComputers(QSorder, QSfilter);
}

size_t ComputerService::getSize() const
{
    return _computers.size();
}
