#include "publication.h"

Publication::Publication()
{
    id_pub = 0;
    titre_pub = "";
    auteurs_pub = "";
    abstract_pub = "";
    type_pub = "";
    mots_cles_pub = "";
    statut_pub = "";
    date_pub = QDate::currentDate();
}

Publication::Publication(int id, QString title, QString authors, QString abs, QString type, QString keywords, QString status, QDate date)
{
    this->id_pub = id;
    this->titre_pub = title;
    this->auteurs_pub = authors;
    this->abstract_pub = abs;
    this->type_pub = type;
    this->mots_cles_pub = keywords;
    this->statut_pub = status;
    this->date_pub = date;
}

// Getters
int Publication::get_id_pub() { return id_pub; }
QString Publication::get_titre_pub() { return titre_pub; }
QString Publication::get_auteurs_pub() { return auteurs_pub; }
QString Publication::get_abstract_pub() { return abstract_pub; }
QString Publication::get_type_pub() { return type_pub; }
QString Publication::get_mots_cles_pub() { return mots_cles_pub; }
QString Publication::get_statut_pub() { return statut_pub; }
QDate Publication::get_date_pub() { return date_pub; }

// Setters
void Publication::set_id_pub(int id) { this->id_pub = id; }
void Publication::set_titre_pub(QString t) { this->titre_pub = t; }
void Publication::set_auteurs_pub(QString a) { this->auteurs_pub = a; }
void Publication::set_abstract_pub(QString a) { this->abstract_pub = a; }
void Publication::set_type_pub(QString t) { this->type_pub = t; }
void Publication::set_mots_cles_pub(QString m) { this->mots_cles_pub = m; }
void Publication::set_statut_pub(QString s) { this->statut_pub = s; }
void Publication::set_date_pub(QDate d) { this->date_pub = d; }

// CRUD Methods

bool Publication::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PUBLICATION (ID_PUB, TITRE_PUB, AUTEURS_PUB, ABSTRACT_PUB, TYPE_PUB, MOTS_CLES_PUB, STATUT_PUB, DATE_PUB) "
                  "VALUES (:id, :titre, :auteurs, :abstract, :type, :mots, :statut, :date)");
    
    query.bindValue(":id", id_pub);
    query.bindValue(":titre", titre_pub);
    query.bindValue(":auteurs", auteurs_pub);
    query.bindValue(":abstract", abstract_pub);
    query.bindValue(":type", type_pub);
    query.bindValue(":mots", mots_cles_pub);
    query.bindValue(":statut", statut_pub);
    query.bindValue(":date", date_pub);

    return query.exec();
}

QSqlQueryModel * Publication::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    // Assuming table name is PUBLICATION
    model->setQuery("SELECT * FROM PUBLICATION ORDER BY ID_PUB ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Auteurs"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Abstract"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mots Clés"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date"));
    return model;
}

bool Publication::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from PUBLICATION where ID_PUB = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Publication::modifier(int id)
{
    QSqlQuery query;
    // Current ID is updated to the id_pub member, filter by the original id
    query.prepare("UPDATE PUBLICATION SET ID_PUB=:newId, TITRE_PUB=:titre, AUTEURS_PUB=:auteurs, ABSTRACT_PUB=:abstract, TYPE_PUB=:type, MOTS_CLES_PUB=:mots, STATUT_PUB=:statut, DATE_PUB=:date WHERE ID_PUB=:oldId");
    
    query.bindValue(":oldId", id);
    query.bindValue(":newId", id_pub);
    query.bindValue(":titre", titre_pub);
    query.bindValue(":auteurs", auteurs_pub);
    query.bindValue(":abstract", abstract_pub);
    query.bindValue(":type", type_pub);
    query.bindValue(":mots", mots_cles_pub);
    query.bindValue(":statut", statut_pub);
    query.bindValue(":date", date_pub);
    
    return query.exec();
}

bool Publication::verifierId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID_PUB FROM PUBLICATION WHERE ID_PUB = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return true; // Exists
    }
    return false; // Not found
}

QMap<QString, int> Publication::getStatistics()
{
    QMap<QString, int> stats;
    QSqlQuery query;
    
    // --- Stats par Statut ---
    query.exec("SELECT STATUT_PUB, COUNT(*) FROM PUBLICATION GROUP BY STATUT_PUB");
    while (query.next()) {
        QString status = query.value(0).toString();
        int count = query.value(1).toInt();
        if (!status.isEmpty()) {
            stats["status_" + status] = count;
        }
    }

    // --- Stats par Type ---
    query.exec("SELECT TYPE_PUB, COUNT(*) FROM PUBLICATION GROUP BY TYPE_PUB");
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        if (!type.isEmpty()) {
            stats["type_" + type] = count;
        }
    }
    
    return stats;
}
