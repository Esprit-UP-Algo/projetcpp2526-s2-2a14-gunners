#include "gestionreviewer.h"
#include "ui_gestionreviewer.h"
#include <QInputDialog>
#include <QFileDialog>

GestionReviewer::GestionReviewer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionReviewer)
    , model(nullptr)
{
    ui->setupUi(this);

    // Connect to database
    connectDatabase();

    // Setup table view
    setupTable();

    // Clear form initially
    clearForm();

    // Connect radio buttons
    connect(ui->actifReviewer, &QRadioButton::clicked, this, &GestionReviewer::on_actifReviewer_clicked);
    connect(ui->inactifReviewer, &QRadioButton::clicked, this, &GestionReviewer::on_inactifReviewer_clicked);

    // Connect table view click
    connect(ui->tableViewReviewer, &QTableView::clicked, this, &GestionReviewer::on_tableViewReviewer_clicked);
}

GestionReviewer::~GestionReviewer()
{
    if (db.isOpen()) {
        db.close();
    }
    delete model;
    delete ui;
}

void GestionReviewer::connectDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("smart_research.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données!");
        return;
    }

    // Create table if not exists
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS reviewers ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "nom TEXT NOT NULL, "
               "email TEXT NOT NULL UNIQUE, "
               "specialite TEXT, "
               "institution TEXT, "
               "statut TEXT DEFAULT 'Actif')");
}

void GestionReviewer::setupTable()
{
    model = new QSqlTableModel(this, db);
    model->setTable("reviewers");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, tr("Spécialité"));
    model->setHeaderData(4, Qt::Horizontal, tr("Institution"));
    model->setHeaderData(5, Qt::Horizontal, tr("Statut"));

    ui->tableViewReviewer->setModel(model);
    ui->tableViewReviewer->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewReviewer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewReviewer->resizeColumnsToContents();
}

void GestionReviewer::clearForm()
{
    ui->idReviewer->clear();
    ui->nomReviewer->clear();
    ui->emailReviewer->clear();
    ui->specialiteReviewer->clear();
    ui->institutionReviewer->clear();
    ui->actifReviewer->setChecked(true);
}

bool GestionReviewer::validateForm()
{
    if (ui->nomReviewer->text().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom est obligatoire!");
        ui->nomReviewer->setFocus();
        return false;
    }

    if (ui->emailReviewer->text().isEmpty()) {
        QMessageBox::warning(this, "Validation", "L'email est obligatoire!");
        ui->emailReviewer->setFocus();
        return false;
    }

    // Simple email validation
    if (!ui->emailReviewer->text().contains('@')) {
        QMessageBox::warning(this, "Validation", "Email invalide! Doit contenir '@'");
        ui->emailReviewer->setFocus();
        return false;
    }

    return true;
}

int GestionReviewer::getSelectedReviewerId()
{
    QModelIndexList selectedIndexes = ui->tableViewReviewer->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty()) {
        return -1;
    }

    int row = selectedIndexes.first().row();
    QModelIndex idIndex = model->index(row, 0);
    return model->data(idIndex).toInt();
}

void GestionReviewer::refreshTable()
{
    model->select();
    ui->tableViewReviewer->resizeColumnsToContents();
}

void GestionReviewer::on_enregistrerReviewer_clicked()
{
    if (!validateForm()) {
        return;
    }

    QString nom = ui->nomReviewer->text();
    QString email = ui->emailReviewer->text();
    QString specialite = ui->specialiteReviewer->text();
    QString institution = ui->institutionReviewer->text();
    QString statut = ui->actifReviewer->isChecked() ? "Actif" : "Inactif";

    QSqlQuery query;

    if (ui->idReviewer->text().isEmpty()) {
        // Insert new reviewer
        query.prepare("INSERT INTO reviewers (nom, email, specialite, institution, statut) "
                      "VALUES (:nom, :email, :specialite, :institution, :statut)");
    } else {
        // Update existing reviewer
        int id = ui->idReviewer->text().toInt();
        query.prepare("UPDATE reviewers SET nom = :nom, email = :email, "
                      "specialite = :specialite, institution = :institution, statut = :statut "
                      "WHERE id = :id");
        query.bindValue(":id", id);
    }

    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":specialite", specialite);
    query.bindValue(":institution", institution);
    query.bindValue(":statut", statut);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Reviewer enregistré avec succès!");
        refreshTable();
        clearForm();
    } else {
        QString error = query.lastError().text();
        if (error.contains("UNIQUE constraint failed")) {
            QMessageBox::critical(this, "Erreur", "Cet email existe déjà dans la base de données!");
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'enregistrement: " + error);
        }
    }
}

