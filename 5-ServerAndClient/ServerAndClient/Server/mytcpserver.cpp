#include "mytcpserver.h"

myTcpServer::myTcpServer(QObject *parent) : QTcpServer(parent)
{

}

void myTcpServer::incomingConnection(qintptr socketDescriptor)
{
    emit newClient(socketDescriptor);
}
