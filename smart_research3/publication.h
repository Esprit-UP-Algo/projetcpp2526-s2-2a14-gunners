#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Publication
{
    int id_pub;
    QString titre_pub, auteurs_pub, abstract_pub, type_pub, mots_cles_pub, statut_pub;
    QDate date_pub;

public:
    Publication();
    Publication(int, QString, QString, QString, QString, QString, QString, QDate);

    // Getters
    int get_id_pub();
    QString get_titre_pub();
    QString get_auteurs_pub();
    QString get_abstract_pub();
    QString get_type_pub();
    QString get_mots_cles_pub();
    QString get_statut_pub();
    QDate get_date_pub();

    // Setters
    void set_id_pub(int);
    void set_titre_pub(QString);
    void set_auteurs_pub(QString);
    void set_abstract_pub(QString);
    void set_type_pub(QString);
    void set_mots_cles_pub(QString);
    void set_statut_pub(QString);
    void set_date_pub(QDate);

    // CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    bool controler_saisie();
};

#endif // PUBLICATION_H
