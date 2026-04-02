#include "utilisateur.h"
#include <QSqlError>
#include <QDebug>

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
}

Utilisateur::Utilisateur(int id, QString nom, QString prenom_val, QString email, QString mdp, QString role, QString num, QString institution)
{
    this->id_utilisateur = id;
    this->nom_utilisateur = nom;
    this->prenom = prenom_val;
    this->email_utilisateur = email;
    this->mdp_utilisateur = mdp;
    this->role_utilisateur = role;
    this->num_utilisateur = num;
    this->institution_utilisateur = institution;
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

// Setters
void Utilisateur::set_id_utilisateur(int id) { this->id_utilisateur = id; }
void Utilisateur::set_nom_utilisateur(QString nom) { this->nom_utilisateur = nom; }
void Utilisateur::set_prenom(QString p) { this->prenom = p; }
void Utilisateur::set_email_utilisateur(QString email) { this->email_utilisateur = email; }
void Utilisateur::set_mdp_utilisateur(QString mdp) { this->mdp_utilisateur = mdp; }
void Utilisateur::set_role_utilisateur(QString role) { this->role_utilisateur = role; }
void Utilisateur::set_num_utilisateur(QString num) { this->num_utilisateur = num; }
void Utilisateur::set_institution_utilisateur(QString inst) { this->institution_utilisateur = inst; }

// CRUD Methods

bool Utilisateur::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TABLE_UTILISATEUR (ID_UTILISATEUR, NOM_UTILISATEUR, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR, PRENOM) "
                  "VALUES (:id, :nom, :email, :mdp, :role, :num, :inst, :prenom)");
    
    query.bindValue(":id", id_utilisateur);
    query.bindValue(":nom", nom_utilisateur);
    query.bindValue(":email", email_utilisateur);
    query.bindValue(":mdp", mdp_utilisateur);
    query.bindValue(":role", role_utilisateur);
    query.bindValue(":num", num_utilisateur);
    query.bindValue(":inst", institution_utilisateur);
    query.bindValue(":prenom", prenom);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'utilisateur :" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel * Utilisateur::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR FROM TABLE_UTILISATEUR ORDER BY ID_UTILISATEUR ASC");
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
    // Current ID is updated to the id_utilisateur member, filter by the original id
    query.prepare("UPDATE TABLE_UTILISATEUR SET ID_UTILISATEUR=:newId, NOM_UTILISATEUR=:nom, EMAIL_UTILISATEUR=:email, MDP_UTILISATEUR=:mdp, ROLE_UTILISATEUR=:role, NUM_UTILISATEUR=:num, INSTITUTION_UTILISATEUR=:inst, PRENOM=:prenom WHERE ID_UTILISATEUR=:oldId");
    
    query.bindValue(":oldId", id);
    query.bindValue(":newId", id_utilisateur);
    query.bindValue(":nom", nom_utilisateur);
    query.bindValue(":email", email_utilisateur);
    query.bindValue(":mdp", mdp_utilisateur);
    query.bindValue(":role", role_utilisateur);
    query.bindValue(":num", num_utilisateur);
    query.bindValue(":inst", institution_utilisateur);
    query.bindValue(":prenom", prenom);
    
    return query.exec();
}

bool Utilisateur::verifierId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID_UTILISATEUR FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
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
