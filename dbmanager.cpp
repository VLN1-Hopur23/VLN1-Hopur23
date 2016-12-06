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
