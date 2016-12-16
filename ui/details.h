#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include <string>
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

    void ScientistDetails(ScientistService* pService, ComputerService* pComputerService);
    void ComputerDetails(ScientistService* pService, ComputerService* pComputerService);

protected:
    void displayAllScientists(const vector<Scientist> &scientists);

    void displayAllComputers(const vector<Computer> &computers);

private slots:

private:
    Ui::Details *ui;
    Scientist _scientist;
    Computer _computer;
};

#endif // DETAILS_H
