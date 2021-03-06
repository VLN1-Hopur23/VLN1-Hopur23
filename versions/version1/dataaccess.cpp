#include "dataaccess.h"

using namespace std;
// constructor
DataAccess::DataAccess()
{

}

//reads scientist from file to vector
void DataAccess::getData(vector<Scientist>& scientists)
{
    ifstream file;
    ofstream file2("newfile.txt");
    Scientist person;
    string check;
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
            getline(file, name);
            getline(file, gender);
            getline(file, yearOfBirth);
            getline(file, yearOfDeath);
            getline(file, delimiter);

            int yearOfBirthInt = atoi(yearOfBirth.c_str());
            int yearOfDeathInt = atoi(yearOfDeath.c_str());

            if(checkValidationOfData(name, gender, yearOfBirth,yearOfBirthInt, yearOfDeath, yearOfDeathInt, delimiter))
            {
                Scientist person(name, gender, yearOfBirthInt, yearOfDeathInt);
                scientists.push_back(person);
            }
            //else
            {
                //DataOk = false;
            }
        }
    }
    else
    {
        FileOpen = false;
    }
}
//validates the scientists characteristic in the file
bool DataAccess::checkValidationOfData(string name, string gender,string yearOfBirth,int yearOfBirthInt, string yearOfDeath,int yearOfDeathInt, string delimiter)
{
    bool nameBool = false;
    bool genderBool = false;
    bool yearOfBirthBool = false;
    bool yearOfDeathBool = false;
    bool delimiterBool = false;

    gender = gender.substr(0,1); // get onlie one characther ( to skip space)
    if(name != "" && name !="####")
    {
        nameBool = true;
    }

    if(gender == "m" || gender =="f")
    {
        genderBool = true;
    }
    if(yearOfBirth != "" && yearOfBirth != "####" && yearOfBirthInt < _time.getYearToDay())
    {
        yearOfBirthBool = true;
    }
    if((yearOfDeath != "" && yearOfDeath != "####" && yearOfDeathInt < _time.getYearToDay()) || yearOfDeathInt == 0)
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
// writes a new scientist in the file
void DataAccess::writeNewScientist(Scientist scientist)
{
    ofstream file;

    file.open("computerScientists.txt", ios_base::app);

    if (file)
    {
        file << scientist.getName() << endl;
        file << scientist.getGender() << endl;
        file << scientist.getYearOfBirth() << endl;
        file << scientist.getYearOfDeath() << endl;
        file << "####\n";
    }

    file.close();
}
//rewrites file, instrument for delete scientists
void DataAccess::writeData(const vector<Scientist>& scientists)
{
    ofstream file;

    file.open("computerScientists.txt");


    if (file)
    {
        int index = 0;

        while(index < scientists.size())
        {

            file << scientists[index].getName() << endl;
            file << scientists[index].getGender() << endl;
            file << scientists[index].getYearOfBirth() << endl;
            file << scientists[index].getYearOfDeath() << endl;
            file << "####\n";

            index++;
        }
    }

    file.close();
}
