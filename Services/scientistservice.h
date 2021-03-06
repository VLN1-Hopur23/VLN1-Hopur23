#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "scientist.h"
#include "dbmanager.h"
#include <vector>
#include <algorithm>

using namespace std;

class ScientistService
{
    vector<Scientist> _scientists;

    DbManager _data;

    LocalTime _time;

public:

    ScientistService();

    void getVectorFoundScientists(string& searchData);

    bool addScientist(Scientist scientist, int& id);

    Scientist getScientist(size_t index);

    size_t getSize() const;

    vector<Scientist> getScientistVector();

    void retrieveScientists();

    string retrievePicUrl(int scientistID);

    void addPicUrl(int scientistID, string url);

    string editScientist(int index, string change, string input);

    bool deleteScientist(int index);

    vector<Scientist> searchingByFilter(string command, string searchData);

    void retrieveIntersectComputer(const QString& param);

    int getLastInsertRowID();

    bool addIntersectComputer(const int& scientistID, const int& computerID);

    QString deleteConnection(const int &scientistID, const int &computerID);
};

#endif // SCIENTISTSERVICE_H
