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
#include <QtWidgets/QFormLayout>
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
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *IPlabel;
    QLineEdit *IPEdit;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *connectButton;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_4;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *FilePathEdit;
    QPushButton *openFileButton;
    QPushButton *sendFileButton;
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
        MainWindow->resize(843, 623);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(10, 0));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        IPlabel = new QLabel(widget);
        IPlabel->setObjectName(QString::fromUtf8("IPlabel"));

        horizontalLayout->addWidget(IPlabel);

        IPEdit = new QLineEdit(widget);
        IPEdit->setObjectName(QString::fromUtf8("IPEdit"));

        horizontalLayout->addWidget(IPEdit);

        PortLabel = new QLabel(widget);
        PortLabel->setObjectName(QString::fromUtf8("PortLabel"));

        horizontalLayout->addWidget(PortLabel);

        PortLineEdit = new QLineEdit(widget);
        PortLineEdit->setObjectName(QString::fromUtf8("PortLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PortLineEdit->sizePolicy().hasHeightForWidth());
        PortLineEdit->setSizePolicy(sizePolicy1);
        PortLineEdit->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(PortLineEdit);

        connectButton = new QPushButton(widget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(connectButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        formLayout = new QFormLayout(widget_4);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        FilePathEdit = new QLineEdit(widget_4);
        FilePathEdit->setObjectName(QString::fromUtf8("FilePathEdit"));

        horizontalLayout_2->addWidget(FilePathEdit);

        openFileButton = new QPushButton(widget_4);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        horizontalLayout_2->addWidget(openFileButton);

        sendFileButton = new QPushButton(widget_4);
        sendFileButton->setObjectName(QString::fromUtf8("sendFileButton"));

        horizontalLayout_2->addWidget(sendFileButton);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout_2);


        verticalLayout->addWidget(widget_4);

        chatHistoryBox = new QGroupBox(centralwidget);
        chatHistoryBox->setObjectName(QString::fromUtf8("chatHistoryBox"));
        gridLayout_2 = new QGridLayout(chatHistoryBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chatHistoryEdit = new QTextEdit(chatHistoryBox);
        chatHistoryEdit->setObjectName(QString::fromUtf8("chatHistoryEdit"));

        gridLayout_2->addWidget(chatHistoryEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(chatHistoryBox);

        sendTextBox = new QGroupBox(centralwidget);
        sendTextBox->setObjectName(QString::fromUtf8("sendTextBox"));
        gridLayout_3 = new QGridLayout(sendTextBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        sendTextEdit = new QTextEdit(sendTextBox);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));

        gridLayout_3->addWidget(sendTextEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(sendTextBox);

        widget_2 = new QWidget(centralwidget);
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

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 843, 25));
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
        IPlabel->setText(QCoreApplication::translate("MainWindow", "IP\357\274\232", nullptr));
        IPEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        PortLabel->setText(QCoreApplication::translate("MainWindow", "Port\357\274\232", nullptr));
        PortLineEdit->setText(QCoreApplication::translate("MainWindow", "8888", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        sendFileButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
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
