#include "dataaccess.h"

using namespace std;


DataAccess::DataAccess()
{
}

//les ur allri skra eftir visindamonnum
void DataAccess::getData(vector<Scientist>& scientists)
{
    ifstream file;
    Scientist person;
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
    string delimiter;

    file.open("computerScientists.txt");

    if(file.is_open())
    {
        while (!file.eof())
        {
            delimiter = "";

            while(delimiter != "####")
            {
                file >> name;
                file >> gender;
                file >> yearOfBirth;
                file >> yearOfDeath;
                file >> delimiter;

                Scientist person(name, gender, yearOfBirth, yearOfDeath);
                scientists.push_back(person);
            }
        }
    }
    else
    {
        //cout << "File cannot open" << endl;
    }

}

void DataAccess::writeData(const vector <Scientist>& scientists)
{
    ofstream file;
    int index = scientists.size() + 1;

    file.open("computerScientists.txt", ios_base::app);


    if (file)
    {

        file << scientists[index].getName() << endl;
        file << scientists[index].getGender() << endl;
        file << scientists[index].getYearOfBirth() << endl;
        file << scientists[index].getYearOfDeath() << endl;
        file << "####";

    }

    file.close();
}

