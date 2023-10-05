#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "packunpack.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_packButton_clicked();

    void on_unpackButton_clicked();

private:
    Ui::Widget *ui;
    PackUnpack m_packunpack;
};
#endif // MAINWINDOW_H
