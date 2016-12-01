#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"

using namespace std;

// Presentation layer

class ConsoleUI
{
public:
    ConsoleUI();

    // Displays the main menu of the program
    void run();

private:
    void displayListOfScientist(vector<Scientist> _scientists);
    void Register();
    void List();
    void Search();
    vector<Scientist> SortVector(vector<Scientist> _listOfScientist,string sort);

private:
    ScientistService _service;
};

#endif // CONSOLEUI_H
