#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include "localtime.h"
//#include "dbmanager.h"

using namespace std;

class Scientist
{
public:

    Scientist();

    Scientist(int scientistID, string name, string gender, int yearOfBirth, int yearOfDeath);

    int getScientistID() const;

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

    bool contains(string str);

    string toString();

private:

    int _scientistID;

    string _name;

    string _gender;

    int _yearOfBirth;

    int _yearOfDeath;

    LocalTime _Time;

    //DbManager _data;
};

#endif // SCIENTIST_H

