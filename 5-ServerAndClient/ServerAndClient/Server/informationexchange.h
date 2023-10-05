#ifndef INFORMATIONEXCHANGE_H
#define INFORMATIONEXCHANGE_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

enum TYPE{
    TYPE_NONE = 0,
    TYPE_TEXT = 1,
    TYPE_FILE = 2,
    TYPE_FILEHEALD = 3,
};

#define HEAD_SIZE 3

class InformationExchange:public QObject
{
    Q_OBJECT
public:
    InformationExchange(QObject *parent = nullptr);
    ~InformationExchange();

public:
    void newClient(qintptr socketDescriptor);
    void readData();

signals:
    void readMessage(QByteArray message,QString clientName);

private:
    //QList<QTcpSocket *> socketList;
    QMap<QString,QTcpSocket* > clientNameMapSocket;
    QMap<qintptr,QTcpSocket* > clientIdMapSocket;

};

#endif // INFORMATIONEXCHANGE_H
