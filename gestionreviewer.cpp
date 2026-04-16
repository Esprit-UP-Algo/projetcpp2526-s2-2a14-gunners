#include "gestionreviewer.h"
#include "ui_smartresearch.h"
#include "reviewer.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QFileDialog>
#include <QButtonGroup>
#include <QSqlRecord>
#include <QProcess>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QTableWidget>
#include <QFormLayout>
#include <algorithm>

GestionReviewer::GestionReviewer(Ui::SmartResearch *ui, QObject *parent)
    : QObject(parent), ui(ui), selectedReviewerId(-1)
{
    // Connect form buttons
    connect(ui->enregistrerReviewer, &QPushButton::clicked, this, &GestionReviewer::on_enregistrerReviewer_clicked);
    connect(ui->modifierReviewer, &QPushButton::clicked, this, &GestionReviewer::on_modifierReviewer_clicked);
    connect(ui->annulerReviewer, &QPushButton::clicked, this, &GestionReviewer::on_annulerReviewer_clicked);
    connect(ui->uploadPhotoBtn, &QPushButton::clicked, this, &GestionReviewer::on_uploadPhotoBtn_clicked);

    // Connect action buttons
    connect(ui->rechercheSession_3, &QPushButton::clicked, this, &GestionReviewer::on_rechercherButton_clicked);
    connect(ui->SuppSession_3, &QPushButton::clicked, this, &GestionReviewer::on_supprimerReviewerButton_clicked);
    connect(ui->quitterSession_3, &QPushButton::clicked, this, &GestionReviewer::on_quitterSession_3_clicked);
    connect(ui->expoSession_3, &QPushButton::clicked, this, &GestionReviewer::on_expoSession_3_clicked);
    connect(ui->tableWidget_7, &QTableView::clicked, this, &GestionReviewer::on_tableWidget_7_clicked);
    
    // Sort combo box
    connect(ui->comboBox_7, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GestionReviewer::on_comboBox_7_currentIndexChanged);

    // Set initial behaviors for table
    ui->tableWidget_7->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_7->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_7->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_7->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_7->verticalHeader()->setVisible(false);
    ui->tableWidget_7->setAlternatingRowColors(true);

    applyModernTheme();
    ensureUserNameField();
    setupCharts();
    afficherReviewers();
}

GestionReviewer::~GestionReviewer()
{
}

void GestionReviewer::clearForm()
{
    ui->idReviewer->clear();
    ui->nomReviewer->clear();
    ui->emailReviewer->clear();
    if (userNameReviewer) userNameReviewer->clear();
    ui->phoneReviewer->clear();
    ui->photoPathReviewer->clear();
    ui->specialiteReviewer->clear();
    ui->institutionReviewer->clear();

    if (ui->actifReviewer->group()) ui->actifReviewer->group()->setExclusive(false);
    ui->actifReviewer->setChecked(true); // Default status
    ui->inactifReviewer->setChecked(false);
    if (ui->actifReviewer->group()) ui->actifReviewer->group()->setExclusive(true);

    selectedReviewerId = -1;
}

