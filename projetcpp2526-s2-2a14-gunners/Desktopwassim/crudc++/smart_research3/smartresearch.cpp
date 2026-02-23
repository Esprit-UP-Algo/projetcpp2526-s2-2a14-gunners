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
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>

#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QDebug>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QVBoxLayout>
#include <QDebug>

SmartResearch::SmartResearch(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartResearch) {
  ui->setupUi(this);
    setupPaiementValidators();
    loadPaiementData();
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

  // --- Gestion Utilisateur Initialization ---
  ui->tableWidget_10->setModel(Utmp.afficher());
  ui->tableWidget_10->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableWidget_10->setSelectionMode(QAbstractItemView::SingleSelection);

  // Explicit Connections for robustness
  connect(ui->btn_Enregistrer_Utilisateur, SIGNAL(clicked()), this, SLOT(on_btn_Enregistrer_Utilisateur_clicked()));
  connect(ui->modif_3, SIGNAL(clicked()), this, SLOT(on_modif_3_clicked()));
  connect(ui->annulerajout_client_3, SIGNAL(clicked()), this, SLOT(on_annulerajout_client_3_clicked()));
  connect(ui->pushButton_supprimer_client_2, SIGNAL(clicked()), this, SLOT(on_pushButton_supprimer_client_2_clicked()));
  connect(ui->tableWidget_10, SIGNAL(clicked(const QModelIndex &)), this, SLOT(on_tableWidget_10_clicked(const QModelIndex &)));
  connect(ui->pushButton_recherche_4, SIGNAL(clicked()), this, SLOT(on_pushButton_recherche_4_clicked()));
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

// --- Gestion Utilisateur Slots ---

void SmartResearch::on_btn_Enregistrer_Utilisateur_clicked() {
    int id = ui->lineEdit_ID_Utilisateur->text().toInt();
    QString nom = ui->lineEdit_Nom_Utilisateur->text();
    QString email = ui->lineEdit_Email_Utilisateur->text();
    QString mdp = ui->lineEdit_Mdp_Utilisateur->text();
    QString num = ui->lineEdit_Institution_Utilisateur_2->text();
    QString inst = ui->lineEdit_Institution_Utilisateur_3->text();
    QString role = "";
    if (ui->radioButton_Admin_7->isChecked()) role = "Admin";
    else if (ui->radioButton_Admin_2->isChecked()) role = "manager";
    else if (ui->radioButton_Admin->isChecked()) role = "editer";
    else if (ui->radioButton_Chercheur->isChecked()) role = "reviewer";

    if(ui->lineEdit_ID_Utilisateur->text().isEmpty() || nom.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez remplir au moins l'ID et le Nom.");
        return;
    }

    Utilisateur u(id, nom, email, mdp, role, num, inst);
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
    int id = ui->lineEdit_ID_Utilisateur->text().toInt();
    QString nom = ui->lineEdit_Nom_Utilisateur->text();
    QString email = ui->lineEdit_Email_Utilisateur->text();
    QString mdp = ui->lineEdit_Mdp_Utilisateur->text();
    QString num = ui->lineEdit_Institution_Utilisateur_2->text();
    QString inst = ui->lineEdit_Institution_Utilisateur_3->text();
    QString role = "";
    if (ui->radioButton_Admin_7->isChecked()) role = "Admin";
    else if (ui->radioButton_Admin_2->isChecked()) role = "manager";
    else if (ui->radioButton_Admin->isChecked()) role = "editer";
    else if (ui->radioButton_Chercheur->isChecked()) role = "reviewer";

    if(ui->lineEdit_ID_Utilisateur->text().isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un utilisateur à modifier (ID requis).");
        return;
    }

    Utilisateur u(id, nom, email, mdp, role, num, inst);
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
    ui->lineEdit_Email_Utilisateur->clear();
    ui->lineEdit_Mdp_Utilisateur->clear();
    ui->lineEdit_Institution_Utilisateur_2->clear();
    ui->lineEdit_Institution_Utilisateur_3->clear();
    ui->radioButton_Admin_7->setChecked(false);
    ui->radioButton_Admin_2->setChecked(false);
    ui->radioButton_Admin->setChecked(false);
    ui->radioButton_Chercheur->setChecked(false);
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
    QString email = ui->tableWidget_10->model()->index(row, 2).data().toString();
    QString mdp = ui->tableWidget_10->model()->index(row, 3).data().toString();
    QString role = ui->tableWidget_10->model()->index(row, 4).data().toString();
    QString num = ui->tableWidget_10->model()->index(row, 5).data().toString();
    QString inst = ui->tableWidget_10->model()->index(row, 6).data().toString();

    ui->lineEdit_ID_Utilisateur->setText(id);
    ui->lineEdit_Nom_Utilisateur->setText(nom);
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
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR LIKE '%" + val + "%' OR NOM_UTILISATEUR LIKE '%" + val + "%' OR EMAIL_UTILISATEUR LIKE '%" + val + "%'");
    
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mot de passe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Rôle"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Institution"));
    
    ui->tableWidget_10->setModel(model);
}

