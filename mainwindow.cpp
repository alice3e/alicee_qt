#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "lib/qcustomplot.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupLayout();

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

void MainWindow::setupLayout()
{
    // Создание и установка макета для центрального виджета
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QVBoxLayout *plotlayout = new QVBoxLayout(centralWidget);
    QVBoxLayout *sliderslayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *X_layout = new QHBoxLayout(centralWidget);
    QHBoxLayout *Y_layout = new QHBoxLayout(centralWidget);

    // Добавление виджетов в макет
    plotlayout->addWidget(ui->customPlot);

    X_layout->addWidget(ui->label_X);
    X_layout->addWidget(ui->horizontalSlider_X);
    X_layout->addWidget(ui->lcdNumber_X);


    Y_layout->addWidget(ui->label_Y);
    Y_layout->addWidget(ui->horizontalSlider_Y);
    Y_layout->addWidget(ui->lcdNumber_Y);


    sliderslayout->addLayout(X_layout);
    sliderslayout->addLayout(Y_layout);

    mainLayout->addLayout(plotlayout);
    mainLayout->addLayout(sliderslayout);

    // Установка макета
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Обновление размеров
    centralWidget->update();
    centralWidget->resize(centralWidget->sizeHint());
}

