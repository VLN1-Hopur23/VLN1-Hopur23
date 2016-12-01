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

    void addScientist(Scientist scientist);

    Scientist getScientist(int index) const;

    int getSize() const;

    bool ifExist(string name);

    vector<int> searchScientists(string searchData);

    vector<Scientist> sortScientists(vector<Scientist> _listOfScientists, string sort);

    vector<Scientist> getScientistVector();

    bool DataAccessWorks();

    void save();

    bool load();
};

#endif // SCIENTISTSERVICE_H
