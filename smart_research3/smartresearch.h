#ifndef SMARTRESEARCH_H
#define SMARTRESEARCH_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QMap>
#include <QLabel>

class GestionSession;
#include "publication.h"
#include "utilisateur.h"
#include "journal.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SmartResearch;
}
QT_END_NAMESPACE

class SmartResearch : public QMainWindow {
  Q_OBJECT

public:
  explicit SmartResearch(QWidget *parent = nullptr);
  ~SmartResearch();

private slots:
  void on_GestionUtilisateurs_clicked();
  void on_GestionPublications_clicked();
  void on_GestionSession_clicked();
  void on_GestionJournalconference_clicked();
  void on_GestionReviewer_clicked();

  void on_GestionSession_2_clicked();
  void on_btnLogin_main_clicked();

    // Journal / Conférence Slots
    void on_enregistrer1_clicked();
    void on_modif1_clicked();
    void on_annuler_clicked();
    void on_SuppSession_4_clicked();
    void on_rechercheSession_4_clicked();
    void on_comboBox_8_currentIndexChanged(int index);
    void on_tableWidget_8_cellClicked(int row, int column);
    void on_expoSession_4_clicked();
    
    // Publication Slots
    void on_enregistrer_clicked();
    void on_modif_clicked();
    void on_annulerajout_client_clicked();
    void on_pushButton_supprimer_client_clicked();
    void on_pushButton_recherche_3_clicked();
    void on_comboBox_9_currentIndexChanged(int index);
    void on_tableWidget_9_clicked(const QModelIndex &index);
    void on_expoSession_5_clicked(); // Export as PDF

    // Utilisateur Slots
    void on_btn_Enregistrer_Utilisateur_clicked();
    void on_modif_3_clicked();
    void on_annulerajout_client_3_clicked();
    void on_pushButton_supprimer_client_2_clicked();
    void on_tableWidget_10_clicked(const QModelIndex &index);
    void on_pushButton_recherche_4_clicked();
    void on_comboBox_11_currentIndexChanged(int index);
    void on_pushButton_pdfclient_clicked(); // Export as PDF

private:
  Ui::SmartResearch *ui;
  GestionSession *sessionController = nullptr;
  Publication Ptmp;
  Utilisateur Utmp;
  Journal Jtmp;

  void updateUtilisateurStats();
  void updatePublicationStats();
  void refreshJournalTable();
  void updateJournalStats();
  void drawBarChart(QLabel *label, const QMap<QString, int> &data, const QColor &barColor);
  int selectedUtilisateurId = -1;
  int selectedPublicationId = -1;
  int selectedJournalId     = -1;
};

#endif // SMARTRESEARCH_H
