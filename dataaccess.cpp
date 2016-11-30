#include "dataaccess.h"


DataAccess::DataAccess()
{
}

Scientist DataAccess::getData()
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

            person.Scientist(temp, t, one, two);
            addScientist(person);
        }
    }
    else
    {
        cout << "File cannot open" << endl;
    }

    return person;
}

void DataAccess::writeData(Scientist scientist)
{
    scientist.getName();
}
