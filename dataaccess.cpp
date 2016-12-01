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
    string yearOfBirth;
    string yearOfDeath;
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

                int yearOfBirthInt = stoi(yearOfBirth);
                int yearOfDeathInt = stoi(yearOfDeath);

                if(checkValidationOfData(name, gender, yearOfBirth,yearOfBirthInt, yearOfDeath, yearOfDeathInt, delimiter))
                {
                Scientist person(name, gender, yearOfBirthInt, yearOfDeathInt);
                scientists.push_back(person);
                }
            }
        }
    }
    else
    {
        //cout << "File cannot open" << endl;
    }

}
bool DataAccess::checkValidationOfData(string name, string gender,string yearOfBirth,int yearOfBirthInt, string yearOfDeath,int yearOfDeathInt, string delimiter)
{
    bool nameBool = false;
    bool genderBool = false;
    bool yearOfBirthBool = false;
    bool yearOfDeathBool = false;
    bool delimiterBool = false;
    if(name != "" && name !="####")
    {
        nameBool = true;
    }
    if(gender == "m" || gender =="f")
    {
        genderBool = true;
    }
    if(yearOfBirth != "" && yearOfBirth != "####" && yearOfBirthInt<2016)//yearToDay
    {
        yearOfBirthBool = true;
    }
    if(yearOfDeath != "" && yearOfDeath != "####" && yearOfDeathInt < 2016 ||yearOfDeathInt ==0)//yearToDay
    {
        yearOfDeathBool = true;
    }
    if(delimiter == "####")
    {
        delimiterBool =true;
    }
    if(nameBool && genderBool && yearOfBirthBool && yearOfDeathBool && delimiterBool)
    {
        return true;
    }
    else
    {
        return false;
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


