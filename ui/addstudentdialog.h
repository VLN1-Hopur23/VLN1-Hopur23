#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QFileDialog>
#include "scientistservice.h"
#include <string.h>
#include "localtime.h"
#include "scientist.h"

using namespace std;

namespace Ui
{
    class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
    Q_OBJECT

public:

    explicit AddStudentDialog(QWidget *parent = 0);

    ~AddStudentDialog();

private slots:

    void on_button_add_scientist_save_clicked();

    void on_button_add_scientist_cancel_clicked();

    void on_PushButton_browse_s_picture_clicked();

private:

    Ui::AddStudentDialog *ui;

    ScientistService _service;

    Scientist _scientist;

    bool ValidInput(string check, string allowed);

    string typeOf(string what);

    LocalTime _time;
};

#endif // ADDSTUDENTDIALOG_H
