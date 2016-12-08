#include "scientistservice.h"

using namespace std;

ScientistService::ScientistService()
{

}

void ScientistService:: getVectorFoundScientists(string& searchData)
{
    _scientists = _data.searchScientist(searchData);
}

string ScientistService::addScientist(Scientist scientist)
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
void ScientistService::retrieveScientists(string order, string filter)
{
    QString QSorder;
    QString QSfilter = QString::fromStdString(filter);

    if(order == "name" || order == "Name" || order == "n" || order == "N")
    {
        QSorder = QString::fromStdString("Name");
        _scientists = _data.getScientists(QSorder, QSfilter);
    }
    else if(order == "gender" || order == "Gender" || order == "g" || order == "G")
    {
        QSorder = QString::fromStdString("Gender");
        _scientists = _data.getScientists(QSorder, QSfilter);
    }
    else if(order == "birth" || order == "Birth" || order == "b" || order == "B")
    {
        QSorder = QString::fromStdString("Birthyear");
        _scientists = _data.getScientists(QSorder, QSfilter);
    }
    else if(order == "death" || order == "Death" || order == "d" || order == "D")
    {
        QSorder = QString::fromStdString("Deathyear");
        _scientists = _data.getScientists(QSorder, QSfilter);
    }
    else
    {
        cout << "Please select one of the given options!" << endl;
        // TO DO ERROR CHECK!!!
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
    //_scientists.erase(_scientists.begin()+index);
    //_data.writeData(_scientists);
    //_data.deleteScientist(getScientist(index));
    _data.deleteScientist(index);
    cout << "delete in scientistservice.cpp" << endl;
}

