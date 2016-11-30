#include "scientist.h"


using namespace std;

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
        return 2016 - _yearOfBirth; // 2016 er notad sem arid i dag
    }
}
