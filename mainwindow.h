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
    void setupLayout();

public slots:
    void updateDisplay_X();
    void updateDisplay_Y();
    void updateDisplay_scale();

private:
    Ui::MainWindow *ui;
    int x_value = 0;
    int y_value = 0;
    long long scale_value = 1;
};
#endif // MAINWINDOW_H
