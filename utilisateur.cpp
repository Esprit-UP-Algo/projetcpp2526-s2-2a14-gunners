#include "utilisateur.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QMessageBox>

// Helper pour échapper les apostrophes (Oracle ODBC compat)
static QString esc(const QString &s) {
    return QString(s).replace("'", "''");
}

Utilisateur::Utilisateur()
{
    id_utilisateur = 0;
    nom_utilisateur = "";
    prenom = "";
    email_utilisateur = "";
    mdp_utilisateur = "";
    role_utilisateur = "";
    num_utilisateur = "";
    institution_utilisateur = "";
    nom_pere = "";
    nom_mere = "";
    age = 0;
    nb_freres = 0;
}

Utilisateur::Utilisateur(int id, QString nom, QString prenom_val, QString email, QString mdp, QString role, QString num, QString institution, QString pere, QString mere, int a, int f)
{
    this->id_utilisateur = id;
    this->nom_utilisateur = nom;
    this->prenom = prenom_val;
    this->email_utilisateur = email;
    this->mdp_utilisateur = mdp;
    this->role_utilisateur = role;
    this->num_utilisateur = num;
    this->institution_utilisateur = institution;
    this->nom_pere = pere;
    this->nom_mere = mere;
    this->age = a;
    this->nb_freres = f;
}

// Getters
int Utilisateur::get_id_utilisateur() { return id_utilisateur; }
QString Utilisateur::get_nom_utilisateur() { return nom_utilisateur; }
QString Utilisateur::get_prenom() { return prenom; }
QString Utilisateur::get_email_utilisateur() { return email_utilisateur; }
QString Utilisateur::get_mdp_utilisateur() { return mdp_utilisateur; }
QString Utilisateur::get_role_utilisateur() { return role_utilisateur; }
QString Utilisateur::get_num_utilisateur() { return num_utilisateur; }
QString Utilisateur::get_institution_utilisateur() { return institution_utilisateur; }
QString Utilisateur::get_nom_pere() { return nom_pere; }
QString Utilisateur::get_nom_mere() { return nom_mere; }
int Utilisateur::get_age() { return age; }
int Utilisateur::get_nb_freres() { return nb_freres; }

// Setters
void Utilisateur::set_id_utilisateur(int id) { this->id_utilisateur = id; }
void Utilisateur::set_nom_utilisateur(QString nom) { this->nom_utilisateur = nom; }
void Utilisateur::set_prenom(QString p) { this->prenom = p; }
void Utilisateur::set_email_utilisateur(QString email) { this->email_utilisateur = email; }
void Utilisateur::set_mdp_utilisateur(QString mdp) { this->mdp_utilisateur = mdp; }
void Utilisateur::set_role_utilisateur(QString role) { this->role_utilisateur = role; }
void Utilisateur::set_num_utilisateur(QString num) { this->num_utilisateur = num; }
void Utilisateur::set_institution_utilisateur(QString inst) { this->institution_utilisateur = inst; }
void Utilisateur::set_nom_pere(QString p) { this->nom_pere = p; }
void Utilisateur::set_nom_mere(QString m) { this->nom_mere = m; }
void Utilisateur::set_age(int a) { this->age = a; }
void Utilisateur::set_nb_freres(int f) { this->nb_freres = f; }

// CRUD Methods

