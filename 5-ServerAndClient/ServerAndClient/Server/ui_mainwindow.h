/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *listenButton;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *chatHistoryBox;
    QGridLayout *gridLayout_2;
    QTextEdit *chatHistoryEdit;
    QGroupBox *sendTextBox;
    QGridLayout *gridLayout_3;
    QTextEdit *sendTextEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 676);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 776, 572));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(layoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(10, 0));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        PortLabel = new QLabel(widget);
        PortLabel->setObjectName(QString::fromUtf8("PortLabel"));

        horizontalLayout->addWidget(PortLabel);

        PortLineEdit = new QLineEdit(widget);
        PortLineEdit->setObjectName(QString::fromUtf8("PortLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PortLineEdit->sizePolicy().hasHeightForWidth());
        PortLineEdit->setSizePolicy(sizePolicy2);
        PortLineEdit->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(PortLineEdit);

        listenButton = new QPushButton(widget);
        listenButton->setObjectName(QString::fromUtf8("listenButton"));
        listenButton->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(listenButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget);

        chatHistoryBox = new QGroupBox(layoutWidget);
        chatHistoryBox->setObjectName(QString::fromUtf8("chatHistoryBox"));
        gridLayout_2 = new QGridLayout(chatHistoryBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chatHistoryEdit = new QTextEdit(chatHistoryBox);
        chatHistoryEdit->setObjectName(QString::fromUtf8("chatHistoryEdit"));

        gridLayout_2->addWidget(chatHistoryEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(chatHistoryBox);

        sendTextBox = new QGroupBox(layoutWidget);
        sendTextBox->setObjectName(QString::fromUtf8("sendTextBox"));
        gridLayout_3 = new QGridLayout(sendTextBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        sendTextEdit = new QTextEdit(sendTextBox);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));

        gridLayout_3->addWidget(sendTextEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(sendTextBox);

        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(272, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        sendButton = new QPushButton(widget_2);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setMinimumSize(QSize(200, 0));

        horizontalLayout_3->addWidget(sendButton);

        horizontalSpacer_2 = new QSpacerItem(272, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        PortLabel->setText(QCoreApplication::translate("MainWindow", "Port\357\274\232", nullptr));
        PortLineEdit->setText(QCoreApplication::translate("MainWindow", "8888", nullptr));
        listenButton->setText(QCoreApplication::translate("MainWindow", "\347\233\221\345\220\254", nullptr));
        chatHistoryBox->setTitle(QCoreApplication::translate("MainWindow", "\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
        sendTextBox->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\346\234\254", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
