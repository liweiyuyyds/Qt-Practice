#ifndef INFORMATIONEXCHANGE_H
#define INFORMATIONEXCHANGE_H

#include <QObject>
#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>

enum TYPE{
    TYPE_NONE = 0,
    TYPE_TEXT = 1,
    TYPE_FILE = 2,
    TYPE_FILEHEALD = 3,
};

class InformationExchange : public QObject
{
    Q_OBJECT
public:
    explicit InformationExchange(QObject *parent = nullptr);
    ~InformationExchange();
    void init(QString clientName);

public slots:
    void connectServer(QString IP,unsigned short port);
    void sendText(QString text);
    void sendFile(QString fileName);

private:
    QTcpSocket * m_tcpSocket;
    bool m_connected;
    QString m_clientName;

};

#endif // INFORMATIONEXCHANGE_H