void GestionReviewer::applyModernTheme()
{
    const QString panelStyle =
        "QGroupBox {"
        "background-color: rgb(0, 36, 168);"
        "border: 2px solid #2c3e50;"
        "border-radius: 15px;"
        "margin-top: 20px;"
        "}"
        "QGroupBox::title {"
        "subcontrol-origin: margin;"
        "subcontrol-position: top center;"
        "padding: 0 10px;"
        "}";

    const QString lineEditStyle =
        "QLineEdit {"
        "background: rgba(255, 255, 255, 0.96);"
        "border: 1px solid #bfdbfe;"
        "border-radius: 12px;"
        "padding: 10px 12px;"
        "color: #0f172a;"
        "selection-background-color: #2563eb;"
        "}"
        "QLineEdit:focus {"
        "border: 2px solid #38bdf8;"
        "background: white;"
        "}";

    const QString buttonStyle =
        "QPushButton {"
        "background-color: #1e293b;"
        "color: white;"
        "border: none;"
        "border-radius: 14px;"
        "padding: 10px 16px;"
        "font-weight: 600;"
        "}"
        "QPushButton:hover { background-color: #334155; }"
        "QPushButton:pressed { background-color: #0f172a; }";

    ui->groupBox_Reviewer_Form->setStyleSheet(panelStyle);
    ui->groupBox_Session_List_3->setStyleSheet(panelStyle);

    const QList<QLineEdit *> lineEdits = {
        ui->idReviewer, ui->nomReviewer, ui->emailReviewer, ui->phoneReviewer,
        ui->photoPathReviewer, ui->specialiteReviewer, ui->institutionReviewer,
        ui->rechSession_3
    };
    for (QLineEdit *lineEdit : lineEdits) {
        if (lineEdit) {
            lineEdit->setStyleSheet(lineEditStyle);
            lineEdit->setMinimumHeight(40);
        }
    }

    ui->comboBox_7->setStyleSheet(
        "QComboBox {"
        "background: rgba(255, 255, 255, 0.96);"
        "border: 1px solid #bfdbfe;"
        "border-radius: 12px;"
        "padding: 8px 12px;"
        "color: #0f172a;"
        "}"
        "QComboBox::drop-down { border: none; width: 28px; }");

    const QList<QPushButton *> buttons = {
        ui->enregistrerReviewer, ui->modifierReviewer, ui->annulerReviewer,
        ui->uploadPhotoBtn, ui->rechercheSession_3, ui->expoSession_3,
        ui->quitterSession_3, ui->SuppSession_3
    };
    for (QPushButton *button : buttons) {
        if (button) {
            button->setStyleSheet(buttonStyle);
            button->setCursor(Qt::PointingHandCursor);
        }
    }

    ui->enregistrerReviewer->setStyleSheet(
        "QPushButton { background-color: #0ea5e9; color: white; border: none; border-radius: 14px; padding: 10px 16px; font-weight: 700; }"
        "QPushButton:hover { background-color: #0284c7; }");
    ui->modifierReviewer->setStyleSheet(
        "QPushButton { background-color: #22c55e; color: white; border: none; border-radius: 14px; padding: 10px 16px; font-weight: 700; }"
        "QPushButton:hover { background-color: #16a34a; }");
    ui->annulerReviewer->setStyleSheet(
        "QPushButton { background-color: #f59e0b; color: #0f172a; border: none; border-radius: 14px; padding: 10px 16px; font-weight: 700; }"
        "QPushButton:hover { background-color: #d97706; color: white; }");
    ui->SuppSession_3->setStyleSheet(
        "QPushButton { background-color: #ef4444; color: white; border: none; border-radius: 14px; padding: 10px 16px; font-weight: 700; }"
        "QPushButton:hover { background-color: #dc2626; }");

    ui->groupBox_Session_List_3->setGeometry(480, 10, 751, 541);
    ui->rechSession_3->setGeometry(30, 30, 171, 41);
    ui->rechercheSession_3->setGeometry(210, 30, 121, 41);
    ui->comboBox_7->setGeometry(520, 30, 181, 41);
    ui->tableWidget_7->setGeometry(20, 110, 681, 150);
    ui->tableWidget_7->setStyleSheet(
        "QTableWidget {"
        "background: white;"
        "border: 1px solid #cbd5e1;"
        "border-radius: 10px;"
        "gridline-color: #e2e8f0;"
        "color: #0f172a;"
        "alternate-background-color: #f8fafc;"
        "selection-background-color: #dbeafe;"
        "selection-color: #0f172a;"
        "}"
        "QHeaderView::section {"
        "background: #e2e8f0;"
        "color: #0f172a;"
        "padding: 8px;"
        "border: none;"
        "font-weight: 700;"
        "}");

    ui->SuppSession_3->setGeometry(20, 490, 131, 34);
    ui->SuppSession_3->setText("Supprimer");
    ui->expoSession_3->setGeometry(160, 490, 191, 34);
    ui->quitterSession_3->setGeometry(560, 490, 131, 34);
    ui->quitterSession_3->setText("Quitter");

    if (!statsPanel) {
        statsPanel = new QFrame(ui->groupBox_Session_List_3);
    }
    statsPanel->setGeometry(20, 270, 691, 181);
    statsPanel->setStyleSheet(
        "QFrame {"
        "background-color: #1e293b;"
        "border: 1px solid #334155;"
        "border-radius: 12px;"
        "}");
    statsPanel->show();
}

