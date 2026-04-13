#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMap>

class Utilisateur
{
    int id_utilisateur;
    QString nom_utilisateur, prenom, email_utilisateur, mdp_utilisateur, role_utilisateur, num_utilisateur, institution_utilisateur;

public:
    // Constructeurs
    Utilisateur();
    Utilisateur(int, QString, QString, QString, QString, QString, QString, QString);

    // Getters
    int get_id_utilisateur();
    QString get_nom_utilisateur();
    QString get_prenom();
    QString get_email_utilisateur();
    QString get_mdp_utilisateur();
    QString get_role_utilisateur();
    QString get_num_utilisateur();
    QString get_institution_utilisateur();

    // Setters
    void set_id_utilisateur(int);
    void set_nom_utilisateur(QString);
    void set_prenom(QString);
    void set_email_utilisateur(QString);
    void set_mdp_utilisateur(QString);
    void set_role_utilisateur(QString);
    void set_num_utilisateur(QString);
    void set_institution_utilisateur(QString);

    // CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int); // The argument is the original ID (for the WHERE clause)
    static bool verifierId(int); // Check if ID exists
    static QMap<QString, int> getStatistics();
};

#endif // UTILISATEUR_H
