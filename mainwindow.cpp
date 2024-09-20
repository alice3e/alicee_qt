#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "lib/qcustomplot.h"
#include <cmath>
#include <algorithm>
#include "math.h"

const long double E = 2.7182;


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

    connect(ui->horizontalSlider_scale, &QSlider::valueChanged, this, [this](int value) {
        scale_value = value;
        updateDisplay_scale();
        plotGraph();
    });

    connect(ui->function_menu_combo_box, &QComboBox::currentIndexChanged, this, [this]() {
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

void MainWindow::updateDisplay_scale()
{
    ui->lcdNumber_scale->display(scale_value / 1.0);
}


void MainWindow::plotGraph()
{
    // Очищаем график перед перерисовкой
    ui->customPlot->clearGraphs();
    int numPoints;
    // Определяем количество точек в зависимости от масштаба
    if(scale_value > 100){
        numPoints = scale_value;
    } else {
        numPoints = 100;
    }

    QVector<double> x(numPoints), y(numPoints);

    double b = x_value / 10.0;
    double a = y_value / 10.0;

    for (int i = 0; i < numPoints; ++i)
    {
        // Расчёт значения x в зависимости от масштаба
        double scaledX = -scale_value + (i * (2.0 * scale_value) / (numPoints - 1)); // Значения от -scale_value до scale_value
        x[i] = scaledX;

        // Изменяем формулу в зависимости от выбранного типа графика
        if (ui->function_menu_combo_box->currentText() == "y = ax + b") {
            y[i] = a * x[i] + b;  // Линейная функция
        } else if (ui->function_menu_combo_box->currentText() == "y = ax^2 + b") {
            y[i] = a * x[i] * x[i] + b;  // Квадратичная функция
        } else if (ui->function_menu_combo_box->currentText() == "y = e^x + b") {
            y[i] = a * std::pow(E, x[i]) + b; // e^x
        } else if (ui->function_menu_combo_box->currentText() == "y = log_a(x) + b") {
            y[i] = std::log(x[i]) / std::log(a) + b; // log_a(x) + b
        }
    }

    // Добавляем данные на график
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    // Устанавливаем диапазоны осей в зависимости от масштаба
    ui->customPlot->xAxis->setRange(-scale_value, scale_value);
    ui->customPlot->yAxis->setRange(-scale_value, scale_value);

    // Отрисовываем график
    ui->customPlot->replot();
}


void MainWindow::setupLayout()
{
    // настройка QComboBox для натсройки функций
    ui->function_menu_combo_box->clear();
    ui->function_menu_combo_box->addItem("y = ax + b");
    ui->function_menu_combo_box->addItem("y = ax^2 + b");
    ui->function_menu_combo_box->addItem("y = e^x + b");
    ui->function_menu_combo_box->addItem("y = log_a(x) + b");

    ui->horizontalSlider_scale->setRange(1, 1000);


    // Создание и установка макета для центрального виджета
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QVBoxLayout *plotlayout = new QVBoxLayout(centralWidget);
    QVBoxLayout *sliderslayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *X_layout = new QHBoxLayout(centralWidget);
    QHBoxLayout *Y_layout = new QHBoxLayout(centralWidget);
    QHBoxLayout *scale_layout = new QHBoxLayout(centralWidget);
    // Добавление виджетов в макет
    plotlayout->addWidget(ui->customPlot);

    X_layout->addWidget(ui->label_X);
    X_layout->addWidget(ui->horizontalSlider_X);
    X_layout->addWidget(ui->lcdNumber_X);


    Y_layout->addWidget(ui->label_Y);
    Y_layout->addWidget(ui->horizontalSlider_Y);
    Y_layout->addWidget(ui->lcdNumber_Y);

    scale_layout->addWidget(ui->label_scale);
    scale_layout->addWidget(ui->horizontalSlider_scale);
    scale_layout->addWidget(ui->lcdNumber_scale);


    sliderslayout->addLayout(X_layout);
    sliderslayout->addLayout(Y_layout);
    sliderslayout->addLayout(scale_layout);
    sliderslayout->addWidget(ui->function_menu_combo_box);

    mainLayout->addLayout(plotlayout);
    mainLayout->addLayout(sliderslayout);

    // Установка макета
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Обновление размеров
    centralWidget->update();
    centralWidget->resize(centralWidget->sizeHint());
}