void GestionReviewer::ensureUserNameField()
{
    if (userNameReviewer || !ui->formLayout_Reviewer) return;

    userNameLabel = new QLabel(ui->formLayoutWidget_Reviewer);
    userNameLabel->setText("<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Username</span></p></body></html>");

    userNameReviewer = new QLineEdit(ui->formLayoutWidget_Reviewer);
    userNameReviewer->setMinimumHeight(40);
    userNameReviewer->setStyleSheet(
        "QLineEdit {"
        "background: rgba(255, 255, 255, 0.96);"
        "border: 1px solid #bfdbfe;"
        "border-radius: 12px;"
        "padding: 10px 12px;"
        "color: #0f172a;"
        "selection-background-color: #2563eb;"
        "}"
        "QLineEdit:focus {"
        "border: 2px solid #38bdf8;"
        "background: white;"
        "}");

    ui->formLayout_Reviewer->insertRow(4, userNameLabel, userNameReviewer);
}

void GestionReviewer::populateReviewerTable(QSqlQueryModel *model)
{
    if (!model) return;

    ui->tableWidget_7->clearContents();
    ui->tableWidget_7->setRowCount(0);
    ui->tableWidget_7->setColumnCount(model->columnCount());
    
    QStringList headers;
    for (int col = 0; col < model->columnCount(); ++col) {
        headers << model->headerData(col, Qt::Horizontal).toString();
    }
    ui->tableWidget_7->setHorizontalHeaderLabels(headers);
    
    for (int row = 0; row < model->rowCount(); ++row) {
        ui->tableWidget_7->insertRow(row);
        for (int col = 0; col < model->columnCount(); ++col) {
            ui->tableWidget_7->setItem(row, col, new QTableWidgetItem(model->index(row, col).data().toString()));
        }
    }
}

void GestionReviewer::afficherReviewers()
{
    Reviewer r;
    QSqlQueryModel *model = r.afficher();
    populateReviewerTable(model);
    delete model;
    updateReviewerStats();
}

void GestionReviewer::rechercherReviewer()
{
    QString val = ui->rechSession_3->text();
    QString ordre = ui->comboBox_7->currentText().contains("decroissant", Qt::CaseInsensitive) ? "DESC" : "ASC";

    Reviewer rev;
    QSqlQueryModel *model = rev.rechercher(val, "ID_REVIEWER", ordre);
    populateReviewerTable(model);
    delete model;
}

void GestionReviewer::trierReviewers()
{
    rechercherReviewer();
}

void GestionReviewer::refreshTable()
{
    afficherReviewers();
}

