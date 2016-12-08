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
bool ComputerService::retrieveComputers(string order, string filter)
{

    QString QSorder = "";
    QString QSfilter = "";
    if(filter == "ASC" || filter == "A")
    {
        QSfilter = QString::fromStdString("ASC");
    }
    if(filter == "DESC" || filter == "D")
    {
        QSfilter = QString::fromStdString("DESC");
    }


    if(order == "Name" || order == "name" || order == "n" || order =="N")
    {
        QSorder = QString::fromStdString("Name");
    }

    if(QSfilter != "" && QSorder != "")
    {
         _computers = _data.getComputers(QSorder, QSfilter);
        return true;
    }
    else
    {
        return false;
    }

}

size_t ComputerService::getSize() const
{
    return _computers.size();
}
