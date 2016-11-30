#include "scientistservice.h"

ScientistService::ScientistService()
{
}

void ScientistService::addScientist(Scientist scientist)
{
    bool isin = false;
    for(size_t i = 0; i < _scientists.size(); i ++)
    {
        if(scientist == _scientists[i])
        {
            isin = true;
        }
    }
    if (isin == false)
    {
         _scientists.push_back(scientist);
    }
}

Scientist ScientistService::getScientist(int index)
{
    return _scientists[index];
}
