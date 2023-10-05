#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>

class myTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit myTcpServer(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor);

signals:
    void newClient(qintptr socketDescriptor);

};

#endif // MYTCPSERVER_H
