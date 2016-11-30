#include "dataaccess.h"

using namespace std;


DataAccess::DataAccess()
{
}


void DataAccess::getData(ScientistService& scientists)
{
    ifstream file;
    Scientist person;
    string temp;
    char t;
    int one;
    int two;
    string delimiter;
    file.open("computerScientists.txt");
    if(file.is_open())
    {
        while(delimiter != "####")
        {
            file >> temp;
            file >> t;
            file >> one;
            file >> two;
            file >> delimiter;

            Scientist person(temp, t, one, two);
            scientists.addScientist(person);
        }
    }
    else
    {
        //cout << "File cannot open" << endl;
    }

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