bool GestionReviewer::validateForm()
{
    // Validate ID
    bool okId;
    int id = ui->idReviewer->text().toInt(&okId);
    if (ui->idReviewer->text().isEmpty() || !okId || id <= 0) {
        QMessageBox::warning(ui->idReviewer, "Erreur", "ID invalide. Doit être un entier positif.");
        return false;
    }

    // Validate Name: not empty, only letters
    QString nom = ui->nomReviewer->text().trimmed();
    QRegularExpression reName("^[a-zA-ZÀ-ÿ\\s]+$");
    if (nom.isEmpty() || !reName.match(nom).hasMatch()) {
        QMessageBox::warning(ui->nomReviewer, "Erreur", "Le nom ne doit pas être vide et ne doit contenir que des lettres.");
        return false;
    }

    // Validate Email
    QString email = ui->emailReviewer->text().trimmed();
    if (email.isEmpty() || !email.contains('@') || !email.contains('.')) {
        QMessageBox::warning(ui->emailReviewer, "Erreur", "Email invalide.");
        return false;
    }

    // Validate Institution
    QString institution = ui->institutionReviewer->text().trimmed();
    if (institution.isEmpty()) {
        QMessageBox::warning(ui->institutionReviewer, "Erreur", "L'Institution ne doit pas être vide.");
        return false;
    }

    // Validate Statut
    if (!ui->actifReviewer->isChecked() && !ui->inactifReviewer->isChecked()) {
        QMessageBox::warning(ui->actifReviewer, "Erreur", "Le Statut ne doit pas être vide.");
        return false;
    }

    // Validate Phone: only digits
    QString phone = ui->phoneReviewer->text().trimmed();
    QRegularExpression rePhone("^[0-9]+$");
    if (phone.isEmpty() || !rePhone.match(phone).hasMatch()) {
        QMessageBox::warning(ui->phoneReviewer, "Erreur", "Le téléphone ne doit contenir que des chiffres.");
        return false;
    }

    // Validate Photo
    QString photo = ui->photoPathReviewer->text().trimmed();
    if (photo.isEmpty()) {
        QMessageBox::warning(ui->photoPathReviewer, "Erreur", "Veuillez uploader une photo (champ vide).");
        return false;
    }

    return true;
}

void GestionReviewer::on_uploadPhotoBtn_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Sélectionner une photo", "", "Images (*.png *.xpm *.jpg *.jpeg)");
    if (filePath.isEmpty()) return;

    // Robustly find face_checker.py regardless of build directory
    QString scriptPath = QCoreApplication::applicationDirPath() + "/../../../face_checker.py";
    if (!QFile::exists(scriptPath)) {
        scriptPath = QCoreApplication::applicationDirPath() + "/../../face_checker.py";
    }
    if (!QFile::exists(scriptPath)) {
        scriptPath = "face_checker.py"; // Fallback to current working directory
    }

    // Call python script to verify face
    QProcess process;
    process.start("python", QStringList() << scriptPath << filePath);
    process.waitForFinished(10000); // Wait up to 10 seconds
    
    QString output = process.readAllStandardOutput().trimmed();
    QString errorOutput = process.readAllStandardError().trimmed();
    
    if (output == "true") {
        ui->photoPathReviewer->setText(filePath);
        QMessageBox::information(nullptr, "Succès", "Photo validée ! Visage humain détecté.");
    } else {
        if (!errorOutput.isEmpty()) {
            QMessageBox::warning(nullptr, "Erreur Serveur/Python", "Erreur lors de l'analyse (Avez-vous bien installé opencv-python?) :\n" + errorOutput);
        } else {
            QMessageBox::warning(nullptr, "Erreur", "Photo rejetée : Aucun visage humain détecté.");
        }
    }
}

// Old sendSms removed. Delegated to SmsService and reviewer.cpp

void GestionReviewer::on_enregistrerReviewer_clicked()
{
    if (!validateForm()) return;

    int id = ui->idReviewer->text().toInt();
    if (Reviewer::verifierId(id)) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID est déjà utilisé !");
        return;
    }

    QString nom = ui->nomReviewer->text();
    QString email = ui->emailReviewer->text();
    QString telephone = ui->phoneReviewer->text();
    QString photo = ui->photoPathReviewer->text();
    QString spec = ui->specialiteReviewer->text();
    QString inst = ui->institutionReviewer->text();
    QString statut = ui->actifReviewer->isChecked() ? "Actif" : "Inactif";
    QString username = userNameReviewer && !userNameReviewer->text().trimmed().isEmpty()
        ? userNameReviewer->text().trimmed()
        : email.split('@').first();

    Reviewer rev(id, nom, email, username, telephone, photo, spec, inst, statut);
    if (rev.ajouterReviewer()) {
        QMessageBox::information(nullptr, "Succès", "Reviewer ajouté avec succès !");
        afficherReviewers();
        clearForm();
    } else {
        QSqlRecord rec = QSqlDatabase::database().record("TABLE_REVIEWER");
        QString cols;
        for (int i=0; i<rec.count(); i++) cols += rec.fieldName(i) + " ";
        QMessageBox::critical(nullptr, "Erreur", "Echec de l'ajout du reviewer.\nErreur DB : " + rev.lastError + "\nColonnes dispo: " + cols);
    }
}

