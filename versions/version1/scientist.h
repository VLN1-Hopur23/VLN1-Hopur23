#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include "localtime.h"

using namespace std;

class Scientist
{
public:

    Scientist();

    Scientist(string name, string gender, int yearOfBirth, int yearOfDeath);

    string getName() const;

    string getGender() const;

    int getYearOfBirth() const;

    int getYearOfDeath() const;

    int getAge() const;

    int getYearToDay() const;

    void setName(string name);

    void setGender(string gender);

    void setYearOfBirth(int yearOfBirth);

    void setYearOfDeath(int yearOfDeath);


private:

    string _name;

    string _gender;

    int _yearOfBirth;

    int _yearOfDeath;

    LocalTime _Time;
};

#endif // SCIENTIST_H

