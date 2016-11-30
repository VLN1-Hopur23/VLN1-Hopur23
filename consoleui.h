#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientist.h"
#include "scientistservice.h"
#include <iostream>

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
    void registerScientist();

private:
    ScientistService _service;

};

#endif // CONSOLEUI_H
