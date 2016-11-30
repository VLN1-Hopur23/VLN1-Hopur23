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
    void displayListOfScientist(string sort);
    void Register();

private:
    ScientistService _service;

};

#endif // CONSOLEUI_H
