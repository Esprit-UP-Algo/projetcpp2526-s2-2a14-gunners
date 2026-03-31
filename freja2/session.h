#ifndef SESSION_H
#define SESSION_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class session
{
private:
    int    id_session;
    QString titre_session;
    QDate   date_session;
    QString lieu_session;
    QString type_session;
    QString listes_publication_session;
    QString listes_reviewers_session;

public:
    session();
    session(int id, QString titre, QDate date, QString lieu,
            QString type, QString publications, QString reviewers);

    int     getId()           { return id_session; }
    QString getTitre()        { return titre_session; }
    QDate   getDate()         { return date_session; }
    QString getLieu()         { return lieu_session; }
    QString getType()         { return type_session; }
    QString getPublications() { return listes_publication_session; }
    QString getReviewers()    { return listes_reviewers_session; }

    void setId(int x)                  { id_session = x; }
    void setTitre(QString t)           { titre_session = t; }
    void setDate(QDate d)              { date_session = d; }
    void setLieu(QString l)            { lieu_session = l; }
    void setType(QString t)            { type_session = t; }
    void setPublications(QString p)    { listes_publication_session = p; }
    void setReviewers(QString r)       { listes_reviewers_session = r; }

    bool            ajouter();
    QSqlQueryModel* afficher();
    bool            supprimer(int id);
    bool            modifier(int id, QString titre, QDate date, QString lieu,
                  QString type, QString publications, QString reviewers);
    QSqlQueryModel* rechercher(int id);
    QSqlQueryModel* trier(QString ordre = "ASC");
};

#endif // SESSION_H
