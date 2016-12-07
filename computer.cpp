#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(string name, int Yearbuilt, string type, bool built)
{
    _name = name;
    _yearBuilt = Yearbuilt;
    _type = type;
    _built = built;
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
