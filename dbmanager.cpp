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

vector<Scientist> DbManager::getScientists()
{
    vector<Scientist> scientists;

    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM Scientists");

    while (query.next())
    {
        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();

        int yearOfBirth = query.value("Birthyear").toUInt();
        int yearOfDeath = query.value("Deathyear").toUInt();

        Scientist scientist(name, gender, yearOfBirth, yearOfDeath);

        scientists.push_back(scientist);
    }
    return scientists;
}

string DbManager::addScientist(const Scientist& scientist)
{
    string message = "";
    bool success = false;

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO scientists (Name, Gender, BirthYear, DeathYear) VALUES (:Name, :Gender, :BirthYear, :DeathYear)");
    queryAdd.bindValue(":Name", QString::fromStdString(scientist.getName()));
    queryAdd.bindValue(":Gender", QString::fromStdString(scientist.getGender()));
    queryAdd.bindValue(":BirthYear", scientist.getYearOfBirth());
    queryAdd.bindValue(":DeathYear", scientist.getYearOfDeath());

    if(queryAdd.exec())
    {
        success = true;
        message = "Scientist added successfully! ";
    }
    else
    {
        message = "Add scientist failed! ";
    }

    return message;
}

vector<Computer> DbManager::getComputers(){

    vector<Computer> computers;

    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM Computers");

    while (query.next())
    {
        string name = query.value("Name").toString().toStdString();

        int Yearbuilt = query.value("Yearbuilt").toUInt();

        string type = query.value("Type").toString().toStdString();

        bool built = query.value("Built").toBool();

        Computer computer(name, Yearbuilt, type, built);

        computers.push_back(computer);
    }

    return computers;
}
