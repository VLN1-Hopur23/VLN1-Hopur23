#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "scientist.h"
#include <vector>

using namespace std;

class ScientistService
{
    vector<Scientist> _scientists;

public:
    ScientistService();

    void addScientist(Scientist scientist);

    Scientist getScientist(int index);
};

#endif // SCIENTISTSERVICE_H
