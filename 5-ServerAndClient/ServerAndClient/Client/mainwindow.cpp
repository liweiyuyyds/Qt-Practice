#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_port = ui->PortLineEdit->text();
    m_IP = ui->IPEdit->text();

    infoExchange = new InformationExchange();
    m_clientName = "liweiyu";
    infoExchange->init(m_clientName);
    infoExchangeThread = createTread(infoExchange);
    infoExchangeThread->start();

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


void MainWindow::on_connectButton_clicked()
{
    unsigned int port = m_port.toUShort();
    emit connectServer(m_IP,port);
}

void MainWindow::createConnect()
{
    connect(this,&MainWindow::connectServer,infoExchange,&InformationExchange::connectServer);

    connect(this,&MainWindow::sendText,infoExchange,&InformationExchange::sendText);

    connect(this,&MainWindow::sendFile,infoExchange,&InformationExchange::sendFile);

}

void MainWindow::on_sendButton_clicked()
{
    QString text = ui->sendTextEdit->toPlainText();
    ui->sendTextEdit->clear();
    emit sendText(text);
}

void MainWindow::on_sendFileButton_clicked()
{
    QString fileName = ui->FilePathEdit->text();
    emit sendFile(fileName);
}

void MainWindow::on_openFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(NULL,"查找文件路径",".","*.txt");
    ui->FilePathEdit->setText(fileName);
}
