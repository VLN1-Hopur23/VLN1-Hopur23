#include "scientistservice.h"

using namespace std;

ScientistService::ScientistService()
{

}

// Operator instrument that compares names in alphabetical order
struct ScientistComparisonNameForward
{
    bool operator() (Scientist i, Scientist j) {return (i.getName()<j.getName());}
};

// Operator instrument that compares year of birth in ascending order
bool ScientistComparisonYearOfBirthForward (Scientist i, Scientist j)
{
    return (i.getYearOfBirth()<j.getYearOfBirth());
}

bool ScientistComparisonYearOfDeathForward (Scientist i, Scientist j)
{
    return (i.getYearOfDeath()<j.getYearOfDeath());
}

bool ScientistComparisonAgeForward (Scientist i, Scientist j)
{
    return (i.getAge()<j.getAge());
}

// Sorts scientist by aplhabetical order, by year of birth, by year of death and by age
 vector<Scientist> ScientistService::sortScientists(vector<Scientist> _listOfScientists, string sort)
{
    if (sort == "name" || sort == "Name" || sort == "n")
    {
        ScientistComparisonNameForward cmp;
        std::sort(_scientists.begin(), _scientists.end(), cmp);
    }
    else if (sort == "birth" || sort == "Birth" || sort == "b")
    {
        std::sort(_scientists.begin(), _scientists.end(), ScientistComparisonYearOfBirthForward);
    }
    else if (sort == "death" || sort == "Death" || sort == "d")
    {
        std::sort(_scientists.begin(), _scientists.end(), ScientistComparisonYearOfDeathForward);
    }
    else if (sort == "age" || sort == "Age" || sort == "a")
    {
        std::sort(_scientists.begin(), _scientists.end(), ScientistComparisonAgeForward);
    }
    else
    {
        // Default is to sort by name
        ScientistComparisonNameForward cmp;
        std::sort(_scientists.begin(), _scientists.end(), cmp);
    }
    return _listOfScientists;
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
bool ScientistService::load()
{
    _data.getData(_scientists);

    return DataAccessWorks();
}
*/

/*
bool ScientistService::DataAccessWorks()
{
    if (_data.DataOk && _data.FileOpen)
    {
        return true;
    }

    return false;
}
*/

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

/*
void ScientistService::deleteScientist(int index)
{
    _scientists.erase(_scientists.begin()+index);
    _data.writeData(_scientists);
}
*/
