#include "dbmanager.h"
#include <QDebug>

using namespace std;

// Constructor connects to sqlite database
DbManager::DbManager()
{
    this->dbName = "VLN1-Hopur23.sqlite";
    this->connName = "ThisConnection";

    // Contains() default argument is initialized to default connection
    if (QSqlDatabase::contains(connName))
    {
        this->_db = QSqlDatabase::database(connName, false);
    }
    else
    {
        this->_db = QSqlDatabase::addDatabase("QSQLITE", connName);
        this->_db.setDatabaseName(dbName);
        this->_db.open();
    }
}

DbManager::~DbManager()
{
    if (this->_db.isOpen())
    {
        this->_db.close();
    }

    QSqlDatabase::removeDatabase(dbName);
}

// Get scientist for display - Optional order, Name, Gender, BirthYear, DeathYear. Optional filter DESC and ASC
vector<Scientist> DbManager::getScientists()
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    vector<Scientist> scientists;

    QSqlQuery querySort(_db);

    querySort.prepare("SELECT * FROM Scientists");

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

// Gets computer and his information from database(SQL) and reads into Computer vector
// Optional (QS)order, Name, Gender, BirthYear, DeathYear. Optional (QS)filter DESC and ASC
vector<Computer> DbManager::getComputers()
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    vector<Computer> computers;

    QSqlQuery query(_db);

    query.prepare("SELECT * FROM Computers");
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

bool DbManager::addScientist(const Scientist& scientist, int& id)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery queryAdd(_db);

    queryAdd.prepare("INSERT INTO scientists (Name, Gender, BirthYear, DeathYear) VALUES (:Name, :Gender, :BirthYear, :DeathYear)");
    queryAdd.bindValue(":Name", QString::fromStdString(scientist.getName()));
    queryAdd.bindValue(":Gender", QString::fromStdString(scientist.getGender()));
    queryAdd.bindValue(":BirthYear", scientist.getYearOfBirth());
    queryAdd.bindValue(":DeathYear", scientist.getYearOfDeath());

    if(queryAdd.exec())
    {
        id = queryAdd.lastInsertId().toInt();
        return true;
    }
    else
    {
        return false;
    }
}

// Deletes scientist with chosen ID number from database and his previous connection to computer
bool DbManager::deleteComputer(const int ID)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery queryDelete(_db);
    queryDelete.prepare("DELETE FROM Computers WHERE ComputerID = (:ComputerID)");
    queryDelete.bindValue(":ComputerID",ID);
    queryDelete.exec();

    QSqlQuery queryDeleteConnection(_db);
    queryDeleteConnection.prepare("DELETE FROM Computers_Scientists WHERE ComputerID = (:ComputerID)");
    queryDeleteConnection.bindValue(":ComputerID",ID);
    queryDeleteConnection.exec();

    if(queryDelete.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Deletes connection link between scientist and computer
void DbManager::deleteConnection(const int ID)
{
    QSqlQuery queryDeleteConnection(_db);
    queryDeleteConnection.prepare("DELETE FROM Computers_Scientists WHERE Computer_ScientistID = (:Computer_ScientistID)");
    queryDeleteConnection.bindValue(":Computer_ScientistID",ID);
    queryDeleteConnection.exec();
}

// Deletes computer with chosen ID number from database and his previous connection to scientist
bool DbManager::deleteScientist(const int ID)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery queryDelete(_db);
    queryDelete.prepare("DELETE FROM Scientists WHERE ScientistID = (:ScientistID)");
    queryDelete.bindValue(":ScientistID",ID);
    queryDelete.exec();

    QSqlQuery queryDeleteConnection(_db);
    queryDeleteConnection.prepare("DELETE FROM Computers_Scientists WHERE ScientistID = (:ScientistID)");
    queryDeleteConnection.bindValue(":ScientistID",ID);
    queryDeleteConnection.exec();

    if(queryDelete.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DbManager::addComputer(const Computer& computer, int& id)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery queryAdd(_db);

    queryAdd.prepare("INSERT INTO computers (Name, Yearbuilt, Type, Built) VALUES (:Name, :Yearbuilt, :Type, :Built)");
    queryAdd.bindValue(":Name", QString::fromStdString(computer.getName()));
    queryAdd.bindValue(":Yearbuilt", computer.getYearBuilt());
    queryAdd.bindValue(":Type", QString::fromStdString(computer.getType()));
    queryAdd.bindValue(":Built", computer.getBuilt());

    if(queryAdd.exec())
    {
        id = queryAdd.lastInsertId().toInt();
        return true;
    }
    else
    {
        return false;
    }
}

// Returns vector with all computers associated with the scientist/s
vector<Computer> DbManager::intersectScientist(const string& id)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    vector<Computer> intersectedComputers;

    QSqlQuery intersectQuery(_db);

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

// Returns vector with all scientists associated with the computer/s
vector<Scientist> DbManager::intersectComputer(const string& id)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    vector<Scientist> intersectedScientists;

    QSqlQuery intersectQuery(_db);

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
    if (!_db.isOpen())
    {
        _db.open();
    }

    vector<Scientist> foundScientists;

    QSqlQuery query(_db);

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

        foundScientists.push_back(scientist);
    }
    return foundScientists;
}

