#ifndef SMARTRESEARCH_H
#define SMARTRESEARCH_H

#include <QMainWindow>

class GestionSession;
#include "publication.h"
#include "utilisateur.h"

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
  void on_quitterPub_clicked();
  void on_GestionUtilisateurs_clicked();
  void on_GestionPublications_clicked();
  void on_GestionSession_clicked();
  void on_GestionJournalconference_clicked();
  void on_GestionReviewer_clicked();

  void on_GestionSession_2_clicked();
  void on_btnLogin_main_clicked();
    
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

private:
  Ui::SmartResearch *ui;
  GestionSession *sessionController = nullptr;
  Publication Ptmp;
  Utilisateur Utmp;
};

#endif // SMARTRESEARCH_H
