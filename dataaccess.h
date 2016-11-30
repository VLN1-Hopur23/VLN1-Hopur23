#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include "scientistservice.h"
#include "scientist.h"
#include "scientistservice.h"

using namespace std;

class DataAccess
{
public:
    DataAccess();


    void getData(ScientistService& scientists);

    void writeData(const ScientistService& scientists);
};

#endif // DATAACCESS_H

