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

namespace Ui {
class Details;
}

class Details : public QDialog
{
    Q_OBJECT

public:
    explicit Details(QWidget *parent = 0, Scientist* pScientist = NULL, ScientistService* pService = NULL, ComputerService* pComputerService = NULL);
    explicit Details(QWidget *parent = 0, Computer* pComputer = NULL, ScientistService* pService = NULL, ComputerService* pComputerService = NULL);
    ~Details();

    void ScientistDetails();
    void ComputerDetails();

protected:
    void displayAllScientists(const vector<Scientist> &scientists);

    void displayAllComputers(const vector<Computer> &computers);

    void displayAllComputersAddConnection();
    void displayAllScientistsAddConnection();

private slots:

    void on_browse_scientist_photo_clicked();

    void on_connect_table_customContextMenuRequested();

    void on_pushButton_clicked();

    void on_action_remove_connection_triggered();

    void on_table_add_connect_cellDoubleClicked(int row, int column);

private:
    Ui::Details *ui;
    Scientist _scientist;
    Computer _computer;

    ScientistService* _pService;
    ScientistService _service;

    ComputerService* _pComputerService;
    ComputerService _computerservice;

    vector <Scientist> _currentlyDisplayedScientists;
    vector <Computer> _currentlyDisplayedComputers;

    void displayComputers();
    void displayScientists();

    short _active;

    string _tableAddConnectDisplays;
};

#endif // DETAILS_H
