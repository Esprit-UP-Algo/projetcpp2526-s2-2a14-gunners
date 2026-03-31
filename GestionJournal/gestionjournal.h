#ifndef GESTIONJOURNAL_H
#define GESTIONJOURNAL_H

#include <QMainWindow>

#include <QStandardItemModel>

#include "journal.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GestionJournal;
}
QT_END_NAMESPACE

class GestionJournal : public QMainWindow {
  Q_OBJECT

public:
  GestionJournal(QWidget *parent = nullptr);
  ~GestionJournal();

private slots:
  void on_enregistrer_clicked();
  void on_modif_clicked();
  void on_SuppPub_clicked();
  void on_annuler_clicked();
  void on_tableViewPub_clicked(const QModelIndex &index);
  void on_recherchePub_clicked();
  void on_expoPub_clicked();
  void on_quitterPub_clicked();
  void on_triePub_clicked();
  void on_refreshPub_clicked();

private:
  Ui::GestionJournal *ui;
  Journal Jtmp;
  void updateTableModel(QSqlQueryModel *model);
};
#endif // GESTIONJOURNAL_H
