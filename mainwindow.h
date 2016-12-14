#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "scientistservice.h"

#include <QMainWindow>
#include <QLabel>

using namespace std;

namespace Ui {
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



private:
    void getAllScientist();
    void displayAllScientists();

    Ui::MainWindow *ui;

    ScientistService _service;

    QString currentScientistSortColumn;
    QString currentComputerSortColumn;

    QLabel* statusBarMessage;

    vector <Scientist> currentScientist;
    vector <Scientist> currentlyDisplayedScientist;

};

#endif // MAINWINDOW_H
