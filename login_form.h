#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class login_form;
}

class login_form : public QDialog
{
    Q_OBJECT

public:
    explicit login_form(QWidget *parent = nullptr);
    ~login_form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login_form *ui;
};

#endif // LOGIN_FORM_H
