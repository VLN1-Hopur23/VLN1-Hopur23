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

    bool retrieveScientists(string order, string filter);

    string editScientist(int index, string change, string input);

    void deleteScientist(int index);

    bool searchingByFilter(string filter, string searchData);

    void retrieveIntersectComputer(const string& param);

    int getLastInsertRowID();

};

#endif // SCIENTISTSERVICE_H