void SmartResearch::setupPaiementValidators()
{
    // Validateur pour ID (entier)
    QIntValidator *idValidator = new QIntValidator(1, 99999999, this);
    ui->lineEdit_ID_Paiement->setValidator(idValidator);

    // Validateur pour Montant (décimal)
    QDoubleValidator *montantValidator = new QDoubleValidator(0.0, 99999999.99, 2, this);
    montantValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_Montant->setValidator(montantValidator);

    // Validateur pour Devise (lettres uniquement) - CORRIGÉ
    QRegularExpression rxDevise("^[A-Za-z]+$");
    QRegularExpressionValidator *deviseValidator = new QRegularExpressionValidator(rxDevise, this);
    ui->lineEdit_Devise->setValidator(deviseValidator);
    ui->lineEdit_Devise->setMaxLength(10);

    // Validateur pour Type (lettres et espaces) - CORRIGÉ
    QRegularExpression rxType("^[A-Za-z\\s]+$");
    QRegularExpressionValidator *typeValidator = new QRegularExpressionValidator(rxType, this);
    ui->lineEdit_Type->setValidator(typeValidator);
    ui->lineEdit_Type->setMaxLength(50);

    // Validateur pour Mode Paiement (lettres et espaces) - CORRIGÉ
    QRegularExpression rxMode("^[A-Za-z\\s]+$");
    QRegularExpressionValidator *modeValidator = new QRegularExpressionValidator(rxMode, this);
    ui->lineEdit_ModePaiement->setValidator(modeValidator);
    ui->lineEdit_ModePaiement->setMaxLength(50);

    // Validateur pour recherche (nombres uniquement) - CORRIGÉ
    QRegularExpression rxRecherche("^[0-9]+$");
    QRegularExpressionValidator *rechercheValidator = new QRegularExpressionValidator(rxRecherche, this);
    ui->lineEdit_recherchPaiement->setValidator(rechercheValidator);

    // Date par défaut : aujourd'hui
    ui->dateEdit->setDate(QDate::currentDate());

    // Radio button "En Attente" sélectionné par défaut
    ui->radioButton_attente->setChecked(true);
}

// ==================== AJOUTER (Enregistrer) ====================

