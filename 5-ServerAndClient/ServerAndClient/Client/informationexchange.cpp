#include "informationexchange.h"

#include <QFile>

InformationExchange::InformationExchange(QObject *parent) : QObject(parent)
{
    m_connected = false;

}

InformationExchange::~InformationExchange()
{

}

void InformationExchange::init(QString clientName)
{
    m_clientName = clientName;
}

void InformationExchange::connectServer(QString IP,unsigned short port)
{
    m_tcpSocket = new QTcpSocket();
    m_tcpSocket->connectToHost(QHostAddress(IP),port);

    connect(m_tcpSocket,&QTcpSocket::connected,this,[=]{
        qDebug() << "连接服务器成功!";
        m_connected = true;
        connect(m_tcpSocket,&QTcpSocket::readyRead,this,[=]{

        });
    });

    connect(m_tcpSocket,&QTcpSocket::disconnected,this,[=]{
        m_connected = false;
        m_tcpSocket->close();
        m_tcpSocket->deleteLater();
    });
}

void InformationExchange::sendText(QString text)
{
    if(!m_connected)
    {
        qDebug() << "请先连接服务器!";
        return;
    }
    else
    {
        QByteArray blok;
        int type = TYPE_TEXT;
        QByteArray typeHead((char*)&type,sizeof(int));
        blok.append(typeHead);

        int clientSize = m_clientName.toUtf8().size();
        QByteArray clientsizeHead((char*)&clientSize,sizeof(int));
        blok.append(clientsizeHead);

        int dataLen = text.toUtf8().size();
        QByteArray dataLenHead((char*)&dataLen,sizeof(int));
        blok.append(dataLenHead);

        QByteArray clienName = m_clientName.toUtf8();
        blok.append(m_clientName);

        QByteArray data = text.toUtf8();
        blok.append(text);

        m_tcpSocket->write(blok);
    }
}

void InformationExchange::sendFile(QString fileName)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    int flag = 0;

    while(!file.atEnd())
    {
        int type = 0;
        if(flag == 0)
        {
            type = TYPE_FILEHEALD;
            flag = 1;
        }
        else
        {
            type = TYPE_FILE;
        }


        QByteArray lineData = file.readLine();

        QByteArray blok;
        QByteArray typeHead((char*)&type,sizeof(int));
        blok.append(typeHead);

        int clientSize = m_clientName.toUtf8().size();
        QByteArray clientsizeHead((char*)&clientSize,sizeof(int));
        blok.append(clientsizeHead);

        int dataLen = lineData.size();
        QByteArray dataLenHead((char*)&dataLen,sizeof(int));
        blok.append(dataLenHead);

        QByteArray clienName = m_clientName.toUtf8();
        blok.append(m_clientName);

        blok.append(lineData);

        m_tcpSocket->write(blok);
    }

}
