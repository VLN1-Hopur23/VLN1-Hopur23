#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include "scientistservice.h"
#include "scientist.h"

using namespace std;

class DataAccess
{
public:
    DataAccess();

    void getData();

    void writeData(const ScientistService& scientists);
};

#endif // DATAACCESS_H

