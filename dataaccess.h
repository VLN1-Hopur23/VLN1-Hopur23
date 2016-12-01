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

    void writeData(const vector<Scientist>& scientists);

};

#endif // DATAACCESS_H

