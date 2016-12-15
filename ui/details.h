#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include "scientist.h"
#include "computer.h"

namespace Ui {
class Details;
}

class Details : public QDialog
{
    Q_OBJECT

public:
    explicit Details(QWidget *parent = 0, Scientist* scientist = NULL);
    explicit Details(QWidget *parent = 0, Computer* computer = NULL);
    ~Details();

    void ScientistDetails();
    void ComputerDetails();

private slots:

private:
    Ui::Details *ui;
    Scientist _scientist;
    Computer _computer;
};

#endif // DETAILS_H
