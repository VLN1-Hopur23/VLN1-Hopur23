#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include ""
//#include ""

#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentScientistSortColumn = "Name";

    statusBarMessage = new QLabel();
    ui->statusBar->addPermanentWidget(statusBarMessage,1);

    ui->input_dropdown_sort_s->addItem("Name");
    ui->input_dropdown_sort_s->addItem("Gender");
    ui->input_dropdown_sort_s->addItem("Birth");
    ui->input_dropdown_sort_s->addItem("Death");

    ui->input_keyword_s->setPlaceholderText("search scientists...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_add_scientist_clicked()
{

}

void MainWindow::getAllScientist()
{
    currentScientist = _service.getScientistVector();
    displayAllScientists();
}

void MainWindow::displayAllScientists()
{
    ui->table_s->clearContents();
    ui->table_s->setRowCount(_service.getSize());

    //currentlyDisplayedScientist.clear();

    for(unsigned int row = 0; row < currentScientist.size(); row++)
    {
        Scientist currentScientist = _service.getScientist(row);

        string searchString = ui->input_keyword_s->text().toStdString();
        //if(currentScientist.contains(searchString))
        {
            ui->table_s->setItem(row,0,new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));
            ui->table_s->setItem(row,1,new QTableWidgetItem(QString::fromStdString(currentScientist.getGender())));
            ui->table_s->setItem(row,2,new QTableWidgetItem(currentScientist.getYearOfBirth()));
            ui->table_s->setItem(row,3,new QTableWidgetItem(currentScientist.getYearOfDeath()));
            //ui->table_s->addItem(QString::fromStdString(currentScientist.toString()));

            currentlyDisplayedScientist.push_back(currentScientist);
        }
        //currentlyDisplayedScientist = _service;
    }

    ui->table_s->setRowCount(currentlyDisplayedScientist.size());
}
