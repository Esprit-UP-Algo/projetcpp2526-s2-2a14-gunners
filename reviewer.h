#ifndef REVIEWER_H
#define REVIEWER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMap>
#include <QDebug>

class Reviewer
{
    int id_reviewer;
    QString nom, email, username, telephone, photo_path, specialite, institution, statut;

public:
    QString lastError;
    Reviewer();
    Reviewer(int id, QString nom, QString email, QString username, QString telephone, QString photo, QString specialite, QString institution, QString statut);

    // Getters
    int get_id();
    QString get_nom();
    QString get_email();
    QString get_username();
    QString get_telephone();
    QString get_photo();
    QString get_specialite();
    QString get_institution();
    QString get_statut();

    // Setters
    void set_id(int id);
    void set_nom(QString nom);
    void set_email(QString email);
    void set_username(QString username);
    void set_telephone(QString tel);
    void set_photo(QString photo);
    void set_specialite(QString spec);
    void set_institution(QString inst);
    void set_statut(QString stat);

    // CRUD
    bool ajouterReviewer();
    QSqlQueryModel* afficher();
    bool modifier(int originalId);
    bool supprimer(int id);

    // Logic
    static bool verifierId(int id);
    QSqlQueryModel* rechercher(QString val, QString critere, QString orderASC);
    static QMap<QString, int> getStatistics();
};

#endif // REVIEWER_H
