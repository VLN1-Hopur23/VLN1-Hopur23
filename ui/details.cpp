#include "details.h"
#include "ui_details.h"

Details::Details(QWidget* parent, Scientist* pScientist, ScientistService* pService, ComputerService* pComputerService) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);

    ui->statusBar->showMessage("This guy!", 2000);

    _scientist = *pScientist;
    _pService = pService;
    _pComputerService = pComputerService;
    _active = 1;

    ScientistDetails();
}

Details::Details(QWidget* parent, Computer* pComputer, ScientistService* pService, ComputerService* pComputerService) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);

    _computer = *pComputer;
    _pService = pService;
    _pComputerService = pComputerService;
    _active = 2;

    ComputerDetails();
}

Details::~Details()
{
    delete ui;
}

void Details::ScientistDetails()
{
    QStringList labels;
    labels << "Name" << "Year Built" << "Type" << "Was Built";

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

    displayComputers();
}

void Details::ComputerDetails()
{
    QStringList labels;
    labels << "Name" << "Gender" << "Year Of Birth" << "Year Of Death";

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

    displayScientists();
}

void Details::displayComputers()
{
    _pComputerService->retrieveIntersectScientist(QString::number(_scientist.getScientistID()));

    vector<Computer> computers = _pComputerService->getComputerVector();

    displayAllComputers(computers);
}

void Details::displayScientists()
{
    _pService->retrieveIntersectComputer(QString::number(_computer.getComputerID()));

    vector<Scientist> scientists = _pService->getScientistVector();

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

    _currentlyDisplayedScientists = scientists;
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
    _currentlyDisplayedComputers = computers;
}

void Details::on_connect_table_customContextMenuRequested()
{
    QMenu* menu = new QMenu(this);
    menu->addAction(ui->action_remove_connection);
    menu->addAction(ui->action_add_connection);
    menu->exec(QCursor::pos());
}

void Details::on_action_remove_connection_triggered()
{
    int currentlySelectedIndex = ui->connect_table->currentIndex().row();

    if (_active == 2)
    {
        Scientist currentlySelectedScientist = _currentlyDisplayedScientists.at(currentlySelectedIndex);

        int scientistID = currentlySelectedScientist.getScientistID();

        QMessageBox::StandardButton sure;
        sure = QMessageBox::question(this, "Delete", "Are you sure you want to delete this connection?", QMessageBox::No|QMessageBox::Yes);
        if(sure == QMessageBox::Yes)
        {
            ui->statusBar->showMessage(_pService->deleteConnection(scientistID, _computer.getComputerID()), 2000);
            displayScientists();
        }
    }
    else if (_active == 1)
    {
        Computer currentlySelectedComputer = _currentlyDisplayedComputers.at(currentlySelectedIndex);

        int computerID = currentlySelectedComputer.getComputerID();

        QMessageBox::StandardButton sure;
        sure = QMessageBox::question(this, "Delete", "Are you sure you want to delete this connection?", QMessageBox::No|QMessageBox::Yes);
        if(sure == QMessageBox::Yes)
        {
            ui->statusBar->showMessage(_pComputerService->deleteConnection(_scientist.getScientistID(), computerID), 2000);
            displayComputers();
        }
    }
    else
    {
        ui->statusBar->showMessage("Extreme fail!", 2000);
    }
}

void Details::on_pushButton_clicked()
{
    this->close();
}
