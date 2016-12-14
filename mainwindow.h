#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scientistservice.h"
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
<<<<<<< HEAD
    void on_button_add_scientist_clicked();

    void on_input_keyword_s_textChanged(const QString &arg1);
=======

    void on_button_add_scientist_clicked();
>>>>>>> e40c00521b23cd2bf993da0691eb172a29041d4f

private:

    void getAllScientist();
    void displayAllScientists(const vector<Scientist>& scientists);

    Ui::MainWindow *ui;

<<<<<<< HEAD


=======
>>>>>>> e40c00521b23cd2bf993da0691eb172a29041d4f
    ScientistService _service;

    QString currentScientistSortColumn;
    QString currentComputerSortColumn;

    QLabel* statusBarMessage;

    vector <Scientist> currentlyDisplayedScientist;
};

#endif // MAINWINDOW_H
