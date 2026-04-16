#ifndef SMARTRESEARCH_H
#define SMARTRESEARCH_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QMap>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>

class GestionSession;
class GestionReviewer;
#include "publication.h"
#include "utilisateur.h"
#include "journal.h"
#include "session.h"
#include "smtp.h"

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
    
    // Session Slots
    void on_enregistrerSession_clicked();
    void on_modifSession_clicked();
    void on_annulerajout_client_Session_clicked();
    void on_SuppSession_clicked();
    void on_rechercheSession_clicked();
    void on_tableWidget_5_clicked(const QModelIndex &index);
    void on_expoSession_clicked();
    
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
  GestionReviewer *reviewerController = nullptr;
  Publication Ptmp;
  Utilisateur Utmp;
  Journal Jtmp;
  Session Stmp;

  void updateUtilisateurStats();
  void updatePublicationStats();
  void updateSessionStats();
  void refreshJournalTable();
  void updateJournalStats();
  QLabel* label_Chart_Session = nullptr;
  void drawBarChart(QLabel *label, const QMap<QString, int> &data, const QColor &barColor);
  void drawDoubleBarChart(QLabel *label, const QMap<QString, int> &data1, const QString &title1, const QColor &color1, const QMap<QString, int> &data2, const QString &title2, const QColor &color2);
  
  // Session Validation Helpers
  bool validerID(int id);
  bool validerTitre(QString titre);
  bool validerDate(QDate date, bool isUpdate);
  bool validerLieu(QString lieu);
  bool validerType();
  void setFieldStyle(QWidget *w, bool isValid);
  void applySessionColoring();

  int selectedUtilisateurId = -1;
  int selectedPublicationId = -1;
  int selectedJournalId     = -1;
  int selectedSessionId     = -1;
};

#endif // SMARTRESEARCH_H
