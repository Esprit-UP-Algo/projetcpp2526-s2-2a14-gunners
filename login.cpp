#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    // Rendre le lien "Mot de passe oublié" cliquable
    ui->lblForgotPassword->setCursor(Qt::PointingHandCursor);
    ui->lblForgotPassword->installEventFilter(this);
}

Login::~Login()
{
    delete ui;
}

bool Login::eventFilter(QObject *watched, QEvent *event) {
    if (watched == ui->lblForgotPassword && event->type() == QEvent::MouseButtonPress) {
        handleForgotPassword();
        return true;
    }
    return QWidget::eventFilter(watched, event);
}

void Login::on_btnLogin_clicked()
{
    QString email = ui->txtUsername->text();
    QString password = ui->txtPassword->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery q;
    q.prepare("SELECT * FROM TABLE_UTILISATEUR WHERE EMAIL_UTILISATEUR = :email AND MDP_UTILISATEUR = :password");
    q.bindValue(":email", email);
    q.bindValue(":password", password);
    
    if (q.exec() && q.next()) {
        emit loginSuccessful();
        this->close();
    } else {
        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect.");
    }
}

void Login::on_btnSignUp_clicked()
{
    // Functionality removed as per request. Users are now managed by Admins.
}

void Login::handleForgotPassword()
{
    QString email = ui->txtUsername->text();
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Pour retrouver votre compte, veuillez taper votre Email dans la case de connexion puis recliquez sur 'Mot de passe oublié'.");
        return;
    }

    QSqlQuery checkQ;
    checkQ.prepare("SELECT * FROM TABLE_UTILISATEUR WHERE EMAIL_UTILISATEUR = :e");
    checkQ.bindValue(":e", email);
    if (!checkQ.exec() || !checkQ.next()) {
        QMessageBox::warning(this, "Erreur", "L'adresse Email " + email + " est introuvable dans la base de données.");
        return;
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Récupération de compte");
    dialog.setMinimumWidth(400);
    
    QFormLayout form(&dialog);
    QLabel* lbl = new QLabel("Pour prouver que c'est bien vous, veuillez répondre<br>aux questions de sécurité fournies lors de l'inscription :", &dialog);
    form.addRow(lbl);

    QLineEdit *pereEdit = new QLineEdit(&dialog);
    QLineEdit *mereEdit = new QLineEdit(&dialog);
    QSpinBox *ageEdit = new QSpinBox(&dialog);
    ageEdit->setRange(1, 120);
    QSpinBox *freresEdit = new QSpinBox(&dialog);
    freresEdit->setRange(0, 50);

    form.addRow("Nom du père :", pereEdit);
    form.addRow("Nom de la mère :", mereEdit);
    form.addRow("Votre Âge :", ageEdit);
    form.addRow("Nombre de frères/sœurs :", freresEdit);

    QPushButton *btnRecover = new QPushButton("Vérifier et Récupérer", &dialog);
    btnRecover->setStyleSheet("QPushButton { background-color: #0078D7; color: white; border-radius: 5px; padding: 8px; } QPushButton:hover { background-color: #005a9e; }");
    form.addRow(btnRecover);

    connect(btnRecover, &QPushButton::clicked, [&]() {
        QSqlQuery q;
        q.prepare("SELECT MDP_UTILISATEUR FROM TABLE_UTILISATEUR WHERE EMAIL_UTILISATEUR = :e AND NOM_PERE = :p AND NOM_MERE = :m AND AGE = :a AND FRERES = :f");
        q.bindValue(":e", email);
        q.bindValue(":p", pereEdit->text());
        q.bindValue(":m", mereEdit->text());
        q.bindValue(":a", ageEdit->value());
        q.bindValue(":f", freresEdit->value());

        if (q.exec() && q.next()) {
            QString pass = q.value(0).toString();
            QMessageBox::information(&dialog, "Récupération réussie", "Authentification réussie ! \n\nVotre mot de passe est : " + pass);
            ui->txtPassword->setText(pass); // Pre-fill password field
            dialog.accept();
        } else {
            QMessageBox::warning(&dialog, "Échec", "Les réponses fournies sont incorrectes.");
        }
    });

    dialog.exec();
}
