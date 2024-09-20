/********************************************************************************
** Form generated from reading UI file 'login_form.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_FORM_H
#define UI_LOGIN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login_form
{
public:
    QLineEdit *login_input;
    QLineEdit *password_input;
    QPushButton *button_login;

    void setupUi(QDialog *login_form)
    {
        if (login_form->objectName().isEmpty())
            login_form->setObjectName("login_form");
        login_form->resize(480, 640);
        login_input = new QLineEdit(login_form);
        login_input->setObjectName("login_input");
        login_input->setGeometry(QRect(110, 100, 221, 51));
        password_input = new QLineEdit(login_form);
        password_input->setObjectName("password_input");
        password_input->setGeometry(QRect(120, 240, 221, 51));
        button_login = new QPushButton(login_form);
        button_login->setObjectName("button_login");
        button_login->setGeometry(QRect(170, 370, 100, 32));

        retranslateUi(login_form);

        QMetaObject::connectSlotsByName(login_form);
    } // setupUi

    void retranslateUi(QDialog *login_form)
    {
        login_form->setWindowTitle(QCoreApplication::translate("login_form", "Dialog", nullptr));
        button_login->setText(QCoreApplication::translate("login_form", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_form: public Ui_login_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_FORM_H
