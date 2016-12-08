#include "dbmanager.h"

using namespace std;

// Constructor connects to sqlite database
DbManager::DbManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("VLN1-Hopur23.sqlite");
}

// Optional order, Name, Gender, BirthYear, DeathYear. Optional filter DESC and ASC
vector<Scientist> DbManager::getScientists(QString QSorder, QString QSfilter)
{
    vector<Scientist> scientists;

    db.open();

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

string DbManager::addScientist(const Scientist& scientist)
{
    string message = "";

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO scientists (Name, Gender, BirthYear, DeathYear) VALUES (:Name, :Gender, :BirthYear, :DeathYear)");
    queryAdd.bindValue(":Name", QString::fromStdString(scientist.getName()));
    queryAdd.bindValue(":Gender", QString::fromStdString(scientist.getGender()));
    queryAdd.bindValue(":BirthYear", scientist.getYearOfBirth());
    queryAdd.bindValue(":DeathYear", scientist.getYearOfDeath());

    if(queryAdd.exec())
    {
        message = "Scientist added successfully! ";
    }
    else
    {
        message = "Add scientist failed! ";
    }

    return message;
}

// Gets computer and his information from database(SQL) and reads into Computer vector
// Optional (QS)order, Name, Gender, BirthYear, DeathYear. Optional (QS)filter DESC and ASC
vector<Computer> DbManager::getComputers(QString QSorder, QString QSfilter)
{
    vector<Computer> computers;

    db.open();

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
// Returns vector with all computers associated with the scientist/s
vector<Computer> DbManager::intersectScientists()
{
    vector<Computer> intersectedComputers;

   /*QSqlQuery intersectQuery;

    //intersectQuery.prepare("SELECT * FROM Scientists WHERE INTERSECT SELECT * FROM Computers ");

    while (intersectQuery.next())
    {
        int computerID = intersectQuery.value("ComputerID").toUInt();

        string name = intersectQuery.value("Name").toString().toStdString();

        int yearBuilt = intersectQuery.value("Yearbuilt").toUInt();

        string type = intersectQuery.value("Type").toString().toStdString();

        bool built = intersectQuery.value("Built").toBool();

        Computer computer(computerID, name, yearBuilt, type, built);

        intersectedComputers.push_back(computer);
    }*/
    return intersectedComputers;
}

// Gets the info on Scientist which is searced for
vector<Scientist> DbManager::searchScientist(const string& searchData)
{
    vector<Scientist> foundScientist;

    QSqlQuery query;

    // if (scientistExists(searchData))
    {

        //query.prepare("SELECT * FROM Scientists WHERE ScientistID OR Name OR Gender OR Birthyear OR Deathyear LIKE (SearchValue) VALUES (:SearchValue)");
        //query.bindValue(":SearchValue",QString::fromStdString(searchData));

        if (isdigit(searchData.at(0)))
        {
            cout << "first works\n";
            query.exec("SELECT * FROM Scientists WHERE (Birthyear || Deathyear) LIKE '%" + QString::fromStdString(searchData) + "%'");
        }
        else
        {
            cout << "Second workds\n";
            query.exec("SELECT * FROM Scientists WHERE (Name || Gender) LIKE '%" + QString::fromStdString(searchData) + "%'");
        }

        while (query.next())
        {

            int scientistID = query.value("ScientistID").toUInt();
            string name = query.value("Name").toString().toStdString();
            string gender = query.value("Gender").toString().toStdString();

            int yearOfBirth = query.value("Birthyear").toUInt();
            int yearOfDeath = query.value("Deathyear").toUInt();

            cout << endl;
            cout << name;
            cout << endl;

            Scientist scientist(scientistID, name, gender, yearOfBirth, yearOfDeath);

            foundScientist.push_back(scientist);
        }
    }
    // else
    {
       // qDebug() << "This scientist does not exist in this database " << query.lastError();
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
