#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "scientistservice.h"
#include "scientist.h"
#include "computer.h"
#include "computerservice.h"
#include "localtime.h"
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

    void editScientist();

    void editComputer();

    void deleteScientist();

    void deleteComputer();

    void searchScientists();

    void searchComputers();

    void listScientists();

    void sortScientists();

    void listComputers();

    void sortComputers();

    void listIntersectScientist(const string& param);

    void listIntersectComputer(const string& param);

    void registerScientist();

    void registerComputer();

    void displayScientists();

    void displayComputers();

    void printFrame();

    void printScientistHeader();

    void printComputerHeader();

    vector<Scientist> SortVector(vector<Scientist> _listOfScientist,string sort);

    void searchAllColumsByKeyword(string searchDataKeyword);



private:

    //TODO skyrari nofn
    ScientistService _service;
    LocalTime _time;
    ComputerService _computers;

    string typeOf(string what);
    bool ValidInput(string check, string allowed);
};

#endif // CONSOLEUI_H
