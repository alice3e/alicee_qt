#include "login_form.h"
#include "ui_login_form.h"
#include "mainwindow.h"
#include <QMessageBox>

login_form::login_form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login_form)
{
    ui->setupUi(this);
    this->resize(400, 200);
    this->setWindowTitle("Форма входа");
    ui->login_input->setPlaceholderText("логин");
    ui->password_input->setPlaceholderText("пароль");
    ui->password_input->setEchoMode(QLineEdit::Password);

    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *welcomeLabel = new QLabel("Добро пожаловать в подделку Desmos");
    QLabel *instructionLabel = new QLabel("Введите логин и пароль (admin - 1234)");
    ui->button_login->setText("Войти");
    // Добавляем виджеты в layout
    layout->addWidget(welcomeLabel);
    layout->addWidget(instructionLabel);
    layout->addWidget(ui->login_input);
    layout->addWidget(ui->password_input);
    layout->addWidget(ui->button_login);

    // Устанавливаем отступы (если нужно)
    layout->setContentsMargins(50, 50, 50, 50); // Отступы от краев окна

    // Устанавливаем промежуточное пространство между элементами
    layout->setSpacing(20); // Расстояние между виджетами

    // Центрирование элементов
    layout->setAlignment(Qt::AlignCenter);

    // Устанавливаем этот layout в качестве основного для формы
    this->setLayout(layout);

    connect(ui->button_login, &QPushButton::clicked, this, &login_form::on_pushButton_clicked);
}

login_form::~login_form()
{
    delete ui;
}

void login_form::on_pushButton_clicked()
{
    QString username = ui->login_input->text().trimmed();
    QString password = ui->password_input->text().trimmed();



    if (username == "admin" && password == "1234") {
        // Создаем новую страницу и показываем её
        MainWindow *main_window = new MainWindow();
        main_window->show();
        this->hide(); // Скрываем главное окно
    } else {
        // показать уведомление, что пароль неверный и попробовать заново
        QMessageBox::warning(this, "Ошибка входа", "Неверное имя пользователя или пароль. Пожалуйста, попробуйте снова.");
    }
}
