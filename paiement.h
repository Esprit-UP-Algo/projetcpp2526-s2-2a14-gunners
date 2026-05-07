#ifndef PAIEMENT_H
#define PAIEMENT_H

#include <QString>
#include <QSqlQueryModel>

class paiement
{
public:
    // Constructeurs
    paiement();
    paiement(int idPaiement, QString typeFraisPaiement, QString modePaiement,
             QString datePaiement, QString montantPaiement, QString devicePaiement,
             QString statutPaiement);

    // Getters
    int getIdPaiement() const;
    QString getTypeFraisPaiement() const;
    QString getModePaiement() const;
    QString getDatePaiement() const;
    QString getMontantPaiement() const;
    QString getDevicePaiement() const;
    QString getStatutPaiement() const;

    // Setters
    void setIdPaiement(int idPaiement);
    void setTypeFraisPaiement(const QString &typeFraisPaiement);
    void setModePaiement(const QString &modePaiement);
    void setDatePaiement(const QString &datePaiement);
    void setMontantPaiement(const QString &montantPaiement);
    void setDevicePaiement(const QString &devicePaiement);
    void setStatutPaiement(const QString &statutPaiement);

    // CRUD Operations
    bool ajouter();
    bool modifier();
    bool supprimer(int id);

    // Affichage
    QSqlQueryModel* afficher();

    // Recherche
    bool rechercherParId(int idRecherche);
    QSqlQueryModel* rechercherParTypeFrais(const QString &typeFrais);
    QSqlQueryModel* rechercherParModePaiement(const QString &mode);
    QSqlQueryModel* rechercherParStatut(const QString &statut);
    QSqlQueryModel* rechercherParDevice(const QString &device);

    // Tri
    QSqlQueryModel* trierParId();
    QSqlQueryModel* trierParIdDesc();
    QSqlQueryModel* trierParMontant();
    QSqlQueryModel* trierParDate();
    QSqlQueryModel* trierParTypeFrais();
    QSqlQueryModel* trierParModePaiement();
    QSqlQueryModel* trierParDevice();

    // Statistiques
    QSqlQueryModel* statistiquesParStatut();
    QSqlQueryModel* statistiquesParModePaiement();
    QSqlQueryModel* statistiquesParTypeFrais();
    QSqlQueryModel* statistiquesParDevice();
    QString getLastError() const;

private:
    int idPaiement;
    QString typeFraisPaiement;
    QString modePaiement;
    QString datePaiement;
    QString montantPaiement;
    QString devicePaiement;
    QString statutPaiement;
    QString lastError;
};

#endif // PAIEMENT_H
