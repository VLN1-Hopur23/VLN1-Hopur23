#include "scientistservice.h"

using namespace std;

ScientistService::ScientistService()
{

}

void ScientistService:: getVectorFoundScientists(string& searchData)
{
    _scientists = _data.searchScientist(searchData);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return _data.addScientist(scientist);
}

Scientist ScientistService::getScientist(size_t index)
{
    return _scientists[index];
}

size_t ScientistService::getSize() const
{
    return _scientists.size();
}

bool ScientistService::ifExist(string name)
{
   for (size_t i = 0; i < _scientists.size(); i++)
   {
       if (_scientists[i].getName() == name)
       {
           return true;
       }
   }
   return false;
}

vector<Scientist> ScientistService::getScientistVector()
{
    return _scientists;
}

// Fetches table of scientists from SQL database
bool ScientistService::retrieveScientists(string order, string filter)
{
    QString QSorder = "";
    QString QSfilter = "";

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

    if(order == "name" || order == "Name" || order == "n" || order == "N")
    {
        QSorder = QString::fromStdString("Name");
    }
    else if(order == "gender" || order == "Gender" || order == "g" || order == "G")
    {
        QSorder = QString::fromStdString("Gender");
    }
    else if(order == "birth" || order == "Birth" || order == "b" || order == "B")
    {
        QSorder = QString::fromStdString("Birthyear");
    }
    else if(order == "death" || order == "Death" || order == "d" || order == "D")
    {
        QSorder = QString::fromStdString("Deathyear");
    }
    else
    {
        // TO DO ERROR CHECK!!!
    }

    if(QSfilter != "" && QSorder != "")
    {
        _scientists = _data.getScientists(QSorder, QSfilter);
        return true;
    }
    else
    {
        return false;
    }
}

/*
string ScientistService::editScientist(int index, string change, string input)
{
    string message = "Invalid, ignored";
    if(index > _scientists.size()){
        message = "Index out of range";
    }
    if (change == "name")
    {
        message = "Name changed successfully";
        _scientists[index].setName(input); 
    }
    else if (change == "gender")
    {
        message = "Gender changed successfully";
        _scientists[index].setGender(input);
    }
    else if (change == "birth")
    {
        message = "Birth year changed successfully";
        _scientists[index].setYearOfBirth(stoi(input, 0));
    }
    else if (change == "death")
    {
        message = "Death year changed successfully";
        _scientists[index].setYearOfDeath(stoi(input, 0));
    }
    _data.writeData(_scientists);
    return message;
}
*/

void ScientistService::deleteScientist(int index)
{
    _data.deleteScientist(index);

}

bool ScientistService::searchingByFilter(string command, string searchData) //fall sem er kallad a i consoleUI, skilar 1/true ef input er rett annars 0/false
{
    string finalCommand;
    string finalSearchData;
    bool inputOkay = false;
    if (command == "gender" || command == "Gender" || command == "g" || command == "1" || command == "01")
    {
        finalCommand = "Gender";
        //searchdata must be f or m
        if(searchData == "f" || searchData == "F")
        {
            finalSearchData = "f";
            inputOkay = true;
        }
        else if( searchData == "m" || searchData == "M")
        {
            finalSearchData = "m";
            inputOkay = true;
        }
    }
    else if (command == "birth" || command == "Birth" || command == "b" || command == "2" || command == "02")
    {
        finalCommand = "Birthyear";
    }
    else if (command == "death" || command == "Death" || command == "d" || command == "3" || command == "03")
    {
        finalCommand = "Deathyear";
    }

    if(inputOkay)
    {
        _scientists = _data.filterScientist(finalCommand, finalSearchData);
        return true;
    }
    return false;
}

void ScientistService::retrieveIntersectComputer(const string& param)
{
    _scientists = _data.intersectComputer(param);
}
