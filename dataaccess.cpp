#include "dataaccess.h"

using namespace std;


DataAccess::DataAccess()
{
}


void DataAccess::getData(vector<Scientist>& scientists)
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
        while (!file.eof())
        {
            delimiter = "";

            while(delimiter != "####")
            {
                file >> temp;
                file >> t;
                file >> one;
                file >> two;
                file >> delimiter;

                Scientist person(temp, t, one, two);
                scientists.push_back(person);
            }
        }
    }
    else
    {
        //cout << "File cannot open" << endl;
    }

}

void DataAccess::writeData(const vector<Scientist>& scientists)
{
    ofstream file;

    file.open("computerScientists.txt");

    if (file)
    {
        for (size_t i = 0; i < scientists.size(); i++)
        {
            file << scientists[i].getName();
            file << scientists[i].getGender();
            file << scientists[i].getYearOfBirth();
            file << scientists[i].getYearOfDeath();
            file << "####";
        }
    }

    file.close();
}
