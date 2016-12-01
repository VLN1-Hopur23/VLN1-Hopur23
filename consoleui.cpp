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
            List();
        }
        else if (command == "register" || command == "Register")
        {
            Register();
        }
        else if (command == "search" || command == "Search")
        {
            //TODO: Search functionality
            Search();
        }
        else if (command == "save" || command == "Save")
        {
            // TODO
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

void ConsoleUI::Search()
{
    string searchData;
    //Call the function searchScientists
    cout << "Searching by first letter/s in the name" << endl;
    cout << "Please write the letter/s of the scientist/s that you want to display" << endl;
    cin >> searchData;
    vector<Scientist> foundScientists = _service.searchScientists(searchData);
    cout << endl;
    for (size_t i = 0; i < foundScientists.size(); i++)
    {
        cout << foundScientists[i].getName() << endl;
    }
}

void ConsoleUI::List()
{
    string sort;

    while(sort != "back" || sort!= "Back")
    {
        cout << endl;
        cout << "Choose how you want your list sorted\n";
        cout << endl;
        cout << "name\t\t- Sort by name\n";
        cout << "age\t\t- Sort by age\n";
        cout << "birth\t\t- Sort by year of birth\n";
        cout << "death\t\t- Sort by year of death\n";
        cout << "back\t\t- Back to main menu\n";
        cout << endl;

        cin >> sort;

        displayListOfScientist(sort);
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
    while (gender != "m" && gender != "M" && gender != "f" && gender != "F")
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

    //service.addScientist(newScientist);

    cout << "Scientist added!" << endl;
}

void ConsoleUI::displayListOfScientist(string sort)
{
    //TODO
    vector<Scientist> scientists = _service.getScientists(sort);


    cout << "===============================================================" << endl;
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
      cout << "===============================================================" << endl;
}
