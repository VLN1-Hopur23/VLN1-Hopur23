#include "scientistservice.h"
#include <algorithm>
#include <iostream>

using namespace std;

ScientistService::ScientistService()
{
}
//compares names of scientists in alphabetical order
struct ScientistComparisonNameForward
{
    bool operator() (Scientist i, Scientist j) {return (i.getName()<j.getName());}
};

//compares year of birth between scientists in ascending order
bool ScientistComparisonYearOfBirthForward (Scientist i, Scientist j)
{
    return (i.getYearOfBirth()<j.getYearOfBirth());
}
//compares year of death between scientists in ascending order
bool ScientistComparisonYearOfDeathForward (Scientist i, Scientist j)
{
    return (i.getYearOfDeath()<j.getYearOfDeath());
}
//compares age between scientists in ascending order
bool ScientistComparisonAgeForward (Scientist i, Scientist j)
{
    return (i.getAge()<j.getAge());
}
//NEED TO USE OR TERMINATE
/*
struct ScientistComparisonGenderForward
{
    bool operator() (Scientist i, Scientist j) {return (i.getGender()<j.getGender());}
};

*/

//sorts scientist by aplhabetical order, by year of birth, by year of death and by age
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
        //default is to sort by name
        ScientistComparisonNameForward cmp;
        std::sort(_scientists.begin(), _scientists.end(), cmp);
    }
    return _listOfScientists;
}
//search for scientist by name
vector<int> ScientistService::searchScientists(string searchData)
{
    vector<int> foundScientists;

    for(unsigned long i = 0; i < _scientists.size(); i++)
    {
        string name = _scientists[i].getName();
        if(name.substr(0,searchData.size()) == searchData)
        {
            //If we find the scientist then we...

            foundScientists.push_back(i);
        }
    }
    return foundScientists; //remeber to change
}
// adds an registered scientist to vector
void ScientistService::addScientist(Scientist scientist)
{
    bool isin = ifExist(scientist.getName());

    if (isin == false)
    {
         _scientists.push_back(scientist);
         _data.writeNewScientist(scientist);
    }
}
//get functions
Scientist ScientistService::getScientist(int index) const
{
    return _scientists[index];
}
//get vector size
int ScientistService::getSize() const
{
    return _scientists.size();
}
//validation - registering a scientist that is already registered is not allowed
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
//get scientist vector
vector<Scientist> ScientistService::getScientistVector()
{
    return _scientists;
}
//loads from file to vector
bool ScientistService::load()
{
    _data.getData(_scientists);

    return DataAccessWorks();
}
//validates if DataAccess works
bool ScientistService::DataAccessWorks()
{
    if (_data.DataOk && _data.FileOpen)
    {
        return true;
    }

    return false;
}
