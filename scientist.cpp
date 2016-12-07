#include "scientist.h"

using namespace std;

Scientist::Scientist()
{

}

Scientist::Scientist(int scientistID, string name, string gender, int yearOfBirth, int yearOfDeath)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;
    _scientistID = scientistID;
}

Scientist::Scientist(string name, string gender, int yearOfBirth, int yearOfDeath)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;
}

int Scientist::getScientistID() const
{
    return _scientistID;
}

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
        return _Time.getYearToDay() - _yearOfBirth; // 2016 is used as the year today
    }
}

// Updates year to the current year of users time
int Scientist::getYearToDay() const
{
      time_t rawtime;
      struct tm * timeinfo;

      time (&rawtime);
      timeinfo = localtime (&rawtime);

      // Get the only the year in integer form from localtime
      string str = asctime(timeinfo);
      int LastSpace = str.find_last_of(" ")+1;
      int StrEnd = str.size();
      string StringYearToDay = str.substr( LastSpace,StrEnd);
      int YearToDay = std::stoi (StringYearToDay);

      return YearToDay;
}

void Scientist::setName(string name)
{
    _name = name;
}

void Scientist::setGender(string gender)
{
    _gender = gender;
}

void Scientist::setYearOfBirth(int yearOfBirth)
{
    _yearOfBirth = yearOfBirth;
}

void Scientist::setYearOfDeath(int yearOfDeath)
{
    _yearOfDeath = yearOfDeath;
}
