#include "computerservice.h"

using namespace std;

ComputerService::ComputerService()
{

}

bool ComputerService::addComputer(Computer computer, int& id)
{
    return _data.addComputer(computer, id);
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
void ComputerService::retrieveComputers()
{
    _computers = _data.getComputers();
}

// Get size for computer vector
size_t ComputerService::getSize() const
{
    return _computers.size();
}

// Connects the link function in console to dbmanager
void ComputerService::retrieveIntersectScientist(const QString& param)
{
    _computers = _data.intersectScientist(param);
}

// Connects the search function in console to dbmanager
void ComputerService::getVectorFoundComputer(string& searchData)
{
    _computers = _data.searchComputer(searchData);
}

bool ComputerService::searchComputersByPeriod(int yearFrom, int yearTo)
{
    if(yearFrom < _time.getYearToDay() && yearFrom < yearTo)
    {
        _computers = _data.searchComputerPeriod(yearFrom, yearTo);
        return true;
    }
    return false;
}

bool ComputerService::deleteComputer(int index)
{
    return _data.deleteComputer(index);
}

vector<Computer> ComputerService::searchingComputerByFilter(string command, string searchData)
{
    if (searchData == "")
    {
        retrieveComputers();
        return getComputerVector();
    }
    else
    {
        return _data.filterComputer(command, searchData);
    }
}

bool ComputerService::addIntersectScientist(const int& scientistID, const int& computerID)
{
    return _data.addIntersect(scientistID, computerID);
}

// Edit function takes input from the user and fetches data from the dbmanagar
string ComputerService::editComputer(int index, string change, string input)
{
    string message = "Invalid, ignored";

    if (change == "name")
    {
        message = _data.editComputerName(index, input);
    }
    else if (change == "yearbuilt")
    {
        message = _data.editComputerYearBuilt(index, input);
    }
    else if (change == "type")
    {
        message = _data.editComputerType(index, input);
    }
    else if(change == "built")
    {
        if(input =="1")
        {
            message = _data.editComputeBuilt(index, true);
        }
        else if(input=="0")
        {
            message = _data.editComputeBuilt(index, false);
        }

    }
    return message;
}

QString ComputerService::deleteConnection(const int& scientistID, const int& computerID)
{
    return _data.deleteConnection(scientistID, computerID);
}