vector<Computer> DbManager::filterComputer(const string& Command, const string& searchData)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    vector<Computer> foundComputers;
    QString qCommand = QString::fromStdString(Command);
    QString qSearchData = QString::fromStdString(searchData);

    QSqlQuery findquery(_db);
    QString sqlCommand = "SELECT * FROM Computers WHERE " + qCommand + " LIKE '" +qSearchData + "%' ";
    findquery.prepare(sqlCommand);
    findquery.exec();

    while (findquery.next())
    {
        int computerID = findquery.value("ComputerID").toUInt();
        string name = findquery.value("Name").toString().toStdString();
        int yearBuilt = findquery.value("Yearbuilt").toUInt();
        string type = findquery.value("Type").toString().toStdString();
        bool built = findquery.value("Built").toBool();
        Computer computer(computerID, name, yearBuilt, type, built);
        foundComputers.push_back(computer);
    }
    return foundComputers;
}

vector<Scientist> DbManager::filterScientist(const string& Command, const string& searchData)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    vector<Scientist> foundScientists;
    QString qCommand = QString::fromStdString(Command);
    QString qSearchData = QString::fromStdString(searchData);

    QSqlQuery findquery(_db);

    QString sqlCommand = "SELECT * FROM Scientists WHERE " + qCommand + " LIKE '" +qSearchData + "%' ";
    findquery.prepare(sqlCommand);
    findquery.exec();

    while (findquery.next())
    {
        int scientistID = findquery.value("ScientistID").toUInt();
        string name = findquery.value("Name").toString().toStdString();
        string gender = findquery.value("Gender").toString().toStdString();
        int yearOfBirth = findquery.value("Birthyear").toUInt();
        int yearOfDeath = findquery.value("Deathyear").toUInt();
        Scientist scientist(scientistID, name, gender, yearOfBirth, yearOfDeath);

        foundScientists.push_back(scientist);
    }
    return foundScientists;
}

// Gets the info on Computer which is searched for
vector<Computer> DbManager::searchComputer(string& searchData)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    vector<Computer> foundComputer;
    QSqlQuery query(_db);

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

string DbManager::editScientistName(const int& id, const string& newName)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery query(_db);
    string message;

    query.prepare("UPDATE Scientists SET Name=:Name WHERE ScientistID=:ScientistID");
    query.bindValue(":Name", QString::fromStdString(newName));
    query.bindValue(":ScientistID", id);

    if (query.exec())
    {
        message = "Successfully edited!";
    }
    else if (!query.exec())
    {
        message = "Error occurred while editiing!";
    }
    else
    {
        message = "Unkown error occurred";
    }
    return message;
}

string DbManager::editScientistGender(const int& id, const string& newGender)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery query(_db);
    string message;

    query.prepare("UPDATE Scientists SET Gender=:Gender WHERE ScientistID=:ScientistID");
    query.bindValue(":Gender", QString::fromStdString(newGender));
    query.bindValue(":ScientistID", id);

    if (query.exec())
    {
        message = "Successfully edited!";
    }
    else if (!query.exec())
    {
        message = "Error occurred while editiing!";
    }
    else
    {
        message = "Unkown error occurred";
    }
    return message;
}

