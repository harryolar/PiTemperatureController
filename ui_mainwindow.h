/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Oct 3 00:18:43 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEditP;
    QLineEdit *lineEditI;
    QLineEdit *lineEditD;
    QLineEdit *lineEditSetTemperature;
    QPushButton *pushButtonSetTemperature;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButtonLoadPID;
    QPushButton *pushButtonSaveparams;
    QDial *dial;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(547, 351);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 180, 111, 24));
        lineEditP = new QLineEdit(centralWidget);
        lineEditP->setObjectName(QString::fromUtf8("lineEditP"));
        lineEditP->setGeometry(QRect(390, 90, 113, 23));
        lineEditI = new QLineEdit(centralWidget);
        lineEditI->setObjectName(QString::fromUtf8("lineEditI"));
        lineEditI->setGeometry(QRect(390, 120, 113, 23));
        lineEditD = new QLineEdit(centralWidget);
        lineEditD->setObjectName(QString::fromUtf8("lineEditD"));
        lineEditD->setGeometry(QRect(390, 150, 113, 23));
        lineEditSetTemperature = new QLineEdit(centralWidget);
        lineEditSetTemperature->setObjectName(QString::fromUtf8("lineEditSetTemperature"));
        lineEditSetTemperature->setGeometry(QRect(110, 230, 51, 23));
        pushButtonSetTemperature = new QPushButton(centralWidget);
        pushButtonSetTemperature->setObjectName(QString::fromUtf8("pushButtonSetTemperature"));
        pushButtonSetTemperature->setGeometry(QRect(170, 230, 121, 24));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 50, 301, 131));
        lcdNumber->setSmallDecimalPoint(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 171, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 90, 16, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 120, 20, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(370, 150, 16, 16));
        pushButtonLoadPID = new QPushButton(centralWidget);
        pushButtonLoadPID->setObjectName(QString::fromUtf8("pushButtonLoadPID"));
        pushButtonLoadPID->setGeometry(QRect(390, 200, 111, 24));
        pushButtonSaveparams = new QPushButton(centralWidget);
        pushButtonSaveparams->setObjectName(QString::fromUtf8("pushButtonSaveparams"));
        pushButtonSaveparams->setGeometry(QRect(390, 220, 111, 27));
        dial = new QDial(centralWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(50, 210, 50, 64));
        dial->setMaximum(100);
        dial->setWrapping(true);
        dial->setNotchesVisible(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 547, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Set PID", 0, QApplication::UnicodeUTF8));
        lineEditP->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        lineEditI->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        lineEditD->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        lineEditSetTemperature->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButtonSetTemperature->setText(QApplication::translate("MainWindow", "Set Temperature", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Current temperature", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "P", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "I", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
        pushButtonLoadPID->setText(QApplication::translate("MainWindow", "Load PID", 0, QApplication::UnicodeUTF8));
        pushButtonSaveparams->setText(QApplication::translate("MainWindow", "Save PID", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
