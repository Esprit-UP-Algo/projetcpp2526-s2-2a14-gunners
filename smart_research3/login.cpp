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
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery q;
    q.prepare("SELECT * FROM log WHERE USERNAME = :username AND PASSWORD = :password");
    q.bindValue(":username", username);
    q.bindValue(":password", password);
    
    if (q.exec() && q.next()) {
        emit loginSuccessful();
        this->close();
    } else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect.");
    }
}

void Login::on_btnSignUp_clicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Créer un compte principal");
    dialog.setMinimumWidth(400);

    QFormLayout form(&dialog);

    QLineEdit *userEdit = new QLineEdit(&dialog);
    QLineEdit *passEdit = new QLineEdit(&dialog);
    passEdit->setEchoMode(QLineEdit::Password);
    
    // Questions de sécurité
    QLineEdit *pereEdit = new QLineEdit(&dialog);
    QLineEdit *mereEdit = new QLineEdit(&dialog);
    QSpinBox *ageEdit = new QSpinBox(&dialog);
    ageEdit->setRange(1, 120);
    ageEdit->setValue(18); // default
    QSpinBox *freresEdit = new QSpinBox(&dialog);
    freresEdit->setRange(0, 50);

    form.addRow("Nom d'utilisateur :", userEdit);
    form.addRow("Mot de passe :", passEdit);
    
    QLabel* lblSecu = new QLabel("<b>Questions de sécurité obligatoires :</b>", &dialog);
    form.addRow(lblSecu);
    form.addRow("Nom du père :", pereEdit);
    form.addRow("Nom de la mère :", mereEdit);
    form.addRow("Votre Âge :", ageEdit);
    form.addRow("Nombre de frères/sœurs :", freresEdit);

    QPushButton *btnSubmit = new QPushButton("M'inscrire", &dialog);
    // Petit style basique pour le bouton
    btnSubmit->setStyleSheet("QPushButton { background-color: #0078D7; color: white; border-radius: 5px; padding: 8px; } QPushButton:hover { background-color: #005a9e; }");
    form.addRow(btnSubmit);

    connect(btnSubmit, &QPushButton::clicked, [&]() {
        if (userEdit->text().isEmpty() || passEdit->text().isEmpty() || pereEdit->text().isEmpty() || mereEdit->text().isEmpty()) {
            QMessageBox::warning(&dialog, "Erreur", "Veuillez remplir tous les champs.");
            return;
        }

        QSqlQuery q;
        q.prepare("INSERT INTO log (USERNAME, PASSWORD, NOM_PERE, NOM_MERE, AGE, FRERES) VALUES (:u, :p, :pere, :mere, :age, :f)");
        q.bindValue(":u", userEdit->text());
        q.bindValue(":p", passEdit->text());
        q.bindValue(":pere", pereEdit->text());
        q.bindValue(":mere", mereEdit->text());
        q.bindValue(":age", ageEdit->value());
        q.bindValue(":f", freresEdit->value());

        if (q.exec()) {
            QMessageBox::information(&dialog, "Succès", "Votre compte a été créé ! Vous pouvez maintenant vous connecter.");
            ui->txtUsername->setText(userEdit->text()); // Pré-remplir le champ username
            dialog.accept();
        } else {
            qDebug() << "Sign up err:" << q.lastError().text();
            QMessageBox::warning(&dialog, "Erreur", "Ce nom d'utilisateur existe déjà ou une erreur est survenue.");
        }
    });

    dialog.exec();
}

void Login::handleForgotPassword()
{
    QString username = ui->txtUsername->text();
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Pour retrouver votre compte, veuillez taper votre Nom d'utilisateur dans la case de connexion puis recliquez sur 'Mot de passe oublié'.");
        return;
    }

    QSqlQuery checkQ;
    checkQ.prepare("SELECT * FROM log WHERE USERNAME = :u");
    checkQ.bindValue(":u", username);
    if (!checkQ.exec() || !checkQ.next()) {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur " + username + " est introuvable dans la base de données.");
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
        q.prepare("SELECT PASSWORD FROM log WHERE USERNAME = :u AND NOM_PERE = :p AND NOM_MERE = :m AND AGE = :a AND FRERES = :f");
        q.bindValue(":u", username);
        q.bindValue(":p", pereEdit->text());
        q.bindValue(":m", mereEdit->text());
        q.bindValue(":a", ageEdit->value());
        q.bindValue(":f", freresEdit->value());

        if (q.exec() && q.next()) {
            QString pass = q.value(0).toString();
            QMessageBox::information(&dialog, "Récupération réussie", "Authentification réussie ! \n\nVotre mot de passe est : " + pass);
            ui->txtPassword->setText(pass); // Pré-remplir le champ de mot de passe
            dialog.accept();
        } else {
            QMessageBox::warning(&dialog, "Échec", "Les réponses fournies sont incorrectes. (Attention aux majuscules/minuscules dans les noms)");
        }
    });

    dialog.exec();
}
