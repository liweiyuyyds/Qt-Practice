#include "informationexchange.h"
#include <QDataStream>
#include <QFile>

InformationExchange::InformationExchange(QObject *parent)
    : QObject(parent)
{

}

InformationExchange::~InformationExchange()
{

}

void InformationExchange::newClient(qintptr socketDescriptor)
{
    QTcpSocket *tcpSocket = new QTcpSocket();
    tcpSocket->setSocketDescriptor(socketDescriptor);

    connect(tcpSocket,&QTcpSocket::readyRead,this,&InformationExchange::readData);

    clientIdMapSocket[socketDescriptor] = tcpSocket;
}

void InformationExchange::readData()
{
    qDebug() << "开始接受数据!";
    int informationType = 0;
    int clientNameSize = 0;
    int dataSize = 0;
    int revcSize = 0;
    QByteArray blok;
    QTcpSocket *tcpSocket = qobject_cast<QTcpSocket *>(sender());

    if(tcpSocket->bytesAvailable() == 0)
    {
        qDebug() <<"数据发送完毕!";
        return;
    }

    int size = HEAD_SIZE*sizeof(int);
    if(tcpSocket->bytesAvailable() >= size)
    {
        QByteArray messageType = tcpSocket->read(sizeof(int));
        informationType = *(int*)(messageType.data());
        qDebug() << "消息类型:" << informationType;

        QByteArray clientName = tcpSocket->read(sizeof(int));
        clientNameSize = *(int*)(clientName.data());
        qDebug() << "客户端名大小:" << clientNameSize;

        QByteArray messageData = tcpSocket->read(sizeof(int));
        dataSize = *(int*)(messageData.data());
        qDebug() << "数据大小:" << dataSize;
    }
    else
    {
        return;
    }

    QByteArray clientName = tcpSocket->read(clientNameSize);
    qDebug() << "客户端名:" << clientName.data();

    while(dataSize - revcSize > 0 && tcpSocket->bytesAvailable())
    {
        blok.append(tcpSocket->read(dataSize - revcSize));
        revcSize = blok.size();
    }
    if(dataSize == revcSize)
    {
        if(informationType == TYPE_FILE || informationType ==  TYPE_FILEHEALD)
        {
            if(informationType ==  TYPE_FILEHEALD)
            {
                if(QFile::exists("liweiyu.txt"))
                {
                    QFile::remove("liweiyu.txt");
                }
            }

            QFile file("liweiyu.txt");
            file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
            file.write(blok);
            file.close();
        }
        emit readMessage(blok,clientName);
        qDebug() << "发送的消息:" << QString::fromUtf8(blok);
    }
    if(tcpSocket->bytesAvailable() > 0)
    {
        qDebug() << "开始递归调用";
        readData();
    }
}
