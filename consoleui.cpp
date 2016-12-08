#include "consoleui.h"
#include <iomanip>
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
            cout << "01. register\t\t- Register a known character or computer\n";
            cout << "02. list\t\t- Display the list of computer scientists or computers\n";
            cout << "03. search\t\t- Search scientist or computer\n";
            cout << "04. edit\t\t- Edit scientist or computer\n";
            cout << "05. delete\t\t- Delete scientist or computer\n";
            cout << "06. quit\t\t- Exit program\n";
            cout << endl;

            cin >> command;
            cout << endl;

            // Frequent users could use one lower case letter for shortcut
            if (command == "list" || command == "List" || command == "l" || command == "2" || command == "02")
            {
                string lOption;
                cout << "Select a table to display:" << endl;
                cout << "01. scientist" << endl;
                cout << "02. computer" << endl;
                cin >> lOption;
                cout << endl;

                if (lOption == "scientist" || lOption == "Scientist" || lOption == "scientists" || lOption == "Scientists" || lOption == "s" || lOption == "S" || lOption == "1" || lOption == "01")
                {
                    //_service.retrieveScientists();
                    listScientists();
                    displayScientists();
                }
                else if (lOption == "computer" || lOption == "Computer" || lOption == "computers" || lOption == "Computers" || lOption == "c" || lOption == "C" || lOption == "2" || lOption == "02")
                {
                    //_computers.retrieveComputers();
                    listComputers();
                    //displayComputers();
                }
                else
                {
                    cout << "Please choose one of the given options!\n";
                }
            }

            else if (command == "register" || command == "Register" || command == "r" || command == "1" || command == "01")
            {
                string rOption;
                cout << "Select one of the given options to register:" << endl;
                cout << "01. scientist" << endl;
                cout << "02. computer" << endl;
                cin >> rOption;
                cout << endl;

                if (rOption == "Scientist" || rOption == "scientist" || rOption == "s" || rOption == "S" || rOption == "1" || rOption == "01")
                {
                     registerScientist();
                }
                else if (rOption == "Computer" || rOption == "computer" || rOption == "c" || rOption == "C" || rOption == "2" || rOption == "02")
                {
                    // TODO: with SQL
                     registerComputer();
                }
                else
                {
                    cout << "Please choose one of the given options!\n";
                }
            }

            else if (command == "search" || command == "Search" || command == "s" || command == "3" || command == "03")
            {
               string sOption;
               cout << "Select one of the given options to search:" << endl;
               cout << "01. scientists" << endl;
               cout << "02. computers" << endl;
               cin >> sOption;
               cout << endl;

               if (sOption == "Scientist" || sOption == "scientist" || sOption == "Scientists" || sOption == "scientists" || sOption == "S" || sOption == "s" || sOption == "1" || sOption == "01")
               {
                   searchScientists();
               }
               else if (sOption == "Computer" || sOption == "computer" || sOption == "Computers" || sOption == "computers" || sOption == "C" || sOption == "c" || sOption == "2" || sOption == "02")
               {
                   searchComputers();
               }
               else
               {
                   cout << "Please choose one of the given options!\n";
               }
            }

            else if (command == "edit" || command == "Edit" || command == "e" || command == "4" || command == "04")
            {
                string edOption;
                cout << "Select one of the given options to edit:" << endl;
                cout << "01. scientists" << endl;
                cout << "02. computers" << endl;
                cin >> edOption;
                cout << endl;

                if (edOption ==  "Scientist" || edOption == "scientist" || edOption == "Scientists" || edOption == "scientists" || edOption == "s" || edOption == "S" || edOption == "1" || edOption == "01")
                {
                    editScientist();
                }
                else if (edOption == "Computer" || edOption == "computer" || edOption == "Computers" || edOption == "computers" || edOption == "C" || edOption == "c" || edOption == "2" || edOption == "02")
                {
                    editComputer();
                }
                else
                {
                    cout << "Please choose one of the following options!\n";
                }
            }

            else if (command == "delete" || command == "Delete" || command == "d" || command == "5" || command == "05")
            {
                cout << "Select one of the given options to delete:" << endl;
                cout << "01. scientist" << endl;
                cout << "02. computer" << endl;
                string deOption;
                cin >> deOption;

                if (deOption == "Scientist" || deOption == "scientist" || deOption == "Scientists" || deOption == "scientists" || deOption == "S" || deOption == "s" || deOption == "1" || deOption == "01")
                {
                    deleteScientist();
                }
                else if (deOption == "Computer" || deOption == "computer" || deOption == "Computers" || deOption == "computers" || deOption == "C" || deOption == "c" || deOption == "2" || deOption == "02")
                {
                    deleteComputer();
                }
                else
                {
                    cout << "Please choose one of the following options!\n";
                }
            }

            else if (command == "quit" || command == "Quit" || command == "q" || command == "6" || command == "06")
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

void ConsoleUI::editComputer()
{
    cout << "Edit registered computer" << endl;
    cout << endl;

    int cIndex;
    string cChange, cInput;

    cout << "Enter the index number of the computer you want to change: ";
    cin >> cIndex;
}

