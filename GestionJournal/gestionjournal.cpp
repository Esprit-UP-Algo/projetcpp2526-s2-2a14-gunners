#include "gestionjournal.h"
#include "ui_gestionjournal.h"
#include <QGroupBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>

GestionJournal::GestionJournal(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GestionJournal) {
  ui->setupUi(this);

  // Force tous les champs de texte à avoir un texte noir sur fond blanc
  QList<QLineEdit *> lineEdits = this->findChildren<QLineEdit *>();
  for (QLineEdit *lineEdit : lineEdits) {
    lineEdit->setStyleSheet("color: black; background-color: white;");
  }

  // Masquer les titres de groupes ('Ajout une conférence ou journal', etc.)
  QList<QGroupBox *> groupBoxes = this->findChildren<QGroupBox *>();
  for (QGroupBox *gb : groupBoxes) {
    gb->setTitle("");
  }

  // Masquer les en-têtes d'onglets redondants (le bouton 'Gestion Conférence ou
  // Journal') en haut
  ui->tabWidget->setStyleSheet(
      "QTabBar::tab { height: 0px; width: 0px; margin: 0; padding: 0; border: "
      "none; color: transparent; font-size: 0px; background: transparent; }"
      "QTabWidget::pane { border: none; }");

  // Force le texte de l'onglet à être vide pour éviter les résidus d'affichage
  for (int i = 0; i < ui->tabWidget->count(); ++i) {
    ui->tabWidget->setTabText(i, "");
  }

  // Force le tableau et ses en-tetes à etre lisibles et modernes
  ui->tableViewPub->setStyleSheet(
      "QTableView {"
      "  background-color: white;"
      "  alternate-background-color: #f0f4fc;"
      "  color: #333333;"
      "  gridline-color: #dbe2ef;"
      "  border: 1px solid #c0c0c0;"
      "  border-radius: 4px;"
      "  selection-background-color: #0044cc;"
      "  selection-color: white;"
      "  font-family: 'Segoe UI', Arial, sans-serif;"
      "  font-size: 13px;"
      "}"
      "QTableView::item {"
      "  padding: 4px;"
      "  border: none;"
      "}"
      "QHeaderView::section {"
      "  background-color: #002266;"
      "  color: white;"
      "  font-weight: bold;"
      "  font-size: 13px;"
      "  padding: 6px;"
      "  border: none;"
      "  border-right: 1px solid #001133;"
      "  border-bottom: 2px solid #0044cc;"
      "}");

  ui->tableViewPub->setAlternatingRowColors(true);

  updateTableModel(Jtmp.afficher());
  ui->tableViewPub->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableViewPub->setSelectionMode(QAbstractItemView::SingleSelection);
}

GestionJournal::~GestionJournal() { delete ui; }

void GestionJournal::on_enregistrer_clicked() {
  int id = ui->id->text().toInt();
  QString nom = ui->nom->text();
  QString type = ui->type->text();
  QString domaine = ui->domaine_scientifique->text();
  QString facteur = ui->facteur_impact->text();
  QString classement = ui->classement->text();
  QString pays = ui->pays->text();
  QString organisation = ui->organisation->text();
  QString periodicite = ui->periodicite->text();
  QString siteweb = ui->siteweb->text();

  Journal J(id, nom, type, domaine, facteur, classement, pays, organisation,
            periodicite, siteweb);
  bool test = J.ajouter();

  if (test) {
    updateTableModel(Jtmp.afficher());
    QMessageBox::information(
        nullptr, QObject::tr("OK"),
        QObject::tr("Ajout effectué\nClick Cancel to exit."),
        QMessageBox::Cancel);
  } else {
    QMessageBox::critical(
        nullptr, QObject::tr("Not OK"),
        QObject::tr("Ajout non effectué\nClick Cancel to exit."),
        QMessageBox::Cancel);
  }
}

void GestionJournal::on_modif_clicked() {
  int id = ui->id->text().toInt();
  QString nom = ui->nom->text();
  QString type = ui->type->text();
  QString domaine = ui->domaine_scientifique->text();
  QString facteur = ui->facteur_impact->text();
  QString classement = ui->classement->text();
  QString pays = ui->pays->text();
  QString organisation = ui->organisation->text();
  QString periodicite = ui->periodicite->text();
  QString siteweb = ui->siteweb->text();

  Journal J(id, nom, type, domaine, facteur, classement, pays, organisation,
            periodicite, siteweb);
  bool test = J.modifier(id);

  if (test) {
    updateTableModel(Jtmp.afficher());
    QMessageBox::information(
        nullptr, QObject::tr("OK"),
        QObject::tr("Modification effectuée\nClick Cancel to exit."),
        QMessageBox::Cancel);
  } else {
    QMessageBox::critical(
        nullptr, QObject::tr("Not OK"),
        QObject::tr("Modification non effectuée\nClick Cancel to exit."),
        QMessageBox::Cancel);
  }
}

