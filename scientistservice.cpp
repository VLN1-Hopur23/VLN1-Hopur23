#include "scientistservice.h"

ScientistService::ScientistService()
{
}

void ScientistService::addScientist(Scientist scientist)
{
    _scientists.push_back(scientist);
}

Scientist ScientistService::getScientist(int index)
{
    return _scientists[index];
}
