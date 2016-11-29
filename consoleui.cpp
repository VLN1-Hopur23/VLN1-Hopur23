#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
}

void ConsoleUI::run()
{
    cout << "Choose a command:\n";
    cout << endl;
    cout << "register\t- Register a scientist\n";
    cout << "list\t\t- List scientists\n";
    cout << "save\t\t- Save changes\n";
    cout << "quit\t\t- Exit program\n";
    cout << endl;
}
