#include "scientist.h"

using namespace std;
//constructors
Scientist::Scientist()
{

}

Scientist::Scientist(string name, string gender, int yearOfBirth, int yearOfDeath)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;
}
//getfunctions
string Scientist::getName() const
{
    return _name;
}

string Scientist::getGender() const
{
    return _gender;
}

int Scientist::getYearOfBirth() const
{
    return _yearOfBirth;
}

int Scientist::getYearOfDeath() const
{
    return _yearOfDeath;
}

int Scientist::getAge() const
{
    if(_yearOfDeath != 0)
    {
        return _yearOfDeath - _yearOfBirth;
    }
    else
    {
        return getYearToDay() - _yearOfBirth; // 2016 er notad sem arid i dag
    }
}
//updates year to the current year of users time
int Scientist::getYearToDay() const
{
      time_t rawtime;
      struct tm * timeinfo;

      time (&rawtime);
      timeinfo = localtime (&rawtime);
      //printf ("Current local time and date: %s", asctime(timeinfo));  //prints out logal time in ascicharecters

      // get the only the year in integer form from localtime
      string str = asctime(timeinfo);
      int LastSpace = str.find_last_of(" ")+1;
      int StrEnd = str.size();
      string StringYearToDay = str.substr( LastSpace,StrEnd);
      int YearToDay = std::stoi (StringYearToDay);

      return YearToDay;
}
