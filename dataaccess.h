#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include "scientist.h"

using namespace std;

class DataAccess
{
public:
    DataAccess();

   // Scientist getData();

    void writeData(Scientist scientist);
};

#endif // DATAACCESS_H

