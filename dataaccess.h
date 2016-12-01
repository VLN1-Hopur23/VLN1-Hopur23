#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <vector>
#include "scientist.h"

using namespace std;

class DataAccess
{
public:
    DataAccess();

   // Scientist getData();

    void getData(vector<Scientist>& scientists);

    void writeNewScientist(Scientist scientist);

    void writeData(vector<Scientist> scientists);

private:
    bool checkValidationOfData(string name, string gender,string yearOfBirth,int yearOfBirthInt, string yearOfDeath,int yearOfDeathInt, string delimiter);

};

#endif // DATAACCESS_H

