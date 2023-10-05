#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<qintptr >("qintptr");

    m_tcpServer = new myTcpServer();
    m_port = ui->PortLineEdit->text();

    m_infoExchange = new InformationExchange();
    m_infoExchangeThread = createTread(m_infoExchange);

    m_infoExchangeThread->start();

    createConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QThread* MainWindow::createTread(QObject *obj)
{
    QThread *thread = new QThread();
    obj->moveToThread(thread);
    return thread;
}

void MainWindow::createConnect()
{
    connect(m_infoExchange,&InformationExchange::readMessage,this,[=](QByteArray message,QString clientName){

        QByteArray readMessage = message;
        m_record.append(clientName);
        m_record.append(":");
        m_record.append(QString::fromUtf8(readMessage));
        ui->chatHistoryEdit->setText(m_record);
    });

    connect(m_tcpServer,&myTcpServer::newClient,m_infoExchange,&InformationExchange::newClient);
}


void MainWindow::on_listenButton_clicked()
{
    unsigned short port = m_port.toUShort();
    ui->PortLineEdit->setDisabled(true);
    m_tcpServer->listen(QHostAddress::Any,port);
}

void MainWindow::on_sendButton_clicked()
{
    QString sendData = ui->sendTextEdit->toPlainText();
}
