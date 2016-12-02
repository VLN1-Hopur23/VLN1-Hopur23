#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"
#include "scientist.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Presentation layer

class ConsoleUI
{
public:

    ConsoleUI();

    // Displays the main menu of the program
    void run();

private:

    void displayListOfScientist();
    void Register();
    void List();
    void Search();
    void Edit();
    void Delete();
    void printFrame();
    vector<Scientist> SortVector(vector<Scientist> _listOfScientist,string sort);

private:

    ScientistService _service;
};

#endif // CONSOLEUI_H
