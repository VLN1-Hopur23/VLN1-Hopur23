#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
}

AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}

void AddComputerDialog::on_button_add_computer_add_computer_clicked()
{
    QString error = "<span style='color:red'>Not validated input<\\span>";
    QString name = ui->input_add_computer_name->text();
    QString buildingYear = ui->input_add_computer_building_year->text();
    QString typeOfComputer = ui->input_add_computer_type_of->text();

    bool InputIsNotValid = false;
    bool built =0;

    int buildingYearInt = buildingYear.toInt();

    ui->label_error_add_computer_building_year->setText("");
    ui->label_error_add_computer_built->setText("");
    ui->label_error_add_computer_name->setText("");
    ui->label_error_add_computer_type_of->setText("");

    if(name.isEmpty() || !(ValidInput(typeOf(name.toStdString()),"ACI_AC_AI_A")) )
    {
        ui->label_error_add_computer_name->setText(error);
        InputIsNotValid = true;
    }
    if(buildingYear.isEmpty() || !(ValidInput(typeOf(buildingYear.toStdString()),"I")) || buildingYearInt> _time.getYearToDay())
    {
        ui->label_error_add_computer_building_year->setText(error);
        InputIsNotValid = true;
    }
    if(typeOfComputer.isEmpty() || !(ValidInput(typeOf(typeOfComputer.toStdString()),"ACI_AC_AI_A")))
    {
        ui->label_error_add_computer_type_of->setText(error);
        InputIsNotValid = true;
    }
    if(!ui->button_radio_add_computer_yes->isChecked() && !ui->button_radio_add_computer_no->isChecked())
    {
        ui->label_error_add_computer_built->setText(error);
        InputIsNotValid = true;
    }
    else if(ui->button_radio_add_computer_yes)
    {
        built = 1; // true (default is 0 false)
    }

    if(InputIsNotValid)
    {
        return;
    }
    string nameString = name.toStdString();
    string typeOfComputerString = typeOfComputer.toStdString();
    Computer computer(_computers.getSize(), nameString, buildingYearInt, typeOfComputerString, built);
    int computerID;
    bool success = _computers.addComputer(computer, computerID);

    if(success)
    {
        ui->input_add_computer_building_year->setText("");
        ui->input_add_computer_name->setText("");
        ui->input_add_computer_type_of->setText("");

        this->done(1);  // 1 means successful
    }
    else
    {
        this->done(-1); //-1 means something went wrong
    }
}

void AddComputerDialog::on_button_add_computer_cancel_clicked()
{
    this->done(0);// 0 means cancel add computer
}


// typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I",
// includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
string AddComputerDialog::typeOf(string what)
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

bool AddComputerDialog::ValidInput(string check, string allowed)
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




