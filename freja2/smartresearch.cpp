#include "smartresearch.h"
#include "ui_smartresearch.h"

#include "gestionsession.h"
#include "session.h"

#include <QMessageBox>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>

#include <QPixmap>
#include <QVBoxLayout>
#include <QDebug>

SmartResearch::SmartResearch(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartResearch) {
  ui->setupUi(this);
  ui->tableSession->setModel(s.afficher());

  // --- Logo (resource first) ---
  QPixmap logo(":/logo.png");
  if (!logo.isNull()) {
    ui->label_10->setPixmap(logo);
    ui->label_10->setScaledContents(true);
  }

  // --- Embed GestionSession into the existing tab_session from UI ---
  // GestionSession is a controller, not a widget (UI is in smartresearch.ui)
  sessionController = new GestionSession(ui, this);

  // IMPORTANT: do NOT create extra connects to a non-existing ui->tab_session.
  // Rely on Qt auto-connect slot: on_GestionSession_clicked()

  // --- Initial Login State ---
  // Hide the sidebar, top logo, and "Tableau de Board" label
  ui->groupBox->setVisible(false);
  ui->label_10->setVisible(false);
  ui->TableaudeBoard->setVisible(false);
  
  // Resize stackedWidget to cover the sidebar area
  // Original geometry: x=200, y=100, w=1221, h=621
  // New geometry:      x=10,  y=100, w=1411, h=621 (covering the 190px gap)
  ui->stackedWidget->setGeometry(10, 100, 1411, 621);
  
  // Ensure we start on the login page (index 0)
  ui->stackedWidget->setCurrentIndex(0); 

  // --- Gestion Publication Initialization ---
  ui->tableWidget_9->setModel(Ptmp.afficher());
  ui->tableWidget_9->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableWidget_9->setSelectionMode(QAbstractItemView::SingleSelection);

  // Explicit Connections for robustness
  connect(ui->enregistrer, SIGNAL(clicked()), this, SLOT(on_enregistrer_clicked()));
  connect(ui->modif, SIGNAL(clicked()), this, SLOT(on_modif_clicked()));
  
  // Connect table click for selection
  connect(ui->tableWidget_9, SIGNAL(clicked(const QModelIndex &)), this, SLOT(on_tableWidget_9_clicked(const QModelIndex &)));
}

SmartResearch::~SmartResearch() {
  delete ui;
}

void SmartResearch::on_quitterPub_clicked() { close(); }

void SmartResearch::on_GestionUtilisateurs_clicked() {
  // Your designer tab for users is named: stackedWidgetPage1
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
}

void SmartResearch::on_GestionPublications_clicked() {
  // Your designer tab for publications is named: stackedWidgetPage2
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
  ui->tableWidget_9->setModel(Ptmp.afficher());
}

void SmartResearch::on_GestionSession_clicked() {
  // Go to the embedded Gestion Session tab (stackedWidgetPage5 from UI)
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage5);
}

void SmartResearch::on_GestionJournalconference_clicked() {
  // Go to the embedded Gestion Journal tab
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage3);
}

void SmartResearch::on_GestionReviewer_clicked() {
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);
}

void SmartResearch::on_GestionSession_2_clicked()
{
    // Go to the embedded Gestion Paiement tab
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage6);
}

void SmartResearch::on_btnLogin_main_clicked()
{
    // Simple transition: Show sidebar, logo, and "Tableau de Board" label
    ui->groupBox->setVisible(true);
    ui->label_10->setVisible(true);
    ui->TableaudeBoard->setVisible(true);
    
    // Restore stackedWidget geometry
    ui->stackedWidget->setGeometry(200, 100, 1221, 621);
    
    // Switch to the User Management page (or whatever is your default main page)
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
    
    // Optional: Clear fields
    if (ui->txtPassword_login) ui->txtPassword_login->clear();
    if (ui->txtUsername_login) ui->txtUsername_login->clear();
}

// --- Gestion Publication Slots ---

void SmartResearch::on_enregistrer_clicked() {
    int id = ui->Id_utilisateur->text().toInt(); 
    QString titre = ui->titrePub->text();
    QString auteurs = ui->auteurPub->text();
    QString abstract = ui->abstractPub->text();
    QString type = ui->radioButton_Admin_3->isChecked() ? "Conférence" : "Journal";
    QString mots_cles = ui->mot_clePub->text();
    QString statut = ui->statutPub->text();
    QDate date = ui->datePub->date();

    if(ui->Id_utilisateur->text().isEmpty() || titre.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez remplir au moins l'ID et le Titre.");
        return;
    }

    Publication p(id, titre, auteurs, abstract, type, mots_cles, statut, date);
    bool test = p.ajouter();
    if (test) {
        ui->tableWidget_9->setModel(Ptmp.afficher()); // Refresh
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué."), QMessageBox::Ok);
        on_annulerajout_client_clicked(); // Clear fields
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectué.\nID peut-être dupliqué."), QMessageBox::Ok);
    }
}

