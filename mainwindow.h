#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lib/qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void plotGraph();

public slots:
    void updateDisplay();
    void updateGraph();

private:
    Ui::MainWindow *ui;
    int x_value = 0;
    int y_value = 0;
};
#endif // MAINWINDOW_H
