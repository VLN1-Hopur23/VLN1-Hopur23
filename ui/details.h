#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include <string>
#include <QMenu>
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

private slots:

    void on_connection_table_customContextMenuRequested();

    void on_pushButton_clicked();

    void on_action_remove_connection_triggered();

private:
    Ui::Details *ui;
    Scientist _scientist;
    Computer _computer;

    ScientistService* _pService;
    ComputerService* _pComputerService;

    vector <Scientist> currentlyDisplayedScientist;
    vector <Computer> currentlyDisplayedComputers;
};

#endif // DETAILS_H