void GestionReviewer::on_modifierReviewer_clicked()
{
    if (selectedReviewerId == -1) {
        QMessageBox::warning(nullptr, "Erreur", "Veuillez sélectionner un reviewer dans la table.");
        return;
    }
    if (!validateForm()) return;

    int id = ui->idReviewer->text().toInt();
    if (id != selectedReviewerId && Reviewer::verifierId(id)) {
        QMessageBox::warning(nullptr, "Erreur", "Le nouvel ID est déjà utilisé par un autre reviewer !");
        return;
    }

    QString nom = ui->nomReviewer->text();
    QString email = ui->emailReviewer->text();
    QString telephone = ui->phoneReviewer->text();
    QString photo = ui->photoPathReviewer->text();
    QString spec = ui->specialiteReviewer->text();
    QString inst = ui->institutionReviewer->text();
    QString statut = ui->actifReviewer->isChecked() ? "Actif" : "Inactif";
    QString username = userNameReviewer && !userNameReviewer->text().trimmed().isEmpty()
        ? userNameReviewer->text().trimmed()
        : email.split('@').first();

    Reviewer rev(id, nom, email, username, telephone, photo, spec, inst, statut);
    if (rev.modifier(selectedReviewerId)) {
        QMessageBox::information(nullptr, "Succès", "Reviewer modifié avec succès !");
        afficherReviewers();
        clearForm();
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Echec de la modification.");
    }
}

void GestionReviewer::on_supprimerReviewerButton_clicked()
{
    // The UI uses ui->idReviewer for the ID, let's see which is selected
    int idToDelete = ui->idReviewer->text().toInt();
    if (idToDelete == 0) {
        QMessageBox::warning(nullptr, "Erreur", "Veuillez sélectionner un reviewer à supprimer.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Confirmation", "Êtes-vous sûr de vouloir supprimer ce reviewer?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        Reviewer rev;
        if (rev.supprimer(idToDelete)) {
            QMessageBox::information(nullptr, "Succès", "Reviewer supprimé.");
            afficherReviewers();
            clearForm();
        } else {
            QMessageBox::critical(nullptr, "Erreur", "Echec de la suppression.");
        }
    }
}

void GestionReviewer::on_rechercherButton_clicked()
{
    rechercherReviewer();
}

void GestionReviewer::on_comboBox_7_currentIndexChanged(int index) {
    Q_UNUSED(index);
    trierReviewers();
}

void GestionReviewer::on_tableWidget_7_clicked(const QModelIndex &index)
{
    int row = index.row();
    
    QString id = ui->tableWidget_7->item(row, 0)->text();
    QString nom = ui->tableWidget_7->item(row, 1)->text();
    QString email = ui->tableWidget_7->item(row, 2)->text();
    QString username = ui->tableWidget_7->item(row, 3)->text();
    QString tel = ui->tableWidget_7->item(row, 4)->text();
    QString photo = ui->tableWidget_7->item(row, 5)->text();
    QString spec = ui->tableWidget_7->item(row, 6)->text();
    QString inst = ui->tableWidget_7->item(row, 7)->text();
    QString status = ui->tableWidget_7->item(row, 8)->text();

    selectedReviewerId = id.toInt();
    ui->idReviewer->setText(id);
    ui->nomReviewer->setText(nom);
    ui->emailReviewer->setText(email);
    if (userNameReviewer) userNameReviewer->setText(username);
    ui->phoneReviewer->setText(tel);
    ui->photoPathReviewer->setText(photo);
    ui->specialiteReviewer->setText(spec);
    ui->institutionReviewer->setText(inst);

    if (status == "Actif") ui->actifReviewer->setChecked(true);
    else if (status == "Inactif") ui->inactifReviewer->setChecked(true);
}

void GestionReviewer::on_annulerReviewer_clicked()
{
    clearForm();
}

void GestionReviewer::on_quitterSession_3_clicked()
{
    clearForm();
    afficherReviewers();
}

void GestionReviewer::updateReviewerStats()
{
    updateStatistics();
}

void GestionReviewer::setupCharts()
{
    QChart *barChart = new QChart();
    barChart->setTitle("Reviewers par statut");
    barChart->setAnimationOptions(QChart::SeriesAnimations);
    barChart->setBackgroundBrush(QBrush(QColor("#1e293b")));
    barChart->setTitleBrush(QBrush(Qt::white));
    barChart->legend()->setVisible(false);
    barChart->setMargins(QMargins(8, 8, 8, 8));

    barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    barChartView->setStyleSheet("background: transparent; border: none;");
    barChartView->setParent(statsPanel);
    barChartView->setGeometry(10, 10, 671, 161);
    barChartView->show();
}

void GestionReviewer::updateStatistics()
{
    QMap<QString, int> stats = Reviewer::getStatistics();
    const int actif = stats.value("Statut_Actif", 0);
    const int inactif = stats.value("Statut_Inactif", 0);

    QChart *barChart = barChartView->chart();
    barChart->removeAllSeries();
    for (QAbstractAxis *axis : barChart->axes()) {
        barChart->removeAxis(axis);
        delete axis;
    }

    QBarSeries *barSeries = new QBarSeries();
    QBarSet *barSet = new QBarSet("Reviewers");
    barSet->setColor(QColor("#10b981"));
    *barSet << actif << inactif;

    barSeries->append(barSet);
    barChart->addSeries(barSeries);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(QStringList() << "Actif" << "Inactif");
    axisX->setLabelsColor(QColor("#e2e8f0"));
    axisX->setGridLineVisible(false);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    axisY->setLabelsColor(QColor("#e2e8f0"));
    axisY->setGridLineColor(QColor(255, 255, 255, 50));
    axisY->setRange(0, qMax(1, qMax(actif, inactif) + 1));
    axisY->setTickCount(qMax(2, qMax(actif, inactif) + 2));
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);
}

