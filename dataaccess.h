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

    void getData(vector<Scientist>& scientists);

    void writeNewScientist(Scientist scientist);

    void writeData(const vector<Scientist>& scientists);

    bool DataOk = true;

    bool FileOpen = true;

private:

    bool checkValidationOfData(string name, string gender,string yearOfBirth,int yearOfBirthInt, string yearOfDeath,int yearOfDeathInt, string delimiter);
};

#endif // DATAACCESS_H

