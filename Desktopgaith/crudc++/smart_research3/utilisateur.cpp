#include "utilisateur.h"
#include <QSqlError>
#include <QDebug>

Utilisateur::Utilisateur()
{
    id_utilisateur = 0;
    nom_utilisateur = "";
    email_utilisateur = "";
    mdp_utilisateur = "";
    role_utilisateur = "";
    num_utilisateur = "";
    institution_utilisateur = "";
}

Utilisateur::Utilisateur(int id, QString nom, QString email, QString mdp, QString role, QString num, QString institution)
{
    this->id_utilisateur = id;
    this->nom_utilisateur = nom;
    this->email_utilisateur = email;
    this->mdp_utilisateur = mdp;
    this->role_utilisateur = role;
    this->num_utilisateur = num;
    this->institution_utilisateur = institution;
}

// Getters
int Utilisateur::get_id_utilisateur() { return id_utilisateur; }
QString Utilisateur::get_nom_utilisateur() { return nom_utilisateur; }
QString Utilisateur::get_email_utilisateur() { return email_utilisateur; }
QString Utilisateur::get_mdp_utilisateur() { return mdp_utilisateur; }
QString Utilisateur::get_role_utilisateur() { return role_utilisateur; }
QString Utilisateur::get_num_utilisateur() { return num_utilisateur; }
QString Utilisateur::get_institution_utilisateur() { return institution_utilisateur; }

// Setters
void Utilisateur::set_id_utilisateur(int id) { this->id_utilisateur = id; }
void Utilisateur::set_nom_utilisateur(QString nom) { this->nom_utilisateur = nom; }
void Utilisateur::set_email_utilisateur(QString email) { this->email_utilisateur = email; }
void Utilisateur::set_mdp_utilisateur(QString mdp) { this->mdp_utilisateur = mdp; }
void Utilisateur::set_role_utilisateur(QString role) { this->role_utilisateur = role; }
void Utilisateur::set_num_utilisateur(QString num) { this->num_utilisateur = num; }
void Utilisateur::set_institution_utilisateur(QString inst) { this->institution_utilisateur = inst; }

// CRUD Methods

bool Utilisateur::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TABLE_UTILISATEUR (ID_UTILISATEUR, NOM_UTILISATEUR, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR) "
                  "VALUES (:id, :nom, :email, :mdp, :role, :num, :inst)");
    
    query.bindValue(":id", id_utilisateur);
    query.bindValue(":nom", nom_utilisateur);
    query.bindValue(":email", email_utilisateur);
    query.bindValue(":mdp", mdp_utilisateur);
    query.bindValue(":role", role_utilisateur);
    query.bindValue(":num", num_utilisateur);
    query.bindValue(":inst", institution_utilisateur);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'utilisateur :" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel * Utilisateur::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_UTILISATEUR");
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des utilisateurs :" << model->lastError().text();
    }
    
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mot de passe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Rôle"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Institution"));
    return model;
}

bool Utilisateur::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Utilisateur::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE TABLE_UTILISATEUR SET NOM_UTILISATEUR=:nom, EMAIL_UTILISATEUR=:email, MDP_UTILISATEUR=:mdp, ROLE_UTILISATEUR=:role, NUM_UTILISATEUR=:num, INSTITUTION_UTILISATEUR=:inst WHERE ID_UTILISATEUR=:id");
    
    query.bindValue(":id", id);
    query.bindValue(":nom", nom_utilisateur);
    query.bindValue(":email", email_utilisateur);
    query.bindValue(":mdp", mdp_utilisateur);
    query.bindValue(":role", role_utilisateur);
    query.bindValue(":num", num_utilisateur);
    query.bindValue(":inst", institution_utilisateur);
    
    return query.exec();
}
