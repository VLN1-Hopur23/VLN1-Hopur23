#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientist.h"
#include "scientistservice.h"
#include <iostream>
#include <string>

class ConsoleUI
{
public:
    ConsoleUI();

    // Displays the main menu of the program
    void run();

private:
    void displayListOfScientist(string sort);

private:
    ScientistService _service;

};

#endif // CONSOLEUI_H
