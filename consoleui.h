#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"
#include "scientist.h"
#include "computer.h"
#include "computerservice.h"
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

    void displayScientists();

    void displayComputers();

    void searchScientists();

    void searchComputers();

    void editScientist();

    void editComputer();

    void deleteScientist();

    void deleteComputer();

    void printFrame();

    void printScientistHeader();

    void printComputerHeader();

    void listIntersectScientist(const string& param);

    void listIntersectComputer(const string& param);

    vector<Scientist> SortVector(vector<Scientist> _listOfScientist,string sort);

    LocalTime _time;

private:

    //TODO skyrari nofn
    ScientistService _service;

    ComputerService _computers;
};

#endif // CONSOLEUI_H
