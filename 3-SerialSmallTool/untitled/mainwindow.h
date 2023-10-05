#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "packunpack.h"
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void timerEvent(QTimerEvent* event);

private slots:
    void on_openUARTButton_clicked();

    void on_closeUARTButton_clicked();

    void on_sendButton_clicked();

    void read_serial();

    void on_clearReceiveButton_clicked();

    void on_clearSendButton_clicked();

    void on_timeCycleLineEdit_textChanged(const QString &arg1);

    void on_sendCheckBox_stateChanged(int arg1);

private:
    void process_UART_data();

    bool unpack_recv_data(uchar data);

private:
    Ui::MainWindow *ui;

    bool m_UART_openflag=false; //串口状态

    int m_timer_id;
    int m_timer_interval=1000; //定时器间隔

    PackUnpack* m_pack_unpack;
    QSerialPort* m_serial_port;

    QByteArray m_rx_data;  //暂存接受到的数据
    QList<uchar> m_data_after_unpack;  //解包后的数据

};
#endif // MAINWINDOW_H
