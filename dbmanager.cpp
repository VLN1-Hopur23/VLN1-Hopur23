#include "dbmanager.h"

using namespace std;

// Constructor connects to sqlite database
DbManager::DbManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("VLN1-Hopur23.sqlite");

    // Validates the connection
    if (!db.open())
    {
        qDebug() << "Error: connection with database fail"; // MÁ EKKI VERA HÉR EÐA HVAÐ????????????????
    }
    else
    {
        qDebug() << "Database: connection ok";              // MÁ EKKI VERA HÉR EÐA HVAÐ????????????????
    }
}

// Gets scientist and his information from database and reads into Scientist vector
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

// Gets computer and his information from database and reads into Computer vector
vector<Computer> DbManager::getComputers()
{
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
// Checks if scientist already exist in the database
bool DbManager::scientistExists(const string& searchData) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT Name FROM Scientists WHERE (Name) VALUES (:Name)");
    checkQuery.bindValue(":Name",QString::fromStdString(searchData));

    if (checkQuery.exec())
    {
         exists = true;
    }
    else
    {
        qDebug() << "Error in scientist exists: " << checkQuery.lastError();
    }

    return exists;
}
// Checks if computer already exist in the database
bool DbManager::computerExists(const string& searchData) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT Name FROM Computers WHERE (Name) VALUES (:Name)");
    checkQuery.bindValue(":Name",QString::fromStdString(searchData));

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Error in computer exists: " << checkQuery.lastError();
    }
    return exists;
}

// Gets the info on Scientist which is searced for
vector<Scientist> DbManager::searchScientist(string& searchData)
{
    vector<Scientist> foundScientist;
    QSqlQuery query;

    if (scientistExists(searchData))
    {
        query.prepare("SELECT Name FROM Scientists WHERE (Name) VALUES (:Name)");
        query.bindValue(":Name",QString::fromStdString(searchData));

        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();

        int yearOfBirth = query.value("Birthyear").toUInt();
        int yearOfDeath = query.value("Deathyear").toUInt();

        Scientist scientist(name, gender, yearOfBirth, yearOfDeath);

        foundScientist.push_back(scientist);
    }
    else
    {
        qDebug() << "This scientist does not exist in this database " << query.lastError();
    }
    return foundScientist;
}

// Gets the info on Computer which is searched for
vector<Computer> DbManager::searchComputer(string& searchData)
{
    vector<Computer> foundComputer;
    QSqlQuery query;

    if(computerExists(searchData))
    {
        query.prepare("SELECT Name FROM Computers WHERE (Name) VALUES (:Name)");
        query.bindValue(":Name",QString::fromStdString(searchData));

        string name = query.value("Name").toString().toStdString();

        int Yearbuilt = query.value("Yearbuilt").toUInt();

        string type = query.value("Type").toString().toStdString();

        bool built = query.value("Built").toBool();

        Computer computer(name, Yearbuilt, type, built);

        foundComputer.push_back(computer);
    }
    else
    {
        qDebug() << "This computer does not exist in this database " << query.lastError();
    }
    return foundComputer;
}