void ConsoleUI::editScientist()
{
    cout << "Edit registered computer scientist character" << endl;
    cout << endl;

    int index;
    string change, input;

    cout << "Enter the index number of the computer scientist you want to change: ";
    cin >> index;
/*    while (cin.fail() || index > _service.getSize() || index < 0)
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
*/}

void ConsoleUI::deleteComputer()
{
    int cIndex;
//  char cConfirm;

    cout << "Delete registered computer" << endl;
    cout << endl;
    cout << "Enter the index number of the scientist to delete: ";
    cin >> cIndex;
}

void ConsoleUI::deleteScientist()
{
    int index;
//  char confirm;

    cout << "Delete registered scientist" << endl;
    cout << endl;
    cout << "Enter the index number of the scientist to delete: ";
    cin >> index;
/*  while (cin.fail() || index > _service.getSize() || index < 0)
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
*/
}

// Search for inserted keyword in Scientist vector
void ConsoleUI::searchScientists()
{
    string searchData;

    cout << "Enter search keyword: ";
    cin.ignore();
    getline(cin, searchData);
    cout << "Searching for " << searchData << endl;

    _service.getVectorFoundScientists(searchData);

    // If vector turns up with search results and searchData is not empty then
    if ((_service.getSize() != 0) && (!searchData.empty()))
    {
        displayScientists();
        // Custom menu
        string command = "";
        cout << "If you want to change displayed scientist(s) then select the following options\n";
        cout << "01. edit\t\t- Edit scientist \n";
        cout << "02. delete\t\t- Delete scientist\n";
        cout << "03. link\t\t- Link scientist to a computer\n";
        cout << "04. any other key\t- Exit program\n";
        cin >> command;

        if (command == "edit" || command == "Edit" || command == "e" || command == "1" || command == "01")
        {
            //editScientist();
        }
        else if (command == "delete" || command == "Delete" || command == "d" || command == "2" || command == "02")
        {
            //deleteScientist();
        }
        else if(command == "link" || command == "Link" || command == "l" || command == "3" || command == "03")
        {
            //linkScientist();
        }
    }
    // Keyword is rubbish or empty
    else
    {
        cout << "Keyword not found in database\n";
    }
}

void ConsoleUI::searchComputers()
{
    string searchData;

    cout << "Enter search keyword: ";
    cin.ignore();
    getline(cin, searchData);
    cout << "Searching for " << searchData << endl;

    _computers.getVectorFoundComputer(searchData);

    // If vector turns up with search results and searchData is not empty then
    if ((_computers.getSize() != 0) && (!searchData.empty()))
    {
        displayComputers();
        //Custom menu
        string command = "";
        cout << "If you want to change displayed computer(s) then select the following options\n";
        cout << "01. edit\t\t- Edit computer\n";
        cout << "02. delete\t\t- Delete computer\n";
        cout << "03. link\t\t- Link computer to a scientist\n";
        cout << "04. any other key\t- Exit program\n";
        cin >> command;

        if (command == "edit" || command == "Edit" || command == "e" || command == "1" || command == "01")
        {
            //editScientist();
        }
        else if (command == "delete" || command == "Delete" || command == "d" || command == "2" || command == "02")
        {
            //deleteScientist();
        }
        else if(command == "link" || command == "Link" || command == "l" || command == "3" || command == "03")
        {
            //linkScientist();
        }
        // Else then it returns to main menu for example when quit is chosen

    }
    // Keyword is rubish or empty
    //else if
    {
        cout << "Keyword not found in database\n";
    }
}

void ConsoleUI::listScientists()
{
    string order, filter;
    bool loopNotReturn = true;

    while(loopNotReturn)
    {
        cout << endl;
        cout << "Write the option how you want your list sorted\n";
        cout << endl;
        cout << "name\t\t- Sort by name\n";
        cout << "gender\t\t- Sort by gender\n";
        cout << "birth\t\t- Sort by year of birth\n";
        cout << "death\t\t- Sort by year of death\n";
        //cout << "age\t\t- Sort by age\n";
        cout << "return\t\t- Return to main menu\n";
        cout << endl;

        cin >> order;
        cout << endl;

        if(order == "return" || order == "Return" || order == "r" || order == "R")
        {
            loopNotReturn = false;
        }
        else
        {
            cout << "Write ASC for ascending order or DESC for descending order:\n";
            cout << endl;
            cin >> filter;
                    // TO DO ERROR CHECK!!
            if(_service.retrieveScientists(order, filter))
            {
                displayScientists();
            }
            else
            {
                cout << endl;
                cout << "Not a validated input, try again!"<<endl;
                cout << endl;
            }

            //vector<Scientist> _AllScientist = _service.getScientistVector();
            //_AllScientist = SortVector( _AllScientist, sort);
            //displayListOfScientist();
        }
    }
}

