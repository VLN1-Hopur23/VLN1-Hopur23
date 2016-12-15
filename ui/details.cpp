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
    on_label_name_linkActivated();
}

void Details::ComputerDetails()
{
    on_label_name_linkActivated();
}

void Details::on_label_name_linkActivated()
{
    ui->label_name->setText(QString::fromStdString(_scientist.getName()));
}

void Details::on_button_browse_image_clicked()
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
    }
    else
    {
        //didnt select file
    }
}