void GestionReviewer::on_modifierReviewer_clicked()
{
    int id = getSelectedReviewerId();
    if (id == -1) {
        QMessageBox::warning(this, "Sélection", "Veuillez sélectionner un reviewer à modifier!");
        return;
    }

    loadReviewerData(id);
}

void GestionReviewer::loadReviewerData(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM reviewers WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        ui->idReviewer->setText(query.value("id").toString());
        ui->nomReviewer->setText(query.value("nom").toString());
        ui->emailReviewer->setText(query.value("email").toString());
        ui->specialiteReviewer->setText(query.value("specialite").toString());
        ui->institutionReviewer->setText(query.value("institution").toString());

        QString statut = query.value("statut").toString();
        if (statut == "Actif") {
            ui->actifReviewer->setChecked(true);
        } else {
            ui->inactifReviewer->setChecked(true);
        }
    }
}

void GestionReviewer::on_supprimerReviewerButton_clicked()
{
    int id = getSelectedReviewerId();
    if (id == -1) {
        QMessageBox::warning(this, "Sélection", "Veuillez sélectionner un reviewer à supprimer!");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Êtes-vous sûr de vouloir supprimer ce reviewer?\nCette action est irréversible.",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM reviewers WHERE id = :id");
        query.bindValue(":id", id);

        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Reviewer supprimé avec succès!");
            refreshTable();
            clearForm();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression: " + query.lastError().text());
        }
    }
}

void GestionReviewer::on_rechercherButton_clicked()
{
    QString searchText = ui->rechercheLineEdit->text().trimmed();

    if (searchText.isEmpty()) {
        model->setFilter("");
    } else {
        QString filter = QString("nom LIKE '%%1%' OR "
                                 "email LIKE '%%1%' OR "
                                 "specialite LIKE '%%1%' OR "
                                 "institution LIKE '%%1%'").arg(searchText);
        model->setFilter(filter);
    }

    model->select();
}

void GestionReviewer::on_assignerPublicationButton_clicked()
{
    int reviewerId = getSelectedReviewerId();
    if (reviewerId == -1) {
        QMessageBox::warning(this, "Sélection", "Veuillez sélectionner un reviewer!");
        return;
    }

    // Create publications table if not exists
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS publications ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "titre TEXT NOT NULL, "
               "auteurs TEXT, "
               "statut TEXT)");

    // Get available publications
    query.exec("SELECT id, titre FROM publications WHERE statut = 'Soumis'");

    QStringList publications;
    QMap<QString, int> pubMap;

    while (query.next()) {
        int id = query.value("id").toInt();
        QString titre = query.value("titre").toString();
        QString item = QString("#%1 - %2").arg(id).arg(titre);
        publications << item;
        pubMap[item] = id;
    }

    if (publications.isEmpty()) {
        QMessageBox::information(this, "Information", "Aucune publication disponible pour assignation.");
        return;
    }

    bool ok;
    QString selected = QInputDialog::getItem(this, "Assigner Publication",
                                             "Sélectionnez une publication:",
                                             publications, 0, false, &ok);

    if (ok && !selected.isEmpty()) {
        int publicationId = pubMap[selected];

        // Create assignments table if not exists
        query.exec("CREATE TABLE IF NOT EXISTS assignments ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "reviewer_id INTEGER, "
                   "publication_id INTEGER, "
                   "date_assignment DATETIME DEFAULT CURRENT_TIMESTAMP, "
                   "statut TEXT DEFAULT 'En attente', "
                   "FOREIGN KEY (reviewer_id) REFERENCES reviewers(id), "
                   "FOREIGN KEY (publication_id) REFERENCES publications(id))");

        // Check if already assigned
        query.prepare("SELECT id FROM assignments WHERE reviewer_id = :reviewer_id AND publication_id = :publication_id");
        query.bindValue(":reviewer_id", reviewerId);
        query.bindValue(":publication_id", publicationId);

        if (query.exec() && query.next()) {
            QMessageBox::warning(this, "Assignation", "Cette publication est déjà assignée à ce reviewer!");
            return;
        }

        // Assign publication to reviewer
        query.prepare("INSERT INTO assignments (reviewer_id, publication_id) "
                      "VALUES (:reviewer_id, :publication_id)");
        query.bindValue(":reviewer_id", reviewerId);
        query.bindValue(":publication_id", publicationId);

        if (query.exec()) {
            QMessageBox::information(this, "Succès",
                                     QString("Publication assignée avec succès!\n\nReviewer: #%1\nPublication: #%2")
                                         .arg(reviewerId).arg(publicationId));
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'assignation: " + query.lastError().text());
        }
    }
}

