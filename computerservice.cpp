#include "computerservice.h"

using namespace std;

ComputerService::ComputerService()
{

}

bool ComputerService::addComputer(Computer computer)
{
    return _data.addComputer(computer);
}

// Get functions
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

    // Filter is for ascending (ASC) or descending (DESC)
    if(filter == "asc" || filter == "ASC" || filter == "a" || filter == "A")
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
    else if(order == "year" || order == "Year" || order == "y" || order =="Y")
    {
        QSorder = QString::fromStdString("Yearbuilt");
    }
    else if(order == "type" || order == "Type" || order == "t" || order =="T")
    {
        QSorder = QString::fromStdString("Type");
    }
    else if(order == "built" || order == "Built" || order == "b" || order == "B")
    {
        QSorder = QString::fromStdString("Built");
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

// Get size for computer vector
size_t ComputerService::getSize() const
{
    return _computers.size();
}

// Connects the link function in console to dbmanager
void ComputerService::retrieveIntersectScientist(const string& param)
{
    _computers = _data.intersectScientist(param);
}

// Connects the search function in console to dbmanager
void ComputerService:: getVectorFoundComputer(string& searchData)
{
    _computers = _data.searchComputer(searchData);
}

void ComputerService::deleteComputer(int index)
{
    _data.deleteComputer(index);

}
