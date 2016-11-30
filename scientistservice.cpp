#include "scientistservice.h"
#include <algorithm>
#include<iostream>

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
 vector<Scientist> ScientistService::getScientists(string sort)
{
    vector<Scientist> performers;

    Scientist p("duran duran","f",1640,1700); //60 ara
    Scientist p2("madona","m",1953,1999 ); //46 ara
    Scientist p3("ALi","f",2130,2200); //70 ara

    performers.push_back(p);
    performers.push_back(p2);
    performers.push_back(p3);

    //TODO: logic
    //sort by name

    if (sort == "name")
    {
        ScientitComparisonNameForward cmp;
        std::sort(performers.begin(), performers.end(), cmp);
    }
    else if (sort == "birth")
    {
        std::sort(performers.begin(), performers.end(), ScientitComparisonYearOfBirthForward);
    }
    else if (sort == "death")
    {
        std::sort(performers.begin(), performers.end(), ScientitComparisonYearOfDeathForward);
    }
    else if (sort == "age")
    {
        std::sort(performers.begin(), performers.end(), ScientitComparisonAgeForward);
    }
    else
    {
        //default is to sort by name
        ScientitComparisonNameForward cmp;
        std::sort(performers.begin(), performers.end(), cmp);
    }

    return performers;
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

/*void ScientistService::addScientist(Scientist scientist)
{
   // _scientists.push_back(scientist);
}

/*Scientist ScientistService::getScientist(int index)
{
    //return _scientists[index];
}
*/

/*/////////////////////////////////////////////////////////////
/*
#include "performerservice.h"
#include <algorithm>

using namespace std;

struct PerformerComparison {
    bool operator() (Performer i, Performer j) {return (i.getName()<j.getName());}
};

PerformerService::PerformerService()
{

}

 vector<Performer> PerformerService::getPerformers(ToDO: parameter)
 {
     vector<Performer> performers;

     Performer p("duran duran", 41);
     Performer p2("madona", 55);
     Performer p3("ALi", 35);

     performers.push_back(p);
     performers.push_back(p2);
     performers.push_back(p3);

     //TODO: logic
     //sort by name
     PerformerComparison cmp;
     std::sort(performers.begin(), performers.end(), cmp);

     return performers;
 }
*/
