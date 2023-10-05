#include "mainwindow.h"
#include "ui_widget.h"

#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include "utils.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromLocal8Bit("打包解包小工具"));
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_packButton_clicked()
{
    QList<QString> data_list;
    QList<uchar> temp_list;

    data_list.append(ui->modIDLineEdit->text().toLatin1().toHex());
    data_list.append(ui->secIDLineEdit->text().toLatin1().toHex());

    QStringList packDinList= ui->packDinLineEdit->text().split(" ");
    if(packDinList.length()!=6)
    {
        QMessageBox::information(nullptr, tr("提示"), tr("打包数据长度错误"), "确定");
        return;
    }
    for(int i = 0; i < packDinList.length(); i++)
    {
        data_list.append(packDinList[i].toLatin1().toHex());
    }

    data_list.append(QString("00").toLatin1().toHex());
    data_list.append(QString("00").toLatin1().toHex());

    bool ok = false;

    for(int i = 0; i < data_list.count(); i++)
    {
        temp_list.append(convertHexStrToByteArray(data_list.at(i)).toInt(&ok, 16));
    }

    m_packunpack.pack_data(temp_list);

    QString packDout;

    for(int i = 0; i < temp_list.count(); i++)
    {
        packDout += QString::number(temp_list.at(i), 16).right(4) + " ";
    }


    ui->packDoutLineEdit->setText(packDout);

}


void Widget::on_unpackButton_clicked()
{
    QList<uchar> unpackRsltList;
    QString unpackDout;
    bool findPack = false;
    bool ok;

    QString unpackDin;
    unpackDin = ui->unpackDinLineEdit->text().trimmed();  //去掉前后空格
    QStringList unpackDinList = unpackDin.split(" ");

    if(unpackDinList.length() != 10)
    {
        QMessageBox::information(nullptr, tr("提示"), tr("解包数据长度错误"), "确定");
        return;
    }

    for(int i = 0; i < unpackDinList.count(); i++)
    {
        qDebug() << unpackDinList.at(i).toLatin1();
        qDebug() << unpackDinList.at(i).toLatin1().toHex();

        findPack = m_packunpack.unpackData(convertHexStrToByteArray(unpackDinList.at(i).toLatin1().toHex()).toInt(&ok, 16));

        if(findPack)
        {
           unpackRsltList = m_packunpack.getUnpackRslt();

           for(int j = 0; j < unpackRsltList.count() - 2; j++)
           {
               unpackDout += QString("%1").arg(unpackRsltList.at(j),2,16,QLatin1Char('0')) + " ";
           }


           ui->unpackDoutLineEdit->setText(unpackDout);
           break;
        }
    }
}






