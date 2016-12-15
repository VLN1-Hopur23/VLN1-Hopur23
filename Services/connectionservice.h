#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include "computer.h"
#include "scientist.h"
#include "dbmanager.h"
#include <algorithm>
#include <vector>

using namespace std;

class ConnectionService
{
public:
    ConnectionService();

    void deleteConnection(int index);

private:

     DbManager _data;
};

#endif // CONNECTIONSERVICE_H
