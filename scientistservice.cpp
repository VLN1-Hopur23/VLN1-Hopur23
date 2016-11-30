#include "scientistservice.h"

ScientistService::ScientistService()
{
}

void ScientistService::addScientist(Scientist scientist)
{
    _scientists.push_back(scientist);
}

Scientist ScientistService::getScientist(int index) const
{
    return _scientists[index];
}

int ScientistService::getSize() const
{
    return _scientists.size();
}
