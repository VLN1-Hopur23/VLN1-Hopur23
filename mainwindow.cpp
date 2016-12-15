#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //From scientist tabs
    currentScientistSortColumn = "Name";

    ui->input_dropdown_sort_s->addItem("Name");
    ui->input_dropdown_sort_s->addItem("Gender");
    ui->input_dropdown_sort_s->addItem("Birth");
    ui->input_dropdown_sort_s->addItem("Death");
    connect(this->ui->input_dropdown_sort_s, SIGNAL(activated(int)), this, SLOT(on_input_keyword_s_textChanged()));

    ui->input_keyword_s->setPlaceholderText("Search scientists...");

    //From computer tabs
    currentComputerSortColumn = "Name";

    ui->input_dropdown_sort_c->addItem("Name");
    ui->input_dropdown_sort_c->addItem("Year built");
    ui->input_dropdown_sort_c->addItem("Type");
    ui->input_dropdown_sort_c->addItem("Built");
    connect( this->ui->input_dropdown_sort_c, SIGNAL( activated(int) ), this, SLOT(on_input_keyword_c_textChanged()) );

    ui->input_keyword_c->setPlaceholderText("Search computers...");

    getAllScientist();
    getAllComputers();

    ui->statusBar->showMessage("Booga! Booga!", 2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Gets all colums from table scientists from database
void MainWindow::getAllScientist()
{
    _service.retrieveScientists();
    vector <Scientist> scientists = _service.getScientistVector();
    displayAllScientists(scientists);
}

// Gets all colums from table computers from database
void MainWindow::getAllComputers()
{
    _computerservice.retrieveComputers();
    vector <Computer> computers = _computerservice.getComputerVector();
    displayAllComputers(computers);
}

//Displays table with all scientist
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

//Displays table with all computers
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

// To Add scientist to database
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

// To Add comptuer to database
void MainWindow::on_button_add_computer_clicked()
{
    AddComputerDialog addcomputerdialog;
    int addComputerReturnValue = addcomputerdialog.exec();

    ui->statusBar->showMessage("humm",4000);

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
    getAllComputers();
}

// To search the list for scientist
void MainWindow::on_input_keyword_s_textChanged()
{
    string userInput = ui->input_keyword_s->text().toStdString();
    vector<Scientist> scientists;

    switch(this->ui->input_dropdown_sort_s->currentIndex())
    {
        case 0:
        {
            scientists = _service.searchingByFilter("Name", userInput);
            break;
        }
        case 1:
        {
            scientists = _service.searchingByFilter("Gender", userInput);
            break;
        }
        case 2:
        {
            scientists = _service.searchingByFilter("Birthyear", userInput);
            break;
        }
        case 3:
        {
            scientists = _service.searchingByFilter("Deathyear", userInput);
            break;
        }
    }
    displayAllScientists(scientists);
}

// To search the list for computers
void MainWindow::on_input_keyword_c_textChanged()
{
    string userInput = ui->input_keyword_c->text().toStdString();
    vector<Computer> computers;
    switch(this->ui->input_dropdown_sort_c->currentIndex())
    {
        case 0:
        {
            computers = _computerservice.searchingComputerByFilter("Name", userInput);
            break;
        }
        case 1:
        {
            computers = _computerservice.searchingComputerByFilter("YearBuilt", userInput);
            break;
        }
        case 2:
        {
            computers = _computerservice.searchingComputerByFilter("Type", userInput);
            break;
        }
        case 3:
        {
            computers = _computerservice.searchingComputerByFilter("Built", userInput);
            break;
        }
    }
    displayAllComputers(computers);
}

// Shortcut to add scientist with icon
void MainWindow::on_action_add_Scientist_triggered()
{
    on_button_add_scientist_clicked();
}

// Shortcut to add computer with icon
void MainWindow::on_action_add_Computer_triggered()
{
    on_button_add_computer_clicked();
}

// Delete scientist button
void MainWindow::on_table_s_clicked()
{
   ui->button_delete_scientist->setEnabled(true);
}

void MainWindow::on_button_delete_scientist_clicked()
{
    int currentlySelectedScientistIndex = ui->table_s->currentIndex().row();

    Scientist currentlySelectedScientist = currentlyDisplayedScientist.at(currentlySelectedScientistIndex);

    int scientistID = currentlySelectedScientist.getScientistID();

    QMessageBox::StandardButton sure;
    sure = QMessageBox::question(this, "Delete", "Are you sure you want to delete a known scientist?", QMessageBox::No|QMessageBox::Yes);
    if(sure == QMessageBox::Yes)
    {
        if (_service.deleteScientist(scientistID))
        {
            ui -> input_keyword_s->setText("");
            getAllScientist();
            ui->button_delete_scientist->setEnabled(false);
        }
        else
        {
            ui ->statusBar->showMessage("scientist not successfully removed",4000);
        }
    }
}

void MainWindow::on_action_remove_scientist_triggered()
{
    on_button_delete_scientist_clicked();
}

// Delete computer button
void MainWindow::on_table_c_clicked()
{
   ui->button_delete_computer->setEnabled(true);
}

void MainWindow::on_button_delete_computer_clicked()
{
    int currentlySelectedComptuerIndex = ui->table_c->currentIndex().row();

    Computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComptuerIndex);

    int computerID = currentlySelectedComputer.getComputerID();

    QMessageBox::StandardButton sure;
    sure = QMessageBox::question(this, "Delete", "Are you sure you want to delete a known computer?", QMessageBox::No|QMessageBox::Yes);
    if(sure == QMessageBox::Yes)
    {
        if (_computerservice.deleteComputer(computerID))
        {
            ui->input_keyword_c->setText("");
            getAllComputers();
            ui->button_delete_computer->setEnabled(false);
        }
        else
        {
            ui->statusBar->showMessage("Computer not successfully removed",4000);
        }
    }
}

void MainWindow::on_action_remove_computer_triggered()
{
    on_button_delete_computer_clicked();
}
