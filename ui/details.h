#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include <QPixmap>
#include <QFileDialog>
#include <string>
#include <QMenu>
#include <QMessageBox>

#include "scientist.h"
#include "computer.h"
#include "scientistservice.h"
#include "computerservice.h"

namespace Ui
{
    class Details;
}

class Details : public QDialog
{
    Q_OBJECT

public:

    // Constructed if details about a scientist
    explicit Details(QWidget *parent = 0, Scientist* pScientist = NULL, ScientistService* pService = NULL, ComputerService* pComputerService = NULL);

    // Constructed if details about a computer
    explicit Details(QWidget *parent = 0, Computer* pComputer = NULL, ScientistService* pService = NULL, ComputerService* pComputerService = NULL);
    ~Details();

protected:

    void scientistListBuilder(const vector<Scientist> &scientists);

    void computerListBuilder(const vector<Computer> &computers);

    // Displays a list of all computers available to
    // Add as a connection
    void displayAllComputersAddConnection();

    // Displays a list of all scientists available to
    // Add as a connection
    void displayAllScientistsAddConnection();

private slots:

    void on_browse_scientist_photo_clicked();

    // Right click menu on the table of connections
    void on_connect_table_customContextMenuRequested();

    // Closes the window
    void on_pushButton_clicked();

    // Remove connection right click menu selected
    void on_action_remove_connection_triggered();

    // Double click to add a connection
    void on_table_add_connect_cellDoubleClicked(int row);

    // Add connection right click menu selected
    void on_action_add_connection_triggered();

private:

    Ui::Details *ui;

    Scientist _scientist;
    Computer _computer;

    ScientistService* _pService;

    ComputerService* _pComputerService;

    ScientistService _service;
    ComputerService _computerservice;

    vector <Scientist> _currentlyDisplayedScientists;
    vector <Computer> _currentlyDisplayedComputers;

    // Builds the main windows content
    void ScientistDetails();
    void ComputerDetails();

    // Populates the lists
    void displayComputers();
    void displayScientists();

    short _active;

    string _tableAddConnectDisplays;
};

#endif // DETAILS_H
