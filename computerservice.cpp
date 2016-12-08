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

// Fetches table of computers from SQL database
bool ComputerService::retrieveComputers(string order, string filter)
{
    QString QSorder = "";
    QString QSfilter = "";
<<<<<<< HEAD
    // //////////////////////////filter is for ascending (ASC) or
    if(filter == "ASC" || filter == "A")
=======

    if(filter == "asc" || filter == "ASC" || filter == "a" || filter == "A")
>>>>>>> f0be7464097f8cb680f7b5404fc43755392a4a31
    {
        QSfilter = QString::fromStdString("ASC");
    }
    else if(filter == "desc" || filter == "DESC" || filter == "d" || filter == "D")
    {
        QSfilter = QString::fromStdString("DESC");
    }
    else
    {
        // TO DO ERROR CHECK
    }

    if(order == "name" || order == "Name" || order == "n" || order =="N")
    {
        QSorder = QString::fromStdString("Name");
    }
    else if(order == "built" || order == "Built" || order == "b" || order =="B")
    {
        QSorder = QString::fromStdString("Yearbuilt");
    }
    else if(order == "type" || order == "Type" || order == "t" || order =="T")
    {
        QSorder = QString::fromStdString("Type");
    }
    else
    {
        // TO DO ERROR CHECK!!!
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

void ComputerService:: getVectorFoundComputer(string& searchData)
{
    _computers = _data.searchComputer(searchData);
}
