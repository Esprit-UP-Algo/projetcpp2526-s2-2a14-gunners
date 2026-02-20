#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnLogin_clicked()
{
    // For now, no validation. Just emit success.
    // In a real app, check username/password here.
    emit loginSuccessful();
    this->close();
}
