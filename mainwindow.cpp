#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Соединяем слайдер с методом, который обновляет lcdNumber
    connect(ui->horizontalSlider_X, &QSlider::valueChanged, this, &MainWindow::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setValue(int value)
{
    ui->lcdNumber->display(value);
}
