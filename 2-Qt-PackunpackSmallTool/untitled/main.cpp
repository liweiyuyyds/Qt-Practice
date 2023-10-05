#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    uchar i=1;
    qDebug()<<i;
    i<<=1;
    qDebug()<<i;
    i|=(0x80>>7);
    qDebug()<<i;

    QApplication a(argc, argv);

    QFile qssFile(":/new/prefix1/dark_teal.qss");
    if (qssFile.open(QFile::ReadOnly))
    {
        a.setStyleSheet(qssFile.readAll());
    }

    Widget w;
    w.show();
    return a.exec();
}