void SmartResearch::on_btn_Enregistrer_paiement_clicked()
{
    // Récupération des valeurs
    int idPaiement = ui->lineEdit_ID_Paiement->text().toInt();
    QString typeFrais = ui->lineEdit_Type->text();
    QString montant = ui->lineEdit_Montant->text();
    QString devise = ui->lineEdit_Devise->text();
    QString modePaiement = ui->lineEdit_ModePaiement->text();
    QString datePaiement = ui->dateEdit->date().toString("dd/MM/yyyy");

    // Déterminer le statut selon le radio button sélectionné
    QString statutPaiement;
    if (ui->radioButton_attente->isChecked())
        statutPaiement = "En Attente";
    else if (ui->radioButton_paye->isChecked())
        statutPaiement = "Payé";
    else if (ui->radioButton_annule->isChecked())
        statutPaiement = "Annulé";
    else
        statutPaiement = "En Attente"; // Par défaut

    // Validation des champs
    int errorCount = 0;

    if (ui->lineEdit_ID_Paiement->text().isEmpty()) {
        QMessageBox::critical(this, "ERREUR", "L'ID Paiement ne peut pas être vide !");
        errorCount++;
    }
    else if (idPaiement <= 0) {
        QMessageBox::critical(this, "ERREUR", "L'ID Paiement doit être un nombre positif !");
        errorCount++;
    }

    if (typeFrais.isEmpty()) {
        QMessageBox::critical(this, "ERREUR", "Le Type de frais ne peut pas être vide !");
        errorCount++;
    }

    if (montant.isEmpty()) {
        QMessageBox::critical(this, "ERREUR", "Le Montant ne peut pas être vide !");
        errorCount++;
    }

    if (devise.isEmpty()) {
        QMessageBox::critical(this, "ERREUR", "La Devise ne peut pas être vide !");
        errorCount++;
    }

    if (modePaiement.isEmpty()) {
        QMessageBox::critical(this, "ERREUR", "Le Mode de Paiement ne peut pas être vide !");
        errorCount++;
    }

    // Si aucune erreur, procéder à l'ajout
    if (errorCount == 0) {
        paiement p(idPaiement, typeFrais, modePaiement, datePaiement, montant, devise, statutPaiement);

        bool test = p.ajouter();

        if (test) {
            QMessageBox::information(this, "SUCCÈS",
                                     "Paiement ajouté avec succès !");

            // Rafraîchir le tableau
            ui->tablePaiement->setModel(p.afficher());

            // Vider les champs
            on_btn_Annuler_paiement_clicked();
        }
        else {
            QMessageBox::critical(this, "ERREUR",
                                  "Échec de l'ajout du paiement !\nL'ID existe peut-être déjà.");
        }
    }
}

// ==================== MODIFIER ====================

void SmartResearch::on_btn_Modifier_paiement_clicked()
{
    // Récupération des valeurs
    int idPaiement = ui->lineEdit_ID_Paiement->text().toInt();
    QString typeFrais = ui->lineEdit_Type->text();
    QString montant = ui->lineEdit_Montant->text();
    QString devise = ui->lineEdit_Devise->text();
    QString modePaiement = ui->lineEdit_ModePaiement->text();
    QString datePaiement = ui->dateEdit->date().toString("dd/MM/yyyy");

    // Déterminer le statut selon le radio button sélectionné
    QString statutPaiement;
    if (ui->radioButton_attente->isChecked())
        statutPaiement = "En Attente";
    else if (ui->radioButton_paye->isChecked())
        statutPaiement = "Payé";
    else if (ui->radioButton_annule->isChecked())
        statutPaiement = "Annulé";
    else
        statutPaiement = "En Attente";

    // Validation
    if (ui->lineEdit_ID_Paiement->text().isEmpty()) {
        QMessageBox::critical(this, "ERREUR", "Veuillez entrer l'ID du paiement à modifier !");
        return;
    }

    if (typeFrais.isEmpty() || montant.isEmpty() || devise.isEmpty() || modePaiement.isEmpty()) {
        QMessageBox::critical(this, "ERREUR", "Tous les champs doivent être remplis !");
        return;
    }

    // Vérifier si l'ID existe
    paiement p;
    if (!p.rechercherParId(idPaiement)) {
        QMessageBox::critical(this, "ERREUR", "Aucun paiement trouvé avec cet ID !");
        return;
    }

    // Mettre à jour les valeurs
    p.setTypeFraisPaiement(typeFrais);
    p.setMontantPaiement(montant);
    p.setDevicePaiement(devise);
    p.setModePaiement(modePaiement);
    p.setDatePaiement(datePaiement);
    p.setStatutPaiement(statutPaiement);

    bool test = p.modifier();

    if (test) {
        QMessageBox::information(this, "SUCCÈS",
                                 "Paiement modifié avec succès !");

        ui->tablePaiement->setModel(p.afficher());
        on_btn_Annuler_paiement_clicked();
    }
    else {
        QMessageBox::critical(this, "ERREUR",
                              "Échec de la modification du paiement !");
    }
}

