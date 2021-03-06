#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "scientist.h"
#include "dataaccess.h"
#include <vector>

using namespace std;

class ScientistService
{
    vector<Scientist> _scientists;
    DataAccess _data;

public:

    ScientistService();

    vector<Scientist> sortScientists(vector<Scientist> _listOfScientists, string sort);

    vector<int> searchScientists(string& searchData);

    void addScientist(Scientist scientist);

    Scientist getScientist(int index) const;

    int getSize() const;

    bool ifExist(string name);

    vector<Scientist> getScientistVector();

    bool load();

    string editScientist(int index, string change, string input);

    bool DataAccessWorks();

    void deleteScientist(int index);
};

#endif // SCIENTISTSERVICE_H
