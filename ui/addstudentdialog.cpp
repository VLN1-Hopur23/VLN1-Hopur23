#include "addstudentdialog.h"
#include "ui_addstudentdialog.h"
#include <QtGui>
#include <QtCore>

AddStudentDialog::AddStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/db_images/Images of scientists/unknown.jpg");
    ui->label_s_picture->setPixmap(pix);

    /*QPixmap pixmap(QString::fromStdString(_service.retrievePicUrl(_scientist.getScientistID())));
    ui->label_s_picture->setPixmap(pixmap);
    ui->label_s_picture->setScaledContents(true);*/
}

AddStudentDialog::~AddStudentDialog()
{
    delete ui;
}

void AddStudentDialog::on_button_add_scientist_save_clicked()
{
    QString error = "<span style='color: red'>Not validated input<\\span>";
    QString name = ui->input_add_scientist_name->text();
    QString yearBorn = ui->input_add_scientist_year_born->text();
    QString yearOfDeath = ui->input_add_scientist_year_of_death->text();

    bool InputIsNotValid = false;

    int yearOfBirthInt = yearBorn.toInt();
    int yearOfDeathInt = yearOfDeath.toInt();

    ui->label_error_add_scientist_name->setText("");
    ui->label_error_add_scientist_gender->setText("");
    ui->label_error_add_scientist_year_born->setText("");
    ui->label_error_add_scientist_year_of_death->setText("");

    if(name.isEmpty() || !(ValidInput(typeOf(name.toStdString()),"ACI_AC_AI_A")))
    {
        ui->label_error_add_scientist_name->setText(error);
        InputIsNotValid = true;
    }
    if(!ui->button_radio_add_scientist_femail->isChecked() && !ui->button_radio_add_scientist_male->isChecked())
    {
        ui->label_error_add_scientist_gender->setText(error);
        InputIsNotValid = true;
    }
    if(yearBorn.isEmpty() || !(ValidInput(typeOf(yearBorn.toStdString()),"I")) || yearOfBirthInt>_time.getYearToDay() || yearOfBirthInt<0 )
    {
        ui->label_error_add_scientist_year_born->setText(error);
        InputIsNotValid = true;
    }
    if(ui->button_radio_add_scientist_still_alive->isChecked())
    {
        yearOfDeathInt = 0;
        ui->input_add_scientist_year_of_death->setText("");
    }
    else if(yearOfDeath.isEmpty() || !(ValidInput(typeOf(yearOfDeath.toStdString()),"I")) || yearOfDeathInt>_time.getYearToDay() || yearOfDeathInt<0 || yearOfBirthInt>yearOfDeathInt)
    {
        ui->label_error_add_scientist_year_of_death->setText(error);
        InputIsNotValid = true;
    }
    if(InputIsNotValid)
    {
        return;
    }

    string gender;

    if(ui->button_radio_add_scientist_femail->isChecked())
    {
        gender = "f";
    }
    else
    {
        gender = "m";
    }

    string nameString = name.toStdString();
    Scientist scientist(_service.getSize(), nameString, gender, yearOfBirthInt, yearOfDeathInt);

    int scientistID;

    bool success = _service.addScientist(scientist, scientistID);

    if (success)
    {
        ui->input_add_scientist_name->setText("");
        ui->input_add_scientist_year_born->setText("");
        ui->input_add_scientist_year_of_death->setText("");

        this->done(1);// 1 means successful
    }
    else
    {
        this->done(-1); // -1 means something went wrong
    }
}

void AddStudentDialog::on_button_add_scientist_cancel_clicked()
{
    this->done(0); // 0 means canceled
}

// typeOf(command) gives back string if command =="A" it includes onli alphabetical char, c..="C" includes onlie allowed char(, .),c..="I",
// includes onlie integers, if c..="Nv" input not validated, if c..="AC" includes Alphabet and allowed char, command can also be "AI",AC",ACI","CI","I","C","A","NV"
string AddStudentDialog::typeOf(string what)
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
        whatArrayInt[i] = (int)what.substr(i, i+1)[0]; // [0] gives first character in string array that is char
    }

    for(int i = 0; i < whatSize; i++)
    {
        if(whatArrayInt[i] >= 48 && whatArrayInt[i] <= 57) // 48 ='0' ...57 ='9'
        {
            whatIsInt[i] = true;
        }
        else if((whatArrayInt[i] >= 65 && whatArrayInt[i] <= 90) || (whatArrayInt[i] >= 97 && whatArrayInt[i] <= 122) || (whatArrayInt[i] == 32) )//65 = 'A', 90='Z', 97='a',122='z',32 =SPACE
        {
            whatIsAlphabet[i] = true;
        }
        else if(whatArrayInt[i] == 46 || whatArrayInt[i] == 44 ) // 46 = '.', 44 = ',',
        {
           whatIsAlowedChar[i] = true;
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
        return "NV"; // has: Not Validated input
    }
    else if(ThereAreSomeAlphabet && ThereAreSomeAlowedChar && ThereAreSomeInt)
    {
        return "ACI"; // has only: Alphabet, char, int
    }
    else if(ThereAreSomeAlowedChar && ThereAreSomeAlphabet)
    {
        return "AC"; // has only: Alphabet, char
    }
    else if(ThereAreSomeAlowedChar && ThereAreSomeInt)
    {
        return "CI"; // has only: char , int
    }
    else if(ThereAreSomeAlphabet && ThereAreSomeInt)
    {
        return "AI"; // has only: Alphabet, int
    }
    else if(ThereAreSomeAlphabet)
    {
        return "A"; // has only: Alphabet
    }
    else if(ThereAreSomeAlowedChar)
    {
        return "C"; // has only: char
    }
    else if(ThereAreSomeInt)
    {
        return "I"; // has only: int
    }
    else
    {
        return "error in localtime::typeOf(string what)";
    }
}
// Check can be "AI",AC",ACI","CI","I","C","A","NV" see ConsoleUI::typeOf() for mor info
// Allowed can be "A_AC.._I" see above
// Checks if input is allowed

bool AddStudentDialog::ValidInput(string check, string allowed)
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

void AddStudentDialog::on_PushButton_browse_s_picture_clicked()
{
    // ScierntistID will map the right picture url in connection table
    // We need to get the url from the table with the scientist ID

    string url = ""; //":/db_images/Images of scientists/unknown.jpeg";
    string filePath = QFileDialog::getOpenFileName(
                this,
                "Search for image",
                "",
                "Image files(*.png *.jpg)"
                ).toStdString();
    if(filePath.length())
    {
        // user select som file
        QPixmap pixmap(QString::fromStdString(filePath));
        ui->label_s_picture->setPixmap(pixmap);
        ui->label_s_picture->setScaledContents(true);
        // add the url to database
        _service.addPicUrl(_scientist.getScientistID(),filePath);

    }
    else
    {
        filePath = _service.retrievePicUrl(_scientist.getScientistID());
        QPixmap pixmap(QString::fromStdString(filePath));
        ui->label_s_picture->setPixmap(pixmap);
        ui->label_s_picture->setScaledContents(true);
        //didnt select file
        //So we set the default
    }
}