void GestionReviewer::on_rapportButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT statut, COUNT(*) as count FROM reviewers GROUP BY statut");

    QString rapport = "=== STATISTIQUES REVIEWERS ===\n\n";

    int total = 0;
    int actifs = 0;
    int inactifs = 0;

    while (query.next()) {
        QString statut = query.value("statut").toString();
        int count = query.value("count").toInt();

        if (statut == "Actif") actifs = count;
        else if (statut == "Inactif") inactifs = count;

        rapport += QString("%1: %2 reviewers\n").arg(statut).arg(count);
        total += count;
    }

    rapport += QString("\n----------------------------\n");
    rapport += QString("Total: %1 reviewers\n").arg(total);
    rapport += QString("Actifs: %1 (%2%)\n").arg(actifs).arg(total > 0 ? (actifs * 100 / total) : 0);
    rapport += QString("Inactifs: %1 (%2%)\n").arg(inactifs).arg(total > 0 ? (inactifs * 100 / total) : 0);

    // Add assignments statistics
    rapport += "\n=== ASSIGNATIONS ===\n\n";
    query.exec("SELECT COUNT(DISTINCT reviewer_id) as reviewers_assignes, "
               "COUNT(*) as total_assignations FROM assignments");

    if (query.next()) {
        int reviewersAssignes = query.value("reviewers_assignes").toInt();
        int totalAssignations = query.value("total_assignations").toInt();

        rapport += QString("Reviewers avec assignations: %1/%2 (%3%)\n")
                       .arg(reviewersAssignes)
                       .arg(total)
                       .arg(total > 0 ? (reviewersAssignes * 100 / total) : 0);

        rapport += QString("Total d'assignations: %1\n").arg(totalAssignations);

        if (reviewersAssignes > 0) {
            rapport += QString("Moyenne d'assignations par reviewer: %1\n")
            .arg(QString::number((double)totalAssignations / reviewersAssignes, 'f', 1));
        }
    }

    QMessageBox::information(this, "Rapport Statistique", rapport);
}

void GestionReviewer::on_refreshButton_2_clicked()
{
    QStringList sortOptions = {"Nom (A-Z)", "Nom (Z-A)", "Statut", "Institution"};

    bool ok;
    QString selected = QInputDialog::getItem(this, "Trier par",
                                             "Sélectionnez le critère de tri:",
                                             sortOptions, 0, false, &ok);

    if (ok) {
        if (selected == "Nom (A-Z)") {
            model->setSort(1, Qt::AscendingOrder);
        } else if (selected == "Nom (Z-A)") {
            model->setSort(1, Qt::DescendingOrder);
        } else if (selected == "Statut") {
            model->setSort(5, Qt::DescendingOrder); // Statut d'abord
        } else if (selected == "Institution") {
            model->setSort(4, Qt::AscendingOrder);
        }

        model->select();
        QMessageBox::information(this, "Tri", QString("Données triées par: %1").arg(selected));
    }
}

void GestionReviewer::on_annulerReviewer_clicked()
{
    clearForm();
    ui->tableViewReviewer->clearSelection();
}

void GestionReviewer::on_quitterButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quitter",
                                  "Êtes-vous sûr de vouloir quitter l'application?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

void GestionReviewer::on_tableViewReviewer_clicked(const QModelIndex &index)
{
    int row = index.row();
    QModelIndex idIndex = model->index(row, 0);
    int id = model->data(idIndex).toInt();
    loadReviewerData(id);
}

void GestionReviewer::on_actifReviewer_clicked()
{
    // Actif radio button clicked
}

void GestionReviewer::on_inactifReviewer_clicked()
{
    // Inactif radio button clicked
}
