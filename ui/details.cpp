#include "details.h"
#include "ui_details.h"

Details::Details(QWidget* parent, Scientist* scientist) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
    _scientist = *scientist;

    ScientistDetails();
}

Details::Details(QWidget* parent, Computer* computer) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
    _computer = *computer;

    ComputerDetails();
}

Details::~Details()
{
    delete ui;
}

void Details::ScientistDetails()
{
    ui->label_name->setText(QString::fromStdString("<h2>" + _scientist.getName() + "</h2>"));
    ui->first_detail->setText(QString::fromStdString("<b>Gender:</b> " + _scientist.getGender()));
    ui->second_detail->setText(QString::fromStdString("<b>Year Of Birth:</b> ") + QString::number(_scientist.getYearOfBirth()));

    if (_scientist.getYearOfDeath())
    {
        ui->third_detail->setText(QString::fromStdString("<b>Year Of Death:</b> ") + QString::number(_scientist.getYearOfDeath()));
    }
    else
    {
        ui->third_detail->setText("<b>Alive and well (I think)</b>");
    }

    ui->fourth_detail->setText(QString::fromStdString("<b>Age:</b> ") + QString::number(_scientist.getAge()));
}

void Details::ComputerDetails()
{
    ui->label_name->setText(QString::fromStdString("<h2>" + _computer.getName() + "</h2>"));
    ui->first_detail->setText(QString::fromStdString("<b>Year built:</b> ") + QString::number(_computer.getYearBuilt()));
    ui->second_detail->setText(QString::fromStdString("<b>Type:</b> " + _computer.getType()));
    if (_computer.getBuilt())
    {
        ui->third_detail->setText(QString::fromStdString("<b>Existed:</b> Yes"));
    }
    else
    {
        ui->third_detail->setText(QString::fromStdString("<b>Existed:</b> No"));
    }

    ui->fourth_detail->setText("");
}