void SmartResearch::on_modif_clicked() {
    int id = ui->Id_utilisateur->text().toInt();
    QString titre = ui->titrePub->text();
    QString auteurs = ui->auteurPub->text();
    QString abstract = ui->abstractPub->text();
    QString type = ui->radioButton_Admin_3->isChecked() ? "Conférence" : "Journal";
    QString mots_cles = ui->mot_clePub->text();
    QString statut = ui->statutPub->text();
    QDate date = ui->datePub->date();

    if(ui->Id_utilisateur->text().isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une publication à modifier (ID requis).");
        return;
    }

    Publication p(id, titre, auteurs, abstract, type, mots_cles, statut, date);
    bool test = p.modifier(id);
    if (test) {
        ui->tableWidget_9->setModel(Ptmp.afficher()); // Refresh
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée."), QMessageBox::Ok);
        on_annulerajout_client_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification non effectuée."), QMessageBox::Ok);
    }
}

void SmartResearch::on_annulerajout_client_clicked() {
    ui->Id_utilisateur->clear();
    ui->titrePub->clear();
    ui->auteurPub->clear();
    ui->abstractPub->clear();
    ui->mot_clePub->clear();
    ui->statutPub->clear();
    ui->datePub->setDate(QDate::currentDate());
    ui->radioButton_Admin_3->setChecked(false);
    ui->radioButton_Admin_4->setChecked(false);
}

