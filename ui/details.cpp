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
    ui->fourth_detail->setText(QString::fromStdString("<b>Age:</b> ") + QString::number(_scientist.getAge()));
}

void Details::ComputerDetails()
{

}

void Details::on_browse_scientist_photo_clicked()
{
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
        ui->label_image->setPixmap(pixmap);
    }
    else
    {
        //didnt select file
    }
}
