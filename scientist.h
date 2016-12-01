#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <stdio.h>      /* puts, printf */
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <iostream>


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

private:
    string _name;
    string _gender;
    int _yearOfBirth;
    int _yearOfDeath;


};

#endif // SCIENTIST_H

