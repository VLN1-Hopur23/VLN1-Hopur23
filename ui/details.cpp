#include "details.h"
#include "ui_details.h"

Details::Details(QWidget* parent, Scientist* pScientist, ScientistService* pService, ComputerService* pComputerService) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
    _scientist = *pScientist;

    ScientistDetails(pService, pComputerService);
}

Details::Details(QWidget* parent, Computer* pComputer, ScientistService* pService, ComputerService* pComputerService) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
    _computer = *pComputer;

    ComputerDetails(pService, pComputerService);
}

Details::~Details()
{
    delete ui;
}

void Details::ScientistDetails(ScientistService* pService, ComputerService* pComputerService)
{
    QStringList labels;
    labels << "Name" << "Gender" << "Year Of Birth" << "Year Of Death";

    ui->label_name->setText(QString::fromStdString("<h2>" + _scientist.getName() + "</h2>"));
    ui->first_detail->setText(QString::fromStdString("<b>Gender:</b> " + _scientist.getGender()));
    ui->second_detail->setText(QString::fromStdString("<b>Year Of Birth:</b> ") + QString::number(_scientist.getYearOfBirth()));
    ui->connect_table->setHorizontalHeaderLabels(labels);

    if (_scientist.getYearOfDeath())
    {
        ui->third_detail->setText(QString::fromStdString("<b>Year Of Death:</b> ") + QString::number(_scientist.getYearOfDeath()));
    }
    else
    {
        ui->third_detail->setText("<b>Alive and well (I think)</b>");
    }

    ui->fourth_detail->setText(QString::fromStdString("<b>Age:</b> ") + QString::number(_scientist.getAge()));

    pComputerService->retrieveIntersectScientist(QString::number(_scientist.getScientistID()));

    vector<Computer> computers = pComputerService->getComputerVector();

    displayAllComputers(computers);
}

void Details::ComputerDetails(ScientistService* pService, ComputerService* pComputerService)
{
    QStringList labels;
    labels << "Name" << "Year Built" << "Type" << "Was Built";

    ui->label_name->setText(QString::fromStdString("<h2>" + _computer.getName() + "</h2>"));
    ui->first_detail->setText(QString::fromStdString("<b>Year built:</b> ") + QString::number(_computer.getYearBuilt()));
    ui->second_detail->setText(QString::fromStdString("<b>Type:</b> " + _computer.getType()));
    ui->connect_table->setHorizontalHeaderLabels(labels);

    if (_computer.getBuilt())
    {
        ui->third_detail->setText(QString::fromStdString("<b>Existed:</b> Yes"));
    }
    else
    {
        ui->third_detail->setText(QString::fromStdString("<b>Existed:</b> No"));
    }

    ui->fourth_detail->setText("");

    pService->retrieveIntersectComputer(QString::number(_computer.getComputerID()));

    vector<Scientist> scientists = pService->getScientistVector();

    displayAllScientists(scientists);


}

// Displays table with all scientist
void Details::displayAllScientists(const vector<Scientist>& scientists)
{
    ui->connect_table->clearContents();
    ui->connect_table->setRowCount(scientists.size());

    qDebug() << "reached display";

    for(unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists[row];

        qDebug() << QString::fromStdString(currentScientist.getName());

        ui->connect_table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));
        ui->connect_table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(currentScientist.getGender())));
        ui->connect_table->setItem(row,2,new QTableWidgetItem(QString::number(currentScientist.getYearOfBirth())));
        ui->connect_table->setItem(row,3,new QTableWidgetItem(QString::number(currentScientist.getYearOfDeath())));
    }

    //currentlyDisplayedScientist = scientists;
}

// Displays table with all computers
void Details::displayAllComputers(const vector<Computer>& computers)
{
    ui->connect_table->clearContents();
    ui->connect_table->setRowCount(computers.size());

    for(unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        ui->connect_table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(currentComputer.getName())));
        ui->connect_table->setItem(row,1,new QTableWidgetItem(QString::number(currentComputer.getYearBuilt())));
        ui->connect_table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(currentComputer.getType())));
        ui->connect_table->setItem(row,3,new QTableWidgetItem(QString::number(currentComputer.getBuilt())));
    }
    //currentlyDisplayedComputers = computers;
}
