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
    ui->table_s->setColumnHidden(4, true);
    ui->table_c->setColumnHidden(4,true);

    // From scientist tabs
    currentScientistSortColumn = "Name";

    ui->input_dropdown_sort_s->addItem("Name");
    ui->input_dropdown_sort_s->addItem("Gender");
    ui->input_dropdown_sort_s->addItem("Birth");
    ui->input_dropdown_sort_s->addItem("Death");
    ui->input_dropdown_sort_s->addItem("Life");
    connect(this->ui->input_dropdown_sort_s, SIGNAL(activated(int)), this, SLOT(on_input_keyword_s_textChanged()));

    ui->input_keyword_s->setPlaceholderText("Search scientists...");

    // From computer tabs
    currentComputerSortColumn = "Name";

    ui->input_dropdown_sort_c->addItem("Name");
    ui->input_dropdown_sort_c->addItem("Year built");
    ui->input_dropdown_sort_c->addItem("Type");
    ui->input_dropdown_sort_c->addItem("Built");
    ui->input_dropdown_sort_c->addItem("Life");
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

// Displays table with all scientist
void MainWindow::displayAllScientists(const vector<Scientist>& scientists)
{
    ui->table_s->clearContents();
    ui->table_s->setRowCount(scientists.size());
    ui->table_s->setSortingEnabled(false);

    for(unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists[row];

        ui->table_s->setItem(row,0,new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));
        ui->table_s->setItem(row,1,new QTableWidgetItem(QString::fromStdString(currentScientist.getGender())));
        ui->table_s->setItem(row,2,new QTableWidgetItem(QString::number(currentScientist.getYearOfBirth())));
        ui->table_s->setItem(row,3,new QTableWidgetItem(QString::number(currentScientist.getYearOfDeath())));
        ui->table_s->setItem(row,4,new QTableWidgetItem(QString::number(currentScientist.getScientistID())));

    }
    currentlyDisplayedScientist = scientists;
    ui->table_s->setSortingEnabled(true);
}

// Displays table with all computers
void MainWindow::displayAllComputers(const vector<Computer>& computers)
{
    ui->table_c->clearContents();
    ui->table_c->setRowCount(computers.size());
    ui->table_c->setSortingEnabled(false);

    for(unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        ui->table_c->setItem(row,0,new QTableWidgetItem(QString::fromStdString(currentComputer.getName())));
        ui->table_c->setItem(row,1,new QTableWidgetItem(QString::number(currentComputer.getYearBuilt())));
        ui->table_c->setItem(row,2,new QTableWidgetItem(QString::fromStdString(currentComputer.getType())));
        ui->table_c->setItem(row,3,new QTableWidgetItem(QString::number(currentComputer.getBuilt())));
        ui->table_c->setItem(row,4,new QTableWidgetItem(QString::number(currentComputer.getComputerID())));
    }
    currentlyDisplayedComputers = computers;
    ui->table_c->setSortingEnabled(true);
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
        case 4:
        {

            break;
        }
    }

    displayAllScientists(scientists);

    return;
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
    return;
}

// Shortcut to add scientist with icon
void MainWindow::on_action_add_Scientist_triggered()
{
    on_button_add_scientist_clicked();
}



void MainWindow::on_table_s_cellDoubleClicked(int row, int column)
{
    isDoubleClickedScientist = true;
}


