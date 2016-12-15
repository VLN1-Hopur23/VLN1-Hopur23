#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>
//#include ""
//#include ""
#include <iostream>

#include <QMessageBox>
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

    ui->input_keyword_s->setPlaceholderText("search scientists...");

    currentComputerSortColumn = "Name";

    ui->input_dropdown_sort_c->addItem("Name");
    ui->input_dropdown_sort_c->addItem("Year built");
    ui->input_dropdown_sort_c->addItem("Type");
    ui->input_dropdown_sort_c->addItem("Built");

    ui->input_keyword_c->setPlaceholderText("search computers...");

    getAllScientist();
    getAllComputers();


    ui->statusBar->showMessage("Booga! Booga!", 2000);
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

    return;
}

void MainWindow::getAllComputers()
{
    _computerservice.retrieveComputers("Name", "ASC");
    vector <Computer> computers = _computerservice.getComputerVector();
    displayAllComputers(computers);
    return;
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
void MainWindow::on_table_s_cellDoubleClicked(int row, int column)
{
    isDoubleClicked = true;
}


void MainWindow::on_table_s_cellChanged(int row, int column)
{
    if(isDoubleClicked)
    {
        isDoubleClicked = false;
        _service.retrieveScientists();
        vector <Scientist> scientists = _service.getScientistVector();
        Scientist oldScientist = scientists[row];

        int id =  oldScientist.getScientistID();

        QString error = "Not validated input";
        string toChange;
        string message;

        if(column == 0)
        {
            QString newName = ui->table_s->item(row, column)->text();
            if(newName.isEmpty()||!(ValidInput(typeOf(newName.toStdString()), "ACI_AC_AI_A")))
            {
                ui->table_s->setItem(row,column,new QTableWidgetItem(QString::fromStdString(oldScientist.getName())));
                QMessageBox::warning(this, "No changes were made", "Not allowed character used ");


            }
            else
            {
                toChange ="name";
                message = _service.editScientist(id,toChange,newName.toStdString());
                // change sql
            }
        }
        if(column == 1)
        {
            QString newGender = ui->table_s->item(row, column)->text();
            if(newGender.toStdString() == "f" || newGender.toStdString() == "m")
            {
                toChange ="gender";
                message = _service.editScientist(id,toChange,newGender.toStdString());
                // change sql
            }
            else
            {
                ui->table_s->setItem(row,column,new QTableWidgetItem(QString::fromStdString(oldScientist.getGender())));
                QMessageBox::warning(this, "No changes were made", "Not allowed character used ");
            }
        }
        if(column == 2)
        {
            QString newYearOfBirth = ui->table_s->item(row, column)->text();
            int newYearOfBirthInt = newYearOfBirth.toInt();
            //if(ui->table_s->item(row, 3)==0)
            if(newYearOfBirth.isEmpty() || !(ValidInput(typeOf(newYearOfBirth.toStdString()),"I")) || newYearOfBirthInt>_time.getYearToDay() || newYearOfBirthInt<0 || (ui->table_s->item(row, 3)->text().toInt() < newYearOfBirthInt && ui->table_s->item(row, 3)->text().toInt() != 0 ))
            {
                ui->table_s->setItem(oldScientist.getScientistID(),column,new QTableWidgetItem(QString::number(oldScientist.getYearOfBirth())));
                QMessageBox::warning(this, "No changes were made", "Not allowed character used ");
            }
            else
            {
                toChange = "birth";
                message = _service.editScientist(id,toChange,newYearOfBirth.toStdString());
                // change sql
            }
        }
        if( column == 3)
        {
            QString newYearOfDeath = ui->table_s->item(row, column)->text();
            int newYearOfDeathInt = newYearOfDeath.toInt();
            if(newYearOfDeathInt != 0 || newYearOfDeath.isEmpty() || !(ValidInput(typeOf(newYearOfDeath.toStdString()),"I")) || newYearOfDeathInt>_time.getYearToDay() || newYearOfDeathInt<0 || (ui->table_s->item(row, 2)->text().toInt()>newYearOfDeathInt && newYearOfDeathInt !=0))
            {
                ui->table_s->setItem(row,column,new QTableWidgetItem(QString::number(oldScientist.getYearOfDeath())));
                QMessageBox::warning(this, "No changes were made", "Not allowed character used ");
            }
            else
            {
                toChange = "death";
                message = _service.editScientist(id,toChange,newYearOfDeath.toStdString());
                // change SQL
            }
        }
        ui->statusBar->showMessage(QString::fromStdString(message), 4000);

        getAllScientist();
    }
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

//To search the list
void MainWindow::on_input_keyword_s_textChanged(const QString& arg1)
{
    string userInput = ui->input_keyword_s->text().toStdString();

    vector<Scientist> scientists = _service.searchingByFilter("Name", userInput);
    displayAllScientists(scientists);
}

//shortcut to add scientist with icon
void MainWindow::on_action_add_Scientist_triggered()
{
    on_button_add_scientist_clicked();
}

void MainWindow::on_action_add_Computer_triggered()
{
    on_button_add_computer_clicked();
}


// typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I",
// includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
string MainWindow::typeOf(string what)
{
    int whatSize = what.size();

    while(what.substr(whatSize-1, whatSize) == " ")
    {
        what = what.substr(0, whatSize-1);
        whatSize = what.size();
    }

    int* whatArrayInt = new int[whatSize] {};
    bool* whatIsInt = new bool[whatSize] {false};
    bool* whatIsAlphabet = new bool[whatSize] {false};
    bool* whatIsAlowedChar = new bool[whatSize] {false};
    bool* whatNotValidated = new bool[whatSize] {false};

    for(int i = 0; i < whatSize; i++)
    {
        whatArrayInt[i] = (int)what.substr(i, i+1)[0]; //[0] gives first character in string array that is char

    }

    for(int i = 0; i < whatSize; i++)
    {
        if(whatArrayInt[i] >= 48 && whatArrayInt[i] <= 57) //48 ='0' ...57 ='9'
        {
            whatIsInt[i] = true;
        }
        else if((whatArrayInt[i] >= 65 && whatArrayInt[i] <= 90) || (whatArrayInt[i] >= 97 && whatArrayInt[i] <= 122) || (whatArrayInt[i] == 32) )//65 = 'A', 90='Z', 97='a',122='z',32 =SPACE
        {
            whatIsAlphabet[i] = true;
        }
        else if(whatArrayInt[i] == 46 || whatArrayInt[i] == 44 ) // 46='.', 44 = ',',
        {
           whatIsAlowedChar[i] =true;
        }
        else
        {
            whatNotValidated[i] = true;
        }
    }

    bool ThereAreSomeCharNotValidated = false;
    bool ThereAreSomeInt = false;
    bool ThereAreSomeAlphabet = false;
    bool ThereAreSomeAlowedChar = false;

    for(int i = 0; i < whatSize; i++)
    {
        if(whatIsInt[i])
        {
            ThereAreSomeInt = true;
        }
        else if(whatIsAlphabet[i])
        {
            ThereAreSomeAlphabet = true;

        }
        else if(whatIsAlowedChar[i])
        {
            ThereAreSomeAlowedChar = true;
        }
        else
        {
            ThereAreSomeCharNotValidated = true;
        }
    }

    if(ThereAreSomeCharNotValidated)
    {
        return "NV"; //has: Not Validated input
    }
    else if(ThereAreSomeAlphabet && ThereAreSomeAlowedChar && ThereAreSomeInt)
    {
        return "ACI"; //has onlie: Alphabet, char, int
    }
    else if(ThereAreSomeAlowedChar && ThereAreSomeAlphabet)
    {
        return "AC"; //has onlie: Alphabet, char
    }
    else if(ThereAreSomeAlowedChar && ThereAreSomeInt)
    {
        return "CI"; //has onlie: char , int
    }
    else if(ThereAreSomeAlphabet && ThereAreSomeInt)
    {
        return "AI"; // has onlie: Alphabet, int
    }
    else if(ThereAreSomeAlphabet)
    {
        return "A"; // has onlie: Alphabet
    }
    else if(ThereAreSomeAlowedChar)
    {
        return "C"; // has onlie: char
    }
    else if(ThereAreSomeInt)
    {
        return "I"; // has onlie: int
    }
    else
    {
        return "error in localtime::typeOf(string what)";
    }
}
// Check can be "AI",AC",ACI","CI","I","C","A","NV" see ConsoleUI::typeOf() for mor info
// Allowed can be "A_AC.._I" see above
// Checks if input is allowed

bool MainWindow::ValidInput(string check, string allowed)
{
    if( check == "NV")
    {
        return false;
    }

    int count_ = 0;
    int* whereAre = new int[6]{};
    int allowedSize = allowed.size();
    string oneAllowedIntax;
    whereAre[count_] = -1;
    count_++;

    for(int i = 0; i < allowedSize; i++)
    {
        if(allowed[i] == '_')
        {
            whereAre[count_] = i;
            count_++;
        }
    }
    whereAre[count_] = allowedSize;

    for (int i = 0; i < count_; i++)
    {
        oneAllowedIntax = allowed.substr(whereAre[i]+1, whereAre[i+1] - whereAre[i]-1);
        if (check == oneAllowedIntax )
        {
            return true;
        }
    }
    return false;
}








