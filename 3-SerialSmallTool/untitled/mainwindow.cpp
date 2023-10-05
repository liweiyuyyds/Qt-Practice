#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

//#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromLocal8Bit("串口通信小工具"));
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());

    //    mUARTOpenFlag=false;
    m_pack_unpack = new PackUnpack();

    //通过QSerialPortInfo查找可用串口并显示
    ui->uartNumComboBox->clear();
    foreach (const QSerialPortInfo& info, QSerialPortInfo::availablePorts()) {
        ui->uartNumComboBox->addItem(info.portName());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pack_unpack;
    delete m_serial_port;
}


void MainWindow::on_openUARTButton_clicked()
{
    if(!m_UART_openflag)
    {
        m_serial_port=new QSerialPort();
        m_serial_port->setPortName(ui->uartNumComboBox->currentText());
        if(m_serial_port->open(QIODevice::ReadWrite))
        {
            //设置波特率
            m_serial_port->setBaudRate(ui->baudRateComboBox->currentText().toInt());
            //设置数据位
            switch (ui->dataBitsComboBox->currentIndex())
            {
                case 0:
                    m_serial_port->setDataBits(QSerialPort::Data8);
                    break;
                case 1:
                    m_serial_port->setDataBits(QSerialPort::Data7);
                    break;
            }
            //设置停止位
            switch (ui->stopBitsComboBox->currentIndex())
            {
                case 0:
                    m_serial_port->setStopBits(QSerialPort::OneStop);
                    break;
                case 1:
                    m_serial_port->setStopBits(QSerialPort::OneAndHalfStop);
                    break;
                case 2:
                    m_serial_port->setStopBits(QSerialPort::TwoStop);
                    break;
            }
            //设置校验位
            switch (ui->parityComboBox->currentIndex()) {
                case 0:
                    m_serial_port->setParity(QSerialPort::NoParity);
                    break;
                case 1:
                    m_serial_port->setParity(QSerialPort::OddParity);
                    break;
                case 2:
                    m_serial_port->setParity(QSerialPort::EvenParity);
                    break;
            }
            //设置流控制
            m_serial_port->setFlowControl(QSerialPort::NoFlowControl);

            connect(m_serial_port,SIGNAL(QSerialPort::readyRead()),this,SLOT(read_serial()));

        }
        else
        {
            QMessageBox::about(nullptr, "提示", "串口无法打开\r\n不存在或已被占用");
            return;
        }
        m_UART_openflag=true;
    }


}


//关闭串口槽函数
void MainWindow::on_closeUARTButton_clicked()
{
    if(m_UART_openflag)
    {
        m_serial_port->clear();
        m_serial_port->close();
        m_serial_port->deleteLater();
        m_UART_openflag=false;
    }
}


void MainWindow::on_sendButton_clicked()
{
    if(m_UART_openflag)
    {
        if(m_serial_port->isOpen())
        {
            QString send_str = ui->sendPlainTextEdit->toPlainText();
            if(ui->hexCheckBox->isChecked())
            {
                QByteArray bytes = QByteArray::fromHex(send_str.toLatin1());
                m_serial_port->write(bytes);
            }
            else
            {
                QByteArray bytes = send_str.toLocal8Bit();
                m_serial_port->write(bytes);
            }
        }
    }

}

void MainWindow::read_serial()
{
    m_rx_data = m_serial_port->readAll();
    if(!m_rx_data.isEmpty())
    {
        if(ui->unpackCheckBox->checkState())
        {
            process_UART_data();
        }
        else if(ui->hexCheckBox->checkState())
        {
            QString str = m_rx_data.toHex().data();
            str = str.toUpper();
            QString buffer;

            for (int i=0;i<str.length() ;i+=2 )
            {
                buffer+=str.mid(i,2);
                buffer+=" ";
            }
            ui->receiveTextBrowser->append(buffer);

        }
        else
        {
            ui->receiveTextBrowser->append(m_rx_data);
        }
    }
    m_rx_data.clear();

}

void MainWindow::process_UART_data()
{
    char* buffer=nullptr;
    if(m_rx_data.size()>0)
    {
        buffer = m_rx_data.data();
    }

    for(int i=0;i<m_rx_data.size();i++)
    {
        unpack_recv_data(*(buffer+i));
    }
    m_rx_data.clear();

}

//解包并显示串口数据
bool MainWindow::unpack_recv_data(uchar data)
{
    bool findPack = false;
    QString unpack_result;

    findPack = m_pack_unpack->unpackData(data);

    if(findPack)
    {
        if(m_data_after_unpack.size() > 10)
        {
            QMessageBox::information(NULL, tr("Info"), tr("长度异常"), "确定");
        }

       m_data_after_unpack = m_pack_unpack->getUnpackRslt();  //获取解包结果

       for(int j = 0; j < m_data_after_unpack.count() - 2; j++)
       {
           unpack_result += QString("%1").arg(m_data_after_unpack.at(j), 2, 16, QLatin1Char('0')) + " ";
       }

      ui->receiveTextBrowser->append(unpack_result);
    }

    return findPack;
}

void MainWindow::on_clearReceiveButton_clicked()
{
    ui->receiveTextBrowser->clear();
}


void MainWindow::on_clearSendButton_clicked()
{
    ui->sendPlainTextEdit->clear();
}


void MainWindow::on_timeCycleLineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    m_timer_interval=ui->timeCycleLineEdit->text().toInt();
}

void MainWindow::timerEvent(QTimerEvent* event)
{
    if(event->timerId()==m_timer_id)
    {
        on_sendButton_clicked();
    }
}

void MainWindow::on_sendCheckBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1);
    if(ui->sendCheckBox->checkState())
    {
        m_timer_id=startTimer(m_timer_interval);
    }
    else
    {
        killTimer(m_timer_id);
    }
}

