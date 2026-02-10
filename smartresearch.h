#ifndef SMARTRESEARCH_H
#define SMARTRESEARCH_H

#include <QMainWindow>

#include "GestionJournal/gestionjournal.h"
#include "GestionPublication/gestionpublication.h"
#include "gestionreviewer.h"

class GestionSession;

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

private:
  Ui::SmartResearch *ui;

  GestionSession *sessionWidget = nullptr;
  GestionJournal *journalWindow = nullptr;
  GestionPublication *publicationWindow = nullptr;
  GestionReviewer *reviewerWindow = nullptr;
  int journalTabIndex = -1;
  int reviewerTabIndex = -1;
};

#endif // SMARTRESEARCH_H