// ==================== ANNULER (Vider les champs) ====================

void SmartResearch::on_btn_Annuler_paiement_clicked()
{
    ui->lineEdit_ID_Paiement->clear();
    ui->lineEdit_Type->clear();
    ui->lineEdit_Montant->clear();
    ui->lineEdit_Devise->clear();
    ui->lineEdit_ModePaiement->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->radioButton_attente->setChecked(true);
    ui->radioButton_paye->setChecked(false);
    ui->radioButton_annule->setChecked(false);
    ui->lineEdit_recherchPaiement->clear();
}

// ==================== RECHERCHE PAR ID ====================

void SmartResearch::on_recherche_clicked()
{
    QString searchText = ui->lineEdit_recherchPaiement->text();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "ATTENTION", "Veuillez entrer un ID à rechercher !");
        return;
    }

    bool isNumber;
    int idRecherche = searchText.toInt(&isNumber);

    if (!isNumber) {
        QMessageBox::critical(this, "ERREUR", "L'ID doit être un nombre valide !");
        return;
    }

    paiement p;
    bool found = p.rechercherParId(idRecherche);

    if (found) {
        // Afficher les données dans les champs
        ui->lineEdit_ID_Paiement->setText(QString::number(p.getIdPaiement()));
        ui->lineEdit_Type->setText(p.getTypeFraisPaiement());
        ui->lineEdit_Montant->setText(p.getMontantPaiement());
        ui->lineEdit_Devise->setText(p.getDevicePaiement());
        ui->lineEdit_ModePaiement->setText(p.getModePaiement());

        // Convertir la date string en QDate
        QDate date = QDate::fromString(p.getDatePaiement(), "dd/MM/yyyy");
        if (date.isValid())
            ui->dateEdit->setDate(date);

        // Sélectionner le bon radio button selon le statut
        QString statut = p.getStatutPaiement();
        if (statut == "En Attente")
            ui->radioButton_attente->setChecked(true);
        else if (statut == "Payé")
            ui->radioButton_paye->setChecked(true);
        else if (statut == "Annulé")
            ui->radioButton_annule->setChecked(true);

        QMessageBox::information(this, "SUCCÈS", "Paiement trouvé !");
    }
    else {
        QMessageBox::warning(this, "NON TROUVÉ",
                             "Aucun paiement trouvé avec l'ID : " + searchText);

        // Vider le tableau ou afficher un modèle vide
        QSqlQueryModel *emptyModel = new QSqlQueryModel();
        ui->tablePaiement->setModel(emptyModel);
    }
}

// ==================== SUPPRIMER ====================

void SmartResearch::on_pushButton_supprimer_paiement_clicked()
{
    // Récupérer l'ID depuis le lineEdit_ID_Paiement ou lineEdit_recherchPaiement
    QString idText = ui->lineEdit_ID_Paiement->text();

    if (idText.isEmpty()) {
        // Essayer de prendre depuis la recherche
        idText = ui->lineEdit_recherchPaiement->text();
    }

    if (idText.isEmpty()) {
        QMessageBox::critical(this, "ERREUR",
                              "Veuillez entrer l'ID du paiement à supprimer !");
        return;
    }

    bool isNumber;
    int idSuppression = idText.toInt(&isNumber);

    if (!isNumber || idSuppression <= 0) {
        QMessageBox::critical(this, "ERREUR", "ID invalide !");
        return;
    }

    // Confirmation avant suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "CONFIRMATION",
                                  "Êtes-vous sûr de vouloir supprimer le paiement ID : " + idText + " ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        paiement p;
        bool test = p.supprimer(idSuppression);

        if (test) {
            QMessageBox::information(this, "SUCCÈS",
                                     "Paiement supprimé avec succès !");

            ui->tablePaiement->setModel(p.afficher());
            on_btn_Annuler_paiement_clicked();
        }
        else {
            QMessageBox::critical(this, "ERREUR",
                                  "Échec de la suppression !\nLe paiement n'existe peut-être pas.");
        }
    }
}

