#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>
//#include ""
//#include ""

#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStatusBar *statusBar = this->statusBar();
    ui->statusBar->showMessage("Scientist successfully added", 4000);

    currentScientistSortColumn = "Name";

    statusBarMessage = new QLabel();
    ui->statusBar->addPermanentWidget(statusBarMessage,1);

    ui->input_dropdown_sort_s->addItem("Name");
    ui->input_dropdown_sort_s->addItem("Gender");
    ui->input_dropdown_sort_s->addItem("Birth");
    ui->input_dropdown_sort_s->addItem("Death");

    ui->input_keyword_s->setPlaceholderText("search scientists...");

    currentComputerSortColumn = "Name";

    ui->statusBar->addPermanentWidget(statusBarMessage,1);

    ui->input_dropdown_sort_c->addItem("Name");
    ui->input_dropdown_sort_c->addItem("Year built");
    ui->input_dropdown_sort_c->addItem("Type");
    ui->input_dropdown_sort_c->addItem("Built");

    ui->input_keyword_c->setPlaceholderText("search computers...");

    getAllScientist();
    getAllComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_add_scientist_clicked()
{
    AddStudentDialog addstudentdialog;
    int addStudentReturnValue = addstudentdialog.exec();

    if(addStudentReturnValue == 1)
    {
        ui->statusBar->showMessage("Scientist successfully added", 4000);

    }
    else if(addStudentReturnValue == 0)
    {
        ui->statusBar->showMessage("Scientist added was canceled", 4000);
    }
    else
    {
        ui->statusBar->showMessage("Something went wery wery wrong", 4000);
    }

    getAllScientist();
}

void MainWindow::on_button_add_computer_clicked()
{
    AddComputerDialog addcomputerdialog;
    int addComputerReturnValue = addcomputerdialog.exec();

    if(addComputerReturnValue == 1)
    {
        ui->statusBar->showMessage("Computer successfully added", 4000);

    }
    else if(addComputerReturnValue == 0)
    {
        ui->statusBar->showMessage("Computer added was canceled", 4000);
    }
    else
    {
        ui->statusBar->showMessage("Something went wery wery wrong", 4000);
    }

}

void MainWindow::getAllScientist()
{
    _service.retrieveScientists();
    vector <Scientist> scientists = _service.getScientistVector();
    displayAllScientists(scientists);
}

void MainWindow::getAllComputers()
{
    _computerservice.retrieveComputers("Name", "ASC");
    vector <Computer> computers = _computerservice.getComputerVector();
    displayAllComputers(computers);
}


void MainWindow::displayAllScientists(const vector<Scientist>& scientists)
{
    ui->table_s->clearContents();
    ui->table_s->setRowCount(scientists.size());

    for(unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists[row];

        ui->table_s->setItem(row,0,new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));
        ui->table_s->setItem(row,1,new QTableWidgetItem(QString::fromStdString(currentScientist.getGender())));
        ui->table_s->setItem(row,2,new QTableWidgetItem(QString::number(currentScientist.getYearOfBirth())));
        ui->table_s->setItem(row,3,new QTableWidgetItem(QString::number(currentScientist.getYearOfDeath())));
    }

    currentlyDisplayedScientist = scientists;

}

void MainWindow::displayAllComputers(const vector<Computer>& computers)
{
    ui->table_c->clearContents();
    ui->table_c->setRowCount(computers.size());

    for(unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        ui->table_c->setItem(row,0,new QTableWidgetItem(QString::fromStdString(currentComputer.getName())));
        ui->table_c->setItem(row,1,new QTableWidgetItem(QString::number(currentComputer.getYearBuilt())));
        ui->table_c->setItem(row,2,new QTableWidgetItem(QString::fromStdString(currentComputer.getType())));
        ui->table_c->setItem(row,3,new QTableWidgetItem(QString::number(currentComputer.getBuilt())));
    }

    currentlyDisplayedComputers = computers;
}


void MainWindow::on_input_keyword_s_textChanged(const QString& arg1)
{
    string userInput = ui->input_keyword_s->text().toStdString();

    vector<Scientist> scientists = _service.searchingByFilter("Name", userInput);
    displayAllScientists(scientists);
}


