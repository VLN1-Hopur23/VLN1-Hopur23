#include "dataaccess.h"

using namespace std;


DataAccess::DataAccess()
{
}

Scientist DataAccess::getData(ScientistService& scientists)
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

    return person;
}

void DataAccess::writeData(Scientist scientist)
{
    scientist.getName();
}
