#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "computer.h"
#include "computerservice.h"
#include <string.h>

using namespace std;

namespace Ui
{
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:

    explicit AddComputerDialog(QWidget *parent = 0);

    ~AddComputerDialog();

private slots:

    void on_button_add_computer_add_computer_clicked();

    void on_button_add_computer_cancel_clicked();

private:

    Ui::AddComputerDialog *ui;

    ComputerService _computers;

    bool ValidInput(string check, string allowed);

    string typeOf(string what);

    LocalTime _time;
};

#endif // ADDCOMPUTERDIALOG_H

