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

    bool openFileWorks= _service.load();

    if (openFileWorks)
    {
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

            // The user can use one lowe case letter for shortcut
            if (command == "list" || command == "List" || command == "l")
            {
                List();
            }
            else if (command == "register" || command == "Register" || command == "r")
            {
                Register();
            }
            else if (command == "search" || command == "Search" || command == "s")
            {
                //TODO: Search functionality
                Search();
            }
            else if (command == "quit" || command == "Quit" || command == "q")
            {
                loop = false;
            }
            else
            {
                cout << "Please choose one of the given options!\n";
            }
        }
    }
    else
    {
        cout << "Error with opening file" << endl;
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

    printFrame();

    for (size_t i = 0; i < foundScientists.size(); i++)
    {
        cout.fill('0');
        cout.width(2);
        cout << right << foundScientists[i] << ". ";
        cout.fill(' ');
        cout.width(25);
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

    printFrame();

    cout << endl;
}

void ConsoleUI::List()
{
    string sort;

    while(sort != "back" && sort!= "Back" && sort != "b")
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
        vector<Scientist> _AllScientist = _service.getScientistVector();
        _AllScientist = SortVector( _AllScientist, sort);



        displayListOfScientist(_AllScientist);
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
        cout << "ERROR!! Please enter a valid option!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearOfBirth;
    }
    while (yearOfBirth > 9999 || yearOfBirth < 0)
    {
        cout << "ERROR!! Please enter a valid year of birth!\n";
        cin.clear();
        cin >> yearOfBirth;
    }

    cout << "Enter year of death or 0 if the person is still alive:" << endl;
    cin >> yearOfDeath;
    while (cin.fail())
    {
        cout << "ERROR!! Please enter a valid option!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearOfDeath;
    }
    while (yearOfDeath > 99999 || yearOfDeath < yearOfBirth)
    {
        cout << "ERROR!! Please enter a valid year of death!\n";
        cin.clear();
        cin >> yearOfDeath;
    }

    Scientist scientist(name, gender, yearOfBirth, yearOfDeath);
    _service.addScientist(scientist);

    cout << "Scientist added!" << endl;
    cout << endl;
}

void ConsoleUI::displayListOfScientist(vector<Scientist> _scientists)
{
    //vector<Scientist> _scientists = _service.getScientistVector();

    printFrame();

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

    printFrame();
}

void ConsoleUI::printFrame()
{
    cout.fill('=');
    cout.width(63);
    cout << left << "=";
    cout << endl;
    cout.fill(' ');
}


vector<Scientist> ConsoleUI::SortVector(vector<Scientist> _listOfScientist,string sort)
{
   return _service.sortScientists(_listOfScientist, sort);
}