void SmartResearch::on_pushButton_supprimer_client_clicked() {
    int id = ui->Id_utilisateur->text().toInt();
    bool test = Ptmp.supprimer(id);
    if (test) {
        ui->tableWidget_9->setModel(Ptmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
        on_annulerajout_client_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppression non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void SmartResearch::on_tableWidget_9_clicked(const QModelIndex &index) {
    int row = index.row();
    // Indices match database column order from afficher(): 
    // 0: ID, 1: Titre, 2: Auteurs, 3: Abstract, 4: Type, 5: Mots Clés, 6: Statut, 7: Date
    
    QString id = ui->tableWidget_9->model()->index(row, 0).data().toString();
    QString titre = ui->tableWidget_9->model()->index(row, 1).data().toString();
    QString auteurs = ui->tableWidget_9->model()->index(row, 2).data().toString();
    QString abstract = ui->tableWidget_9->model()->index(row, 3).data().toString();
    QString type = ui->tableWidget_9->model()->index(row, 4).data().toString();
    QString mots_cles = ui->tableWidget_9->model()->index(row, 5).data().toString();
    QString statut = ui->tableWidget_9->model()->index(row, 6).data().toString();
    QDate date = ui->tableWidget_9->model()->index(row, 7).data().toDate();

    ui->Id_utilisateur->setText(id);
    ui->titrePub->setText(titre);
    ui->auteurPub->setText(auteurs);
    ui->abstractPub->setText(abstract);
    ui->mot_clePub->setText(mots_cles);
    ui->statutPub->setText(statut);
    ui->datePub->setDate(date);

    if (type == "Conférence") {
        ui->radioButton_Admin_3->setChecked(true);
    } else {
        ui->radioButton_Admin_4->setChecked(true);
    }
}

void SmartResearch::on_rechercheSession_5_clicked() {
    QString id = ui->rechSession_5->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM PUBLICATION WHERE ID_PUB LIKE '%" + id + "%' OR TITRE_PUB LIKE '%" + id + "%' OR AUTEURS_PUB LIKE '%" + id + "%'");
    
    // Set headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Auteurs"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Abstract"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mots Clés"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date"));
    
    ui->tableWidget_9->setModel(model);
}

void SmartResearch::on_expoSession_5_clicked() {
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableWidget_9->model()->rowCount();
    const int columnCount = ui->tableWidget_9->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("Liste des Publications")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> *** LISTE DES PUBLICATIONS *** </strong></h1>"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableWidget_9->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableWidget_9->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableWidget_9->isColumnHidden(column)) {
                QString data = ui->tableWidget_9->model()->data(ui->tableWidget_9->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Exporter en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPdfWriter *printer = new QPdfWriter(fileName);
    printer->setPageSize(QPageSize(QPageSize::A4));
    printer->setPageMargins(QMarginsF(15, 15, 15, 15));

    document->print(printer);
    delete document;
    delete printer;
}
//////////////////////////////////////SESSION///////////////////////////////////////////////////////
void SmartResearch::on_enregistrerSession_clicked()
{
    int id = ui->idSession->text().toInt();
    QString titre = ui->titreSession->text();
    QDate date = ui->dateSession->date();
    QString lieu = ui->lieuSession->text();
    QString publications = ui->listeSession->text();
    QString reviewers = ui->reviewesSession->text();
    QString type;
    if (ui->confSession->isChecked())
        type = "conference";
    else if (ui->atelierSession->isChecked())
        type = "atelier";
    else if (ui->presentSession->isChecked())
        type = "presentation";
    if (titre.isEmpty() || lieu.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    session s(id, titre, date, lieu, type, publications, reviewers);
    if (s.ajouter()) {
        QMessageBox::information(this, "Succès", "Session enregistrée avec succès !");
        ui->tableSession->setModel(s.afficher());
        ui->idSession->clear();
        ui->titreSession->clear();
        ui->dateSession->clear();//setDate(QDate::currentDate());
        ui->lieuSession->clear();
        ui->listeSession->clear();
        ui->reviewesSession->clear();
        ui->confSession->setChecked(false);
        ui->atelierSession->setChecked(false);
        ui->presentSession->setChecked(false);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'enregistrement !");
    }
}

void SmartResearch::on_modifSession_clicked()
{
    int id = ui->idSession->text().toInt();
    QString titre = ui->titreSession->text();
    QDate date = ui->dateSession->date();
    QString lieu = ui->lieuSession->text();
    QString publications = ui->listeSession->text();
    QString reviewers = ui->reviewesSession->text();
    QString type;
    if (ui->confSession->isChecked())
        type = "conference";
    else if (ui->atelierSession->isChecked())
        type = "atelier";
    else if (ui->presentSession->isChecked())
        type = "presentation";
    if (id <= 0 || titre.isEmpty() || lieu.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    session s;
    if (s.modifier(id, titre, date, lieu, type, publications, reviewers)) {
        QMessageBox::information(this, "Succès", "Session modifiée avec succès !");
        ui->tableSession->setModel(s.afficher());
        ui->idSession->clear();
        ui->titreSession->clear();
        ui->dateSession->clear();//setDate(QDate::currentDate());
        ui->lieuSession->clear();
        ui->listeSession->clear();
        ui->reviewesSession->clear();
        ui->confSession->setChecked(false);
        ui->atelierSession->setChecked(false);
        ui->presentSession->setChecked(false);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
    }
}
void SmartResearch::on_SuppSession_clicked()
{
    int id = ui->idSession->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "ID manquant", "Veuillez entrer l'ID de la session à supprimer.");
        return;
    }
    QMessageBox::StandardButton reponse = QMessageBox::question(this, "Confirmation",
                                                                "Voulez-vous vraiment supprimer la session " + QString::number(id) + " ?",
                                                                QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes) {
        session s;
        if (s.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Session supprimée !");
            ui->tableSession->setModel(s.afficher());
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
        }
    }
}

void SmartResearch::on_rechercheSession_clicked()
{
    int id = ui->rechSession->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "ID manquant", "Veuillez entrer un ID à rechercher.");
        return;
    }
    session s;
    QSqlQueryModel* model = s.rechercher(id);
    if (model && model->rowCount() > 0) {
        ui->tableSession->setModel(model);
        ui->rechSession->clear();
    } else {
        QMessageBox::warning(this, "Introuvable", "Aucune session trouvée avec cet ID.");
        session s2;
        ui->tableSession->setModel(s2.afficher());
    }
}


void SmartResearch::on_tableSession_clicked(const QModelIndex &index)
{
    int row = index.row();
    QSqlQueryModel* model = (QSqlQueryModel*)ui->tableSession->model();
    ui->idSession->setText(model->data(model->index(row, 0)).toString());
    ui->titreSession->setText(model->data(model->index(row, 1)).toString());
    ui->dateSession->setDate(QDate::fromString(model->data(model->index(row, 2)).toString(), "yyyy-MM-dd"));
    ui->lieuSession->setText(model->data(model->index(row, 3)).toString());
    QString type = model->data(model->index(row, 4)).toString();
    if (type == "conference")
        ui->confSession->setChecked(true);
    else if (type == "atelier")
        ui->atelierSession->setChecked(true);
    else if (type == "presentation")
        ui->presentSession->setChecked(true);
    ui->listeSession->setText(model->data(model->index(row, 5)).toString());
    ui->reviewesSession->setText(model->data(model->index(row, 6)).toString());

}


void SmartResearch::on_annulerSession_clicked()
{
    ui->tableSession->setModel(s.afficher());
    ui->idSession->clear();
    ui->titreSession->clear();
    ui->dateSession->clear();//setDate(QDate::currentDate());
    ui->lieuSession->clear();
    ui->listeSession->clear();
    ui->reviewesSession->clear();
    ui->confSession->setChecked(false);
    ui->atelierSession->setChecked(false);
    ui->presentSession->setChecked(false);
}


void SmartResearch::on_refresh_clicked()
{
    ui->tableSession->setModel(s.afficher());
}


void SmartResearch::on_trieSession_currentIndexChanged(int index)
{
    QString ordre = (index == 0) ? "ASC" : "DESC";
    session s;
    QSqlQueryModel* model = s.trier(ordre);

    if (model) {
        ui->tableSession->setModel(model);
    }
}

