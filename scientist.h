#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
    string _name = "";
    char _gender;
    int _yearOfBirth = 0;
    int _yearOfDeath = 0;

public:
    Scientist();

    Scientist(string name, char gender, int yearOfBirth, int yearOfDeath);

    string getName() const;

    char getGender() const;

    int getYearOfBirth() const;

    int getYearOfDeath() const;


};

#endif // SCIENTIST_H
