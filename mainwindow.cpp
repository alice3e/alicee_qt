#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>     // std::cout
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Соединяем слайдер с методом, который обновляет lcdNumber
    connect(ui->horizontalSlider_X, &QSlider::valueChanged, this, [this](int value) {
        x_value = value;
        updateDisplay();
    });

    // Запись [this](int value) — это лямбда-функция в C++
    connect(ui->horizontalSlider_Y, &QSlider::valueChanged, this, [this](int value) {
        y_value = value;
        updateDisplay();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay()
{
    int max_value = std::max(x_value,y_value);
    ui->lcdNumber->display(max_value);
}