void MainWindow::on_table_s_cellChanged(int row, int column)
{
    if(isDoubleClickedScientist)
    {
        isDoubleClickedScientist = false;
        _service.retrieveScientists();
        vector <Scientist> scientists = _service.getScientistVector();
        Scientist oldScientist = scientists[row];

        int id =  oldScientist.getScientistID();

        QString error = "Not validated input";
        QString warningTitle = "No changes were made";
        QString warningMessage = "please use valid input";
        string toChange;
        string message;
        int reply;

        if(column == 0)
        {
            QString newName = ui->table_s->item(row, column)->text();
            if(newName.isEmpty()||!(ValidInput(typeOf(newName.toStdString()), "ACI_AC_AI_A")))
            {
                ui->table_s->setItem(row,column,new QTableWidgetItem(QString::fromStdString(oldScientist.getName())));
                QMessageBox::warning(this, warningTitle, warningMessage);


            }
            else
            {
                toChange ="name";
                QString questionM = "Do you want to change >> "+QString::fromStdString(oldScientist.getName())+" << TO >> "+newName+" <<";
                reply = QMessageBox::question(this, "Edit?", questionM, QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    message = _service.editScientist(id,toChange,newName.toStdString());
                }
                else
                {
                    ui->table_s->setItem(row,column,new QTableWidgetItem(QString::fromStdString(oldScientist.getName())));
                }
            }
        }
        if(column == 1)
        {
            QString newGender = ui->table_s->item(row, column)->text();
            if(newGender.toStdString() == "f" || newGender.toStdString() == "m")
            {
                toChange ="gender";
                QString questionM = "Do you want to change >> "+QString::fromStdString(oldScientist.getGender())+" << TO >> "+newGender+" <<";
                reply = QMessageBox::question(this, "Edit?", questionM, QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    message = _service.editScientist(id,toChange,newGender.toStdString());
                }
                else
                {
                    ui->table_s->setItem(row,column,new QTableWidgetItem(QString::fromStdString(oldScientist.getGender())));
                }
            }
            else
            {
                ui->table_s->setItem(row,column,new QTableWidgetItem(QString::fromStdString(oldScientist.getGender())));
                QMessageBox::warning(this, warningTitle, warningMessage);
            }
        }
        if(column == 2)
        {
            QString newYearOfBirth = ui->table_s->item(row, column)->text();
            int newYearOfBirthInt = newYearOfBirth.toInt();
            if(newYearOfBirth.isEmpty() || !(ValidInput(typeOf(newYearOfBirth.toStdString()),"I")) || newYearOfBirthInt>_time.getYearToDay() || newYearOfBirthInt<0 || (ui->table_s->item(row, 3)->text().toInt() < newYearOfBirthInt && ui->table_s->item(row, 3)->text().toInt() != 0 ))
            {
                ui->table_s->setItem(row,column,new QTableWidgetItem(QString::number(oldScientist.getYearOfBirth())));
                QMessageBox::warning(this, warningTitle, warningMessage);
            }
            else
            {
                toChange = "birth";
                QString questionM = "Do you want to change >> "+QString::number(oldScientist.getYearOfBirth())+" << TO >> "+newYearOfBirth+" <<";
                reply = QMessageBox::question(this, "Edit?", questionM, QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    message = _service.editScientist(id,toChange,newYearOfBirth.toStdString());
                }
                else
                {
                    ui->table_s->setItem(row,column,new QTableWidgetItem(QString::number(oldScientist.getYearOfBirth())));
                }
            }
        }
        if( column == 3)
        {
            QString newYearOfDeath = ui->table_s->item(row, column)->text();
            int newYearOfDeathInt = newYearOfDeath.toInt();
            if( newYearOfDeath.isEmpty() || !(ValidInput(typeOf(newYearOfDeath.toStdString()),"I")) || newYearOfDeathInt>_time.getYearToDay() || newYearOfDeathInt<0 || (ui->table_s->item(row, 2)->text().toInt()>newYearOfDeathInt && newYearOfDeathInt !=0))
            {
                ui->table_s->setItem(row,column,new QTableWidgetItem(QString::number(oldScientist.getYearOfDeath())));
                QMessageBox::warning(this, warningTitle, warningMessage);
            }
            else
            {
                toChange = "death";
                QString questionM = "Do you want to change >> "+QString::number(oldScientist.getYearOfDeath())+" << TO >> "+newYearOfDeath+" <<";
                reply = QMessageBox::question(this, "Edit?", questionM, QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                   message = _service.editScientist(id,toChange,newYearOfDeath.toStdString());
                }
                else
                {
                    ui->table_s->setItem(row,column,new QTableWidgetItem(QString::number(oldScientist.getYearOfDeath())));
                }
            }
        }
        ui->statusBar->showMessage(QString::fromStdString(message), 4000);

        getAllScientist();
    }
}



// Shortcut to add computer with icon
void MainWindow::on_action_add_Computer_triggered()
{
    on_button_add_computer_clicked();
}

void MainWindow::on_table_c_cellDoubleClicked(int row, int column)
{
    isDoubleClickedComputer = true;
}

