#include "scientistservice.h"
#include <algorithm>
#include <iostream>

using namespace std;

struct ScientitComparisonNameForward
{
    bool operator() (Scientist i, Scientist j) {return (i.getName()<j.getName());}
};

bool ScientitComparisonYearOfBirthForward (Scientist i, Scientist j)
{
    return (i.getYearOfBirth()<j.getYearOfBirth());
}

bool ScientitComparisonYearOfDeathForward (Scientist i, Scientist j)
{
    return (i.getYearOfDeath()<j.getYearOfDeath());
}

bool ScientitComparisonAgeForward (Scientist i, Scientist j)
{
    return (i.getAge()<j.getAge());
}

struct ScientitComparisonGenderForward
{
    bool operator() (Scientist i, Scientist j) {return (i.getGender()<j.getGender());}
};

ScientistService::ScientistService()
{

}

 vector<Scientist> ScientistService::sortScientists(vector<Scientist> _listOfScientists, string sort)
{
    //TODO: logic
    //sort by name


    if (sort == "name" || sort == "Name")
    {
        ScientitComparisonNameForward cmp;
        std::sort(_listOfScientists.begin(), _listOfScientists.end(), cmp);
    }
    else if (sort == "birth" || sort == "Birth")
    {
        std::sort(_listOfScientists.begin(), _listOfScientists.end(), ScientitComparisonYearOfBirthForward);
    }
    else if (sort == "death" || sort == "Death")
    {
        std::sort(_listOfScientists.begin(), _listOfScientists.end(), ScientitComparisonYearOfDeathForward);
    }
    else if (sort == "age" || sort == "Age")
    {
        std::sort(_listOfScientists.begin(), _listOfScientists.end(), ScientitComparisonAgeForward);
    }
    else
    {
        //default is to sort by name
        ScientitComparisonNameForward cmp;
        std::sort(_listOfScientists.begin(), _listOfScientists.end(), cmp);
    }
    return _listOfScientists;
}

vector<Scientist> ScientistService::searchScientists(string searchData)
{
    vector<Scientist> foundScientists;

    for(unsigned long i = 0; i < _scientists.size(); i++)
    {
        string name = _scientists[i].getName();
        if(name.substr(0,searchData.size()) == searchData)
        {
            //If we find the scientist then we...
            foundScientists.push_back(_scientists[i]);
        }
    }
    return foundScientists; //remeber to change
}

void ScientistService::addScientist(Scientist scientist)
{
    bool isin = ifExist(scientist.getName());

    if (isin == false)
    {
         _scientists.push_back(scientist);
         _data.writeNewScientist(scientist);
    }
}

/*
Scientist ScientistService::getScientist(int index) const
{
    //return _scientists[index];
}
*/

int ScientistService::getSize() const
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

void ScientistService::load()
{
    _data.getData(_scientists);
}
