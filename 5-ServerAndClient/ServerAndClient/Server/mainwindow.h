#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QTcpServer>
#include "informationexchange.h"
#include "mytcpserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QThread * createTread(QObject *obj);
    void createConnect();

signals:
    void listenClient(unsigned short port);
    void createSocket(qintptr socketDescriptor);

private slots:
    void on_listenButton_clicked();

    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
    QString m_record;
    QString m_port;
    InformationExchange *m_infoExchange;
    QThread *m_infoExchangeThread;
    myTcpServer *m_tcpServer;

};
#endif // MAINWINDOW_H
