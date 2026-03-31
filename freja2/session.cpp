#include "session.h"


session::session() {}

session::session(int id, QString titre, QDate date, QString lieu,
                 QString type, QString publications, QString reviewers)
{
    id_session= id;
    titre_session= titre;
    date_session= date;
    lieu_session= lieu;
    type_session= type;
    listes_publication_session = publications;
    listes_reviewers_session  = reviewers;
}

bool session::ajouter()
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO TABLE_SESSION "
        "(ID_SESSION, TITRE_SESSION, DATE_SESSION, LIEU_SESSION, "
        " TYPE_SESSION, LISTES_PUBLICATION_SESSION, LISTES_REVIEWERS_SESSION) "
        "VALUES (:id, :titre, TO_DATE(:date, 'YYYY-MM-DD'), :lieu, :type, :publications, :reviewers)"
        );
    query.bindValue(":id", id_session);
    query.bindValue(":titre", titre_session);
    query.bindValue(":date", date_session.toString("yyyy-MM-dd"));
    query.bindValue(":lieu", lieu_session);
    query.bindValue(":type", type_session);
    query.bindValue(":publications", listes_publication_session);
    query.bindValue(":reviewers", listes_reviewers_session);
    if (!query.exec()) {
        qDebug() << "[SESSION] Erreur ajouter:" << query.lastError().text();
        return false;
    }
    return true;
}



QSqlQueryModel* session::afficher()
{
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "[SESSION] Base de données non ouverte!";
        return nullptr;
    }
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_SESSION");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Session"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Publications"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Reviewers"));

    if (model->lastError().isValid()) {
        qDebug() << "[SESSION] Erreur afficher:" << model->lastError().text();
        delete model;
        return nullptr;
    }
    return model;
}



bool session::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TABLE_SESSION WHERE ID_SESSION = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "[SESSION] Erreur supprimer:" << query.lastError().text();
        return false;
    }
    return true;
}



bool session::modifier(int id, QString titre, QDate date, QString lieu,
                       QString type, QString publications, QString reviewers)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE TABLE_SESSION SET "
        "TITRE_SESSION = :titre, "
        "DATE_SESSION = TO_DATE(:date, 'YYYY-MM-DD'), "
        "LIEU_SESSION = :lieu, "
        "TYPE_SESSION = :type, "
        "LISTES_PUBLICATION_SESSION = :publications, "
        "LISTES_REVIEWERS_SESSION = :reviewers "
        "WHERE ID_SESSION = :id"
        );
    query.bindValue(":titre", titre);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    query.bindValue(":lieu", lieu);
    query.bindValue(":type", type);
    query.bindValue(":publications", publications);
    query.bindValue(":reviewers", reviewers);
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "[SESSION] Erreur modifier:" << query.lastError().text();
        return false;
    }
    return true;
}


QSqlQueryModel* session::rechercher(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM TABLE_SESSION WHERE ID_SESSION = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        model->setQuery(std::move(query));
        model->setHeaderData(0, Qt::Horizontal, "ID Session");
        model->setHeaderData(1, Qt::Horizontal, "Titre");
        model->setHeaderData(2, Qt::Horizontal, "Date");
        model->setHeaderData(3, Qt::Horizontal, "Lieu");
        model->setHeaderData(4, Qt::Horizontal, "Type");
        model->setHeaderData(5, Qt::Horizontal, "Publications");
        model->setHeaderData(6, Qt::Horizontal, "Reviewers");
        return model;
    } else {
        qDebug() << "[SESSION] Erreur rechercher:" << query.lastError().text();
        delete model;
        return nullptr;
    }
}



QSqlQueryModel* session::trier(QString ordre)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_SESSION ORDER BY DATE_SESSION " + ordre);

    if (model->lastError().isValid()) {
        qDebug() << "[SESSION] Erreur trier:" << model->lastError().text();
        delete model;
        return nullptr;
    }
    model->setHeaderData(0, Qt::Horizontal, "ID Session");
    model->setHeaderData(1, Qt::Horizontal, "Titre");
    model->setHeaderData(2, Qt::Horizontal, "Date");
    model->setHeaderData(3, Qt::Horizontal, "Lieu");
    model->setHeaderData(4, Qt::Horizontal, "Type");
    model->setHeaderData(5, Qt::Horizontal, "Publications");
    model->setHeaderData(6, Qt::Horizontal, "Reviewers");

    return model;
}
