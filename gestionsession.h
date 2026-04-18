#ifndef GESTIONSESSION_H
#define GESTIONSESSION_H

#include <QObject>
#include <QVector>
#include <QTableWidgetItem>
#include "publication.h"
#include "reviewer.h"

namespace Ui {
class SmartResearch;
}

class GestionSession : public QObject
{
    Q_OBJECT

public:
    explicit GestionSession(Ui::SmartResearch *ui, QObject *parent = nullptr);
    ~GestionSession();

private:
    Ui::SmartResearch *ui;
    int m_currentSessionId = -1; // -1 = aucune session sélectionnée

    void loadAllPublications();     // Remplir list_Publications
    void loadAllReviewers();        // Remplir list_Reviewers
    void loadSessionsTable();       // Remplir QTableWidget avec toutes les sessions + associations
    void loadSessionPublications(int sessionId);  // Remplir list_SessionPubs
    void loadSessionReviewers(int sessionId);     // Remplir list_SessionRevs
    QString getPublicationsString(int sessionId); // Retourne "titre1, titre2, ..."
    QString getReviewersString(int sessionId);    // Retourne "nom1, nom2, ..."
    bool addPublicationAssociation(int sessionId, int pubId);
    bool addReviewerAssociation(int sessionId, int revId);
    bool removePublicationAssociation(int sessionId, int pubId);
    bool removeReviewerAssociation(int sessionId, int revId);
    void clearSessionForm();        // Vider les champs et listes
    void applyRowColoring();        // Colorer les lignes selon la date

private slots:
    void on_tableWidget_Sessions_itemClicked(QTableWidgetItem *item);
    void on_btn_AssocierPublications_clicked();
    void on_btn_AssocierReviewers_clicked();
    void on_btn_RetirerPub_clicked();
    void on_btn_RetirerRev_clicked();
    void on_btn_Enregistrer_clicked();  // Session principal
    void on_rechercheSession_clicked();
    void on_quitterSession_clicked();
    void on_annuler_2_clicked();
};

#endif // GESTIONSESSION_H
