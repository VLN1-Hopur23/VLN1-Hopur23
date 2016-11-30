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
        displayListOfScientist();

        cout << "Choose how you want your list sorted\n";
        cout << endl;
        cout << "name\t\t- Sort by name\n";
        cout << "age\t\t- Sort by age\n";
        cout << "birth\t\t- Sort by year of birth\n";
        cout << "death\t\t- Sort by year of death\n";
        cout << endl;

        string sort;
        cin >> sort;

        if (sort == "name")
        {
            //TODO
        }
        else if (sort == "age")
        {
            //TODO
        }
        else if (sort == "birth")
        {
            //TODO
        }
        else if (sort == "death")
        {
            //TODO
        }
        else
        {
            cout << "Please choose one of the given options!\n";
            //TODO keep the program running
        }
    }
    else if (command == "register")
    {
        string name;
        string gender;
        int yearOfBirth;
        int yearOfDeath;

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

        cout << "Enter year of death if appropriate:" << endl;
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
    else if (command == "search")
    {
        //TODO
    }
    else if (command == "save")
    {
        //TODO
    }
    else if (command == "quit")
    {
        //TODO
    }
    else
    {
        cout << "Please choose one of the given options!\n";
    }
}

void ConsoleUI::displayListOfScientist()
{
   /* //TODO
    vector<Scientist> scientists = _service.getScientist();

    cout << "Scientist name:" << endl;
    cout << "===============" << endl;
    for (size_t i = 0; i < scientists.size(); i++)
    {
        cout << scientists[i].getName() << endl;
    }*/
}
