#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMap>

class Utilisateur
{
    int id_utilisateur, age, nb_freres;
    QString nom_utilisateur, prenom, email_utilisateur, mdp_utilisateur, role_utilisateur, num_utilisateur, institution_utilisateur;
    QString nom_pere, nom_mere;

public:
    // Constructeurs
    Utilisateur();
    Utilisateur(int, QString, QString, QString, QString, QString, QString, QString, QString, QString, int, int);

    // Getters
    int get_id_utilisateur();
    QString get_nom_utilisateur();
    QString get_prenom();
    QString get_email_utilisateur();
    QString get_mdp_utilisateur();
    QString get_role_utilisateur();
    QString get_num_utilisateur();
    QString get_institution_utilisateur();
    QString get_nom_pere();
    QString get_nom_mere();
    int get_age();
    int get_nb_freres();

    // Setters
    void set_id_utilisateur(int);
    void set_nom_utilisateur(QString);
    void set_prenom(QString);
    void set_email_utilisateur(QString);
    void set_mdp_utilisateur(QString);
    void set_role_utilisateur(QString);
    void set_num_utilisateur(QString);
    void set_institution_utilisateur(QString);
    void set_nom_pere(QString);
    void set_nom_mere(QString);
    void set_age(int);
    void set_nb_freres(int);

    // CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int); // The argument is the original ID (for the WHERE clause)
    static bool verifierId(int); // Check if ID exists
    static QMap<QString, int> getStatistics();
};

#endif // UTILISATEUR_H
