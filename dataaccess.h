#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include "scientist.h"
#include "scientistservice.h"

using namespace std;

class DataAccess
{
public:
    DataAccess();

    Scientist getData(ScientistService& scientists);

    void writeData(Scientist scientist);
};

#endif // DATAACCESS_H

