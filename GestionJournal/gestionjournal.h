#ifndef GESTIONJOURNAL_H
#define GESTIONJOURNAL_H

#include <QMainWindow>

#include <QStandardItemModel>

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

  void on_quitterPub_clicked();

private:
  Ui::GestionJournal *ui;
  QStandardItemModel *model;
};
#endif // GESTIONJOURNAL_H
