#include "scientistservice.h"

using namespace std;

// Constructor
ScientistService::ScientistService()
{

}

// Connects search function in console to search function in dbmanager
void ScientistService:: getVectorFoundScientists(string& searchData)
{
    _scientists = _data.searchScientist(searchData);
}

// Connects to register function in console to add scientist function in dbmanager
bool ScientistService::addScientist(Scientist scientist, int& id)
{
    return _data.addScientist(scientist, id);
}

// Used in display scientist in console, vector for scientist
Scientist ScientistService::getScientist(size_t index)
{
    return _scientists[index];
}

// Gets size of vector
size_t ScientistService::getSize() const
{
    return _scientists.size();
}

vector<Scientist> ScientistService::getScientistVector()
{
    return _scientists;
}

// Fetches table of scientists from dbmanager
void ScientistService::retrieveScientists()
{
    _scientists = _data.getScientists();
}

// Edit function takes input from the user and fetches data from the dbmanagar
string ScientistService::editScientist(int index, string change, string input)
{
    string message = "Invalid, ignored";
    /*if(index > _scientists.size()){
        message = "Index out of range";
    }*/
    if (change == "name")
    {
        message = _data.editScientistName(index, input);
    }
    else if (change == "gender")
    {
        message = _data.editScientistGender(index, input);
    }
    else if (change == "birth")
    {
        message = _data.editScientistBirthYear(index, input);
    }
    else if (change == "death")
    {
        message = _data.editScientistDeathYear(index, input);
    }
    return message;
}

// Fetches deleteScientist function in dbmanager
bool ScientistService::deleteScientist(int index)
{
    return _data.deleteScientist(index);
}

// Fetches appropriate filter from dbmanager for search function in console
vector<Scientist> ScientistService::searchingByFilter(string command, string searchData) // Function that we call in consoleUI, returns 1/true if input is right but 0/false otherwise
{
    if (searchData == "")
    {
        retrieveScientists();
        return getScientistVector();
    }
    else
    {
        _scientists = _data.filterScientist(command, searchData);

        return _scientists;
    }
}

// Connects link function in console to dbmanager
void ScientistService::retrieveIntersectComputer(const string& param)
{
    _scientists = _data.intersectComputer(param);
}

bool ScientistService::addIntersectComputer(const int& scientistID, const int& computerID)
{
    return _data.addIntersect(scientistID, computerID);
}
