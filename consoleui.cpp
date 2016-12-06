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

    // bool openFileWorks= _service.load();

    // if (openFileWorks)
    {
        while(loop == true)
        {
            cout << endl;
            cout << "Choose a command:\n";
            cout << endl;
            cout << "register\t- Register a known character from computer science\n";
            cout << "list\t\t- Display the list of computer scientists\n";
            cout << "search\t\t- Search\n";
            cout << "edit\t\t- Edit computer scientist\n";
            cout << "delete\t\t- Delete computer scientist\n";
            cout << "quit\t\t- Exit program\n";
            cout << endl;

            cin >> command;
            cout << endl;

            // Frequent users could use one lower case letter for shortcut
            if (command == "list" || command == "List" || command == "l")
            {
                string select;

                cout << "Select a table to list:\n";
                cout << endl;
                cout << "01. Scientists\n";
                cout << "02. Computers\n";
                cout << endl;
                cout << "Choose: ";
                cin >> select;

                if (select == "1" || select == "Scientists" || select == "scientists")
                {
                    displayListOfScientist();
                }

                //TODO:
                /*
                else if (select == "2" || select == "Computers" || select == "computers")
                {
                    displayListOfComputer();
                }
                */


                // List();
            }
            else if (command == "register" || command == "Register" || command == "r")
            {
                // Register();
            }
            else if (command == "search" || command == "Search" || command == "s")
            {
                Search();
            }
            else if (command == "edit" || command == "Edit" || command == "e")
            {
               // Edit();
            }
            else if (command == "delete" || command == "Delete" || command == "d")
            {
                // Delete();
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
    //else
    {
      //  cout << "Error with opening file" << endl;
    }
}

/*
void ConsoleUI::Edit()
{
    cout << "Edit registered computer scientist character" << endl;
    cout << endl;

    int index;
    string change, input;

    cout << "Enter the index number of the computer scientist you want to change: ";
    cin >> index;
    while (cin.fail() || index > _service.getSize() || index < 0)
    {
        cout << "ERROR!! Please enter a valid index!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> index;
    }
    cout << "Enter what it is that you want to change about the computer scientist" << endl;
    cout << "(name/gender/birth/death): ";
    cin >> change;
    while (change != "name" && change != "gender" && change != "birth" && change != "death"){
        cout << "ERROR!! Please enter a valid option! (name/gender/birth/death)\n";
        cin.clear();
        cin >> change;
    }
    cout << "Enter the new value: ";
    cin >> input;

    string message = _service.editScientist(index, change, input);

    cout << endl;
    cout << message << endl;
    cout << endl;
}
*/

/*
void ConsoleUI::Delete()
{
    int index;
    char confirm;

    cout << "Delete registered scientist" << endl;
    cout << endl;
    cout << "Enter the index number of the scientist to delete: ";
    cin >> index;
    while (cin.fail() || index > _service.getSize() || index < 0)
    {
        cout << "ERROR!! Please enter a valid index!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> index;
    }

    cout << "Are you sure you want to delete " << _service.getScientist(index).getName() << "? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        _service.deleteScientist(index);

        cout << endl;
        cout << "Successfully deleted!" << endl;
        cout << endl;
    }
}
*/

void ConsoleUI::Search()
{
    string searchData;

    cout << "Searching by first letter/s in the name" << endl;
    cout << "Please write the letter/s of the scientist/s that you want to display" << endl;
    cin >> searchData;

    vector<int> foundScientists = _service.searchScientists(searchData);

    cout << endl;

    printFrame();
    printHeader();

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
        cout << "\t";
        cout << left << _service.getScientist(foundScientists[i]).getAge();
        cout << endl;
    }

    printFrame();

    cout << endl;
}

/*
void ConsoleUI::List()
{    
    string sort;

    while(sort != "return" && sort!= "Return" && sort != "r")
    {
        cout << endl;
        cout << "Write the option how you want your list sorted\n";
        cout << endl;
        cout << "name\t\t- Sort by name\n";
        cout << "age\t\t- Sort by age\n";
        cout << "birth\t\t- Sort by year of birth\n";
        cout << "death\t\t- Sort by year of death\n";
        cout << "return\t\t- Return to main menu\n";
        cout << endl;

        cin >> sort;

        vector<Scientist> _AllScientist = _service.getScientistVector();
        _AllScientist = SortVector( _AllScientist, sort);

        displayListOfScientist();
    }

}
*/

/*
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
    while (yearOfBirth > _time.getYearToDay() || yearOfBirth < 0)
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
    while (yearOfDeath > _time.getYearToDay() || ((yearOfDeath < yearOfBirth) && yearOfDeath != 0) )
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
*/

void ConsoleUI::displayListOfScientist()
{
    printFrame();
    printHeader();

    for (size_t i = 0; i < _service.getSize(); i++)
    {
        cout.fill('0');
        cout.width(2);
        cout << right << i << ". ";
        cout.fill(' ');
        cout.width(25);
        cout << left;
        cout << _service.getScientist(i).getName();
        cout << "\t";
        cout << _service.getScientist(i).getGender();
        cout << "\t";
        cout << left << _service.getScientist(i).getYearOfBirth();
        cout << "\t";
        cout << left << _service.getScientist(i).getYearOfDeath();
        cout << "\t";
        cout << left << _service.getScientist(i).getAge();
        cout << endl;
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

void ConsoleUI::printHeader()
{
    cout << "Nr. Scientist name\t\tGender\tBirth\tDeath\tAge" << endl;
    cout <<"\t\t\t\t\tYear\tYear" << endl;
}

vector<Scientist> ConsoleUI::SortVector(vector<Scientist> _listOfScientist,string sort)
{
   return _service.sortScientists(_listOfScientist, sort);
}
