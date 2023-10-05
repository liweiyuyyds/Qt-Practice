/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *rightWidget;
    QPushButton *packButton;
    QLineEdit *secIDLineEdit;
    QPushButton *unpackButton;
    QLabel *secIDLabel;
    QLabel *modIDLabel;
    QLineEdit *modIDLineEdit;
    QWidget *leftWidget;
    QGroupBox *packGroupBox;
    QLabel *packDinLabel;
    QLineEdit *packDinLineEdit;
    QLabel *packDoutLabel;
    QLineEdit *packDoutLineEdit;
    QGroupBox *unpackGroupBox;
    QLabel *unpackDoutLabel;
    QLabel *unpackDinLabel;
    QLineEdit *unpackDoutLineEdit;
    QLineEdit *unpackDinLineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(827, 519);
        rightWidget = new QWidget(Widget);
        rightWidget->setObjectName(QString::fromUtf8("rightWidget"));
        rightWidget->setGeometry(QRect(640, 20, 161, 481));
        packButton = new QPushButton(rightWidget);
        packButton->setObjectName(QString::fromUtf8("packButton"));
        packButton->setGeometry(QRect(10, 180, 121, 41));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(packButton->sizePolicy().hasHeightForWidth());
        packButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        packButton->setFont(font);
        secIDLineEdit = new QLineEdit(rightWidget);
        secIDLineEdit->setObjectName(QString::fromUtf8("secIDLineEdit"));
        secIDLineEdit->setGeometry(QRect(10, 130, 141, 41));
        secIDLineEdit->setFont(font);
        unpackButton = new QPushButton(rightWidget);
        unpackButton->setObjectName(QString::fromUtf8("unpackButton"));
        unpackButton->setGeometry(QRect(10, 430, 121, 41));
        unpackButton->setFont(font);
        secIDLabel = new QLabel(rightWidget);
        secIDLabel->setObjectName(QString::fromUtf8("secIDLabel"));
        secIDLabel->setGeometry(QRect(10, 100, 101, 31));
        secIDLabel->setFont(font);
        modIDLabel = new QLabel(rightWidget);
        modIDLabel->setObjectName(QString::fromUtf8("modIDLabel"));
        modIDLabel->setGeometry(QRect(10, 10, 91, 31));
        modIDLabel->setFont(font);
        modIDLineEdit = new QLineEdit(rightWidget);
        modIDLineEdit->setObjectName(QString::fromUtf8("modIDLineEdit"));
        modIDLineEdit->setGeometry(QRect(10, 50, 141, 41));
        modIDLineEdit->setFont(font);
        leftWidget = new QWidget(Widget);
        leftWidget->setObjectName(QString::fromUtf8("leftWidget"));
        leftWidget->setGeometry(QRect(9, 19, 621, 491));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftWidget->sizePolicy().hasHeightForWidth());
        leftWidget->setSizePolicy(sizePolicy1);
        leftWidget->setLayoutDirection(Qt::LeftToRight);
        packGroupBox = new QGroupBox(leftWidget);
        packGroupBox->setObjectName(QString::fromUtf8("packGroupBox"));
        packGroupBox->setGeometry(QRect(0, 0, 611, 231));
        packGroupBox->setFont(font);
        packDinLabel = new QLabel(packGroupBox);
        packDinLabel->setObjectName(QString::fromUtf8("packDinLabel"));
        packDinLabel->setGeometry(QRect(30, 25, 461, 21));
        packDinLabel->setFont(font);
        packDinLineEdit = new QLineEdit(packGroupBox);
        packDinLineEdit->setObjectName(QString::fromUtf8("packDinLineEdit"));
        packDinLineEdit->setGeometry(QRect(30, 60, 541, 51));
        QFont font1;
        font1.setPointSize(16);
        packDinLineEdit->setFont(font1);
        packDoutLabel = new QLabel(packGroupBox);
        packDoutLabel->setObjectName(QString::fromUtf8("packDoutLabel"));
        packDoutLabel->setGeometry(QRect(30, 120, 491, 41));
        packDoutLabel->setFont(font);
        packDoutLineEdit = new QLineEdit(packGroupBox);
        packDoutLineEdit->setObjectName(QString::fromUtf8("packDoutLineEdit"));
        packDoutLineEdit->setGeometry(QRect(30, 170, 541, 51));
        packDoutLineEdit->setFont(font1);
        unpackGroupBox = new QGroupBox(leftWidget);
        unpackGroupBox->setObjectName(QString::fromUtf8("unpackGroupBox"));
        unpackGroupBox->setGeometry(QRect(0, 250, 611, 231));
        unpackGroupBox->setFont(font);
        unpackDoutLabel = new QLabel(unpackGroupBox);
        unpackDoutLabel->setObjectName(QString::fromUtf8("unpackDoutLabel"));
        unpackDoutLabel->setGeometry(QRect(30, 120, 451, 41));
        unpackDinLabel = new QLabel(unpackGroupBox);
        unpackDinLabel->setObjectName(QString::fromUtf8("unpackDinLabel"));
        unpackDinLabel->setGeometry(QRect(30, 20, 401, 41));
        unpackDoutLineEdit = new QLineEdit(unpackGroupBox);
        unpackDoutLineEdit->setObjectName(QString::fromUtf8("unpackDoutLineEdit"));
        unpackDoutLineEdit->setGeometry(QRect(30, 170, 541, 51));
        unpackDoutLineEdit->setFont(font1);
        unpackDinLineEdit = new QLineEdit(unpackGroupBox);
        unpackDinLineEdit->setObjectName(QString::fromUtf8("unpackDinLineEdit"));
        unpackDinLineEdit->setGeometry(QRect(30, 60, 541, 51));
        unpackDinLineEdit->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        packButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\214\205", nullptr));
        secIDLineEdit->setText(QCoreApplication::translate("Widget", "02", nullptr));
        unpackButton->setText(QCoreApplication::translate("Widget", "\350\247\243\345\214\205", nullptr));
        secIDLabel->setText(QCoreApplication::translate("Widget", "\344\272\214\347\272\247ID", nullptr));
        modIDLabel->setText(QCoreApplication::translate("Widget", "\346\250\241\345\235\227ID", nullptr));
        modIDLineEdit->setText(QCoreApplication::translate("Widget", "12", nullptr));
        packGroupBox->setTitle(QCoreApplication::translate("Widget", "\346\211\223\345\214\205", nullptr));
        packDinLabel->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\350\243\270\346\225\260\346\215\256\357\274\2106\345\255\227\350\212\202\357\274\214\347\251\272\346\240\274\351\232\224\345\274\200\357\274\211", nullptr));
        packDinLineEdit->setText(QCoreApplication::translate("Widget", "00 01 6E 01 70 00", nullptr));
        packDoutLabel->setText(QCoreApplication::translate("Widget", "\350\276\223\345\207\272\346\211\223\345\214\205\345\245\275\347\232\204\346\225\260\346\215\256\357\274\21010\345\255\227\350\212\202\357\274\211", nullptr));
        unpackGroupBox->setTitle(QCoreApplication::translate("Widget", "\350\247\243\345\214\205", nullptr));
        unpackDoutLabel->setText(QCoreApplication::translate("Widget", "\350\276\223\345\207\272\350\247\243\345\214\205\345\245\275\347\232\204\346\225\260\346\215\256\357\274\2108\345\255\227\350\212\202\357\274\211", nullptr));
        unpackDinLabel->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\345\276\205\350\247\243\345\214\205\346\225\260\346\215\256\357\274\21010\345\255\227\350\212\202\357\274\214\347\251\272\346\240\274\351\232\224\345\274\200\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
