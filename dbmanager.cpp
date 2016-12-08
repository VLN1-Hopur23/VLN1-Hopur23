#include "dbmanager.h"

using namespace std;

// Constructor connects to sqlite database
DbManager::DbManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("VLN1-Hopur23.sqlite");
    db.open();
}

// Optional order, Name, Gender, BirthYear, DeathYear. Optional filter DESC and ASC
vector<Scientist> DbManager::getScientists(QString QSorder, QString QSfilter)
{
    vector<Scientist> scientists;

    QSqlQuery querySort(db);

    querySort.prepare("SELECT * FROM Scientists ORDER BY " + QSorder + " " + QSfilter);

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

bool DbManager::addScientist(const Scientist& scientist) const
{
    //bool message = "";

    QSqlQuery queryAdd(db);
    queryAdd.prepare("INSERT INTO scientists (Name, Gender, BirthYear, DeathYear) VALUES (:Name, :Gender, :BirthYear, :DeathYear)");
    queryAdd.bindValue(":Name", QString::fromStdString(scientist.getName()));
    queryAdd.bindValue(":Gender", QString::fromStdString(scientist.getGender()));
    queryAdd.bindValue(":BirthYear", scientist.getYearOfBirth());
    queryAdd.bindValue(":DeathYear", scientist.getYearOfDeath());

    if(queryAdd.exec())
    {
        //message = "Scientist added successfully! ";
        return true;
    }
    else
    {
        //message = "Add scientist failed! ";
        return false;
    }
    //return message;
}

// Deletes scientist with chosen ID number from database
void DbManager::deleteScientist(const int ID)
{
    QSqlQuery queryDelete(db);
    queryDelete.prepare("DELETE FROM Scientists WHERE ScientistID = (:ScientistID)");
    queryDelete.bindValue(":ScientistID",ID);
    queryDelete.exec();
}

// Gets computer and his information from database(SQL) and reads into Computer vector
// Optional (QS)order, Name, Gender, BirthYear, DeathYear. Optional (QS)filter DESC and ASC
vector<Computer> DbManager::getComputers(QString QSorder, QString QSfilter)
{
    vector<Computer> computers;

    QSqlQuery query(db);

    query.prepare("SELECT * FROM Computers ORDER BY " + QSorder + " " + QSfilter);
    query.exec();

    while (query.next())
    {
        int computerID = query.value("ComputerID").toUInt();

        string name = query.value("Name").toString().toStdString();

        int yearBuilt = query.value("Yearbuilt").toUInt();

        string type = query.value("Type").toString().toStdString();

        bool built = query.value("Built").toBool();

        Computer computer(computerID, name, yearBuilt, type, built);

        computers.push_back(computer);
    }
    return computers;
}

bool DbManager::addComputer(const Computer& computer) const
{
    bool cMessage = "";

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO computers (ComputerID, Name, Yearbuilt, Type, Built) VALUES (:ComputerID, :Name, :Yearbuilt, :Type, :Built)");
    queryAdd.bindValue(":ComputerID", computer.getComputerID());
    queryAdd.bindValue(":Name", QString::fromStdString(computer.getName()));
    queryAdd.bindValue(":Yearbuilt", computer.getYearBuilt());
    queryAdd.bindValue(":Type", QString::fromStdString(computer.getType()));
    queryAdd.bindValue(":Built", computer.getBuilt());

    if(queryAdd.exec())
    {
        cMessage = "Computer added successfully! ";
        return true;
    }
    else
    {
        cMessage = "Add computer failed! ";
        return false;
    }
    return cMessage;
}

// Returns vector with all computers associated with the scientist/s
vector<Computer> DbManager::intersectScientist(const string& id)
{
    vector<Computer> intersectedComputers;

    QSqlQuery intersectQuery(db);

    intersectQuery.prepare("SELECT * FROM Computers INNER JOIN Computers_Scientists ON Computers.ComputerID = Computers_Scientists.ComputerID INNER JOIN Scientists ON Scientists.ScientistID = Computers_Scientists.ScientistID WHERE Scientists.ScientistID = :id");
    intersectQuery.bindValue(":id", QString::fromStdString(id));

    intersectQuery.exec();

    while (intersectQuery.next())
    {
        int computerID = intersectQuery.value("ComputerID").toUInt();

        string name = intersectQuery.value("Name").toString().toStdString();

        int yearBuilt = intersectQuery.value("Yearbuilt").toUInt();

        string type = intersectQuery.value("Type").toString().toStdString();

        bool built = intersectQuery.value("Built").toBool();

        Computer computer(computerID, name, yearBuilt, type, built);

        intersectedComputers.push_back(computer);
    }
    return intersectedComputers;
}

// Returns vector with all computers associated with the scientist/s
vector<Scientist> DbManager::intersectComputer(const string& id)
{
    vector<Scientist> intersectedScientists;

    QSqlQuery intersectQuery(db);

    intersectQuery.prepare("SELECT * FROM Scientists INNER JOIN Computers_Scientists ON Scientists.ScientistID = Computers_Scientists.ScientistID INNER JOIN Computers ON Computers.ComputerID = Computers_Scientists.ComputerID WHERE Computers.ComputerID = :id");
    intersectQuery.bindValue(":id", QString::fromStdString(id));

    intersectQuery.exec();

    while (intersectQuery.next())
    {
        int scientistID = intersectQuery.value("ScientistID").toUInt();

        string name = intersectQuery.value("Name").toString().toStdString();

        string gender = intersectQuery.value("Gender").toString().toStdString();

        int yearOfBirth = intersectQuery.value("Birthyear").toUInt();

        int yearOfDeath = intersectQuery.value("Deathyear").toUInt();

        Scientist scientist(scientistID, name, gender, yearOfBirth, yearOfDeath);

        intersectedScientists.push_back(scientist);
    }
    return intersectedScientists;
}

// Gets the info on Scientist which is searced for
vector<Scientist> DbManager::searchScientist(const string& searchData)
{
    vector<Scientist> foundScientist;

    db.open();

    QSqlQuery query(db);

    if (isdigit(searchData.at(0)))
    {
        query.exec("SELECT * FROM Scientists WHERE (Birthyear || Deathyear) LIKE '%" + QString::fromStdString(searchData) + "%'");
    }
    else
    {
        query.exec("SELECT * FROM Scientists WHERE (Name || Gender) LIKE '%" + QString::fromStdString(searchData) + "%'");
    }

    while (query.next())
    {
        int scientistID = query.value("ScientistID").toUInt();
        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();

        int yearOfBirth = query.value("Birthyear").toUInt();
        int yearOfDeath = query.value("Deathyear").toUInt();

        Scientist scientist(scientistID, name, gender, yearOfBirth, yearOfDeath);

        foundScientist.push_back(scientist);
    }
    return foundScientist;
}

// Gets the info on Computer which is searched for
vector<Computer> DbManager::searchComputer(string& searchData)
{
    vector<Computer> foundComputer;
    QSqlQuery query(db);

    if (isdigit(searchData.at(0)))
    {
        query.exec("SELECT * FROM Computers WHERE (Yearbuilt) LIKE '%" + QString::fromStdString(searchData) + "%'");
    }
    else
    {
        query.exec("SELECT * FROM Computers WHERE (Name || Type) LIKE '%" + QString::fromStdString(searchData) + "%'");
    }

    while(query.next())
    {
        int computerID = query.value("ComputerID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int yearBuilt = query.value("Yearbuilt").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool built = query.value("Built").toBool();

        Computer computer(computerID, name, yearBuilt, type, built);

        foundComputer.push_back(computer);
    }
    return foundComputer;
}
