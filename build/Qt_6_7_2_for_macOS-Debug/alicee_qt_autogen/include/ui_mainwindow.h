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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *horizontalSlider_X;
    QLabel *label_X;
    QLCDNumber *lcdNumber_X;
    QLabel *label_Y;
    QLCDNumber *lcdNumber_Y;
    QSlider *horizontalSlider_Y;
    QCustomPlot *customPlot;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 743);
        MainWindow->setMinimumSize(QSize(400, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalSlider_X = new QSlider(centralwidget);
        horizontalSlider_X->setObjectName("horizontalSlider_X");
        horizontalSlider_X->setGeometry(QRect(16, 372, 84, 25));
        horizontalSlider_X->setMinimum(-100);
        horizontalSlider_X->setMaximum(100);
        horizontalSlider_X->setOrientation(Qt::Orientation::Horizontal);
        label_X = new QLabel(centralwidget);
        label_X->setObjectName("label_X");
        label_X->setGeometry(QRect(2, 372, 16, 16));
        lcdNumber_X = new QLCDNumber(centralwidget);
        lcdNumber_X->setObjectName("lcdNumber_X");
        lcdNumber_X->setGeometry(QRect(108, 372, 64, 23));
        label_Y = new QLabel(centralwidget);
        label_Y->setObjectName("label_Y");
        label_Y->setGeometry(QRect(2, 462, 16, 16));
        lcdNumber_Y = new QLCDNumber(centralwidget);
        lcdNumber_Y->setObjectName("lcdNumber_Y");
        lcdNumber_Y->setGeometry(QRect(108, 462, 64, 23));
        horizontalSlider_Y = new QSlider(centralwidget);
        horizontalSlider_Y->setObjectName("horizontalSlider_Y");
        horizontalSlider_Y->setGeometry(QRect(16, 462, 84, 25));
        horizontalSlider_Y->setMinimum(-100);
        horizontalSlider_Y->setMaximum(100);
        horizontalSlider_Y->setOrientation(Qt::Orientation::Horizontal);
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName("customPlot");
        customPlot->setEnabled(true);
        customPlot->setGeometry(QRect(141, 21, 499, 349));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(100, 650, 103, 32));
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
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "New Item", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "New Item", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "New Item", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
