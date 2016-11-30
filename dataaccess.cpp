#include "dataaccess.h"

using namespace std;

DataAccess::DataAccess()
{
}

void DataAccess::getData()
{

}

void DataAccess::writeData(const ScientistService& scientists)
{
    ofstream file;

    file.open("computerScientists.txt");

    if (file)
    {
        for (int i = 0; i < scientists.getSize(); i++)
        {
            file << scientists.getScientist(i).getName();
            file << scientists.getScientist(i).getGender();
            file << scientists.getScientist(i).getYearOfBirth();
            file << scientists.getScientist(i).getYearOfDeath();
            file << "###";
        }
    }

    file.close();
}
