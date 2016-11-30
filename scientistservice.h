#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "scientist.h"
#include <vector>

using namespace std;

class ScientistService
{
   // vector<Scientist> _scientists;

public:
    ScientistService();

    void addScientist(Scientist scientist);
    vector<Scientist> getScientists(string sort);

    Scientist getScientist(int index);
};

#endif // SCIENTISTSERVICE_H








/*#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H

#include <vector>
#include "performer.h"

class PerformerService
{
public:
    PerformerService();


   vector<Performer> getPerformers(ToDO: parameter);

};

#endif // PERFORMERSERVICE_H
*/