bool Utilisateur::ajouter()
{
    // NUM_UTILISATEUR est un NUMBER dans Oracle
    long long num_val = num_utilisateur.toLongLong();

    QString sql = QString(
        "INSERT INTO TABLE_UTILISATEUR (ID_UTILISATEUR, NOM_UTILISATEUR, EMAIL_UTILISATEUR, "
        "MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR, PRENOM, "
        "NOM_PERE, NOM_MERE, AGE, FRERES) "
        "VALUES (%1, '%2', '%3', '%4', '%5', %6, '%7', '%8', '%9', '%10', %11, %12)")
        .arg(id_utilisateur)
        .arg(esc(nom_utilisateur))
        .arg(esc(email_utilisateur))
        .arg(esc(mdp_utilisateur))
        .arg(esc(role_utilisateur))
        .arg(num_val)
        .arg(esc(institution_utilisateur))
        .arg(esc(prenom))
        .arg(esc(nom_pere))
        .arg(esc(nom_mere))
        .arg(age)
        .arg(nb_freres);

    QSqlQuery query;
    if (!query.exec(sql)) {
        qDebug() << "Erreur lors de l'ajout de l'utilisateur :" << query.lastError().text();
        qDebug() << "SQL:" << sql;
        return false;
    }
    return true;
}

QSqlQueryModel * Utilisateur::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    // Correction : PRENOM_UTILISATEUR -> PRENOM
    // Fetch all columns
    model->setQuery("SELECT ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR, NOM_PERE, NOM_MERE, AGE, FRERES FROM TABLE_UTILISATEUR ORDER BY ID_UTILISATEUR ASC");
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des utilisateurs :" << model->lastError().text();
    }
    
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mot de passe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Rôle"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Institution"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Père"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Mère"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Âge"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Frères"));
    return model;
}

bool Utilisateur::supprimer(int id)
{
    QSqlQuery query;
    QString sql = QString("DELETE FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR = %1").arg(id);
    return query.exec(sql);
}

bool Utilisateur::modifier(int id)
{
    long long num_val = num_utilisateur.toLongLong();

    QString sql = QString(
        "UPDATE TABLE_UTILISATEUR SET "
        "ID_UTILISATEUR = %1, "
        "NOM_UTILISATEUR = '%2', "
        "EMAIL_UTILISATEUR = '%3', "
        "MDP_UTILISATEUR = '%4', "
        "ROLE_UTILISATEUR = '%5', "
        "NUM_UTILISATEUR = %6, "
        "INSTITUTION_UTILISATEUR = '%7', "
        "PRENOM = '%8', "
        "NOM_PERE = '%9', "
        "NOM_MERE = '%10', "
        "AGE = %11, "
        "FRERES = %12 "
        "WHERE ID_UTILISATEUR = %13")
        .arg(id_utilisateur)
        .arg(esc(nom_utilisateur))
        .arg(esc(email_utilisateur))
        .arg(esc(mdp_utilisateur))
        .arg(esc(role_utilisateur))
        .arg(num_val)
        .arg(esc(institution_utilisateur))
        .arg(esc(prenom))
        .arg(esc(nom_pere))
        .arg(esc(nom_mere))
        .arg(age)
        .arg(nb_freres)
        .arg(id);

    QSqlQuery query;
    if (!query.exec(sql)) {
        qDebug() << "Erreur lors de la modification de l'utilisateur :" << query.lastError().text();
        qDebug() << "SQL:" << sql;
        return false;
    }
    return true;
}

bool Utilisateur::verifierId(int id)
{
    QSqlQuery query;
    QString sql = QString("SELECT ID_UTILISATEUR FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR = %1").arg(id);
    if (query.exec(sql) && query.next()) {
        return true; // Exists
    }
    return false; // Not found
}

QMap<QString, int> Utilisateur::getStatistics()
{
    QMap<QString, int> stats;
    QSqlQuery query;
    
    // Total count
    query.prepare("SELECT COUNT(*) FROM TABLE_UTILISATEUR");
    if (query.exec() && query.next()) {
        stats["total"] = query.value(0).toInt();
    }
    
    // Count per role
    QStringList roles = {"Admin", "manager", "editer", "reviewer"};
    for (const QString &role : roles) {
        query.prepare("SELECT COUNT(*) FROM TABLE_UTILISATEUR WHERE ROLE_UTILISATEUR = :role");
        query.bindValue(":role", role);
        if (query.exec() && query.next()) {
            stats[role] = query.value(0).toInt();
        }
    }
    
    return stats;
}
