#include "connectionservice.h"

using namespace std;

ConnectionService::ConnectionService()
{

}

void ConnectionService::deleteConnection(int index)
{
    _data.deleteConnection(index);
}
