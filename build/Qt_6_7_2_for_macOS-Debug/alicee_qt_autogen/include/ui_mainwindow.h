/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *horizontalSlider_X;
    QLabel *label_X;
    QLCDNumber *lcdNumber;
    QSlider *horizontalSlider_Y;
    QLabel *label_Y;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(400, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalSlider_X = new QSlider(centralwidget);
        horizontalSlider_X->setObjectName("horizontalSlider_X");
        horizontalSlider_X->setGeometry(QRect(60, 420, 711, 25));
        horizontalSlider_X->setOrientation(Qt::Orientation::Horizontal);
        label_X = new QLabel(centralwidget);
        label_X->setObjectName("label_X");
        label_X->setGeometry(QRect(30, 420, 21, 16));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(250, 320, 301, 91));
        horizontalSlider_Y = new QSlider(centralwidget);
        horizontalSlider_Y->setObjectName("horizontalSlider_Y");
        horizontalSlider_Y->setGeometry(QRect(60, 480, 711, 25));
        horizontalSlider_Y->setOrientation(Qt::Orientation::Horizontal);
        label_Y = new QLabel(centralwidget);
        label_Y->setObjectName("label_Y");
        label_Y->setGeometry(QRect(30, 480, 21, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_Y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
