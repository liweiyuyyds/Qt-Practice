#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "informationexchange.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QThread * createTread(QObject *obj);
    void createConnect();

signals:
    void connectServer(QString IP,unsigned short port);
    void sendText(QString text);
    void sendFile(QString fileName);

private slots:
    void on_connectButton_clicked();

    void on_sendButton_clicked();

    void on_sendFileButton_clicked();

    void on_openFileButton_clicked();

private:
    Ui::MainWindow *ui;
    InformationExchange *infoExchange;
    QThread *infoExchangeThread;
    QString m_clientName;
    QString m_port;
    QString m_IP;
};
#endif // MAINWINDOW_H
