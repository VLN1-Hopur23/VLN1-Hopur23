#include "consoleui.h"
#include <iomanip>
#define CLEARSCREEN() printf("\033[H\033[J") //Clears screen

using namespace std;

//Presentation layer

// Constructor
ConsoleUI::ConsoleUI()
{

}

// Runs command options and fetches the appropriate function for the operation
void ConsoleUI::run()
{
    string command;
    bool loop = true;

    /*
    _service.retrieveScientists("name", "ASC");
    _computers.retrieveComputers("name", "ASC");
    */

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
        cout << "06. clear\t\t- Clear screen\n";
        cout << "07. quit\t\t- Exit program\n";
        cout << endl;
        cin>>command;
        while(!ValidInput(typeOf(command), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
        {
            cout<<"Input is not valid! Try again!"<<endl;
            cin>>command;
        }
        cout << endl;

        // Frequent users could use one lower case letter for shortcut
        if (command == "list" || command == "List" || command == "l" || command == "L" || command == "2" || command == "02")
        {
            string lOption;
            cout << "Select a table to display:" << endl;
            cout << "01. Scientists" << endl;
            cout << "02. Computers" << endl;
            cin >> lOption;
            while(!ValidInput(typeOf(lOption), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>lOption;
            }

            cout << endl;

            if (lOption == "scientist" || lOption == "Scientist" || lOption == "scientists" || lOption == "Scientists" || lOption == "s" || lOption == "S" || lOption == "1" || lOption == "01")
            {
                _service.retrieveScientists("name", "ASC");
                displayScientists();
                listScientists();
            }
            else if (lOption == "computer" || lOption == "Computer" || lOption == "computers" || lOption == "Computers" || lOption == "c" || lOption == "C" || lOption == "2" || lOption == "02")
            {
                _computers.retrieveComputers("name", "ASC");
                displayComputers();
                listComputers();
            }
            else
            {
                cout << "Please choose one of the given options!\n";
            }
        }

        else if (command == "register" || command == "Register" || command == "r" || command == "R" || command == "1" || command == "01")
        {
            string rOption;
            cout << "Select one of the given options to register:" << endl;
            cout << "01. scientist" << endl;
            cout << "02. computer" << endl;
            cin >> rOption;
            while(!ValidInput(typeOf(rOption), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>rOption;
            }
            cout << endl;

            if (rOption == "Scientist" || rOption == "scientist" || rOption == "Scientists" || rOption == "scientists" || rOption == "s" || rOption == "S" || rOption == "1" || rOption == "01")
            {
                registerScientist();
            }
            else if (rOption == "Computer" || rOption == "computer" || rOption == "Computers" || rOption == "computers" || rOption == "c" || rOption == "C" || rOption == "2" || rOption == "02")
            {
                 registerComputer();
            }
            else
            {
                cout << "Please choose one of the given options!\n";
            }
        }

        else if (command == "search" || command == "Search" || command == "s" || command == "S" || command == "3" || command == "03")
        {
           string sOption;
           cout << "Select one of the given options to search:" << endl;
           cout << "01. scientists" << endl;
           cout << "02. computers" << endl;
           cin >> sOption;
           while(!ValidInput(typeOf(sOption), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
           {
               cout<<"Input is not valid! Try again!"<<endl;
               cin>>sOption;
           }
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

        else if (command == "edit" || command == "Edit" || command == "e" || command == "E" || command == "4" || command == "04")
        {
            string edOption;
            cout << "Select one of the given options to edit:" << endl;
            cout << "01. scientists" << endl;
            cout << "02. computers" << endl;
            cin >> edOption;
            while(!ValidInput(typeOf(edOption), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>edOption;
            }
            cout << endl;

            if (edOption ==  "Scientist" || edOption == "scientist" || edOption == "Scientists" || edOption == "scientists" || edOption == "s" || edOption == "S" || edOption == "1" || edOption == "01")
            {
                editScientist();
            }
            else if (edOption == "Computer" || edOption == "computer" || edOption == "Computers" || edOption == "computers" || edOption == "c" || edOption == "C" || edOption == "2" || edOption == "02")
            {
                editComputer();
            }
            else
            {
                cout << "Please choose one of the following options!\n";
            }
        }

        else if (command == "delete" || command == "Delete" || command == "d" || command == "D" || command == "5" || command == "05")
        {
            cout << "Select one of the given options to delete:" << endl;
            cout << "01. scientist" << endl;
            cout << "02. computer" << endl;
            string deOption;
            cin >> deOption;
            while(!ValidInput(typeOf(deOption), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>deOption;
            }

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

        else if (command == "clear" || command == "Clear" || command == "c" || command == "C" || command == "6" || command == "06")
        {
            CLEARSCREEN();
        }

        else if (command == "quit" || command == "Quit" || command == "q" || command == "Q" || command == "7" || command == "07")
        {

            loop = false;
        }
        else
        {
            cout << "Please choose one of the given options!\n";
        }
    }

}

// function that allows user to edit registered scientist from the db
void ConsoleUI::editScientist()
{
    cout << "Edit registered computer scientist" << endl;
    cout << endl;

    int id;

    string change, input,idString;

    cout << "Enter the ID number of the computer scientist you want to change: ";

    cin >> idString;


    cout<<idString<<endl;
    while(!ValidInput(typeOf(idString), "I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
    {
        cout << "Input is not valid! Try again!"<<endl;
        cin >> idString;
    }
    id = std::stoi(idString);
    cout<<"id = "<<id<<endl;




    cout << "Enter a new value: ";

//TODO delete if not used
/*    while (cin.fail() || index > _service.getSize() || index < 0)

   /*while (cin.fail() || index > _service.getSize() || index < 0)


    {
        cout << "ERROR!! Please enter a valid ID!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> index;
    }
    */
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

    string message = _service.editScientist(id, change, input);

    cout << endl;
    cout << message << endl;
    cout << endl;
}

//TODO function that allows user to edit registered computer
void ConsoleUI::editComputer()
{
    cout << "Edit registered computer" << endl;
    cout << endl;

    int id;
    string change, input;


    cout << "Enter the ID number of the computer you want to change: ";

    cin >> id;
    while (cin.fail() || (unsigned)id > _computers.getSize() || id < 0)
    {
        cout << "ERROR!! Please enter a valid ID!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> id;
    }

    cout << "Enter what it is that you want to change about the computer " << endl;
    cout << "(name/yearbuilt/type): ";
    cin >> change;
    while (change != "name" && change != "yearbuilt" && change != "type"){
        cout << "ERROR!! Please enter a valid option! (name/yearbuilt/type)\n";
        cin.clear();
        cin >> change;
    }

    cout << "Enter the new value: ";
    cin >> input;

    string message = _computers.editComputer(id, change, input);

    cout << endl;
    cout << message << endl;
    cout << endl;
}

// Function that allows user to delete scientist of his choosing
void ConsoleUI::deleteScientist()
{
    int index;
    char confirm;

    cout << "Delete registered scientist" << endl;
    cout << endl;
    cout << "Enter the ID number of the scientist to delete: ";
    cin >> index;




    while (cin.fail()  || index < 0)
    {
        cout << "ERROR!! Please enter a valid ID!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> index;
    }

    string scientistNameToDelete;

    for (size_t i = 0; i < _service.getSize(); i++)
    {
        if(_service.getScientist(i).getScientistID() == index)
        {
            //cout << "Are you sure you want to remove " << _service.getScientist(i).getName() << "(y/n) ";
            scientistNameToDelete = _service.getScientist(i).getName();
        }
    }
    cout << "Are you sure you want to delete " << scientistNameToDelete << "? (y/n): ";
    cin >> confirm;


    if (confirm == 'y' || confirm == 'Y')
    {
        _service.deleteScientist(index);

        cout << endl;
        cout << "Successfully deleted!" << endl;
        cout << endl;
    }
}

// Function that allows user to delete computer of his choosing
void ConsoleUI::deleteComputer()
{
    int index;
    char confirm;

    cout << "Delete registered computer" << endl;
    cout << endl;
    cout << "Enter the ID number of the computer to delete: ";
    cin >> index;



    while (cin.fail()  || index < 0)
    {
        cout << "ERROR!! Please enter a valid ID!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> index;
    }


    string computerNameToDelete;
    for (size_t i = 0; i < _computers.getSize(); i++)
    {
        if(_computers.getComputer(i).getComputerID() == index)
        {
            //cout << "Are you sure you want to remove " << _service.getScientist(i).getName() << "(y/n) ";
            computerNameToDelete = _computers.getComputer(i).getName();
        }
    }
    cout << "Are you sure you want to delete " << computerNameToDelete << "? (y/n): ";
    cin >> confirm;


    if (confirm == 'y' || confirm == 'Y')
    {
        _computers.deleteComputer(index);

        cout << endl;
        cout << "Successfully deleted!" << endl;
        cout << endl;
    }
}

// Search for inserted keyword and by filters in Scientist vector
void ConsoleUI::searchScientists()
{
    string searchData;
    string command;

    cout << "Filter by: \n";
    cout << "01. gender\t\t- Filters scientist by gender \n";
    cout << "02. birth\t\t- Filters scientist by year of birth\n";
    cout << "03. death\t\t- Filters scientist by year of death\n";
    cout << "04. search\t\t- Search by a keyword, name or any character\n";
    cout << "05. life\t\t- Search for meaning of life\n";
    cout << endl;
    cin >> command;
    while(!ValidInput(typeOf(command), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
    {
        cout<<"Input is not valid! Try again!"<<endl;
        cin >> command;
    }

    cout << "Enter search keyword: ";
    cin.ignore();
    getline(cin, searchData);

    while(searchData.empty())
    {
        cout << endl;
        cout << "Keyword cannot be empty!\n";
        cout << endl;
        cout << "Enter search keyword: ";
        getline(cin, searchData);
    }

    if (command == "life" || command == "Life" || command == "l" || command == "5" || command == "05")
        {
            cout << "42\n";
        }
    else if(_service.searchingByFilter(command, searchData))
    {
        displayScientists();
    }
    else
    {
        while(searchData.empty())
        {
            cout << endl;
            cout << "Keyword cannot be empty!\n";
            cout << endl;
            cout << "Enter search keyword: ";
            getline(cin, searchData);
        }
        cout << endl;

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
            cout << "04. any other key\t- Return to main menu\n";
            cin >> command;
            while(!ValidInput(typeOf(command), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>command;
            }

            if (command == "edit" || command == "Edit" || command == "e" || command == "1" || command == "01")
            {
                editScientist();
            }
            else if (command == "delete" || command == "Delete" || command == "d" || command == "2" || command == "02")
            {
                deleteScientist();
            }
            else if(command == "link" || command == "Link" || command == "l" || command == "3" || command == "03")
            {
                string param;
                cout << "Select ID to show associated: ";
                cin >> param;
                while(!ValidInput(typeOf(param), "I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
                {
                    cout<<"Input is not valid! Try again!"<<endl;
                    cin>>param;
                }
                cout << endl;
                listIntersectScientist(param);
            }
        }

        // Keyword is rubbish or empty
        else
        {
            cout << "Keyword not found in database\n";
        }
    }
}

// Search for inserted keyword and by filters in Scientist vector
void ConsoleUI::searchComputers()
{
    string searchData;
    string command;

    cout << "Filter by: \n";
    cout << "01. name\t\t- Filters computer by name \n";
    cout << "02. built\t\t- Filters computer by year built\n";
    cout << "04. search\t\t- Search by a keyword in all the database\n";
    cout << "05. life\t\t- Search for meaning of life\n";
    cout << endl;
    cin >> command;
    while(!ValidInput(typeOf(command), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
    {
        cout<<"Input is not valid! Try again!"<<endl;
        cin>>command;
    }

    if(command == "search" || command == "s" || command == "04" || command == "4")
    {
        cout << "Enter search keyword: ";
        cin.ignore();
        getline(cin, searchData);

        while(searchData.empty())
        {
            cout << endl;
            cout << "Keyword cannot be empty!\n";
            cout << endl;
            cout << "Enter search keyword: ";
            getline(cin, searchData);
        }
        searchAllColumsByKeyword(searchData);
    }
    else if(command == "life" || command == "l" || command == "05" || command == "5")
    {
        cout << "42\n";
    }
    else if(command == "built" || command == "b" || command == "02" || command == "2")
    {
        cout << "Enter what year you want to search from: ";
        int yearFrom, yearTo;
        cin >> yearFrom;
        cout << "Enter what year you want to search to: ";
        cin >> yearTo;

        if(_computers.searchComputersByPeriod(yearFrom,yearTo))
        {
            cout << "Listing computers from "<< yearFrom << " - " << yearTo << endl;
            displayComputers();
        }
    }
    else{
        cout << "Enter search keyword: ";
        cin.ignore();
        getline(cin, searchData);

        while(searchData.empty())
        {
            cout << endl;
            cout << "Keyword cannot be empty!\n";
            cout << endl;
            cout << "Enter search keyword: ";
            getline(cin, searchData);
        }

        if (_computers.searchingComputerByFilter(command, searchData)) //If input if okay it returns true
        {
            //Then we display the computers that matched the criteria
            displayComputers();
        }
    }

}

void ConsoleUI::searchAllColumsByKeyword(string searchDataKeyword)
{
    cout << "Searching for " << searchDataKeyword << endl;

    _computers.getVectorFoundComputer(searchDataKeyword);


    // If vector turns up with search results and searchData is not empty then
    if ((_computers.getSize() != 0) && (!searchDataKeyword.empty()))
    {
        displayComputers();
        //Custom menu
        string command = "";
        cout << "If you want to change displayed computer(s) then select the following options\n";
        cout << "01. edit\t\t- Edit computer\n";
        cout << "02. delete\t\t- Delete computer\n";
        cout << "03. link\t\t- Link computer to a scientist\n";
        cout << "04. any other key\t- Return to main menu\n";
        cin >> command;
        while(!ValidInput(typeOf(command), "A_I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
        {
            cout<<"Input is not valid! Try again!"<<endl;
            cin>>command;
        }

        if (command == "edit" || command == "Edit" || command == "e" || command == "E" || command == "1" || command == "01")
        {
            //editScientist();
        }
        else if (command == "delete" || command == "Delete" || command == "d" || command == "D" || command == "2" || command == "02")
        {
            deleteScientist();
        }
        else if(command == "link" || command == "Link" || command == "l" || command == "L" || command == "3" || command == "03")
        {
            string param;
            cout << "Select ID to show associated: ";
            cin >> param;
            while(!ValidInput(typeOf(param), "I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>param;
            }
            cout << endl;
            listIntersectComputer(param);
        }
        // Else then it returns to main menu for example when quit is chosen
    }
    // keyword is rubbish or empty
    else
    {
        cout << "Keyword not found in database\n";
    }
}

// Displays list of scientist and allows user also reverts to sort option
void ConsoleUI::listScientists()
{
    string option;
    bool exit = false;

    while (exit == false)
    {
        cout << endl;
        cout << "Choose option: \n";
        cout << endl;
        cout << "sort\t\t- Sort list\n";
        cout << "link\t\t- Show associated\n";
        cout << "return\t\t- Return to main menu\n";
        cout << endl;
        cin >> option;
        while(!ValidInput(typeOf(option), "A")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
        {
            cout<<"Input is not valid! Try again!"<<endl;
            cin>>option;
        }

        if (option == "sort" || option == "Sort" || option == "s" || option == "S")
        {
            sortScientists();
            displayScientists();
        }
        else if (option == "link" || option == "Link" || option == "l" || option == "L")
        {
            string param;
            cout << "Select scientistID to show associated computer: ";
            cin >> param;
            while(!ValidInput(typeOf(param), "I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>param;
            }
            cout << endl;
            listIntersectScientist(param);
        }
        else if (option == "return" || option == "Return" || option == "r" || option == "R")
        {
            exit = true;
        }
        else
        {
            cout << "Enter a valid option!\n";
            cout << endl;
        }
    }
}

// Sorts the list of scientist
void ConsoleUI::sortScientists()
{
    string order, filter;

    bool loopNotReturn = true;

    while(loopNotReturn) // Starts as true
    {
        cout << endl;
        cout << "Write the option how you want your list sorted\n";
        cout << endl;
        cout << "name\t\t- Sort by name\n";
        cout << "gender\t\t- Sort by gender\n";
        cout << "birth\t\t- Sort by year of birth\n";
        cout << "death\t\t- Sort by year of death\n";
        //cout << "age\t\t- Sort by age\n";
        cout << "return\t\t- Go back\n";
        cout << endl;

        cin >> order;
        while(!ValidInput(typeOf(order), "A")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
        {
            cout<<"Input is not valid! Try again!"<<endl;
            cin>>order;
        }
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
            while(!ValidInput(typeOf(filter), "A")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>filter;
            }

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
        }
    }
}

// Displays list of computer and allows user also reverts to sort option
void ConsoleUI::listComputers()
{
    string option;
    bool exit = false;

    while (exit == false)
    {
        cout << endl;
        cout << "Choose option: \n";
        cout << endl;
        cout << "sort\t\t- Sort list\n";
        cout << "link\t\t- Show associated\n";
        cout << "return\t\t- Return to main menu\n";
        cout << endl;
        cin >> option;
        while(!ValidInput(typeOf(option), "A")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
        {
            cout<<"Input is not valid! Try again!"<<endl;
            cin>>option;
        }

        if (option == "sort" || option == "Sort" || option == "s" || option == "S")
        {
            sortComputers();
            displayComputers();
        }
        else if (option == "link" || option == "Link" || option == "l" || option == "L")
        {
            string param;
            cout << "Select computerID to show associated scientist: ";
            cin >> param;
            while(!ValidInput(typeOf(param), "I")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
            {
                cout<<"Input is not valid! Try again!"<<endl;
                cin>>param;
            }
            cout << endl;
            listIntersectComputer(param);
        }
        else if (option == "return" || option == "Return" || option == "r" || option == "R")
        {
            exit = true;
        }
        else
        {
            cout << "Enter a valid option!\n";
            cout << endl;
        }
    }
}

// Sorts the list of computers
void ConsoleUI::sortComputers()
{
    string order, filter;
    bool loopNotReturn = true;

    while(loopNotReturn) // Starts as true
    {
        cout << endl;
        cout << "Write the option how you want your list sorted\n";
        cout << endl;
        cout << "name\t\t- Sort by the name\n";
        cout << "year\t\t- Sort by the year computers were built\n";
        cout << "type\t\t- Sort by type\n";
        cout << "built\t\t- Sort by whether the computer was built or not\n";
        cout << "return\t\t- Return to main menu\n";
        cout << endl;

        cin >> order;
        while(!ValidInput(typeOf(order), "A")) // typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I" includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
        {
            cout<<"Input is not valid! Try again!"<<endl;
            cin>>order;
        }
        cout << endl;

        if(order == "return" || order == "Return" || order == "r" || order == "R")
        {
            loopNotReturn = false; // Quit the loop and go back
        }
        else
        {
            cout << "Write ASC for ascending order or DESC for descending order:\n";
            cout << endl;
            cin >> filter;

            if(_computers.retrieveComputers(order, filter))
            {
                displayComputers();
            }
            else                                        // Input NOT_OK -> try agian
            {
                cout << endl;
                cout << "Not a validated input, try again!"<<endl;
                cout << endl;
            }
        }
    }
}

// Finds scientist that are connected to computers
void ConsoleUI::listIntersectScientist(const string& param)
{
    _computers.retrieveIntersectScientist(param);
    if(_computers.getSize() != 0)
    {
         displayComputers();
    }
    else
    {
        cout <<"There is no scientist connected to this computer\n";
    }
}

// Finds computers that are conncected to scientists
void ConsoleUI::listIntersectComputer(const string& param)
{
    _service.retrieveIntersectComputer(param);
    if (_service.getSize() != 0)
    {
        displayScientists();
    }
    else
    {
        cout << "There is no computer connected to this scientist\n";
    }
}

// Function that allows user to register a scientist that is not in database
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
        cout << "The name is required!" << endl;
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

    Scientist scientist(_service.getSize(), name, gender, yearOfBirth, yearOfDeath);

    int scientistID;

    bool message = _service.addScientist(scientist, scientistID);

    if (message == true)
    {
        cout << endl;
        cout << "Scientist added successfully!";
        string connectChoice;
        cout << endl;
        cout << "The ID is: " << scientistID << endl;
        cout << endl;
        cout << "Would you like to connect your scientist to a comptuer? (Yes/No)" << endl;
        cin >> connectChoice;
        cout << endl;

        if (connectChoice == "Yes" || connectChoice == "yes" || connectChoice == "Y" || connectChoice == "y")
        {
            //_computers.retrieveComputers("ASC", "Name");
            displayComputers();

            int computerID;

            cout << "Insert computerID which you want to connect to newly added scientist\n";
            cin >> computerID;
            cout << endl;
            //if (computerID <= _computers.getSize())
            {
                addIntersectScientist(scientistID, computerID);
            }
            //else
            {
               // cout << "Input valid ID number\n";
            }
        }
        else if (connectChoice == "No" || connectChoice == "no" || connectChoice == "N" || connectChoice == "n")
        {
            //Return to main menu
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
        cout << endl;
    }
}

// adds a connection from newly added scientist to a already listed computer
void ConsoleUI::addIntersectScientist(const int& scientistID, const int& computerID)
{
    bool addedsuccessfully = _computers.addIntersectScientist(scientistID, computerID);
    if(addedsuccessfully)
    {
         cout << "Connection was added successfully\n";
    }
    else
    {
        cout <<"Connection was not added successfully\n";
    }
}

// adds a connection from newly added computer to a already listed scientist
void ConsoleUI::addIntersectComputer(const int& scientistID, const int& computerID)
{
    bool addedsuccessfully = _service.addIntersectComputer(scientistID, computerID);
    if(addedsuccessfully)
    {
         cout << "Connection was added successfully\n";
    }
    else
    {
        cout <<"Connection was not added successfully\n";
    }
}

// Function that allows user to register a computer that is not in database
void ConsoleUI::registerComputer()
{
    string name;
    int yearBuilt;
    string type;
    bool built = 0;
    string ynBuilt;

    cout << "Enter the name of the computer: " << endl;
    cin.ignore();
    getline(cin,name);

    while (name.empty())
    {
        cout << "Name is required!" << endl;
        getline(cin, name);
    }

    cout << "Enter the year the computer was built: " << endl;
    cin >> yearBuilt;

    while (cin.fail())
    {
        cout << "ERROR!! Please enter a valid option!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearBuilt;
    }
    while (yearBuilt > _time.getYearToDay() || yearBuilt < 0)
    {
        cout << "ERROR!! Please enter a valid option!\n";
        cin.clear();
        cin >> yearBuilt;
    }

    cout << "Enter the type of the computer: " << endl;
    cin.ignore();
    getline(cin, type);

    while (type.empty())
    {
        cout << "Type is required!" << endl;
        getline(cin, type);
    }

    cout << "Was the computer successfully built? (y/n): " << endl;
    cin >> ynBuilt;

    bool inputOK = false;

    while(!inputOK)
    {
        if (ynBuilt == "Yes" || ynBuilt == "yes" || ynBuilt == "Y" || ynBuilt == "y")
        {
            built = 1;
            inputOK = true;
        }
        else if (ynBuilt == "No" || ynBuilt == "no" || ynBuilt == "N" || ynBuilt == "n")
        {
            built = 0;
            inputOK = true;
        }
        else
        {
            cout << "Please enter either yes or no!" << endl;
            cin >> ynBuilt;
            inputOK = false;
        }
    }

    Computer computer(_computers.getSize(), name, yearBuilt, type, built);

    int computerID;

    bool cMessage = _computers.addComputer(computer, computerID);

    if (cMessage == true)
    {
        cout << endl;
        cout << "Computer added successfully!";
        string connectChoice;
        cout << endl;
        cout << "The ID is: " << computerID << endl;
        cout << endl;
        cout << "Would you like to connect your computer to a scientist? (y/n)" << endl;
        cin >> connectChoice;
        cout << endl;

        if (connectChoice == "Yes" || connectChoice == "yes" || connectChoice == "Y" || connectChoice == "y")
        {
            _service.retrieveScientists("ASC", "Name");
            displayScientists();

            int scientistID;

            cout << "Insert computerID which you want to connect to newly added scientist\n";
            cin >> scientistID;
            cout << endl;

            //TODO: validation
            //if (param2 <= _computers.getSize())
            {
                addIntersectComputer(scientistID, computerID);
            }
            //else
            {
               // cout << "Input valid ID number\n";
            }
        }
        else if (connectChoice == "No" || connectChoice == "no" || connectChoice == "N" || connectChoice == "n")
        {
            //Return to main menu
        }
        else
        {
            cout << "Please enter a valid option!\n";
        }
    }
    else
    {
        cout << endl;
        cout << "Add computer failed!";
        cout << endl;
    }
}

// Function that displays a list of scientist and its characteristics
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

// Function that displays a list of computer and its characteristics
void ConsoleUI::displayComputers()
{
    printFrame();
    printComputerHeader();

    for(size_t i = 0; i < _computers.getSize(); i++)
    {
        string type =_computers.getComputer(i).getType();
        string typeFit1;
        string typeFit2;
        bool typeToLong = false;

        if (type.size()>25)
        {
            typeFit1 =type.substr(0,25);
            int LastSpace = typeFit1.find_last_of(" ");
            int StrEnd = type.size();
            typeFit1 =type.substr(0,LastSpace-1);
            typeFit2 = type.substr(LastSpace+1, StrEnd);
            typeToLong = true;
        }
        else
        {
            typeFit1 =type;
        }

        cout << setw(2) << right << _computers.getComputer(i).getComputerID() << "  ";
        cout <<setw(36)<< left << _computers.getComputer(i).getName();
        cout << setw(8) << _computers.getComputer(i).getYearBuilt();
        cout << setw(27) << typeFit1;
        cout << setw(2) << _computers.getComputer(i).getBuilt();
        cout << endl;

        if(typeToLong)
        {
            cout << setw(4) << left << " ";
            cout <<setw(36)<< left <<" ";
            cout << setw(8) << " ";
            cout << setw(25) << typeFit2;
            cout << setw(5) << " ";
            cout << endl;
        }
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

//typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I",
//includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
string ConsoleUI::typeOf(string what)
{
    int whatSize = what.size();
    while(what.substr(whatSize-1,whatSize) ==" ")
    {
        what = what.substr(0,whatSize-1);
        whatSize = what.size();
    }
    int* whatArrayInt = new int[whatSize] {};
    bool* whatIsInt= new bool[whatSize] {false};
    bool* whatIsAlphabet = new bool[whatSize] {false};
    bool* whatIsAlowedChar = new bool[whatSize] {false};
    bool* whatNotValidated = new bool[whatSize] {false};

    for(int i =0; i<whatSize; i++)
    {
        whatArrayInt[i] = (int)what.substr(i,i+1)[0]; //[0] gives first character in string array that is char

    }
    for(int i = 0; i<whatSize; i++)
    {
        if(whatArrayInt[i] >=48 && whatArrayInt[i] <=57) //48 ='0' ...57 ='9'
        {
            whatIsInt[i]=true;
        }
        else if((whatArrayInt[i] >=65 && whatArrayInt[i] <= 90) || (whatArrayInt[i] >=97 && whatArrayInt[i] <=122) || (whatArrayInt[i] ==32) )//65 = 'A', 90='Z', 97='a',122='z',32 =SPACE
        {
            whatIsAlphabet[i] = true;
        }
        else if(whatArrayInt[i] == 46 || whatArrayInt[i] == 44 ) // 46='.', 44 = ',',
        {
           whatIsAlowedChar[i] =true;
        }
        else
        {
            whatNotValidated[i] = true;
        }
    }
    bool ThereAreSomeCharNotValidated = false;
    bool ThereAreSomeInt = false;
    bool ThereAreSomeAlphabet = false;
    bool ThereAreSomeAlowedChar = false;
    for(int i =0; i<whatSize; i++)
    {
        if(whatIsInt[i])
        {
            ThereAreSomeInt = true;
        }
        else if(whatIsAlphabet[i])
        {
            ThereAreSomeAlphabet = true;

        }
        else if(whatIsAlowedChar[i])
        {
            ThereAreSomeAlowedChar =true;
        }
        else
        {
            ThereAreSomeCharNotValidated =true;
        }
    }
    if(ThereAreSomeCharNotValidated)
    {
        return "NV"; //has: Not Validated input
    }
    else if(ThereAreSomeAlphabet && ThereAreSomeAlowedChar && ThereAreSomeInt)
    {
        return "ACI"; //has onlie: Alphabet, char, int
    }
    else if(ThereAreSomeAlowedChar && ThereAreSomeAlphabet)
    {
        return "AC"; //has onlie: Alphabet, char
    }
    else if(ThereAreSomeAlowedChar && ThereAreSomeInt)
    {
        return "CI"; //has onlie: char , int
    }
    else if(ThereAreSomeAlphabet && ThereAreSomeInt)
    {
        return "AI"; // has onlie: Alphabet, int
    }
    else if(ThereAreSomeAlphabet)
    {
        return "A"; // has onlie: Alphabet
    }
    else if(ThereAreSomeAlowedChar)
    {
        return "C"; // has onlie: char
    }
    else if(ThereAreSomeInt)
    {
        return "I"; // has onlie: int

    }
    else
    {
        return "error in localtime::typeOf(string what)";
    }
}
// check can be "AI",AC",ACI","CI","I","C","A","NV" see ConsoleUI::typeOf() for mor info
// allowed can be "A_AC.._I" see above
// checks if input is allowed

bool ConsoleUI::ValidInput(string check, string allowed)
{
    if( check == "NV")
    {
        return false;
    }

    int count_ =0;
    int* whereAre= new int[6]{};
    int allowedSize = allowed.size();
    string oneAllowedIntax;
    whereAre[count_]=-1;
    count_++;
    for(int i =0; i<allowedSize; i++)
    {
        if(allowed[i]=='_')
        {
            whereAre[count_]=i;
            count_++;
        }
    }
    whereAre[count_]=allowedSize;

    for (int i =0; i<count_;i++)
    {
        oneAllowedIntax = allowed.substr(whereAre[i]+1, whereAre[i+1]-whereAre[i]-1);
       if (check == oneAllowedIntax )
        {
            return true;
        }
    }
    return false;
}
