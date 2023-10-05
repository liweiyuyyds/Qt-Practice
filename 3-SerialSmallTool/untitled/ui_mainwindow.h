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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Widget;
    QGridLayout *gridLayout;
    QWidget *rightWidget;
    QGroupBox *receiveGroupBox;
    QPushButton *clearReceiveButton;
    QTextBrowser *receiveTextBrowser;
    QCheckBox *unpackCheckBox;
    QCheckBox *showHexCheckBox;
    QGroupBox *sendGroupBox;
    QPlainTextEdit *sendPlainTextEdit;
    QPushButton *clearSendButton;
    QWidget *leftWidget;
    QLabel *uartNumLabel;
    QLabel *baudRateLabel;
    QLabel *parityLabel;
    QLabel *dataBitsLabel;
    QLabel *stopBitsLabel;
    QComboBox *uartNumComboBox;
    QComboBox *baudRateComboBox;
    QComboBox *parityComboBox;
    QComboBox *dataBitsComboBox;
    QComboBox *stopBitsComboBox;
    QPushButton *openUARTButton;
    QPushButton *closeUARTButton;
    QCheckBox *sendCheckBox;
    QPushButton *sendButton;
    QLabel *sendCycleLabel;
    QLineEdit *timeCycleLineEdit;
    QLabel *msLabel;
    QCheckBox *hexCheckBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(905, 523);
        Widget = new QWidget(MainWindow);
        Widget->setObjectName(QString::fromUtf8("Widget"));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rightWidget = new QWidget(Widget);
        rightWidget->setObjectName(QString::fromUtf8("rightWidget"));
        receiveGroupBox = new QGroupBox(rightWidget);
        receiveGroupBox->setObjectName(QString::fromUtf8("receiveGroupBox"));
        receiveGroupBox->setGeometry(QRect(9, 9, 421, 231));
        clearReceiveButton = new QPushButton(receiveGroupBox);
        clearReceiveButton->setObjectName(QString::fromUtf8("clearReceiveButton"));
        clearReceiveButton->setGeometry(QRect(270, 190, 141, 31));
        receiveTextBrowser = new QTextBrowser(receiveGroupBox);
        receiveTextBrowser->setObjectName(QString::fromUtf8("receiveTextBrowser"));
        receiveTextBrowser->setGeometry(QRect(10, 40, 401, 141));
        unpackCheckBox = new QCheckBox(receiveGroupBox);
        unpackCheckBox->setObjectName(QString::fromUtf8("unpackCheckBox"));
        unpackCheckBox->setGeometry(QRect(160, 190, 71, 41));
        showHexCheckBox = new QCheckBox(receiveGroupBox);
        showHexCheckBox->setObjectName(QString::fromUtf8("showHexCheckBox"));
        showHexCheckBox->setGeometry(QRect(40, 190, 91, 41));
        showHexCheckBox->setChecked(true);
        sendGroupBox = new QGroupBox(rightWidget);
        sendGroupBox->setObjectName(QString::fromUtf8("sendGroupBox"));
        sendGroupBox->setGeometry(QRect(10, 250, 421, 241));
        sendPlainTextEdit = new QPlainTextEdit(sendGroupBox);
        sendPlainTextEdit->setObjectName(QString::fromUtf8("sendPlainTextEdit"));
        sendPlainTextEdit->setGeometry(QRect(10, 40, 401, 151));
        clearSendButton = new QPushButton(sendGroupBox);
        clearSendButton->setObjectName(QString::fromUtf8("clearSendButton"));
        clearSendButton->setGeometry(QRect(270, 200, 131, 31));

        gridLayout->addWidget(rightWidget, 0, 1, 1, 1);

        leftWidget = new QWidget(Widget);
        leftWidget->setObjectName(QString::fromUtf8("leftWidget"));
        uartNumLabel = new QLabel(leftWidget);
        uartNumLabel->setObjectName(QString::fromUtf8("uartNumLabel"));
        uartNumLabel->setGeometry(QRect(20, 20, 51, 16));
        baudRateLabel = new QLabel(leftWidget);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));
        baudRateLabel->setGeometry(QRect(20, 80, 61, 31));
        parityLabel = new QLabel(leftWidget);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));
        parityLabel->setGeometry(QRect(20, 140, 51, 16));
        dataBitsLabel = new QLabel(leftWidget);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));
        dataBitsLabel->setGeometry(QRect(20, 200, 51, 16));
        stopBitsLabel = new QLabel(leftWidget);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));
        stopBitsLabel->setGeometry(QRect(20, 260, 51, 16));
        uartNumComboBox = new QComboBox(leftWidget);
        uartNumComboBox->addItem(QString());
        uartNumComboBox->addItem(QString());
        uartNumComboBox->addItem(QString());
        uartNumComboBox->addItem(QString());
        uartNumComboBox->addItem(QString());
        uartNumComboBox->addItem(QString());
        uartNumComboBox->addItem(QString());
        uartNumComboBox->addItem(QString());
        uartNumComboBox->addItem(QString());
        uartNumComboBox->setObjectName(QString::fromUtf8("uartNumComboBox"));
        uartNumComboBox->setGeometry(QRect(90, 9, 331, 41));
        baudRateComboBox = new QComboBox(leftWidget);
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->setObjectName(QString::fromUtf8("baudRateComboBox"));
        baudRateComboBox->setGeometry(QRect(90, 70, 331, 41));
        parityComboBox = new QComboBox(leftWidget);
        parityComboBox->addItem(QString());
        parityComboBox->addItem(QString());
        parityComboBox->addItem(QString());
        parityComboBox->setObjectName(QString::fromUtf8("parityComboBox"));
        parityComboBox->setGeometry(QRect(90, 129, 331, 41));
        dataBitsComboBox = new QComboBox(leftWidget);
        dataBitsComboBox->addItem(QString());
        dataBitsComboBox->addItem(QString());
        dataBitsComboBox->setObjectName(QString::fromUtf8("dataBitsComboBox"));
        dataBitsComboBox->setGeometry(QRect(90, 190, 331, 41));
        stopBitsComboBox = new QComboBox(leftWidget);
        stopBitsComboBox->addItem(QString());
        stopBitsComboBox->addItem(QString());
        stopBitsComboBox->addItem(QString());
        stopBitsComboBox->setObjectName(QString::fromUtf8("stopBitsComboBox"));
        stopBitsComboBox->setGeometry(QRect(90, 250, 331, 41));
        openUARTButton = new QPushButton(leftWidget);
        openUARTButton->setObjectName(QString::fromUtf8("openUARTButton"));
        openUARTButton->setGeometry(QRect(90, 320, 101, 41));
        closeUARTButton = new QPushButton(leftWidget);
        closeUARTButton->setObjectName(QString::fromUtf8("closeUARTButton"));
        closeUARTButton->setGeometry(QRect(330, 320, 91, 41));
        sendCheckBox = new QCheckBox(leftWidget);
        sendCheckBox->setObjectName(QString::fromUtf8("sendCheckBox"));
        sendCheckBox->setGeometry(QRect(10, 410, 91, 31));
        sendButton = new QPushButton(leftWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(120, 380, 301, 41));
        sendCycleLabel = new QLabel(leftWidget);
        sendCycleLabel->setObjectName(QString::fromUtf8("sendCycleLabel"));
        sendCycleLabel->setGeometry(QRect(30, 460, 61, 20));
        timeCycleLineEdit = new QLineEdit(leftWidget);
        timeCycleLineEdit->setObjectName(QString::fromUtf8("timeCycleLineEdit"));
        timeCycleLineEdit->setGeometry(QRect(120, 450, 171, 31));
        timeCycleLineEdit->setInputMethodHints(Qt::ImhDigitsOnly);
        msLabel = new QLabel(leftWidget);
        msLabel->setObjectName(QString::fromUtf8("msLabel"));
        msLabel->setGeometry(QRect(310, 460, 54, 21));
        hexCheckBox = new QCheckBox(leftWidget);
        hexCheckBox->setObjectName(QString::fromUtf8("hexCheckBox"));
        hexCheckBox->setGeometry(QRect(10, 360, 161, 41));

        gridLayout->addWidget(leftWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(Widget);
#if QT_CONFIG(shortcut)
        uartNumLabel->setBuddy(uartNumComboBox);
        baudRateLabel->setBuddy(baudRateComboBox);
        parityLabel->setBuddy(parityComboBox);
        dataBitsLabel->setBuddy(dataBitsComboBox);
        stopBitsLabel->setBuddy(stopBitsComboBox);
        sendCycleLabel->setBuddy(timeCycleLineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        receiveGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
        clearReceiveButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266\345\214\272", nullptr));
        unpackCheckBox->setText(QCoreApplication::translate("MainWindow", "\350\247\243\345\214\205", nullptr));
        showHexCheckBox->setText(QCoreApplication::translate("MainWindow", "Hex\346\230\276\347\244\272", nullptr));
        sendGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        clearSendButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201\345\214\272", nullptr));
        uartNumLabel->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        baudRateLabel->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        parityLabel->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        dataBitsLabel->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        stopBitsLabel->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        uartNumComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "COM1", nullptr));
        uartNumComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "COM2", nullptr));
        uartNumComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "COM3", nullptr));
        uartNumComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "COM4", nullptr));
        uartNumComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "COM5", nullptr));
        uartNumComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "COM6", nullptr));
        uartNumComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "COM7", nullptr));
        uartNumComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "COM8", nullptr));
        uartNumComboBox->setItemText(8, QCoreApplication::translate("MainWindow", "COM9", nullptr));

        baudRateComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "115200", nullptr));
        baudRateComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "76800", nullptr));
        baudRateComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "57600", nullptr));
        baudRateComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "38400", nullptr));
        baudRateComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "19200", nullptr));
        baudRateComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "14400", nullptr));
        baudRateComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "9600", nullptr));
        baudRateComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "4800", nullptr));

        parityComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "NONE", nullptr));
        parityComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "ODD", nullptr));
        parityComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "EVEN", nullptr));

        dataBitsComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        dataBitsComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));

        stopBitsComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        stopBitsComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        stopBitsComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        openUARTButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        closeUARTButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
        sendCheckBox->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        sendCycleLabel->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\221\250\346\234\237\357\274\232", nullptr));
        timeCycleLineEdit->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        msLabel->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        hexCheckBox->setText(QCoreApplication::translate("MainWindow", "Hex\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
