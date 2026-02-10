#include "gestionjournal.h"
#include "ui_gestionjournal.h"

GestionJournal::GestionJournal(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GestionJournal) {
  ui->setupUi(this);
  model = new QStandardItemModel(this);
  model->setColumnCount(10);
  model->setHorizontalHeaderLabels(
      QStringList() << "Id" << "Nom" << "Type" << "Domaine Scientifique"
                    << "Facteur d'impact" << "Classement" << "Pays"
                    << "Organisation" << "Périodicité" << "Site Web");
  ui->tableViewPub->setModel(model);
}

GestionJournal::~GestionJournal() { delete ui; }

void GestionJournal::on_quitterPub_clicked() { this->close(); }
