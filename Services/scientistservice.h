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

    string editScientist(int index, string change, string input);

    void deleteScientist(int index);

    vector<Scientist> searchingByFilter(string filter, string searchData);

    void retrieveIntersectComputer(const string& param);

    int getLastInsertRowID();

    bool addIntersectComputer(const int& scientistID, const int& computerID);
};

#endif // SCIENTISTSERVICE_H
