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
    void displayListOfScientist(string sort);
    void Register();
    void List();
    void Search();

private:
    ScientistService _service;
};

#endif // CONSOLEUI_H
