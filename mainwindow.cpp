#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "lib/qcustomplot.h"

#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Соединяем слайдер с методом, который обновляет lcdNumber
    connect(ui->horizontalSlider_X, &QSlider::valueChanged, this, [this](int value) {
        x_value = value;
        updateDisplay_X();
        plotGraph();
    });

    // Запись [this](int value) — это лямбда-функция в C++
    connect(ui->horizontalSlider_Y, &QSlider::valueChanged, this, [this](int value) {
        y_value = value;
        updateDisplay_Y();
        plotGraph();
    });

    plotGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay_X()
{
    ui->lcdNumber_X->display(x_value / 10.0);
}

void MainWindow::updateDisplay_Y()
{
    ui->lcdNumber_Y->display(y_value / 10.0);
}

void MainWindow::plotGraph()
{
    // Создаем график на QCustomPlot
    QVector<double> x(101), y(101); // 101 точка для x^2
    double b = x_value / 10.0;
    double a = y_value / 10.0;
    for (int i=0; i<101; ++i)
    {
        x[i] = i - 50;  // Значения x от -50 до 50
        y[i] = a*x[i] + b;  // y = a*x + b
    }

    // Добавляем данные на график
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    // Устанавливаем диапазоны осей
    ui->customPlot->xAxis->setRange(-5, 5);
    ui->customPlot->yAxis->setRange(-5, 5);

    // Отрисовываем график
    ui->customPlot->replot();
}

void MainWindow::updateGraph()
{

}