string DbManager::editScientistBirthYear(const int& id, const string& newBirthYear)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery query(_db);
    string message;

    query.prepare("UPDATE Scientists SET Birthyear=:Birthyear WHERE ScientistID=:ScientistID");
    query.bindValue(":Birthyear", QString::fromStdString(newBirthYear));
    query.bindValue(":ScientistID", id);

    if (query.exec())
    {
        message = "Successfully edited!";
    }
    else if (!query.exec())
    {
        message = "Error occurred while editiing!";
    }
    else
    {
        message = "Unkown error occurred";
    }
    return message;
}

string DbManager::editScientistDeathYear(const int& id, const string& newDeathYear)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery query(_db);
    string message;

    query.prepare("UPDATE Scientists SET Deathyear=:Deathyear WHERE ScientistID=:ScientistID");
    query.bindValue(":Deathyear", QString::fromStdString(newDeathYear));
    query.bindValue(":ScientistID", id);

    if (query.exec())
    {
        message = "Successfully edited!";
    }
    else if (!query.exec())
    {
        message = "Error occurred while editiing!";
    }
    else
    {
        message = "Unkown error occurred";
    }
    return message;
}

string DbManager::editComputerName(const int& id, const string& newName)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery query(_db);
    string message;

    query.prepare("UPDATE Computers SET Name=:Name WHERE ComputerID=:ComputerID");
    query.bindValue(":Name", QString::fromStdString(newName));
    query.bindValue(":ComputerID", id);

    if (query.exec())
    {
        message = "Successfully edited!";
    }
    else if (!query.exec())
    {
        message = "Error occurred while editiing!";
    }
    else
    {
        message = "Unkown error occurred";
    }
    return message;
}


string DbManager::editComputerYearBuilt(const int& id, const string& newYearBuilt)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery query(_db);
    string message;

    query.prepare("UPDATE Computers SET Yearbuilt=:Yearbuilt WHERE ComputerID=:ComputerID");
    query.bindValue(":Yearbuilt", QString::fromStdString(newYearBuilt));
    query.bindValue(":ComputerID", id);

    if (query.exec())
    {
        message = "Successfully edited!";
    }
    else if (!query.exec())
    {
        message = "Error occurred while editiing!";
    }
    else
    {
        message = "Unkown error occurred";
    }
    return message;
}

string DbManager::editComputerType(const int& id, const string& newType)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery query(_db);
    string message;

    query.prepare("UPDATE Computers SET Type=:Type WHERE ComputerID=:ComputerID");
    query.bindValue(":Type", QString::fromStdString(newType));
    query.bindValue(":ComputerID", id);

    if (query.exec())
    {
        message = "Successfully edited!";
    }
    else if (!query.exec())
    {
        message = "Error occurred while editiing!";
    }
    else
    {
        message = "Unkown error occurred";
    }
    return message;
}

string DbManager::stringToLower(string str)
{
    string result = "";

    for(unsigned int i = 0; i < str.length(); ++i)
    {
        result += tolower(str[i]);
    }
    return result;
}

bool DbManager::addIntersect(const int& scientistID, const int& computerID)
{
    if (!_db.isOpen())
    {
        _db.open();
    }

    QSqlQuery queryAdd(_db);
    queryAdd.prepare("INSERT INTO Computers_Scientists (ComputerID,ScientistID) VALUES (:computerID, :scientistID)");
    queryAdd.bindValue(":computerID", computerID);
    queryAdd.bindValue(":scientistID", scientistID);

    if(queryAdd.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

 vector<Computer> DbManager::searchComputerPeriod(int yearFrom, int yearTo)
{
    if (!_db.isOpen())
    {
     _db.open();
    }

    QSqlQuery query(_db);
    vector<Computer> foundComputer;

    query.prepare("SELECT * FROM Computers WHERE Yearbuilt BETWEEN (:YearFrom) AND (:YearTo)");
    query.bindValue(":YearFrom", yearFrom);
    query.bindValue(":YearTo", yearTo);

    query.exec();

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


