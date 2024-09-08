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
        updateDisplay();
    });

    // Запись [this](int value) — это лямбда-функция в C++
    connect(ui->horizontalSlider_Y, &QSlider::valueChanged, this, [this](int value) {
        y_value = value;
        updateDisplay();
    });

    plotGraph();
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


void MainWindow::plotGraph()
{
    // Создаем график на QCustomPlot
    QVector<double> x(101), y(101); // 101 точка для x^2

    for (int i=0; i<101; ++i)
    {
        x[i] = i - 50;  // Значения x от -50 до 50
        y[i] = x[i] * x[i];  // y = x^2
    }

    // Добавляем данные на график
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    // Устанавливаем диапазоны осей
    ui->customPlot->xAxis->setRange(-50, 50);
    ui->customPlot->yAxis->setRange(0, 2500);

    // Отрисовываем график
    ui->customPlot->replot();
}

void MainWindow::updateGraph()
{

}