void GestionReviewer::on_expoSession_3_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableWidget_7->rowCount();
    const int columnCount = ui->tableWidget_7->columnCount();

    out <<  "<html>\n<head>\n<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("Liste des Reviewers")
        <<  "</head>\n<body bgcolor=#ffffff link=#5000A0>\n"
        <<  "<center> <h1 style=\"color: #1e293b; font-family: Arial, sans-serif;\"><strong> *** LISTE DES REVIEWERS *** </strong></h1> </center>\n"
        <<  "<table border=1 cellspacing=0 cellpadding=8 width=\"100%\" style=\"border-collapse: collapse; border: 1px solid #1e293b; font-family: Arial, sans-serif;\">\n";

    out << "<thead><tr bgcolor=#1e293b style=\"color: #ffffff; font-weight: bold;\">";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableWidget_7->isColumnHidden(column))
            out << QString("<th style=\"border: 1px solid #1e293b; padding: 10px;\">%1</th>").arg(ui->tableWidget_7->horizontalHeaderItem(column)->text());
    out << "</tr></thead>\n";

    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableWidget_7->isColumnHidden(column)) {
                QString data = ui->tableWidget_7->item(row, column)->text().simplified();
                out << QString("<td style=\"border: 1px solid #1e293b; text-align: center; padding: 8px;\">%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n</body>\n</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", QString(), "*.pdf");
    if (fileName.isEmpty()) { delete document; return; }
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPdfWriter *printer = new QPdfWriter(fileName);
    printer->setPageSize(QPageSize(QPageSize::A4));
    printer->setPageOrientation(QPageLayout::Landscape);
    printer->setPageMargins(QMarginsF(15, 15, 15, 15));

    document->print(printer);
    delete document;
    delete printer;

    QMessageBox::information(nullptr, "Exportation PDF", "La liste des reviewers a été exportée avec succès.");
}
