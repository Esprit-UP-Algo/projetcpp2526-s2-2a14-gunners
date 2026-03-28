#include "smartresearch.h"
#include "ui_smartresearch.h"

#include "gestionsession.h"
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
#include <QButtonGroup>

SmartResearch::SmartResearch(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartResearch) {
  ui->setupUi(this);

  // --- Groupe des boutons radio pour éviter les interférences ---
  QButtonGroup *groupType = new QButtonGroup(this);
  groupType->addButton(ui->radioButton_Admin_3);
  groupType->addButton(ui->radioButton_Admin_4);

  QButtonGroup *groupStatut = new QButtonGroup(this);
  groupStatut->addButton(ui->radioButton_statut_attente);
  groupStatut->addButton(ui->radioButton_statut_accepte);
  groupStatut->addButton(ui->radioButton_statut_rejete);

  QButtonGroup *groupRole = new QButtonGroup(this);
  groupRole->addButton(ui->radioButton_Admin_7);
  groupRole->addButton(ui->radioButton_Admin_2);
  groupRole->addButton(ui->radioButton_Admin);
  groupRole->addButton(ui->radioButton_Chercheur);

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

  // --- Configuration du ComboBox Auteurs ---
  ui->auteurPub->setEditable(true); // Permet de saisir un auteur manuellement si besoin

  // Avoid double connections: Qt's QMetaObject::connectSlotsByName automatically 
  // connects slots named on_objectName_signalName()

  // --- Gestion Utilisateur Initialization ---
  ui->tableWidget_10->setModel(Utmp.afficher());
  ui->tableWidget_10->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableWidget_10->setSelectionMode(QAbstractItemView::SingleSelection);

  // Implicit connections are used here as well for Utilisateur components
}

SmartResearch::~SmartResearch() {
  delete ui;
}

void SmartResearch::on_quitterPub_clicked() { close(); }

void SmartResearch::on_GestionUtilisateurs_clicked() {
  // Your designer tab for users is named: stackedWidgetPage1
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
  ui->tableWidget_10->setModel(Utmp.afficher());
}

void SmartResearch::on_GestionPublications_clicked() {
  // Your designer tab for publications is named: stackedWidgetPage2
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
  ui->tableWidget_9->setModel(Ptmp.afficher());

  // Remplir le combobox avec les utilisateurs existants
  ui->auteurPub->clear();
  QSqlQuery query;
  if(query.exec("SELECT NOM_UTILISATEUR, PRENOM FROM TABLE_UTILISATEUR")) {
      while(query.next()) {
          QString nomComplet = query.value(0).toString() + " " + query.value(1).toString();
          ui->auteurPub->addItem(nomComplet);
      }
  }
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
    QString auteurs = ui->auteurPub->currentText();
    QString abstract = ui->abstractPub->text();
    QString type = "";
    if (ui->radioButton_Admin_3->isChecked()) type = "Conférence";
    else if (ui->radioButton_Admin_4->isChecked()) type = "Journal";
    QString mots_cles = ui->mot_clePub->text();
    QString statut = "";
    if (ui->radioButton_statut_attente->isChecked()) statut = "En attente";
    else if (ui->radioButton_statut_accepte->isChecked()) statut = "Accepté";
    else if (ui->radioButton_statut_rejete->isChecked()) statut = "Rejeté";
    QDate date = ui->datePub->date();

    Publication p(id, titre, auteurs, abstract, type, mots_cles, statut, date);
    if (!p.controler_saisie()) {
        return;
    }
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
    QString auteurs = ui->auteurPub->currentText();
    QString abstract = ui->abstractPub->text();
    QString type = "";
    if (ui->radioButton_Admin_3->isChecked()) type = "Conférence";
    else if (ui->radioButton_Admin_4->isChecked()) type = "Journal";
    QString mots_cles = ui->mot_clePub->text();
    QString statut = "";
    if (ui->radioButton_statut_attente->isChecked()) statut = "En attente";
    else if (ui->radioButton_statut_accepte->isChecked()) statut = "Accepté";
    else if (ui->radioButton_statut_rejete->isChecked()) statut = "Rejeté";
    QDate date = ui->datePub->date();

    Publication p(id, titre, auteurs, abstract, type, mots_cles, statut, date);
    if (!p.controler_saisie()) {
        return;
    }
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
    ui->auteurPub->setCurrentIndex(-1);
    ui->abstractPub->clear();
    ui->mot_clePub->clear();
    
    if (ui->radioButton_statut_attente->group()) ui->radioButton_statut_attente->group()->setExclusive(false);
    ui->radioButton_statut_attente->setChecked(false);
    ui->radioButton_statut_accepte->setChecked(false);
    ui->radioButton_statut_rejete->setChecked(false);
    if (ui->radioButton_statut_attente->group()) ui->radioButton_statut_attente->group()->setExclusive(true);
    
    ui->datePub->setDate(QDate::currentDate());
    
    if (ui->radioButton_Admin_3->group()) ui->radioButton_Admin_3->group()->setExclusive(false);
    ui->radioButton_Admin_3->setChecked(false);
    ui->radioButton_Admin_4->setChecked(false);
    if (ui->radioButton_Admin_3->group()) ui->radioButton_Admin_3->group()->setExclusive(true);
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
    ui->auteurPub->setCurrentText(auteurs);
    ui->abstractPub->setText(abstract);
    ui->mot_clePub->setText(mots_cles);
    
    if (statut == "En attente") ui->radioButton_statut_attente->setChecked(true);
    else if (statut == "Accepté") ui->radioButton_statut_accepte->setChecked(true);
    else if (statut == "Rejeté") ui->radioButton_statut_rejete->setChecked(true);
    else {
        if (ui->radioButton_statut_attente->group()) ui->radioButton_statut_attente->group()->setExclusive(false);
        ui->radioButton_statut_attente->setChecked(false);
        ui->radioButton_statut_accepte->setChecked(false);
        ui->radioButton_statut_rejete->setChecked(false);
        if (ui->radioButton_statut_attente->group()) ui->radioButton_statut_attente->group()->setExclusive(true);
    }
    
    ui->datePub->setDate(date);

    if (type == "Conférence") {
        ui->radioButton_Admin_3->setChecked(true);
    } else {
        ui->radioButton_Admin_4->setChecked(true);
    }
}

