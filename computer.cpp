#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(int computerID, string name, int yearBuilt, string type, bool built)
{
    _computerID = computerID;
    _name = name;
    _yearBuilt = yearBuilt;
    _type = type;
    _built = built;
}

int Computer::getComputerID() const
{
    return _computerID;
}

string Computer::getName() const
{
    return _name;
}

int Computer::getYearBuilt() const
{
    return _yearBuilt;
}

string Computer::getType() const
{
    return _type;
}

bool Computer::getBuilt() const
{
    return _built;
}

void Computer::setName(string name)
{
    _name = name;
}

void Computer::setYearBuilt(int yearBuilt)
{
    _yearBuilt = yearBuilt;
}

void Computer::setType(string type)
{
    _type = type;
}

void Computer::setBuilt(bool built)
{
    _built = built;
}
