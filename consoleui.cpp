#include "consoleui.h"

using namespace std;

// Presentation layer

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    string command;
    bool loop = true;

    _service.load();

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
    vector<int> foundScientists = _service.searchScientists(searchData);
    cout << endl;
    for (size_t i = 0; i < foundScientists.size(); i++)
    {
        cout << i << ". ";
        cout.width(20);
        cout << left;
        cout << _service.getScientist(foundScientists[i]).getName();
        cout << "\t";
        cout << _service.getScientist(foundScientists[i]).getGender();
        cout << "\t";
        cout << left << _service.getScientist(foundScientists[i]).getYearOfBirth();
        cout << "\t";
        cout << left << _service.getScientist(foundScientists[i]).getYearOfDeath();
        cout << endl;
    }

    cout << endl;
}

void ConsoleUI::List()
{
    string sort;


    while(sort != "back" && sort!= "Back")
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
    cin.ignore();
    getline(cin,name);

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

    Scientist scientist(name, gender, yearOfBirth, yearOfDeath);
    _service.addScientist(scientist);

    cout << "Scientist added!" << endl;
    cout << endl;
}

void ConsoleUI::displayListOfScientist(string sort)
{
    vector<Scientist> _scientists = _service.getScientistVector();

    cout << "===============================================================" << endl;
    cout << "Scientist name:\t\t\tGender\tBirth\tDeath\tAge" << endl;
    cout <<"\t\t\t\t\tYear\tYear" << endl;

    for (size_t i = 0; i < _scientists.size() - 1; i++)
    {
        string Name = _scientists[i].getName();
        cout << _scientists[i].getName();
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

        cout << _scientists[i].getGender() << "\t" <<_scientists[i].getYearOfBirth()<< "\t" <<_scientists[i].getYearOfDeath() << "\t" << _scientists[i].getAge() << endl;
    }
      cout << "===============================================================" << endl;
}