void SmartResearch::on_pushButton_recherche_3_clicked() {
    QString id = ui->rechSession_5->text();
    QString tri = ui->comboBox_9->currentText();
    QString ordre = "ASC";
    if (tri == "order decroissant") {
        ordre = "DESC";
    }

    QSqlQueryModel * model = new QSqlQueryModel();
    if (id.isEmpty()) {
        model->setQuery("SELECT * FROM PUBLICATION ORDER BY ID_PUB " + ordre);
    } else {
        model->setQuery("SELECT * FROM PUBLICATION WHERE ID_PUB = '" + id + "' ORDER BY ID_PUB " + ordre);
    }
    
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

void SmartResearch::on_comboBox_9_currentIndexChanged(int index) {
    Q_UNUSED(index);
    on_pushButton_recherche_3_clicked();
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

// --- Gestion Utilisateur Slots ---

void SmartResearch::on_btn_Enregistrer_Utilisateur_clicked() {
    QString id_str = ui->lineEdit_ID_Utilisateur->text();
    QString nom = ui->lineEdit_Nom_Utilisateur->text();
    QString prenom = ui->lineEdit_Prenom_Utilisateur->text();
    QString email = ui->lineEdit_Email_Utilisateur->text();
    QString mdp = ui->lineEdit_Mdp_Utilisateur->text();
    QString num = ui->lineEdit_Institution_Utilisateur_2->text();
    QString inst = ui->lineEdit_Institution_Utilisateur_3->text();
    QString role = "";
    if (ui->radioButton_Admin_7->isChecked()) role = "Admin";
    else if (ui->radioButton_Admin_2->isChecked()) role = "manager";
    else if (ui->radioButton_Admin->isChecked()) role = "editer";
    else if (ui->radioButton_Chercheur->isChecked()) role = "reviewer";

    int id = id_str.toInt();
    Utilisateur u(id, nom, prenom, email, mdp, role, num, inst);
    if (!u.controler_saisie()) {
        return;
    }
    bool test = u.ajouter();
    if (test) {
        ui->tableWidget_10->setModel(Utmp.afficher()); // Refresh
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout utilisateur effectué."), QMessageBox::Ok);
        on_annulerajout_client_3_clicked(); // Clear fields
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout utilisateur non effectué.\nID peut-être dupliqué."), QMessageBox::Ok);
    }
}

void SmartResearch::on_modif_3_clicked() {
    QString id_str = ui->lineEdit_ID_Utilisateur->text();
    QString nom = ui->lineEdit_Nom_Utilisateur->text();
    QString prenom = ui->lineEdit_Prenom_Utilisateur->text();
    QString email = ui->lineEdit_Email_Utilisateur->text();
    QString mdp = ui->lineEdit_Mdp_Utilisateur->text();
    QString num = ui->lineEdit_Institution_Utilisateur_2->text();
    QString inst = ui->lineEdit_Institution_Utilisateur_3->text();
    QString role = "";
    if (ui->radioButton_Admin_7->isChecked()) role = "Admin";
    else if (ui->radioButton_Admin_2->isChecked()) role = "manager";
    else if (ui->radioButton_Admin->isChecked()) role = "editer";
    else if (ui->radioButton_Chercheur->isChecked()) role = "reviewer";

    int id = id_str.toInt();
    Utilisateur u(id, nom, prenom, email, mdp, role, num, inst);
    if (!u.controler_saisie()) {
        return;
    }
    bool test = u.modifier(id);
    if (test) {
        ui->tableWidget_10->setModel(Utmp.afficher()); // Refresh
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification utilisateur effectuée."), QMessageBox::Ok);
        on_annulerajout_client_3_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification utilisateur non effectuée."), QMessageBox::Ok);
    }
}

void SmartResearch::on_annulerajout_client_3_clicked() {
    ui->lineEdit_ID_Utilisateur->clear();
    ui->lineEdit_Nom_Utilisateur->clear();
    ui->lineEdit_Prenom_Utilisateur->clear();
    ui->lineEdit_Email_Utilisateur->clear();
    ui->lineEdit_Mdp_Utilisateur->clear();
    ui->lineEdit_Institution_Utilisateur_2->clear();
    ui->lineEdit_Institution_Utilisateur_3->clear();
    if (ui->radioButton_Admin_7->group()) ui->radioButton_Admin_7->group()->setExclusive(false);
    ui->radioButton_Admin_7->setChecked(false);
    ui->radioButton_Admin_2->setChecked(false);
    ui->radioButton_Admin->setChecked(false);
    ui->radioButton_Chercheur->setChecked(false);
    if (ui->radioButton_Admin_7->group()) ui->radioButton_Admin_7->group()->setExclusive(true);
}

void SmartResearch::on_pushButton_supprimer_client_2_clicked() {
    int id = ui->lineEdit_ID_Utilisateur->text().toInt();
    bool test = Utmp.supprimer(id);
    if (test) {
        ui->tableWidget_10->setModel(Utmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression utilisateur effectuée."), QMessageBox::Ok);
        on_annulerajout_client_3_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppression utilisateur non effectuée."), QMessageBox::Ok);
    }
}

void SmartResearch::on_tableWidget_10_clicked(const QModelIndex &index) {
    int row = index.row();
    
    QString id = ui->tableWidget_10->model()->index(row, 0).data().toString();
    QString nom = ui->tableWidget_10->model()->index(row, 1).data().toString();
    QString prenom = ui->tableWidget_10->model()->index(row, 2).data().toString();
    QString email = ui->tableWidget_10->model()->index(row, 3).data().toString();
    QString mdp = ui->tableWidget_10->model()->index(row, 4).data().toString();
    QString role = ui->tableWidget_10->model()->index(row, 5).data().toString();
    QString num = ui->tableWidget_10->model()->index(row, 6).data().toString();
    QString inst = ui->tableWidget_10->model()->index(row, 7).data().toString();

    ui->lineEdit_ID_Utilisateur->setText(id);
    ui->lineEdit_Nom_Utilisateur->setText(nom);
    ui->lineEdit_Prenom_Utilisateur->setText(prenom);
    ui->lineEdit_Email_Utilisateur->setText(email);
    ui->lineEdit_Mdp_Utilisateur->setText(mdp);
    ui->lineEdit_Institution_Utilisateur_2->setText(num);
    ui->lineEdit_Institution_Utilisateur_3->setText(inst);

    if (role == "Admin") ui->radioButton_Admin_7->setChecked(true);
    else if (role == "manager") ui->radioButton_Admin_2->setChecked(true);
    else if (role == "editer") ui->radioButton_Admin->setChecked(true);
    else if (role == "reviewer") ui->radioButton_Chercheur->setChecked(true);
}

void SmartResearch::on_pushButton_recherche_4_clicked() {
    QString val = ui->rechSession_7->text();
    QString tri = ui->comboBox_11->currentText();
    QString ordre = "ASC";
    if (tri == "order decroissant") {
        ordre = "DESC";
    }

    QSqlQueryModel * model = new QSqlQueryModel();
    if (val.isEmpty()) {
        model->setQuery("SELECT ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR FROM TABLE_UTILISATEUR ORDER BY ID_UTILISATEUR " + ordre);
    } else {
        model->setQuery("SELECT ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR = '" + val + "' ORDER BY ID_UTILISATEUR " + ordre);
    }
    
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mot de passe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Rôle"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Institution"));
    
    ui->tableWidget_10->setModel(model);
}

void SmartResearch::on_comboBox_11_currentIndexChanged(int index) {
    Q_UNUSED(index);
    on_pushButton_recherche_4_clicked();
}
