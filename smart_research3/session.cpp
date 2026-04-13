#include "session.h"

Session::Session()
{
    id_session = 0;
    titre_session = "";
    date_session = QDate::currentDate();
    lieu_session = "";
    type_session = "";
    listes_publication_session = "";
    listes_reviewers_session = "";
}

Session::Session(int id, QString titre, QDate date, QString lieu, QString type, QString listPub, QString listRev)
{
    this->id_session = id;
    this->titre_session = titre;
    this->date_session = date;
    this->lieu_session = lieu;
    this->type_session = type;
    this->listes_publication_session = listPub;
    this->listes_reviewers_session = listRev;
}

// Getters
int Session::get_id_session() { return id_session; }
QString Session::get_titre_session() { return titre_session; }
QDate Session::get_date_session() { return date_session; }
QString Session::get_lieu_session() { return lieu_session; }
QString Session::get_type_session() { return type_session; }
QString Session::get_listes_publication_session() { return listes_publication_session; }
QString Session::get_listes_reviewers_session() { return listes_reviewers_session; }

// Setters
void Session::set_id_session(int id) { this->id_session = id; }
void Session::set_titre_session(QString t) { this->titre_session = t; }
void Session::set_date_session(QDate d) { this->date_session = d; }
void Session::set_lieu_session(QString l) { this->lieu_session = l; }
void Session::set_type_session(QString t) { this->type_session = t; }
void Session::set_listes_publication_session(QString lp) { this->listes_publication_session = lp; }
void Session::set_listes_reviewers_session(QString lr) { this->listes_reviewers_session = lr; }

// CRUD Methods

bool Session::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TABLE_SESSION (ID_SESSION, TITRE_SESSION, DATE_SESSION, LIEU_SESSION, TYPE_SESSION, LISTES_PUBLICATION_SESSION, LISTES_REVIEWERS_SESSION) "
                  "VALUES (:id, :titre, :date, :lieu, :type, :listpub, :listrev)");
    
    query.bindValue(":id", id_session);
    query.bindValue(":titre", titre_session);
    query.bindValue(":date", date_session);
    query.bindValue(":lieu", lieu_session);
    query.bindValue(":type", type_session);
    query.bindValue(":listpub", listes_publication_session);
    query.bindValue(":listrev", listes_reviewers_session);

    return query.exec();
}

QSqlQueryModel * Session::afficher()
{
    ColorSqlQueryModel * model = new ColorSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_SESSION ORDER BY ID_SESSION ASC");
    
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Publications"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Reviewers"));
    
    return model;
}

bool Session::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TABLE_SESSION WHERE ID_SESSION = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Session::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE TABLE_SESSION SET ID_SESSION=:newId, TITRE_SESSION=:titre, DATE_SESSION=:date, LIEU_SESSION=:lieu, TYPE_SESSION=:type, LISTES_PUBLICATION_SESSION=:lp, LISTES_REVIEWERS_SESSION=:lr WHERE ID_SESSION=:oldId");
    
    query.bindValue(":oldId", id);
    query.bindValue(":newId", id_session);
    query.bindValue(":titre", titre_session);
    query.bindValue(":date", date_session);
    query.bindValue(":lieu", lieu_session);
    query.bindValue(":type", type_session);
    query.bindValue(":lp", listes_publication_session);
    query.bindValue(":lr", listes_reviewers_session);
    
    return query.exec();
}

bool Session::verifierId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID_SESSION FROM TABLE_SESSION WHERE ID_SESSION = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}

QSqlQueryModel * Session::rechercherSession(QString val)
{
    ColorSqlQueryModel * model = new ColorSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_SESSION WHERE TO_CHAR(ID_SESSION) LIKE '%" + val + "%' OR LOWER(TITRE_SESSION) LIKE LOWER('%" + val + "%')");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Publications"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Reviewers"));

    return model;
}

QSqlQueryModel * Session::trierSessionASC()
{
    ColorSqlQueryModel * model = new ColorSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_SESSION ORDER BY ID_SESSION ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Publications"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Reviewers"));

    return model;
}

QSqlQueryModel * Session::trierSessionDESC()
{
    ColorSqlQueryModel * model = new ColorSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_SESSION ORDER BY ID_SESSION DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Publications"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Reviewers"));

    return model;
}

QMap<QString, int> Session::getStatistics()
{
    QMap<QString, int> stats;
    QSqlQuery query("SELECT TYPE_SESSION, COUNT(*) FROM TABLE_SESSION GROUP BY TYPE_SESSION");
    
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        stats[type] = count;
    }
    
    return stats;
}