// ==================== QUITTER ====================

void SmartResearch::on_quitterSession_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "CONFIRMATION",
                                  "Voulez-vous vraiment quitter l'application ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

// ==================== EXPORT PDF ====================

void SmartResearch::on_expoSession_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Enregistrer le PDF",
                                                    "Liste_Paiements.pdf",
                                                    "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return; // L'utilisateur a annulé
    }

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tablePaiement->model()->rowCount();
    const int columnCount = ui->tablePaiement->model()->columnCount();

    // En-tête HTML avec style
    out << "<html>\n"
        << "<head>\n"
        << "<meta Content=\"Text/html; charset=UTF-8\">\n"
        << "<title>Liste des Paiements</title>\n"
        << "<style>\n"
        << "body { font-family: Arial, sans-serif; background-color: #f0f0f0; }\n"
        << "h1 { color: #003366; text-align: center; }\n"
        << "table { border-collapse: collapse; width: 100%; margin: 20px 0; }\n"
        << "th { background-color: #003366; color: white; padding: 10px; text-align: left; }\n"
        << "td { padding: 8px; border-bottom: 1px solid #ddd; }\n"
        << "tr:nth-child(even) { background-color: #f2f2f2; }\n"
        << ".header-info { text-align: center; margin-bottom: 20px; }\n"
        << "</style>\n"
        << "</head>\n"
        << "<body>\n"
        << "<div class='header-info'>\n"
        << "<h1>Liste des Paiements</h1>\n"
        << "<p>Généré le : " << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss") << "</p>\n"
        << "</div>\n"
        << "<table border='1' cellspacing='0' cellpadding='5'>\n";

    // En-têtes de colonnes
    out << "<thead><tr>";
    for (int column = 0; column < columnCount; column++) {
        if (!ui->tablePaiement->isColumnHidden(column)) {
            QString header = ui->tablePaiement->model()->headerData(column, Qt::Horizontal).toString();
            out << QString("<th>%1</th>").arg(header);
        }
    }
    out << "</tr></thead>\n<tbody>\n";

    // Données
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tablePaiement->isColumnHidden(column)) {
                QString data = ui->tablePaiement->model()->data(
                                                             ui->tablePaiement->model()->index(row, column)).toString().simplified();
                out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : "&nbsp;");
            }
        }
        out << "</tr>\n";
    }

    out << "</tbody></table>\n"
        << "<p style='text-align: center; margin-top: 20px;'>"
        << "Total des paiements : " << rowCount << "</p>\n"
        << "</body>\n"
        << "</html>";

    // Création et impression du PDF
    QTextDocument document;
    document.setHtml(strStream);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize::A4);
    printer.setPageOrientation(QPageLayout::Portrait);

    document.print(&printer);

    QMessageBox::information(this, "SUCCÈS",
                             "PDF généré avec succès !\nEmplacement : " + fileName);
}
// Pour charger les données au démarrage
void SmartResearch::loadPaiementData()
{
    paiement p;
    ui->tablePaiement->setModel(p.afficher());

    // Configurer l'apparence du tableau
    ui->tablePaiement->resizeColumnsToContents();
    ui->tablePaiement->horizontalHeader()->setStretchLastSection(true);
    ui->tablePaiement->setAlternatingRowColors(true);
    ui->tablePaiement->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablePaiement->setSelectionMode(QAbstractItemView::SingleSelection);
}

void SmartResearch::on_expoSession_2_linkActivated(const QString &link)
{

}

