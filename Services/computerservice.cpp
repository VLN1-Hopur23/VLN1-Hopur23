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

void ComputerService::deleteComputer(int index)
{
    _data.deleteComputer(index);
}

bool ComputerService::searchingComputerByFilter(string command, string searchData)
{
    string finalCommand;
    string finalSearchData;
    bool inputOkay = false;

    if (command == "Name" || command == "name" || command == "n")
    {
        cout << "inside Name in searching by filter in Computer Service" << endl;
        finalCommand = "Name";

        // Searchdata can be characters and number but not weird symbols
        finalSearchData = searchData;
        inputOkay = true;
    }
    else if (command == "Year" || command == "year" || command == "y")
    {
        finalCommand = "Yearbuilt";
        int intSearchData = stoi(searchData);

        if(intSearchData <= _time.getYearToDay() && intSearchData >= 0)
        {
            finalSearchData = intSearchData;
            inputOkay = true;
        }
    }

    if(inputOkay) //Returns true if input is accepted
    {
        _computers = _data.filterComputer(finalCommand, finalSearchData);
        return true;
    }
    return false;
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
    return message;
}
