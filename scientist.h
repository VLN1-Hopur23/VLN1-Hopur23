#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
    string _name;
    string _gender;
    int _yearOfBirth;
    int _yearOfDeath;

public:
    Scientist();

    Scientist(string name, string gender, int yearOfBirth, int yearOfDeath);

    string getName() const;

    string getGender() const;

    int getYearOfBirth() const;

    int getYearOfDeath() const;


};

#endif // SCIENTIST_H
