#include "smartresearch.h"
#include "ui_smartresearch.h"

#include "gestionsession.h"
#include "journal.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>

#include <QPixmap>
#include <QVBoxLayout>
#include <QDebug>
#include <QButtonGroup>
#include <QMap>
#include <algorithm>
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

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

  // Avoid double connections: Qt's QMetaObject::connectSlotsByName automatically 
  // connects slots named on_objectName_signalName()

  // --- Gestion Utilisateur Initialization ---
  ui->tableWidget_10->setModel(Utmp.afficher());
  ui->tableWidget_10->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableWidget_10->setSelectionMode(QAbstractItemView::SingleSelection);

  // --- Gestion Journal Initialization ---
  ui->type->addItem("Journal");
  ui->type->addItem("Conférence");
  ui->type->setCurrentIndex(-1); // Show empty by default
  ui->domaine_scientifique->addItems({
      "-- Sélectionner un domaine --",
      "Computer Science (Informatique)",
      "  - Artificial Intelligence (Intelligence Artificielle)",
      "  - Machine Learning (Apprentissage Automatique)",
      "  - Cybersecurity (Sécurité Informatique)",
      "  - Computer Vision (Vision par Ordinateur)",
      "  - Computer Networks (Réseaux Informatiques)",
      "Mathematics (Mathématiques)",
      "  - Algebra (Algèbre)",
      "  - Analysis (Analyse)",
      "  - Geometry (Géométrie)",
      "  - Statistics (Statistiques)",
      "Logic (Logique)",
      "Natural Sciences (Sciences Naturelles)",
      "Physics (Physique)",
      "  - Astrophysics (Astrophysique)",
      "  - Quantum Physics (Physique Quantique)",
      "  - Thermodynamics (Thermodynamique)",
      "  - Optics (Optique)",
      "Chemistry (Chimie)",
      "  - Organic Chemistry (Chimie Organique)",
      "  - Analytical Chemistry (Chimie Analytique)",
      "  - Biochemistry (Biochimie)",
      "Biology (Biologie)",
      "  - Genetics (Génétique)",
      "  - Molecular Biology (Biologie Moléculaire)",
      "  - Ecology (Écologie)",
      "  - Neuroscience (Neurosciences)",
      "  - Botany (Botanique)",
      "Earth Sciences (Sciences de la Terre)",
      "  - Geology (Géologie)",
      "  - Climatology (Climatologie)",
      "  - Oceanography (Océanographie)",
      "Social and Human Sciences (Sciences Sociales et Humaines)",
      "Economics (Économie)",
      "Psychology (Psychologie)",
      "Sociology (Sociologie)",
      "History (Histoire)",
      "Political Science (Sciences Politiques)",
      "Linguistics (Linguistique)",
      "Anthropology (Anthropologie)",
      "Applied Sciences & Engineering (Sciences Appliquées et Ingénierie)",
      "Medicine (Médecine)",
      "  - Cardiology (Cardiologie)",
      "  - Oncology (Oncologie)",
      "  - Neurology (Neurologie)",
      "  - Pediatrics (Pédiatrie)",
      "Civil Engineering (Génie Civil)",
      "Electrical Engineering (Génie Électrique)",
      "Mechanical Engineering (Génie Mécanique)",
      "Biotechnology (Biotechnologie)",
      "Agronomy / Agricultural Science (Agronomie)"
  });
  ui->classement->addItems({
      "-- Sélectionner un classement --",
      "Q1 (Quartile 1): The top 25% of journals in the field",
      "Q2 (Quartile 2): The journals in the 25% to 50% group",
      "Q3 (Quartile 3): The journals in the 50% to 75% group",
      "Q4 (Quartile 4): The bottom 25% of journals in the field"
  });
  ui->periodicite->addItems({
      "-- Sélectionner la périodicité --",
      "Annuelle",
      "Semestrielle",
      "Trimestrielle",
      "Mensuelle",
      "Continue"
  });
  refreshJournalTable();

  updateUtilisateurStats();
  updatePublicationStats();
  updateJournalStats();
}

SmartResearch::~SmartResearch() {
  delete ui;
}