void GestionJournal::on_SuppPub_clicked() {
  int id = ui->id->text().toInt();
  bool test = Jtmp.supprimer(id);

  if (test) {
    updateTableModel(Jtmp.afficher());
    QMessageBox::information(
        nullptr, QObject::tr("OK"),
        QObject::tr("Suppression effectuée\nClick Cancel to exit."),
        QMessageBox::Cancel);
  } else {
    QMessageBox::critical(
        nullptr, QObject::tr("Not OK"),
        QObject::tr("Suppression non effectuée\nClick Cancel to exit."),
        QMessageBox::Cancel);
  }
}

void GestionJournal::on_annuler_clicked() {
  ui->id->clear();
  ui->nom->clear();
  ui->type->clear();
  ui->domaine_scientifique->clear();
  ui->facteur_impact->clear();
  ui->classement->clear();
  ui->pays->clear();
  ui->organisation->clear();
  ui->periodicite->clear();
  ui->siteweb->clear();
}

void GestionJournal::on_tableViewPub_clicked(const QModelIndex &index) {
  int row = index.row();
  ui->id->setText(ui->tableViewPub->model()->index(row, 0).data().toString());
  ui->nom->setText(ui->tableViewPub->model()->index(row, 1).data().toString());
  ui->type->setText(ui->tableViewPub->model()->index(row, 2).data().toString());
  ui->domaine_scientifique->setText(
      ui->tableViewPub->model()->index(row, 3).data().toString());
  ui->facteur_impact->setText(
      ui->tableViewPub->model()->index(row, 4).data().toString());
  ui->classement->setText(
      ui->tableViewPub->model()->index(row, 5).data().toString());
  ui->pays->setText(ui->tableViewPub->model()->index(row, 6).data().toString());
  ui->organisation->setText(
      ui->tableViewPub->model()->index(row, 7).data().toString());
  ui->periodicite->setText(
      ui->tableViewPub->model()->index(row, 8).data().toString());
  ui->siteweb->setText(
      ui->tableViewPub->model()->index(row, 9).data().toString());
}

void GestionJournal::on_recherchePub_clicked() {
  QString rech = ui->rechPub->text();
  updateTableModel(Jtmp.rechercher(rech));
}

void GestionJournal::on_expoPub_clicked() {
  QPdfWriter pdf("Liste_Journaux.pdf");
  QPainter painter(&pdf);
  
  const int titleX = 2000;
  const int titleY = 2000;
  const int startY = 4000;
  const int rowHeight = 500;
  const int colIdX = 200;
  const int colNomX = 1500;
  const int colTypeX = 4000;

  int currentY = startY;
  painter.setPen(Qt::blue);
  painter.setFont(QFont("Arial", 30));
  painter.drawText(titleX, titleY, "Liste des Journaux");
  painter.setPen(Qt::black);
  painter.setFont(QFont("Arial", 15));

  QSqlQuery query;
  query.prepare("SELECT * FROM TABLE_JOURNAL_CONF");
  query.exec();

  while (query.next()) {
    painter.drawText(colIdX, currentY, query.value(0).toString());
    painter.drawText(colNomX, currentY, query.value(1).toString());
    painter.drawText(colTypeX, currentY, query.value(2).toString());
    currentY += rowHeight;
  }

  QMessageBox::information(
      nullptr, QObject::tr("PDF Enregistré"),
      QObject::tr("PDF généré avec succès.\nClick Cancel to exit."),
      QMessageBox::Cancel);
}

void GestionJournal::on_quitterPub_clicked() { this->close(); }

void GestionJournal::on_triePub_clicked() {
  updateTableModel(Jtmp.trier());
}

void GestionJournal::on_refreshPub_clicked() {
  updateTableModel(Jtmp.afficher());
}

void GestionJournal::updateTableModel(QSqlQueryModel *newModel) {
  QAbstractItemModel *oldModel = ui->tableViewPub->model();
  ui->tableViewPub->setModel(newModel);
  if (oldModel) {
    oldModel->deleteLater();
  }
}
