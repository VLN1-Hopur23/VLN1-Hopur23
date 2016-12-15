#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>

#include <QMessageBox>
#include <QMenu>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentScientistSortColumn = "Name";

    ui->input_dropdown_sort_s->addItem("Name");
    ui->input_dropdown_sort_s->addItem("Gender");
    ui->input_dropdown_sort_s->addItem("Birth");
    ui->input_dropdown_sort_s->addItem("Death");
    connect( this->ui->input_dropdown_sort_s, SIGNAL( activated(int) ), this, SLOT(on_input_keyword_s_textChanged()) );

    ui->input_keyword_s->setPlaceholderText("search scientists...");

    currentComputerSortColumn = "Name";

    ui->input_dropdown_sort_c->addItem("Name");
    ui->input_dropdown_sort_c->addItem("Year built");
    ui->input_dropdown_sort_c->addItem("Type");
    ui->input_dropdown_sort_c->addItem("Built");

    ui->input_keyword_c->setPlaceholderText("search computers...");

    getAllScientist();
    getAllComputers();

    //ui->statusBar->showMessage("Booga! Booga!", 2000);
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

void MainWindow::getAllScientist()
{
    _service.retrieveScientists();
    vector <Scientist> scientists = _service.getScientistVector();
    displayAllScientists(scientists);
}

void MainWindow::getAllComputers()
{
    _computerservice.retrieveComputers();
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

    vector<Computer> computers = _computerservice.searchingComputerByFilter("Name", userInput);
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
//custommenu for scientist table


//delete scientist button
void MainWindow::on_table_s_clicked(const QModelIndex &index)
{
   ui->button_delete_scientist->setEnabled(true);
}
//delete scientist with button on main window
void MainWindow::on_button_delete_scientist_clicked()
{
    int currentlySelectedScientistIndex = ui->table_s->currentIndex().row();

    Scientist currentlySelectedScientist = currentlyDisplayedScientist.at(currentlySelectedScientistIndex);

    int scientistID = currentlySelectedScientist.getScientistID();

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
//shortcut icon for delete scientist
void MainWindow::on_action_remove_scientist_triggered()
{
    on_button_delete_scientist_clicked();
}

void MainWindow::on_table_c_clicked(const QModelIndex &index)
{
   ui->button_delete_computer->setEnabled(true);
}

//delete computer with button on main window
void MainWindow::on_button_delete_computer_clicked()
{
    int currentlySelectedComptuerIndex = ui->table_c->currentIndex().row();

    Computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComptuerIndex);

    int computerID = currentlySelectedComputer.getComputerID();

    if (_computerservice.deleteComputer(computerID))
    {
        ui->input_keyword_c->setText("");
        getAllComputers();
        ui->button_delete_computer->setEnabled(false);
    }
    else
    {
        ui ->statusBar->showMessage("Computer not successfully removed",4000);
    }
}
//shortcut icon for delete computer
void MainWindow::on_action_remove_computer_triggered()
{
    on_button_delete_computer_clicked();
}

void MainWindow::on_action_details_triggered()
{
    //TODO DETAILS CONNECTION
}
void MainWindow::on_table_c_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "Right clicked menu requested on table";

    //ui->table_s->setItem(row,0,new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));

    QTableWidgetItem* computer = ui->table_c->itemAt(pos);

    QMenu* menu =new QMenu(this);
    menu->addAction(ui->action_remove_computer);
    menu->addAction(ui->action_details);
    menu->popup(ui->table_c->viewport()->mapFromGlobal(pos));

}

void MainWindow::on_table_s_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "Right clicked menu requested on table";

}