void ConsoleUI::listComputers()
{
    string order, filter;
    bool loopNotReturn = true;

    while(loopNotReturn)
    {
        cout << endl;
        cout << "Write the option how you want your list sorted\n";
        cout << endl;
        cout << "name\t\t- Sort by the name\n";
        cout << "built\t\t- Sort by the year computers were built\n";
        cout << "type\t\t- Sort by type\n";
        cout << "return\t\t- Return to main menu\n";
        cout << endl;

        cin >> order;
        cout << endl;

        if(order == "return" || order == "Return" || order == "r" || order == "R")
        {
            loopNotReturn = false;
        }
        else
        {
            cout << "Write ASC for ascending order or DESC for descending order:\n";
            cout << endl;
            cin >> filter;
                // TO DO ERROR CHECK!!
            if(_computers.retrieveComputers(order, filter)) // if TRUE then input is OK
            {
                displayComputers();
            }
            else                                            // input NOT_OK -> try agian
            {
                cout << endl;
                cout << "Not a validated input, try again!"<<endl;
                cout << endl;
            }
        }
    }
}

void ConsoleUI::registerScientist()
{
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;

    cout << "Enter the name of the person:" << endl;
    cin.ignore();
    getline(cin, name);

    while (name.empty())
    {
        cout << "Enter the name of the person:" << endl;
        getline(cin, name);
    }

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

    Scientist scientist(_service.getSize(),name, gender, yearOfBirth, yearOfDeath);

    bool message = _service.addScientist(scientist);
    cout << endl;
//  cout << message << endl;

    if (message == true)
    {
        cout << endl;
        cout << "Scientist added successfully!";
        string connectChoice;
        cout << endl;
        cout << "Would you like to connect your scientist to a comptuer?" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cin >> connectChoice;
        cout << endl;

        if (connectChoice == "Yes" || connectChoice == "yes" || connectChoice == "Y" || connectChoice == "y")
        {
            cout << "yay" << endl;
            // TODO link
        }
        else if (connectChoice == "No" || connectChoice == "no" || connectChoice == "N" || connectChoice == "n")
        {
            exit(0);
        }
        else
        {
           cout << "Please enter a valid option!\n";
        }
    }
    else
    {
        cout << endl;
        cout << "Add scientist failed!";
        exit(0);
    }
}

void ConsoleUI::registerComputer()
{
    string computerName;
    int computerBuildYear;
    string computerType;

    cout << "Enter the name of the computer: " << endl;
    cin.ignore();
    getline(cin,computerName);

    cout << "Enter the year the computer was built: " << endl;
    cin >> computerBuildYear;

    cout << "Enter the type of the computer: " << endl;
    cin.ignore();
    getline(cin,computerType);

    cout << "Computer added!" << endl;
    cout << endl;


}

void ConsoleUI::displayComputers()
{
    printFrame();
    printComputerHeader();

    for(size_t i = 0; i < _computers.getSize(); i++)
    {

        cout << setw(2) << right << _computers.getComputer(i).getComputerID() << "  ";
        cout <<setw(36)<< left << _computers.getComputer(i).getName();
        cout << setw(8) << _computers.getComputer(i).getYearBuilt();
        cout << setw(27) << _computers.getComputer(i).getType();
        cout << setw(2) << _computers.getComputer(i).getBuilt();
        cout << endl;
/* -----FOR TROUBLE SHOTING
        cout << setw(3) << right << _computers.getComputer(i).getComputerID() << " ";
        cout <<setw(36)<< left << _computers.getComputer(i).getName().size();
        cout << setw(8) << _computers.getComputer(i).getYearBuilt();
        cout << setw(25) << _computers.getComputer(i).getType().size();
        cout << setw(5) << _computers.getComputer(i).getBuilt();
        cout << endl;
*/
    }
    printFrame();
}

void ConsoleUI::displayScientists()
{
    printFrame();
    printScientistHeader();

    for (size_t i = 0; i < _service.getSize(); i++)
    {
        cout.fill(' ');
        cout.width(2);
        cout << right << _service.getScientist(i).getScientistID() << "  ";
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
    cout.width(78);
    cout << left << "=";
    cout << endl;
    cout.fill(' ');
}

void ConsoleUI::printScientistHeader()
{
    cout << "ID Scientist name\t\tGender\tBirth\tDeath\tAge" << endl;
    cout <<"\t\t\t\t\tYear\tYear" << endl;

    cout.fill('-');
    cout.width(78);
    cout << left << "-";
    cout << endl;
    cout.fill(' ');
}

void ConsoleUI::printComputerHeader()
{
    //cout << "ID  Computer name\t\t\t\tYear Built\tType\tBuilt" << endl;
    //cout <<"\t\t\t\t\t" << endl;
    cout << setw(4) << "ID" << setw(36)<<"Computer name" << setw(8) << "Year";
    cout << setw(25) << "Type" << setw(5) << "Built" << endl;
    cout << setw(40) <<" "<< "Built" << endl;
    cout.fill('-');
    cout.width(78);
    cout << left << "-";
    cout << endl;
    cout.fill(' ');
}

vector<Scientist> ConsoleUI::SortVector(vector<Scientist> _listOfScientist,string sort)
{
   return _service.sortScientists(_listOfScientist, sort);
}

