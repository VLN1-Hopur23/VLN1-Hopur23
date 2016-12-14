#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scientistservice.h"
#include "computerservice.h"
#include <QMainWindow>
#include "addstudentdialog.h"
#include <QLabel>
#include <vector>

using namespace std;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_button_add_scientist_clicked();

    void on_input_keyword_s_textChanged(const QString &arg1);

private:

    void getAllScientist();
    void displayAllScientists(const vector<Scientist>& scientists);
    void displayAllComputers(const vector<Computer>& computers);

    Ui::MainWindow *ui;

    ScientistService _service;
    ComputerService _computerservice;

    QString currentScientistSortColumn;
    QString currentComputerSortColumn;

    QLabel* statusBarMessage;

    vector <Scientist> currentlyDisplayedScientist;
    vector <Computer> currentlyDisplayedComputers;
};

#endif // MAINWINDOW_H
