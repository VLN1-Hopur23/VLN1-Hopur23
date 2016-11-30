#include <iostream>
#include <string>
#include "consoleui.h"
#include "scientist.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    cout << "Choose a command:\n";
    cout << endl;
    cout << "register\t- Register a scientist\n";
    cout << "list\t\t- Display the list of scientists\n";
    cout << "search\t\t- Search\n";
    cout << "save\t\t- Save changes\n";
    cout << "quit\t\t- Exit program\n";
    cout << endl;

    string command;
    cin >> command;

    if (command == "list")
    {
       List();
    }
    else if (command == "register")
    {
        Register();
    }
    else if (command == "search")
    {
        //TODO
    }
    else if (command == "save")
    {
        // TO DO
    }
    else if (command == "quit")
    {
        // TO DO
    }
    else
    {
        cout << "Please choose one of the given options!\n";
    }
}

void ConsoleUI::List()
{
    cout << endl;
    cout << "Choose how you want your list sorted\n";
    cout << endl;
    cout << "name\t\t- Sort by name\n";
    cout << "age\t\t- Sort by age\n";
    cout << "birth\t\t- Sort by year of birth\n";
    cout << "death\t\t- Sort by year of death\n";
    cout << endl;

    string sort;
    cin >> sort;
    displayListOfScientist(sort);

}

void ConsoleUI::Register()
{
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
    int age;

    cout << "Enter the name of the person:" << endl;
    cin >> name;
    //check?

    cout << "Enter gender (m for male, f for female):" << endl;
    cin >> gender;
    while (gender != "m" && gender != "f")
    {
        cout << "Please enter either m or f!\n";
        cin.clear();
        cin >> gender;
    }

    cout << "Enter year of birth:" << endl;
    cin >> yearOfBirth;
    while (cin.fail())
    {
        cout << "Please enter a valid option!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearOfBirth;
    }

    cout << "Enter year of death or - if the person is still alive:" << endl;
    cin >> yearOfDeath;
    while (cin.fail())
    {
        cout << "Please enter a valid option!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearOfDeath;
    }

    //Scientist newScientist(name, gender, yearOfBirth, yearOfDeath);

    //service.addScientist(newScientist);
}

void ConsoleUI::displayListOfScientist(string sort)
{
    //TODO
    vector<Scientist> scientists = _service.getScientists(sort);

    cout << "Scientist name:" << endl;
    cout << "===============" << endl;
    cout << "Scientist name:\t\t\tGender\tBirth\tDeath\tAge" << endl;
    cout <<"\t\t\t\t\tYear\tYear" << endl;

    for (size_t i = 0; i < scientists.size(); i++)
    {
        string Name = scientists[i].getName();
        cout << scientists[i].getName();
        if(Name.size()<8)
        {
            cout<< "\t\t\t\t";
        }
        else if(Name.size()<16)
        {
            cout << "\t\t\t";
        }
        else if(Name.size()<24)
        {
            cout<< "\t\t";
        }
        else if(Name.size()<30)
        {
            cout<< "\t";
        }

        cout << scientists[i].getGender() << "\t" <<scientists[i].getYearOfBirth()<< "\t" <<scientists[i].getYearOfDeath() << "\t" << scientists[i].getAge() << endl;

    }
}





