#include "scientistservice.h"
#include <algorithm>
#include <iostream>

using namespace std;

struct ScientitComparisonNameForward {
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
struct ScientitComparisonGenderForward {
    bool operator() (Scientist i, Scientist j) {return (i.getGender()<j.getGender());}
};

ScientistService::ScientistService()
{

}
 void ScientistService::sortScientists(string sort)
{

    //TODO: logic
    //sort by name

    if (sort == "name" || sort == "Name")
    {
        ScientitComparisonNameForward cmp;
        std::sort(_scientists.begin(), _scientists.end(), cmp);
    }
    else if (sort == "birth" || sort == "Birth")
    {
        std::sort(_scientists.begin(), _scientists.end(), ScientitComparisonYearOfBirthForward);
    }
    else if (sort == "death" || sort == "Death")
    {
        std::sort(_scientists.begin(), _scientists.end(), ScientitComparisonYearOfDeathForward);
    }
    else if (sort == "age" || sort == "Age")
    {
        std::sort(_scientists.begin(), _scientists.end(), ScientitComparisonAgeForward);
    }
    else
    {
        //default is to sort by name
        ScientitComparisonNameForward cmp;
        std::sort(_scientists.begin(), _scientists.end(), cmp);
    }


}

vector<Scientist> ScientistService::searchScientists(string searchData){
    vector<Scientist> performers;

    vector<Scientist> foundScientists;

    Scientist p("duran duran","f",1640,1700); //60 ara
    Scientist p2("madona","m",1953,1999 ); //46 ara
    Scientist p3("ALi","f",2130,2200); //70 ara
    Scientist p4("Anna","f",1640,1700); //60 ara
    Scientist p5("Arnaldur","m",1953,1999 ); //46 ara

    performers.push_back(p);
    performers.push_back(p2);
    performers.push_back(p3);
    performers.push_back(p4);
    performers.push_back(p5);



    for(unsigned long i = 0; i < performers.size(); i++){
        string name = performers[i].getName();
        if(name.substr(0,searchData.size()) == searchData)
        {
            //If we find the scientist then we...
            foundScientists.push_back(performers[i]);

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

vector<Scientist> ScientistService:: getScientistVector()
{
    return _scientists;
}
