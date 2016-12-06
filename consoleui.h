#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"
#include "scientist.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <localtime.h>

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

    void registerScientist();

    void registerComputer();

    void listScientists();

    void listComputers();

    void Search();

    void Edit();

    void Delete();

    void printFrame();

    void printHeader();

    vector<Scientist> SortVector(vector<Scientist> _listOfScientist,string sort);

    LocalTime _time;

private:

    ScientistService _service;
};

#endif // CONSOLEUI_H
