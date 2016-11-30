#include "consoleui.h"
#include "scientist.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Presentation layer

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    string command;
    bool loop = true;

    while(loop == true)
    {
        cout << "Choose a command:\n";
        cout << endl;
        cout << "register\t- Register a scientist\n";
        cout << "list\t\t- Display the list of scientists\n";
        cout << "search\t\t- Search\n";
        cout << "save\t\t- Save changes\n";
        cout << "quit\t\t- Exit program\n";
        cout << endl;

        cin >> command;

        if (command == "list" || command == "List")
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
            //Er innbyggt i displayListOfS... functioninu og dar er default sort by name
            /*if (sort == "name")
            {
                displayListOfScientist(sort);
                //TODO
            }
            else if (sort == "age")
            {
                displayListOfScientist(sort);
            }
            else if (sort == "birth")
            {
                displayListOfScientist(sort);//TODO
            }
            else if (sort == "death")
            {
                displayListOfScientist(sort);
            }
            else
            {
                cout << "Please choose one of the given options!\n";
                //TODO keep the program running
            }*/
        }
        else if (command == "register" || command == "Register")
        {
            registerScientist();
        }
        else if (command == "search" || command == "Search")
        {
            //TODO: Search functionality
        }
        else if (command == "save" || command == "Save")
        {
            // TO DO
        }
        else if (command == "quit" || command == "Quit")
        {
            loop = false;
        }
        else
        {
            cout << "Please choose one of the given options!\n";
        }
    }
}

void ConsoleUI::Register()
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

    cout << "Enter year of death or - if the person is still alive:" << endl;
    cin >> yearOfDeath;
    while (cin.fail())
    {
        cout << "Please enter a valid option!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearOfDeath;
    }

    Scientist newScientist(name, gender, yearOfBirth, yearOfDeath);

    service.addScientist(newScientist);

    cout << "Scientist added!" << endl;
}

void ConsoleUI::displayListOfScientist(string sort)
{
    vector<Scientist> scientists = _service.getScientists(sort);

    cout << "Scientist name:" << endl;
    cout << "===============" << endl;
    for (size_t i = 0; i < scientists.size(); i++)
    {
        cout << scientists[i].getName() << endl;
    }
}