void MainWindow::on_table_c_cellChanged(int row, int column)
{
    if(isDoubleClickedComputer)
    {
        isDoubleClickedComputer = false;
        _computerservice.retrieveComputers();
        vector <Computer> computers = _computerservice.getComputerVector();
        Computer oldComputer = computers[row];

        int id = oldComputer.getComputerID();
        int reply;

        QString error = "Not validated input";
        string toChange;
        string message;

        if(column ==0)
        {
            QString newName = ui->table_c->item(row, column)->text();
            if(newName.isEmpty()||!(ValidInput(typeOf(newName.toStdString()), "ACI_AC_AI_A")))
            {
                ui->table_c->setItem(row,column, new QTableWidgetItem(QString::fromStdString(oldComputer.getName())));
                QMessageBox::warning(this, "No changes were made", "Not allowed character used ");
            }
            else
            {
                toChange ="name";
                QString questionM = "Do you want to change >> "+QString::fromStdString(oldComputer.getName())+" << TO >> "+newName+" <<";
                reply = QMessageBox::question(this, "Edit?", questionM, QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                     message = _computerservice.editComputer(id,toChange,newName.toStdString());
                }
                else
                {
                    ui->table_c->setItem(row,column, new QTableWidgetItem(QString::fromStdString(oldComputer.getName())));
                }
            }
        }
        if(column == 1)
        {
            QString newYearBuilt = ui->table_c->item(row, column)->text();
            int newYearBuiltInt = newYearBuilt.toInt();
            if(newYearBuilt.isEmpty() || !(ValidInput(typeOf(newYearBuilt.toStdString()),"I")) || newYearBuiltInt>_time.getYearToDay() || newYearBuiltInt<0 )
            {
                ui->table_c->setItem(row,column, new QTableWidgetItem(QString::number(oldComputer.getYearBuilt())));
                QMessageBox::warning(this, "No changes were made", "Not allowed character used ");
            }
            else
            {
                toChange = "yearbuilt";
                QString questionM = "Do you want to change >> "+QString::number(oldComputer.getYearBuilt())+" << TO >> "+newYearBuilt+" <<";
                reply = QMessageBox::question(this, "Edit?", questionM, QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    message = _computerservice.editComputer(id, toChange, newYearBuilt.toStdString());
                }
                else
                {
                    ui->table_c->setItem(row,column, new QTableWidgetItem(QString::number(oldComputer.getYearBuilt())));
                }
            }

        }
        if(column == 2)
        {
            QString newType = ui->table_c->item(row, column)->text();
            if(newType.isEmpty() || !(ValidInput(typeOf(newType.toStdString()), "ACI_AC_AI_A")))
            {
                ui->table_c->setItem(row, column, new QTableWidgetItem(QString::fromStdString(oldComputer.getType())));
                QMessageBox::warning(this, "No changes were made", "Not allowed character used ");
            }
            else
            {
                toChange = "type";
                QString questionM = "Do you want to change >> "+QString::fromStdString(oldComputer.getType())+" << TO >> "+newType+" <<";
                reply = QMessageBox::question(this, "Edit?", questionM, QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    message = _computerservice.editComputer(id, toChange, newType.toStdString());
                }
                else
                {
                    ui->table_c->setItem(row, column, new QTableWidgetItem(QString::fromStdString(oldComputer.getType())));
                }
            }
        }

        if(column == 3)
        {
            QString newBuilt = ui->table_c->item(row, column)->text();
            //int newBuiltInt = newBuilt.toInt();
            if(newBuilt == "1" || newBuilt =="0")
            {
               toChange ="built";
               QString questionM = "Do you want to change >> "+QString::number(oldComputer.getBuilt())+" << TO >> "+newBuilt+" <<";
               reply = QMessageBox::question(this, "Edit?", questionM, QMessageBox::Yes | QMessageBox::No);
               if(reply == QMessageBox::Yes)
               {
                   message = _computerservice.editComputer(id,toChange, newBuilt.toStdString());
               }
               else
               {
                   ui->table_c->setItem(row, column, new QTableWidgetItem(QString::number(oldComputer.getBuilt())));
               }
            }
            else
            {
                ui->table_c->setItem(row, column, new QTableWidgetItem(QString::number(oldComputer.getBuilt())));
                QMessageBox::warning(this, "No changes were made", "Not allowed character used ");
            }

        }
        ui->statusBar->showMessage(QString::fromStdString(message), 4000);
    }
}


// Delete scientist button
void MainWindow::on_table_s_clicked()
{
   ui->button_delete_scientist->setEnabled(true);
}
//delete scientist with button on main window
void MainWindow::on_button_delete_scientist_clicked()
{
    int currentlySelectedScientistIndex = ui->table_s->currentIndex().row();

    Scientist currentlySelectedScientist = currentlyDisplayedScientist.at(currentlySelectedScientistIndex);

    int scientistID = ui->table_s->item(currentlySelectedScientistIndex, 4)->text().toInt();

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
//shortcut icon for delete scientist
void MainWindow::on_action_remove_scientist_triggered()
{
    on_button_delete_scientist_clicked();
}

// Delete computer button
void MainWindow::on_table_c_clicked()
{
   ui->button_delete_computer->setEnabled(true);
}

//delete computer with button on main window
void MainWindow::on_button_delete_computer_clicked()
{
    int currentlySelectedComptuerIndex = ui->table_c->currentIndex().row();

    Computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComptuerIndex);

    int computerID = ui->table_c->item(currentlySelectedComptuerIndex, 4)->text().toInt();

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
//shortcut icon for delete computer
void MainWindow::on_action_remove_computer_triggered()
{
    on_button_delete_computer_clicked();
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
        else if(whatArrayInt[i] == 46 || whatArrayInt[i] == 44 || whatArrayInt[i] == 45 ) // 46='.', 44 = ',', 45 = '-'
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

void MainWindow::on_table_c_customContextMenuRequested()
{
    QMenu* menu =new QMenu(this);
    menu->addAction(ui->action_remove_computer);
    menu->addAction(ui->action_details_c);
    menu->exec(QCursor::pos());

}

void MainWindow::on_table_s_customContextMenuRequested()
{
    QMenu* menu =new QMenu(this);
    menu->addAction(ui->action_remove_scientist);
    menu->addAction(ui->action_details_s);
    menu->exec(QCursor::pos());
}

void MainWindow::on_action_details_s_triggered()
{
    int currentlySelectedScientistIndex = ui->table_s->currentIndex().row();

    Scientist currentlySelectedScientist = currentlyDisplayedScientist.at(currentlySelectedScientistIndex);

    Details details(0, &currentlySelectedScientist, &_service, &_computerservice);

    details.exec();
}

void MainWindow::on_action_details_c_triggered()
{
    int currentlySelectedComputerIndex = ui->table_c->currentIndex().row();

    Computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);

    Details details(0, &currentlySelectedComputer, &_service, &_computerservice);

    details.exec();
}
