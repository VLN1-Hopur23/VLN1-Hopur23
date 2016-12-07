#include "dbmanager.h"

using namespace std;

DbManager::DbManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("VLN1-Hopur23.sqlite");

    if (!db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}
// Optional order, Name, Gender, BirthYear, DeathYear. Optional filter DESC and ASC
vector<Scientist> DbManager::getScientists(QString order, QString filter)
{
    vector<Scientist> scientists;
    order = QString::fromStdString("Name");
    filter = QString::fromStdString("DESC");

    order = "Name";
    filter = "DESC";

    db.open();

    QSqlQuery querySort(db);
    /*
    querySort.prepare("SELECT * FROM Scientists ORDER BY order = :order, filter = :filter)");
    querySort.bindValue(":order", order);
    querySort.bindValue(":filter", filter);
    */
    querySort.prepare("SELECT * FROM Scientists ORDER BY Name ASC");
    querySort.exec();

    while (querySort.next())
    {
        int scientistID = querySort.value("ScientistID").toUInt();
        string name = querySort.value("Name").toString().toStdString();
        string gender = querySort.value("Gender").toString().toStdString();

        int yearOfBirth = querySort.value("Birthyear").toUInt();
        int yearOfDeath = querySort.value("Deathyear").toUInt();

        Scientist scientist(scientistID, name, gender, yearOfBirth, yearOfDeath);

        scientists.push_back(scientist);
    }
    return scientists;
}

vector<Computer> DbManager::getComputers(){

    vector<Computer> computers;

    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM Computers");

    while (query.next())
    {
        int computerID = query.value("ComputerID").toUInt();

        string name = query.value("Name").toString().toStdString();

        int yearBuilt = query.value("yearBuilt").toUInt();

        string type = query.value("Type").toString().toStdString();

        bool built = query.value("Built").toBool();

        Computer computer(computerID, name, yearBuilt, type, built);

        computers.push_back(computer);
    }

    return computers;
}
