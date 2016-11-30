#include "scientistservice.h"

ScientistService::ScientistService()
{
}

void ScientistService::addScientist(Scientist scientist)
{
    bool isin = ifExist(scientist.getName());

    if (isin == false)
    {

         _scientists.push_back(scientist);
    }
}

Scientist ScientistService::getScientist(int index) const
{
    return _scientists[index];
}

int ScientistService::getSize() const
{
    return _scientists.size();
}

bool ScientistService::ifExist(string name)
{
   for (size_t i = 0; i < _scientists.size(); i++)
   {
       if (_scientists[i].getName() == name)
       {
           return true;
       }
   }

   return false;
}