void SmartResearch::on_GestionUtilisateurs_clicked() {
  // Your designer tab for users is named: stackedWidgetPage1
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
  ui->tableWidget_10->setModel(Utmp.afficher());
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
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage3);
  refreshJournalTable();
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
    QString statut = "";
    if (ui->radioButton_statut_attente->isChecked()) statut = "En attente";
    else if (ui->radioButton_statut_accepte->isChecked()) statut = "Accepté";
    else if (ui->radioButton_statut_rejete->isChecked()) statut = "Rejeté";
    QDate date = ui->datePub->date();

    // 1. Contrôle ID
    if (ui->Id_utilisateur->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'ID' est obligatoire. Veuillez le renseigner.");
        return;
    }
    bool ok;
    int id_val = ui->Id_utilisateur->text().toInt(&ok);
    if (!ok || id_val <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID saisi est invalide. Il doit s'agir d'un nombre entier strictement positif.");
        return;
    }

    // 2. Contrôle Titre
    if (titre.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Titre' est obligatoire.");
        return;
    }
    QRegularExpression rePub("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!rePub.match(titre).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Titre' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 3. Contrôle Auteurs
    if (auteurs.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Auteurs' est obligatoire.");
        return;
    }
    if (!rePub.match(auteurs).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Auteurs' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 4. Contrôle Abstract
    if (abstract.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Abstract' est obligatoire.");
        return;
    }
    if (!rePub.match(abstract).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Abstract' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 5. Contrôle Type
    if (!ui->radioButton_Admin_3->isChecked() && !ui->radioButton_Admin_4->isChecked()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner le 'Type' (Conférence ou Journal).");
        return;
    }

    // 6. Contrôle Mots clés
    if (mots_cles.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mots clés' est obligatoire.");
        return;
    }
    if (!rePub.match(mots_cles).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mots clés' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 7. Contrôle Statut
    if (statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Statut' est obligatoire.");
        return;
    }

    Publication p(id, titre, auteurs, abstract, type, mots_cles, statut, date);
    bool test = p.ajouter();
    if (test) {
        ui->tableWidget_9->setModel(Ptmp.afficher()); // Refresh
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué."), QMessageBox::Ok);
        updatePublicationStats();
        on_annulerajout_client_clicked(); // Clear fields
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectué.\nID peut-être dupliqué."), QMessageBox::Ok);
    }
}

void SmartResearch::on_modif_clicked() {
    int id_val; // Declare to replace the removed int id
    QString titre = ui->titrePub->text();
    QString auteurs = ui->auteurPub->text();
    QString abstract = ui->abstractPub->text();
    QString type = ui->radioButton_Admin_3->isChecked() ? "Conférence" : "Journal";
    QString mots_cles = ui->mot_clePub->text();
    QString statut = "";
    if (ui->radioButton_statut_attente->isChecked()) statut = "En attente";
    else if (ui->radioButton_statut_accepte->isChecked()) statut = "Accepté";
    else if (ui->radioButton_statut_rejete->isChecked()) statut = "Rejeté";
    QDate date = ui->datePub->date();

    // 1. Contrôle ID
    if (ui->Id_utilisateur->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'ID' est obligatoire. Veuillez sélectionner une publication à modifier.");
        return;
    }
    bool ok;
    id_val = ui->Id_utilisateur->text().toInt(&ok);
    if (!ok || id_val <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID saisi est invalide. Il doit s'agir d'un nombre entier strictement positif.");
        return;
    }

    // Check if ID is changed and already exists
    if (selectedPublicationId != -1 && id_val != selectedPublicationId) {
        if (Publication::verifierId(id_val)) {
            QMessageBox::warning(this, "Erreur de saisie", "Cet ID est déjà utilisé par une autre publication. Veuillez en choisir un autre.");
            return;
        }
    }

    // 2. Contrôle Titre
    if (titre.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Titre' est obligatoire.");
        return;
    }
    QRegularExpression rePubMod("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!rePubMod.match(titre).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Titre' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 3. Contrôle Auteurs
    if (auteurs.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Auteurs' est obligatoire.");
        return;
    }
    if (!rePubMod.match(auteurs).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Auteurs' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 4. Contrôle Abstract
    if (abstract.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Abstract' est obligatoire.");
        return;
    }
    if (!rePubMod.match(abstract).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Abstract' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 5. Contrôle Type
    if (!ui->radioButton_Admin_3->isChecked() && !ui->radioButton_Admin_4->isChecked()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner le 'Type' (Conférence ou Journal).");
        return;
    }

    // 6. Contrôle Mots clés
    if (mots_cles.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mots clés' est obligatoire.");
        return;
    }
    if (!rePubMod.match(mots_cles).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mots clés' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 7. Contrôle Statut
    if (statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Statut' est obligatoire.");
        return;
    }

    Publication p(id_val, titre, auteurs, abstract, type, mots_cles, statut, date);
    // Use the original selected ID to find the row, even if the ID in the object is different
    bool test = p.modifier(selectedPublicationId != -1 ? selectedPublicationId : id_val);
    if (test) {
        ui->tableWidget_9->setModel(Ptmp.afficher()); // Refresh
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée."), QMessageBox::Ok);
        updatePublicationStats();
        on_annulerajout_client_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification non effectuée."), QMessageBox::Ok);
    }
}

void SmartResearch::on_annulerajout_client_clicked() {
    ui->Id_utilisateur->clear();
    this->selectedPublicationId = -1;
    ui->titrePub->clear();
    ui->auteurPub->clear();
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
        updatePublicationStats();
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
    this->selectedPublicationId = id.toInt();
    ui->titrePub->setText(titre);
    ui->auteurPub->setText(auteurs);
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
        "<center> <h1 style=\"color: #1e293b; font-family: Arial, sans-serif;\"><strong> *** LISTE DES PUBLICATIONS *** </strong></h1> </center>\n"
        "<table border=1 cellspacing=0 cellpadding=8 width=\"100%\" style=\"border-collapse: collapse; border: 1px solid #1e293b; font-family: Arial, sans-serif;\">\n";

    // headers
    out << "<thead><tr bgcolor=#1e293b style=\"color: #ffffff; font-weight: bold;\">";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableWidget_9->isColumnHidden(column))
            out << QString("<th style=\"border: 1px solid #1e293b; padding: 10px;\">%1</th>").arg(ui->tableWidget_9->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableWidget_9->isColumnHidden(column)) {
                QString data = ui->tableWidget_9->model()->data(ui->tableWidget_9->model()->index(row, column)).toString().simplified();
                out << QString("<td style=\"border: 1px solid #1e293b; text-align: center; padding: 8px;\">%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
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
    if (fileName.isEmpty()) {
        delete document;
        return;
    }
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPdfWriter *printer = new QPdfWriter(fileName);
    printer->setPageSize(QPageSize(QPageSize::A4));
    printer->setPageOrientation(QPageLayout::Landscape);
    printer->setPageMargins(QMarginsF(15, 15, 15, 15));

    document->print(printer);
    delete document;
    delete printer;

    QMessageBox::information(this, "Exportation PDF", "La liste des publications a été exportée avec succès.");
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

    // 1. Contrôle ID
    if (id_str.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'ID' est obligatoire. Veuillez le renseigner.");
        return;
    }
    bool ok;
    int id = id_str.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID saisi est invalide. Il doit s'agir d'un nombre entier strictement positif.");
        return;
    }

    // 2. Contrôle Nom
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' est obligatoire. Veuillez le renseigner.");
        return;
    }
    QRegularExpression reUser("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!reUser.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 3. Contrôle Prénom
    if (prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Prénom' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (!reUser.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Prénom' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 4. Contrôle Email
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Email' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (!email.contains("@") || !email.contains(".")) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse 'Email' saisie est invalide. Vérifiez qu'elle contient bien un '@' et un '.'.");
        return;
    }

    // 5. Contrôle Mot de passe
    if (mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mot de passe' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (mdp.length() < 6) {
        QMessageBox::warning(this, "Erreur de saisie", "Pour votre sécurité, le 'Mot de passe' doit contenir au moins 6 caractères.");
        return;
    }

    // 6. Contrôle Rôle
    if (role.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner un 'Rôle' (Admin, manager, etc.) pour cet utilisateur.");
        return;
    }

    // 7. Contrôle Numéro
    if (num.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Numéro' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (num.length() != 8) {
        QMessageBox::warning(this, "Erreur de saisie", "Le 'Numéro' doit contenir exactement 8 chiffres.");
        return;
    }
    long long num_val = num.toLongLong(&ok);
    if (!ok || num_val <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le 'Numéro' saisi est invalide. Il doit être composé uniquement de chiffres positifs.");
        return;
    }

    // 8. Contrôle Institution
    if (inst.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Institution' est obligatoire. Veuillez le renseigner.");
        return;
    }

    Utilisateur u(id, nom, prenom, email, mdp, role, num, inst);
    bool test = u.ajouter();
    if (test) {
        ui->tableWidget_10->setModel(Utmp.afficher()); // Refresh
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout utilisateur effectué."), QMessageBox::Ok);
        updateUtilisateurStats();
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

    // 1. Contrôle ID
    if (id_str.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'ID' est obligatoire. Veuillez le renseigner.");
        return;
    }
    bool ok;
    int id = id_str.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID saisi est invalide. Il doit s'agir d'un nombre entier strictement positif.");
        return;
    }

    // Check if ID is changed and already exists
    if (selectedUtilisateurId != -1 && id != selectedUtilisateurId) {
        if (Utilisateur::verifierId(id)) {
            QMessageBox::warning(this, "Erreur de saisie", "Cet ID est déjà utilisé par un autre utilisateur. Veuillez en choisir un autre.");
            return;
        }
    }

    // ... (rest of validation)
    // 2. Contrôle Nom
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' est obligatoire. Veuillez le renseigner.");
        return;
    }
    QRegularExpression reMod("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!reMod.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 3. Contrôle Prénom
    if (prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Prénom' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (!reMod.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Prénom' ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 4. Contrôle Email
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Email' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (!email.contains("@") || !email.contains(".")) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse 'Email' saisie est invalide. Vérifiez qu'elle contient bien un '@' et un '.'.");
        return;
    }

    // 5. Contrôle Mot de passe
    if (mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mot de passe' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (mdp.length() < 6) {
        QMessageBox::warning(this, "Erreur de saisie", "Pour votre sécurité, le 'Mot de passe' doit contenir au moins 6 caractères.");
        return;
    }

    // 6. Contrôle Rôle
    if (role.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner un 'Rôle' (Admin, manager, etc.) pour cet utilisateur.");
        return;
    }

    // 7. Contrôle Numéro
    if (num.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Numéro' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (num.length() != 8) {
        QMessageBox::warning(this, "Erreur de saisie", "Le 'Numéro' doit contenir exactement 8 chiffres.");
        return;
    }
    long long num_val = num.toLongLong(&ok);
    if (!ok || num_val <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le 'Numéro' saisi est invalide. Il doit être composé uniquement de chiffres positifs.");
        return;
    }

    // 8. Contrôle Institution
    if (inst.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Institution' est obligatoire. Veuillez le renseigner.");
        return;
    }

    Utilisateur u(id, nom, prenom, email, mdp, role, num, inst);
    // Use the original selected ID to find the row, even if the ID in the object is different
    bool test = u.modifier(selectedUtilisateurId != -1 ? selectedUtilisateurId : id);
    if (test) {
        ui->tableWidget_10->setModel(Utmp.afficher()); // Refresh
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification utilisateur effectuée."), QMessageBox::Ok);
        updateUtilisateurStats();
        on_annulerajout_client_3_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification utilisateur non effectuée."), QMessageBox::Ok);
    }
}

void SmartResearch::on_annulerajout_client_3_clicked() {
    ui->lineEdit_ID_Utilisateur->clear();
    this->selectedUtilisateurId = -1;
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
        updateUtilisateurStats();
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
    this->selectedUtilisateurId = id.toInt();
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

void SmartResearch::on_pushButton_pdfclient_clicked() {
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableWidget_10->model()->rowCount();
    const int columnCount = ui->tableWidget_10->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("Liste des Utilisateurs")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<center> <h1 style=\"color: #1e293b; font-family: Arial, sans-serif;\"><strong> *** LISTE DES UTILISATEURS *** </strong></h1> </center>\n"
        "<table border=1 cellspacing=0 cellpadding=8 width=\"100%\" style=\"border-collapse: collapse; border: 1px solid #1e293b; font-family: Arial, sans-serif;\">\n";

    // headers
    out << "<thead><tr bgcolor=#1e293b style=\"color: #ffffff; font-weight: bold;\">";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableWidget_10->isColumnHidden(column))
            out << QString("<th style=\"border: 1px solid #1e293b; padding: 10px;\">%1</th>").arg(ui->tableWidget_10->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableWidget_10->isColumnHidden(column)) {
                QString data = ui->tableWidget_10->model()->data(ui->tableWidget_10->model()->index(row, column)).toString().simplified();
                out << QString("<td style=\"border: 1px solid #1e293b; text-align: center; padding: 8px;\">%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
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
    if (fileName.isEmpty()) {
        delete document;
        return;
    }
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPdfWriter *printer = new QPdfWriter(fileName);
    printer->setPageSize(QPageSize(QPageSize::A4));
    printer->setPageOrientation(QPageLayout::Landscape);
    printer->setPageMargins(QMarginsF(15, 15, 15, 15));

    document->print(printer);
    delete document;
    delete printer;
    
    QMessageBox::information(this, "Exportation PDF", "La liste des utilisateurs a été exportée avec succès.");
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
        model->setQuery("SELECT ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM_UTILISATEUR, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR FROM TABLE_UTILISATEUR ORDER BY ID_UTILISATEUR " + ordre);
    } else {
        model->setQuery("SELECT ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM_UTILISATEUR, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR = '" + val + "' ORDER BY ID_UTILISATEUR " + ordre);
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

void SmartResearch::updateUtilisateurStats() {
    QMap<QString, int> stats = Utilisateur::getStatistics();

    // Prepare data for Chart
    QMap<QString, int> chartData;
    chartData["Admins"] = stats["Admin"];
    chartData["Managers"] = stats["manager"];
    chartData["Editors"] = stats["editer"];
    chartData["Reviewers"] = stats["reviewer"];
    
    drawBarChart(ui->label_Chart_Utilisateur, chartData, QColor("#10b981"));
}

void SmartResearch::updatePublicationStats() {
    QMap<QString, int> stats = Publication::getStatistics();

    // Prepare data for Chart
    QMap<QString, int> chartData;
    chartData["Attente"] = stats["status_En attente"];
    chartData["Accepté"] = stats["status_Accepté"];
    chartData["Rejeté"] = stats["status_Rejeté"];
    chartData["Journal"] = stats["type_Journal"];
    chartData["Conférence"] = stats["type_Conférence"];
    
    drawBarChart(ui->label_Chart_Publication, chartData, QColor("#10b981"));
}

void SmartResearch::drawBarChart(QLabel *label, const QMap<QString, int> &data, const QColor &barColor) {
    if (!label) return;
    
    int w = label->width();
    int h = label->height();
    if (w <= 0 || h <= 0) return;

    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    int margin = 35;
    int chartW = w - 2 * margin;
    int chartH = h - 2 * margin;

    // Find max value
    int maxVal = 0;
    for (int val : data.values()) {
        if (val > maxVal) maxVal = val;
    }
    if (maxVal == 0) maxVal = 5; 

    // --- Background Grid Lines ---
    painter.setPen(QPen(QColor(255, 255, 255, 30), 1, Qt::DashLine));
    int steps = 4;
    for (int j = 0; j <= steps; j++) {
        int y_grid = margin + chartH - (j * chartH / steps);
        painter.drawLine(margin, y_grid, margin + chartW, y_grid);
    }

    int barCount = data.count();
    if (barCount == 0) return;
    
    int barSpacing = 30;
    int barWidth = (chartW - (barCount - 1) * barSpacing) / barCount;

    int i = 0;
    QMapIterator<QString, int> it(data);
    while (it.hasNext()) {
        it.next();
        QString category = it.key();
        int value = it.value();

        int barH = (static_cast<double>(value) / maxVal) * chartH;
        int x = margin + i * (barWidth + barSpacing);
        int y = h - margin - barH;

        // --- Premium Gradient for bars ---
        QLinearGradient gradient(x, y, x, y + barH);
        gradient.setColorAt(0, barColor.lighter(110));
        gradient.setColorAt(1, barColor.darker(150));

        // Draw bar
        painter.setBrush(gradient);
        painter.setPen(QPen(barColor.lighter(130), 1));
        painter.drawRoundedRect(x, y, barWidth, barH, 6, 6);

        // --- Exact Value on top ---
        painter.setPen(Qt::white);
        QFont valueFont = painter.font();
        valueFont.setBold(true);
        valueFont.setPointSize(10);
        painter.setFont(valueFont);
        painter.drawText(QRect(x, y - 25, barWidth, 20), Qt::AlignCenter, QString::number(value));

        // --- Category Name below ---
        painter.setPen(QColor(148, 163, 184)); // Slate-Gray
        QFont catFont = painter.font();
        catFont.setBold(false);
        catFont.setPointSize(9);
        painter.setFont(catFont);
        painter.drawText(QRect(x, h - margin + 8, barWidth, 30), Qt::AlignCenter, category);

        i++;
    }

    label->setPixmap(pixmap);
}

void SmartResearch::drawDoubleBarChart(QLabel *label, const QMap<QString, int> &data1, const QString &title1, const QColor &color1, const QMap<QString, int> &data2, const QString &title2, const QColor &color2) {
    if (!label) return;
    
    int w = label->width();
    int h = label->height();
    if (w <= 0 || h <= 0) return;

    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    int margin = 35;
    int chartW = w - 2 * margin;
    int chartH = h - 2 * margin - 15; // little more margin for title

    int maxVal = 0;
    for (int val : data1.values()) if (val > maxVal) maxVal = val;
    for (int val : data2.values()) if (val > maxVal) maxVal = val;
    if (maxVal == 0) maxVal = 5;

    // Background Grid Lines
    painter.setPen(QPen(QColor(255, 255, 255, 30), 1, Qt::DashLine));
    int steps = 4;
    for (int j = 0; j <= steps; j++) {
        int y_grid = margin + 15 + chartH - (j * chartH / steps);
        painter.drawLine(margin, y_grid, margin + chartW, y_grid);
    }
    
    // Titles
    painter.setPen(Qt::white);
    QFont titleFont = painter.font();
    titleFont.setBold(true);
    titleFont.setPointSize(11);
    painter.setFont(titleFont);
    painter.drawText(QRect(margin, 5, chartW / 2, 25), Qt::AlignCenter, title1);
    painter.drawText(QRect(margin + chartW / 2, 5, chartW / 2, 25), Qt::AlignCenter, title2);

    auto drawBars = [&](const QMap<QString, int> &data, int startX, int width, QColor color) {
        int barCount = data.count();
        if (barCount == 0) return;
        int barSpacing = 15;
        int barWidth = (width - (barCount + 1) * barSpacing) / barCount;
        if (barWidth < 15) barWidth = 15;
        if (barWidth > 60) barWidth = 60; // max width

        int i = 0;
        QMapIterator<QString, int> it(data);
        while (it.hasNext()) {
            it.next();
            QString category = it.key();
            int value = it.value();

            int barH = (static_cast<double>(value) / maxVal) * chartH;
            
            int totalBarsWidth = barCount * barWidth + (barCount - 1) * barSpacing;
            int offset = startX + (width - totalBarsWidth) / 2;
            int x = offset + i * (barWidth + barSpacing);
            int y = h - margin - barH;

            QLinearGradient gradient(x, y, x, y + barH);
            gradient.setColorAt(0, color.lighter(110));
            gradient.setColorAt(1, color.darker(150));

            painter.setBrush(gradient);
            painter.setPen(QPen(color.lighter(130), 1));
            painter.drawRoundedRect(x, y, barWidth, barH, 6, 6);

            painter.setPen(Qt::white);
            QFont valueFont = painter.font();
            valueFont.setBold(true);
            valueFont.setPointSize(9);
            painter.setFont(valueFont);
            painter.drawText(QRect(x - 5, y - 25, barWidth + 10, 20), Qt::AlignCenter, QString::number(value));

            painter.setPen(QColor(148, 163, 184));
            QFont catFont = painter.font();
            catFont.setBold(false);
            catFont.setPointSize(8);
            painter.setFont(catFont);
            QFontMetrics metrics(catFont);
            QString elidedName = metrics.elidedText(category, Qt::ElideRight, barWidth + 15);
            painter.drawText(QRect(x - 10, h - margin + 8, barWidth + 20, 30), Qt::AlignCenter, elidedName);

            i++;
        }
    };

    drawBars(data1, margin, chartW / 2, color1);
    
    // Separator line
    painter.setPen(QPen(QColor(255, 255, 255, 50), 2, Qt::SolidLine));
    painter.drawLine(margin + chartW / 2, margin, margin + chartW / 2, h - margin + 10);
    
    drawBars(data2, margin + chartW / 2, chartW / 2, color2);

    label->setPixmap(pixmap);
}


// ============================================================
// === GESTION JOURNAL / CONFERENCE ===========================
// ============================================================

void SmartResearch::refreshJournalTable()
{
    QSqlQuery query;
    query.exec(
        "SELECT ID_JOURNALCONFERENCE, NOM_JOURNAL, TYPE_JOURNAL, DOMAINE_JOURNAL, "
        "FACTEUR_IMPACT, CLASSEMENT_JOURNAL, PAYS_JOURNAL, ORGANISATION_JOURNAL, "
        "PERIODICITE_JOURNAL, SITE_WEB_JOURNAL "
        "FROM TABLE_JOURNAL_CONF ORDER BY ID_JOURNALCONFERENCE ASC");

    ui->tableWidget_8->setRowCount(0);
    ui->tableWidget_8->setColumnCount(10);
    QStringList headers = {"ID", "Nom", "Type", "Domaine",
                           "Facteur d'impact", "Classement", "Pays",
                           "Organisation", "Périodicité", "Site Web"};
    ui->tableWidget_8->setHorizontalHeaderLabels(headers);
    ui->tableWidget_8->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_8->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_8->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_8->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int row = 0;
    while (query.next()) {
        ui->tableWidget_8->insertRow(row);
        for (int col = 0; col < 10; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget_8->setItem(row, col, item);
        }
        row++;
    }
    updateJournalStats();
}

void SmartResearch::updateJournalStats() {
    QMap<QString, int> stats = Journal::getStatistics();

    QMap<QString, int> confData;
    QMap<QString, int> jourData;

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        if (it.key().startsWith("pays_Conférence_")) {
            QString country = it.key().mid(16);
            if (!country.isEmpty() && it.value() > 0) confData[country] = it.value();
        } else if (it.key().startsWith("pays_Journal_")) {
            QString country = it.key().mid(13);
            if (!country.isEmpty() && it.value() > 0) jourData[country] = it.value();
        }
    }

    auto getTop10 = [](const QMap<QString, int>& data) {
        QList<QPair<int, QString>> sorted;
        for (auto it = data.begin(); it != data.end(); ++it)
            sorted.append(qMakePair(it.value(), it.key()));
        std::sort(sorted.begin(), sorted.end(), [](const QPair<int,QString> &a, const QPair<int,QString> &b){
            return a.first > b.first; 
        });

        QMap<QString, int> chartData;
        int limit = qMin(sorted.size(), 5); // reduce limit to max 5 per side so they fit
        for (int i = 0; i < limit; ++i)
            chartData[sorted[i].second] = sorted[i].first;
        return chartData;
    };

    QMap<QString, int> confChart = getTop10(confData);
    QMap<QString, int> jourChart = getTop10(jourData);

    if (!confChart.isEmpty() || !jourChart.isEmpty()) {
        drawDoubleBarChart(ui->label_Chart_Journal, confChart, "Conférence", QColor("#f59e0b"), jourChart, "Journal", QColor("#3b82f6"));
    } else {
        // Fall back to types if nowhere has a country set
        QMap<QString, int> chartData;
        chartData["Journal"]     = stats.value("type_Journal", 0);
        chartData["Conférence"]  = stats.value("type_Conférence", 0);
        drawBarChart(ui->label_Chart_Journal, chartData, QColor("#10b981"));
    }
}


// --- Enregistrer (Ajouter) ---
void SmartResearch::on_enregistrer1_clicked()
{
    QString id_str  = ui->id->text();
    QString nom_val = ui->nom->text();
    QString type_val= ui->type->currentText();
    QString domaine = ui->domaine_scientifique->currentText();
    if (domaine == "-- Sélectionner un domaine --") domaine = "";
    QString facteur = ui->facteur_impact->text();
    QString clas    = ui->classement->currentText();
    if (clas == "-- Sélectionner un classement --") clas = "";
    QString pays_val= ui->pays->currentText();
    if (pays_val == "-- Sélectionner un pays --") pays_val = "";
    QString org     = ui->organisation->text();
    QString peri    = ui->periodicite->currentText();
    if (peri == "-- Sélectionner la périodicité --") peri = "";
    QString site    = ui->siteweb->text();

    // --- Validations ---
    if (id_str.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'ID' est obligatoire.");
        return;
    }
    bool ok;
    int id = id_str.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID doit être un entier strictement positif.");
        return;
    }
    if (Journal::verifierId(id)) {
        QMessageBox::warning(this, "Erreur de saisie", "Cet ID est déjà utilisé. Choisissez-en un autre.");
        return;
    }
    if (nom_val.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' est obligatoire.");
        return;
    }
    QRegularExpression reNom("^[a-zA-ZÀ-ÿ0-9\\s\\-\\.]+$");
    if (!reNom.match(nom_val).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le 'Nom' contient des caractères invalides.");
        return;
    }
    if (type_val.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Type' est obligatoire.");
        return;
    }
    if (domaine.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Domaine Scientifique' est obligatoire.");
        return;
    }
    if (!facteur.isEmpty()) {
        bool okFacteur;
        double f = facteur.toDouble(&okFacteur);
        if (!okFacteur || f < 0) {
            QMessageBox::warning(this, "Erreur de saisie", "Le 'Facteur d'impact' doit être un nombre positif (ex: 1.5).");
            return;
        }
    }
    // pays_val is validated by the ComboBox: no extra check needed
    if (!site.isEmpty()) {
        QRegularExpression reUrl("^(http:\\/\\/|https:\\/\\/)?(www\\.)?[a-zA-Z0-9\\-\\.]+\\.[a-zA-Z]{2,}(\\/\\S*)?$");
        if (!reUrl.match(site).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le 'Site Web' n'est pas dans un format valide (ex: www.exemple.com).");
            return;
        }
    }

    Journal j(id, nom_val, type_val, domaine, facteur, clas, pays_val, org, peri, site);
    if (j.ajouter()) {
        refreshJournalTable();
        QMessageBox::information(this, "OK", "Journal/Conférence ajouté avec succès.");
        on_annuler_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout échoué. L'ID est peut-être déjà utilisé.");
    }
}

// --- Modifier ---
void SmartResearch::on_modif1_clicked()
{
    QString id_str  = ui->id->text();
    QString nom_val = ui->nom->text();
    QString type_val= ui->type->currentText();
    QString domaine = ui->domaine_scientifique->currentText();
    if (domaine == "-- Sélectionner un domaine --") domaine = "";
    QString facteur = ui->facteur_impact->text();
    QString clas    = ui->classement->currentText();
    if (clas == "-- Sélectionner un classement --") clas = "";
    QString pays_val= ui->pays->currentText();
    if (pays_val == "-- Sélectionner un pays --") pays_val = "";
    QString org     = ui->organisation->text();
    QString peri    = ui->periodicite->currentText();
    if (peri == "-- Sélectionner la périodicité --") peri = "";
    QString site    = ui->siteweb->text();

    if (id_str.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner un enregistrement à modifier.");
        return;
    }
    bool ok;
    int id = id_str.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID doit être un entier strictement positif.");
        return;
    }
    if (selectedJournalId != -1 && id != selectedJournalId) {
        if (Journal::verifierId(id)) {
            QMessageBox::warning(this, "Erreur de saisie", "Cet ID est déjà utilisé. Choisissez-en un autre.");
            return;
        }
    }
    if (nom_val.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' est obligatoire.");
        return;
    }
    QRegularExpression reNom("^[a-zA-ZÀ-ÿ0-9\\s\\-\\.]+$");
    if (!reNom.match(nom_val).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le 'Nom' contient des caractères invalides.");
        return;
    }
    if (type_val.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Type' est obligatoire.");
        return;
    }
    if (domaine.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Domaine Scientifique' est obligatoire.");
        return;
    }
    QRegularExpression reAlpha("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!reAlpha.match(domaine).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le 'Domaine Scientifique' ne doit contenir que des lettres.");
        return;
    }
    if (!facteur.isEmpty()) {
        bool okFacteur;
        double f = facteur.toDouble(&okFacteur);
        if (!okFacteur || f < 0) {
            QMessageBox::warning(this, "Erreur de saisie", "Le 'Facteur d'impact' doit être un nombre positif (ex: 1.5).");
            return;
        }
    }
    // pays_val is validated by the ComboBox: no extra check needed
    if (!site.isEmpty()) {
        QRegularExpression reUrl("^(http:\\/\\/|https:\\/\\/)?(www\\.)?[a-zA-Z0-9\\-\\.]+\\.[a-zA-Z]{2,}(\\/\\S*)?$");
        if (!reUrl.match(site).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le 'Site Web' n'est pas dans un format valide (ex: www.exemple.com).");
            return;
        }
    }

    Journal j(id, nom_val, type_val, domaine, facteur, clas, pays_val, org, peri, site);
    bool test = j.modifier(selectedJournalId != -1 ? selectedJournalId : id);
    if (test) {
        refreshJournalTable();
        QMessageBox::information(this, "OK", "Modification effectuée avec succès.");
        on_annuler_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}

// --- Annuler (vider les champs) ---
void SmartResearch::on_annuler_clicked()
{
    ui->id->clear();
    ui->nom->clear();
    ui->type->setCurrentIndex(-1);
    ui->domaine_scientifique->setCurrentIndex(0);
    ui->facteur_impact->clear();
    ui->classement->setCurrentIndex(0);
    ui->pays->setCurrentIndex(0);
    ui->organisation->clear();
    ui->periodicite->setCurrentIndex(0);
    ui->siteweb->clear();
    selectedJournalId = -1;
}

// --- Supprimer ---
void SmartResearch::on_SuppSession_4_clicked()
{
    QString id_str = ui->id->text();
    if (id_str.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un enregistrement dans le tableau.");
        return;
    }
    bool ok;
    int id = id_str.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide.");
        return;
    }

    QMessageBox::StandardButton rep = QMessageBox::question(
        this, "Confirmation",
        "Êtes-vous sûr de vouloir supprimer cet enregistrement ?",
        QMessageBox::Yes | QMessageBox::No);
    if (rep != QMessageBox::Yes) return;

    bool test = Jtmp.supprimer(id);
    if (test) {
        refreshJournalTable();
        QMessageBox::information(this, "OK", "Suppression effectuée avec succès.");
        on_annuler_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "La suppression a échoué.");
    }
}

// --- Clic sur une ligne du tableau (remplir les champs) ---
void SmartResearch::on_tableWidget_8_cellClicked(int row, int column)
{
    Q_UNUSED(column);
    auto cellText = [&](int col) -> QString {
        QTableWidgetItem *item = ui->tableWidget_8->item(row, col);
        return item ? item->text() : QString();
    };

    ui->id->setText(cellText(0));
    selectedJournalId = cellText(0).toInt();
    ui->nom->setText(cellText(1));
    ui->type->setCurrentText(cellText(2));
    ui->domaine_scientifique->setCurrentText(cellText(3));
    ui->facteur_impact->setText(cellText(4));
    ui->classement->setCurrentText(cellText(5));
    ui->pays->setCurrentText(cellText(6));
    ui->organisation->setText(cellText(7));
    ui->periodicite->setCurrentText(cellText(8));
    ui->siteweb->setText(cellText(9));
}

// --- Recherche + tri ---
void SmartResearch::on_rechercheSession_4_clicked()
{
    QString val   = ui->rechSession_4->text();
    QString tri   = ui->comboBox_8->currentText();
    QString ordre = (tri == "order decroissant") ? "DESC" : "ASC";

    QString baseQ =
        "SELECT ID_JOURNALCONFERENCE, NOM_JOURNAL, TYPE_JOURNAL, DOMAINE_JOURNAL, "
        "FACTEUR_IMPACT, CLASSEMENT_JOURNAL, PAYS_JOURNAL, ORGANISATION_JOURNAL, "
        "PERIODICITE_JOURNAL, SITE_WEB_JOURNAL FROM TABLE_JOURNAL_CONF ";

    QSqlQuery query;
    if (val.isEmpty()) {
        query.exec(baseQ + "ORDER BY ID_JOURNALCONFERENCE " + ordre);
    } else {
        query.prepare(baseQ + "WHERE ID_JOURNALCONFERENCE = :val ORDER BY ID_JOURNALCONFERENCE " + ordre);
        query.bindValue(":val", val);
        query.exec();
    }

    ui->tableWidget_8->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget_8->insertRow(row);
        for (int col = 0; col < 10; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget_8->setItem(row, col, item);
        }
        row++;
    }
}

void SmartResearch::on_comboBox_8_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    on_rechercheSession_4_clicked();
}

// --- Exportation PDF ---
void SmartResearch::on_expoSession_4_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount    = ui->tableWidget_8->rowCount();
    const int columnCount = ui->tableWidget_8->columnCount();

    out << "<html>\n<head>\n"
        << "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>Liste des Journaux/Conferences</title>\n</head>\n"
        << "<body bgcolor=#ffffff>\n"
        << "<center><h1 style=\"color:#1e293b;font-family:Arial,sans-serif;\">"
        << "<strong>*** LISTE DES JOURNAUX/CONFERENCES ***</strong></h1></center>\n"
        << "<table border=1 cellspacing=0 cellpadding=8 width=\"100%\" "
        << "style=\"border-collapse:collapse;border:1px solid #1e293b;font-family:Arial,sans-serif;\">\n";

    // Headers
    out << "<thead><tr bgcolor=#1e293b style=\"color:#ffffff;font-weight:bold;\">";
    for (int col = 0; col < columnCount; col++) {
        if (!ui->tableWidget_8->isColumnHidden(col)) {
            QTableWidgetItem *h = ui->tableWidget_8->horizontalHeaderItem(col);
            out << QString("<th style=\"border:1px solid #1e293b;padding:10px;\">%1</th>")
                       .arg(h ? h->text() : QString());
        }
    }
    out << "</tr></thead>\n";

    // Data
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int col = 0; col < columnCount; col++) {
            if (!ui->tableWidget_8->isColumnHidden(col)) {
                QTableWidgetItem *cell = ui->tableWidget_8->item(row, col);
                QString data = cell ? cell->text().simplified() : "";
                out << QString("<td style=\"border:1px solid #1e293b;text-align:center;padding:8px;\">%1</td>")
                           .arg(data.isEmpty() ? "&nbsp;" : data);
            }
        }
        out << "</tr>\n";
    }
    out << "</table>\n</body>\n</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", QString(), "*.pdf");
    if (fileName.isEmpty()) { delete document; return; }
    if (QFileInfo(fileName).suffix().isEmpty()) fileName.append(".pdf");

    QPdfWriter *printer = new QPdfWriter(fileName);
    printer->setPageSize(QPageSize(QPageSize::A4));
    printer->setPageOrientation(QPageLayout::Landscape);
    printer->setPageMargins(QMarginsF(15, 15, 15, 15));
    document->print(printer);
    delete document;
    delete printer;

    QMessageBox::information(this, "Exportation PDF",
                             "La liste a été exportée avec succès.");
}
