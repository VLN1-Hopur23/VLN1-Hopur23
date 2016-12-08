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

public:

    ScientistService();

    bool retrieveScientists(string order, string filter);

    void getVectorFoundScientists(string& searchData);

    bool addScientist(Scientist scientist);

    Scientist getScientist(size_t index);

    size_t getSize() const;

    bool ifExist(string name);

    vector<Scientist> getScientistVector();

    bool load();

    string editScientist(int index, string change, string input);

    bool DataAccessWorks();

    void deleteScientist(int index);
};

#endif // SCIENTISTSERVICE_H
