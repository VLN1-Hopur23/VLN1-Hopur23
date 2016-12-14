#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>

using namespace std;

class Computer
{
public:

    Computer();

    Computer(int computerID, string name, int yearBuilt, string type, bool built);

    int getComputerID() const;

    string getName() const;

    int getYearBuilt() const;

    string getType() const;

    bool getBuilt() const;

    void setName(string name);

    void setYearBuilt(int yearBuilt);

    void setType(string type);

    void setBuilt(bool built);

private:

    int _computerID;

    string _name;

    int _yearBuilt;

    string _type;

    bool _built;

    //LocalTime _Time;
};

#endif // COMPUTER_H
