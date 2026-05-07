#include "smartresearch.h"
#include "ui_smartresearch.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkReply>
#include <QDesktopServices>

#include "gestionsession.h"
#include "gestionreviewer.h"
#include "journal.h"
#include "exportexcel.h"
// Force Rebuild UI Cache and Linked Objects
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QTextStream>
#include <QTextDocument>
#include <QPrinter>
#include <QTextDocument>
#include"qrcode.h"
#include<fstream>
#include <QPixmap>
#include <QVBoxLayout>
#include <QDebug>
#include <QButtonGroup>
#include<QtSvg/QSvgRenderer>
#include <QMap>
#include <algorithm>
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>

using qrcodegen::QrCode;
using qrcodegen::QrSegment;

SmartResearch::SmartResearch(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartResearch) {
    ui->setupUi(this);
    arduino = nullptr; // Initialisation pour éviter le crash dans setupSerial
    setupSerial();

    // Initialize Network Manager for OpenAlex API
    apiManager = new QNetworkAccessManager(this);
    connect(apiManager, &QNetworkAccessManager::finished, this, &SmartResearch::onJournalAPIResponse);
    ui->nom->setPlaceholderText("Tapez le nom et appuyez sur [Entrée] pour chercher en ligne...");
    ui->nom->setToolTip("Appuyez sur la touche Entrée pour auto-remplir depuis la BDD mondiale OpenAlex.");
    connect(ui->nom, &QLineEdit::returnPressed, this, &SmartResearch::fetchJournalAPI);

    // --- Add Map Button near Pays field ---
    QPushButton *btnMap = new QPushButton("🗺️ Carte", this);
    btnMap->setToolTip("Choisir le pays sur une carte du monde");
    btnMap->setCursor(Qt::PointingHandCursor);
    btnMap->setStyleSheet("background-color: #3b82f6; color: white; font-weight: bold; border-radius: 5px; padding: 3px;");

    if (ui->pays->parentWidget() && ui->pays->parentWidget()->layout()) {
        ui->pays->parentWidget()->layout()->addWidget(btnMap);
    } else {
        btnMap->setParent(ui->pays->parentWidget());
        btnMap->setGeometry(ui->pays->x() + ui->pays->width() + 5, ui->pays->y(), 60, ui->pays->height());
    }
    connect(btnMap, &QPushButton::clicked, this, &SmartResearch::on_btnChooseMap_clicked);

    // Initialisation du Chatbot
    chatbotWidget = new Chatbot(this);
    ui->stackedWidget->addWidget(chatbotWidget);

    loadPubTypes();

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
    sessionController = new GestionSession(ui, this);
    reviewerController = new GestionReviewer(ui, this);

    // --- Démarrage normal ---
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);

    // --- Gestion Publication Initialization ---
    ui->tableWidget_9->setModel(Ptmp.afficher());
    ui->tableWidget_9->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_9->setSelectionMode(QAbstractItemView::SingleSelection);

    // --- Gestion Utilisateur Initialization ---
    ui->tableWidget_10->setModel(Utmp.afficher());
    ui->tableWidget_10->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_10->setSelectionMode(QAbstractItemView::SingleSelection);

    // --- Gestion Journal Initialization ---
    ui->type->addItem("Journal");
    ui->type->addItem("Conférence");
    ui->type->setCurrentIndex(-1);
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
        "Q1 (Quartile 1): Les 25% meilleurs journaux dans le domaine",
        "Q2 (Quartile 2): Les journaux du groupe 25% à 50%",
        "Q3 (Quartile 3): Les journaux du groupe 50% à 75%",
        "Q4 (Quartile 4): Les 25% derniers journaux dans le domaine"
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
    updateSessionStats();

    // --- Gestion Session Initialization ---
    ui->tableWidget_Sessions->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_Sessions->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_Sessions->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_Sessions->setAlternatingRowColors(true);

    // ==================== Gestion Paiement Initialization ====================
    setupPaiementValidators();
    populatePaiementComboBoxes();
    loadPaiementData();
    connect(ui->tablePaiement, &QTableView::clicked, this, &SmartResearch::on_tablePaiement_clicked);

    // ==================== Arduino Serial Port Setup ====================
    serial = new QSerialPort(this);
    bool found = false;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.hasVendorIdentifier() && info.hasProductIdentifier()) {
            serial->setPortName(info.portName());
            found = true;
            break;
        }
    }

    if (!found) serial->setPortName("COM3"); // Fallback

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Serial Port Open:" << serial->portName();
    } else {
        qDebug() << "Serial Error:" << serial->errorString();
    }

    connect(serial, &QSerialPort::readyRead, this, &SmartResearch::readArduinoData);
    connect(this, &SmartResearch::validationReceived, this, &SmartResearch::handleValidation);
    connect(this, &SmartResearch::validationFinished, this, &SmartResearch::showValidationResult);

    // --- 7-Segment Display Arduino ---
    initArduino();
}


SmartResearch::~SmartResearch() {
    // serial == arduino (shared pointer), only delete arduino
    if (arduino && arduino->isOpen()) arduino->close();
    delete ui;
}

// ============================================================
// === ARDUINO DISPLAY (7-SEGMENT) ============================
// ============================================================

void SmartResearch::initArduino()
{
    arduinoDisplay = new ArduinoController(this);

    // Log connection events
    connect(arduinoDisplay, &ArduinoController::connected, this, [](const QString &port){
        qDebug() << "[Display Arduino] Connected on" << port;
    });
    connect(arduinoDisplay, &ArduinoController::errorOccurred, this, [](const QString &err){
        qDebug() << "[Display Arduino] Error:" << err;
    });

    // Build a list of ports already claimed by other serial connections in this app
    QStringList usedPorts;
    if (serial  && serial->isOpen())  usedPorts << serial->portName();
    if (arduino && arduino->isOpen()) usedPorts << arduino->portName();
    qDebug() << "[Display Arduino] Skipping already-used ports:" << usedPorts;

    // Manually scan — skip any port already held by this process
    bool found = false;
    const QList<quint16> arduinoVIDs = {0x2341, 0x2A03, 0x1A86, 0x0403, 0x10C4};

    // 1st pass: prefer known Arduino VIDs
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        if (usedPorts.contains(info.portName())) continue;
        if (arduinoVIDs.contains(info.vendorIdentifier())) {
            qDebug() << "[Display Arduino] Trying VID-matched port" << info.portName();
            if (arduinoDisplay->connectToPort(info.portName())) { found = true; break; }
        }
    }

    // 2nd pass: try any remaining free port
    if (!found) {
        for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
            if (usedPorts.contains(info.portName())) continue;
            qDebug() << "[Display Arduino] Trying free port" << info.portName();
            if (arduinoDisplay->connectToPort(info.portName())) { found = true; break; }
        }
    }

    if (!found) {
        qDebug() << "[Display Arduino] No free port available for 7-seg display. "
                    "Connect the display Arduino to a second USB port.";
        return;
    }

    // Send live publication count immediately on startup
    QSqlQuery q;
    int total = 0, journals = 0, conferences = 0;
    q.exec("SELECT COUNT(*) FROM PUBLICATION");
    if (q.next()) total = q.value(0).toInt();
    q.exec("SELECT COUNT(*) FROM PUBLICATION WHERE TYPE_PUB = 'Journal'");
    if (q.next()) journals = q.value(0).toInt();
    q.exec("SELECT COUNT(*) FROM PUBLICATION WHERE TYPE_PUB = 'Conférence'");
    if (q.next()) conferences = q.value(0).toInt();

    arduinoDisplay->sendPublicationCount(total, journals, conferences);
    qDebug() << "[Display Arduino] Sent startup count:" << total << journals << conferences;
}

// ============================================================
// === GESTION PAIEMENT =======================================
// ============================================================

// ==================== PUBLIC METHODS ====================

void SmartResearch::setupPaiementValidators()
{
    QDoubleValidator *montantValidator = new QDoubleValidator(0.01, 9999999.99, 2, this);
    montantValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_Montant->setValidator(montantValidator);

    QRegularExpression rxRecherche("^[0-9]+$");
    QRegularExpressionValidator *rechercheValidator = new QRegularExpressionValidator(rxRecherche, this);
    ui->lineEdit_recherchPaiement->setValidator(rechercheValidator);

    ui->lineEdit_ID_Paiement->setReadOnly(true);
    ui->dateEdit->setDate(QDate::currentDate());

    // Status is managed exclusively by Arduino — hide manual radio buttons
    ui->radioButton_attente->setChecked(true);
    ui->radioButton_attente->hide();
    ui->radioButton_paye->hide();
    ui->radioButton_annule->hide();
}

void SmartResearch::loadPaiementData()
{
    paiement p;
    ui->tablePaiement->setModel(p.afficher());

    ui->tablePaiement->resizeColumnsToContents();
    ui->tablePaiement->horizontalHeader()->setStretchLastSection(true);
    ui->tablePaiement->setAlternatingRowColors(true);
    ui->tablePaiement->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablePaiement->setSelectionMode(QAbstractItemView::SingleSelection);
}

void SmartResearch::populatePaiementComboBoxes()
{
    ui->comboBox_TypeFrais->clear();
    ui->comboBox_TypeFrais->addItems({tr("Choisir"), tr("Inscription"), tr("Scolarité"), tr("Transport"), tr("Hébergement"), tr("Autre")});

    ui->comboBox_ModePaiement->clear();
    ui->comboBox_ModePaiement->addItems({tr("Choisir"), tr("Espèces"), tr("Carte Bancaire"), tr("Virement"), tr("Chèque"), tr("Paiement en ligne")});

    ui->comboBox_Devise->clear();
    ui->comboBox_Devise->addItems({
        tr("Choisir"),
        "TND - " + tr("Tunisian Dinar"), "EUR - " + tr("Euro"), "USD - " + tr("US Dollar"),
        "GBP - " + tr("British Pound"), "JPY - " + tr("Japanese Yen"), "CAD - " + tr("Canadian Dollar"),
        "AUD - " + tr("Australian Dollar"), "CHF - " + tr("Swiss Franc"),
        "CNY - " + tr("Chinese Yuan"), "SAR - " + tr("Saudi Riyal"), "AED - " + tr("UAE Dirham")
    });

    ui->dateEdit->setMaximumDate(QDate::currentDate());
    ui->lineEdit_ID_Paiement->setText(QString::number(generatePaiementID()));
}

int SmartResearch::generatePaiementID()
{
    QSqlQuery query;
    query.exec("SELECT MAX(ID_PAIEMENT) FROM TABLE_PAIEMENT");
    if (query.next()) {
        int maxId = query.value(0).toInt();
        return maxId > 0 ? maxId + 1 : 1;
    }
    return 1;
}

// ==================== PAIEMENT SLOTS ====================

void SmartResearch::on_btn_Enregistrer_paiement_clicked()
{
    if (ui->comboBox_TypeFrais->currentIndex() == 0 ||
        ui->comboBox_Devise->currentIndex() == 0 ||
        ui->comboBox_ModePaiement->currentIndex() == 0) {
        QMessageBox::warning(this, tr("Erreur de Saisie"), tr("Le choix est obligatoire."));
        return;
    }

    QString montantStr = ui->lineEdit_Montant->text().replace(",", ".");
    double montantValue = montantStr.toDouble();

    if (montantValue <= 0) {
        QMessageBox::warning(this, tr("Erreur de Saisie"), tr("Le montant doit être strictement positif."));
        return;
    }

    int idPaiement = ui->lineEdit_ID_Paiement->text().toInt();
    QString typeFrais = ui->comboBox_TypeFrais->currentText();
    QString montant = QString::number(montantValue, 'f', 2);
    QString devise = ui->comboBox_Devise->currentText().left(3);
    QString modePaiement = ui->comboBox_ModePaiement->currentText();
    QString datePaiement = ui->dateEdit->date().toString("dd/MM/yyyy");

    // Status is always "EN ATTENTE" on creation — Arduino handles confirmation/cancellation
    QString statutPaiement = "EN ATTENTE";

    paiement p(idPaiement, typeFrais, modePaiement, datePaiement, montant, devise, statutPaiement);

    if (p.ajouter()) {
        QMessageBox::information(this, tr("SUCCÈS"), tr("Paiement ajouté avec succès !"));
        ui->tablePaiement->setModel(p.afficher());
        on_btn_Annuler_paiement_clicked();
    } else {
        QMessageBox::critical(this, tr("ERREUR"), tr("Échec de l'ajout du paiement.\nL'ID existe peut-être déjà."));
    }
}

void SmartResearch::on_qr_clicked()
{
    if (ui->tablePaiement->currentIndex().row() == -1) {
        QMessageBox::information(this, tr("QR Code"),
                                 tr("Veuillez choisir un paiement dans le tableau."));
        return;
    }

    int row = ui->tablePaiement->currentIndex().row();
    QAbstractItemModel *model = ui->tablePaiement->model();

    int    id      = model->index(row, 0).data().toInt();
    QString type   = model->index(row, 1).data().toString();
    QString mode   = model->index(row, 2).data().toString();
    QString date   = model->index(row, 3).data().toString();
    QString montant= model->index(row, 4).data().toString();
    QString devise = model->index(row, 5).data().toString();
    QString statut = model->index(row, 6).data().toString();

    QString qrText = QString("ID:%1|Type:%2|Mode:%3|Date:%4|Montant:%5 %6|Statut:%7")
                         .arg(id).arg(type).arg(mode).arg(date)
                         .arg(montant).arg(devise).arg(statut);

    try {
        const QrCode qr = QrCode::encodeText(qrText.toUtf8().constData(), QrCode::Ecc::LOW);

        std::ofstream myfile("qrcode.svg");
        myfile << qr.toSvgString(4);
        myfile.close();

        QSvgRenderer svgRenderer(QString("qrcode.svg"));

        QPixmap pix(200, 200);
        pix.fill(Qt::white);
        QPainter pixPainter(&pix);
        svgRenderer.render(&pixPainter);
        pixPainter.end();

        ui->QRCODE_3->setPixmap(pix);
        ui->QRCODE_3->setScaledContents(true);

    } catch (const std::exception &e) {
        QMessageBox::critical(this, tr("Erreur QR Code"),
                              tr("Impossible de générer le QR Code: ") + QString(e.what()));
    }
}

void SmartResearch::on_pb_excel_clicked()
{
    if (!ui->tablePaiement->model() || ui->tablePaiement->model()->rowCount() == 0) {
        QMessageBox::warning(this, tr("Attention"), tr("Aucune donnée à exporter !"));
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en Excel"),
                                                    qApp->applicationDirPath() + "/Paiements.xls",
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    if (!fileName.endsWith(".xls", Qt::CaseInsensitive))
        fileName += ".xls";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de créer le fichier !"));
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    QAbstractItemModel *model = ui->tablePaiement->model();
    int rowCount    = model->rowCount();
    int columnCount = model->columnCount();

    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    out << "<?mso-application progid=\"Excel.Sheet\"?>\n";
    out << "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n";
    out << " xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\">\n";
    out << "<Styles>\n";
    out << "  <Style ss:ID=\"Header\">\n";
    out << "    <Font ss:Bold=\"1\" ss:Color=\"#FFFFFF\" ss:Size=\"11\"/>\n";
    out << "    <Interior ss:Color=\"#003366\" ss:Pattern=\"Solid\"/>\n";
    out << "    <Alignment ss:Horizontal=\"Center\"/>\n";
    out << "  </Style>\n";
    out << "  <Style ss:ID=\"Row1\">\n";
    out << "    <Interior ss:Color=\"#FFFFFF\" ss:Pattern=\"Solid\"/>\n";
    out << "  </Style>\n";
    out << "  <Style ss:ID=\"Row2\">\n";
    out << "    <Interior ss:Color=\"#DCE6F1\" ss:Pattern=\"Solid\"/>\n";
    out << "  </Style>\n";
    out << "</Styles>\n";
    out << "<Worksheet ss:Name=\"Paiements\">\n";
    out << "<Table>\n";

    QList<int> colWidths = {60, 120, 100, 120, 100, 80, 80};
    for (int i = 0; i < columnCount && i < colWidths.size(); i++)
        out << QString("  <Column ss:Width=\"%1\"/>\n").arg(colWidths[i]);

    out << "  <Row>\n";
    for (int col = 0; col < columnCount; col++) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        out << QString("    <Cell ss:StyleID=\"Header\"><Data ss:Type=\"String\">%1</Data></Cell>\n")
                   .arg(header.toHtmlEscaped());
    }
    out << "  </Row>\n";

    for (int row = 0; row < rowCount; row++) {
        QString style = (row % 2 == 0) ? "Row1" : "Row2";
        out << "  <Row>\n";
        for (int col = 0; col < columnCount; col++) {
            QString value = model->data(model->index(row, col)).toString();
            bool isNumber = false;
            double numVal = value.toDouble(&isNumber);
            if (isNumber && col != 3) {
                out << QString("    <Cell ss:StyleID=\"%1\"><Data ss:Type=\"Number\">%2</Data></Cell>\n")
                .arg(style).arg(numVal);
            } else {
                out << QString("    <Cell ss:StyleID=\"%1\"><Data ss:Type=\"String\">%2</Data></Cell>\n")
                .arg(style).arg(value.toHtmlEscaped());
            }
        }
        out << "  </Row>\n";
    }

    out << "</Table>\n";
    out << "</Worksheet>\n";
    out << "</Workbook>\n";

    file.close();

    QMessageBox::information(this, tr("Succès"),
                             QString(tr("%1 paiement(s) exporté(s) avec succès !\nFichier : %2"))
                                 .arg(rowCount).arg(fileName));
}

void SmartResearch::on_btn_Modifier_paiement_clicked()
{
    if (ui->comboBox_TypeFrais->currentIndex() == 0 ||
        ui->comboBox_Devise->currentIndex() == 0 ||
        ui->comboBox_ModePaiement->currentIndex() == 0) {
        QMessageBox::warning(this, tr("Erreur de Saisie"), tr("Le choix est obligatoire."));
        return;
    }

    int idPaiement = ui->lineEdit_ID_Paiement->text().toInt();
    QString typeFrais = ui->comboBox_TypeFrais->currentText();
    QString montantStr = ui->lineEdit_Montant->text().replace(",", ".");
    double montantValue = montantStr.toDouble();
    QString montant = QString::number(montantValue, 'f', 2);
    QString devise = ui->comboBox_Devise->currentText().left(3);
    QString modePaiement = ui->comboBox_ModePaiement->currentText();
    QString datePaiement = ui->dateEdit->date().toString("dd/MM/yyyy");

    // NOTE: Status is NOT manually modifiable — Arduino manages it exclusively

    if (ui->lineEdit_ID_Paiement->text().isEmpty()) {
        QMessageBox::critical(this, tr("ERREUR"), tr("Veuillez entrer l'ID du paiement à modifier !"));
        return;
    }

    if (montantValue <= 0) {
        QMessageBox::warning(this, tr("Erreur de Saisie"), tr("Le montant doit être strictement positif."));
        return;
    }

    paiement p;
    if (!p.rechercherParId(idPaiement)) {
        QMessageBox::critical(this, tr("ERREUR"), tr("Aucun paiement trouvé avec cet ID !"));
        return;
    }

    p.setTypeFraisPaiement(typeFrais);
    p.setMontantPaiement(montant);
    p.setDevicePaiement(devise);
    p.setModePaiement(modePaiement);
    p.setDatePaiement(datePaiement);
    // p.setStatutPaiement(...) intentionally omitted — status is set by Arduino only

    if (p.modifier()) {
        QMessageBox::information(this, tr("SUCCÈS"), tr("Paiement modifié avec succès !"));
        ui->tablePaiement->setModel(p.afficher());
        on_btn_Annuler_paiement_clicked();
    } else {
        QMessageBox::critical(this, tr("ERREUR"), tr("Échec de la modification du paiement !"));
    }
}

void SmartResearch::on_btn_Annuler_paiement_clicked()
{
    ui->lineEdit_ID_Paiement->setText(QString::number(generatePaiementID()));
    ui->comboBox_TypeFrais->setCurrentIndex(0);
    ui->lineEdit_Montant->clear();
    ui->comboBox_Devise->setCurrentIndex(0);
    ui->comboBox_ModePaiement->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->radioButton_attente->setChecked(true);
    ui->radioButton_paye->setChecked(false);
    ui->radioButton_annule->setChecked(false);
    ui->lineEdit_recherchPaiement->clear();
}

void SmartResearch::on_recherche_clicked()
{
    QString searchText = ui->lineEdit_recherchPaiement->text();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, tr("ATTENTION"), tr("Veuillez entrer un ID à rechercher !"));
        return;
    }

    bool isNumber;
    int idRecherche = searchText.toInt(&isNumber);

    if (!isNumber) {
        QMessageBox::critical(this, tr("ERREUR"), tr("L'ID doit être un nombre valide !"));
        return;
    }

    paiement p;
    bool found = p.rechercherParId(idRecherche);

    if (found) {
        ui->lineEdit_ID_Paiement->setText(QString::number(p.getIdPaiement()));
        ui->comboBox_TypeFrais->setCurrentText(p.getTypeFraisPaiement());
        ui->lineEdit_Montant->setText(p.getMontantPaiement());
        int idxDevise = ui->comboBox_Devise->findText(p.getDevicePaiement(), Qt::MatchStartsWith);
        if (idxDevise >= 0) ui->comboBox_Devise->setCurrentIndex(idxDevise);
        ui->comboBox_ModePaiement->setCurrentText(p.getModePaiement());

        QDate date = QDate::fromString(p.getDatePaiement(), "dd/MM/yyyy");
        if (date.isValid()) ui->dateEdit->setDate(date);

        // Normalize status to uppercase for robust comparison
        QString statut = p.getStatutPaiement().toUpper().trimmed();
        if (statut == "EN ATTENTE") ui->radioButton_attente->setChecked(true);
        else if (statut == "PAYE")  ui->radioButton_paye->setChecked(true);
        else if (statut == "ANNULE") ui->radioButton_annule->setChecked(true);

        QMessageBox::information(this, tr("SUCCÈS"), tr("Paiement trouvé !"));
    } else {
        QMessageBox::warning(this, tr("NON TROUVÉ"), tr("Aucun paiement trouvé avec l'ID : ") + searchText);
        QSqlQueryModel *emptyModel = new QSqlQueryModel();
        ui->tablePaiement->setModel(emptyModel);
    }
}

void SmartResearch::on_pushButton_supprimer_paiement_clicked()
{
    QString idText = ui->lineEdit_ID_Paiement->text();
    if (idText.isEmpty()) idText = ui->lineEdit_recherchPaiement->text();

    if (idText.isEmpty()) {
        QMessageBox::critical(this, "ERREUR", "Veuillez entrer l'ID du paiement à supprimer !");
        return;
    }

    bool isNumber;
    int idSuppression = idText.toInt(&isNumber);

    if (!isNumber || idSuppression <= 0) {
        QMessageBox::critical(this, "ERREUR", "ID invalide !");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "CONFIRMATION",
                                  "Êtes-vous sûr de vouloir supprimer le paiement ID : " + idText + " ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        paiement p;
        if (p.supprimer(idSuppression)) {
            QMessageBox::information(this, "SUCCÈS", "Paiement supprimé avec succès !");
            ui->tablePaiement->setModel(p.afficher());
            on_btn_Annuler_paiement_clicked();
        } else {
            QMessageBox::critical(this, "ERREUR", "Échec de la suppression !\nLe paiement n'existe peut-être pas.");
        }
    }
}

void SmartResearch::on_quitterSession_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "CONFIRMATION",
                                  "Voulez-vous vraiment quitter l'application ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) QApplication::quit();
}

void SmartResearch::on_quitterSession_7_clicked()
{
    on_quitterSession_2_clicked();
}

void SmartResearch::on_expoSession_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Enregistrer le PDF",
                                                    "Liste_Paiements.pdf",
                                                    "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) fileName += ".pdf";

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tablePaiement->model()->rowCount();
    const int columnCount = ui->tablePaiement->model()->columnCount();

    out << "<html>\n<head>\n<meta Content=\"Text/html; charset=UTF-8\">\n"
        << "<title>Liste des Paiements</title>\n<style>\n"
        << "body { font-family: Arial, sans-serif; background-color: #f0f0f0; }\n"
        << "h1 { color: #003366; text-align: center; }\n"
        << "table { border-collapse: collapse; width: 100%; margin: 20px 0; }\n"
        << "th { background-color: #003366; color: white; padding: 10px; text-align: left; }\n"
        << "td { padding: 8px; border-bottom: 1px solid #ddd; }\n"
        << "tr:nth-child(even) { background-color: #f2f2f2; }\n"
        << ".header-info { text-align: center; margin-bottom: 20px; }\n"
        << "</style>\n</head>\n<body>\n"
        << "<div class='header-info'>\n<h1>Liste des Paiements</h1>\n"
        << "<p>Généré le : " << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss") << "</p>\n"
        << "</div>\n<table border='1' cellspacing='0' cellpadding='5'>\n<thead><tr>";

    for (int column = 0; column < columnCount; column++)
        if (!ui->tablePaiement->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tablePaiement->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n<tbody>\n";

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
        << "<p style='text-align: center; margin-top: 20px;'>Total des paiements : " << rowCount << "</p>\n"
        << "</body>\n</html>";

    QTextDocument document;
    document.setHtml(strStream);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize::A4);
    printer.setPageOrientation(QPageLayout::Portrait);

    document.print(&printer);
    QMessageBox::information(this, "SUCCÈS", "PDF généré avec succès !\nEmplacement : " + fileName);
}

void SmartResearch::on_comboBoxPaiement_currentIndexChanged(int index)
{
    paiement p;
    if (index == 0) ui->tablePaiement->setModel(p.trierParId());
    else ui->tablePaiement->setModel(p.trierParIdDesc());
}

void SmartResearch::on_lineEdit_recherchPaiement_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        loadPaiementData();
        return;
    }

    bool ok;
    int id = arg1.toInt(&ok);
    if (!ok) {
        QSqlQueryModel *emptyModel = new QSqlQueryModel();
        ui->tablePaiement->setModel(emptyModel);
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM TABLE_PAIEMENT WHERE ID_PAIEMENT = :id");
    query.bindValue(":id", id);
    query.exec();
    model->setQuery(std::move(query));
    ui->tablePaiement->setModel(model);
}

void SmartResearch::on_tablePaiement_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;

    int row = index.row();
    QAbstractItemModel *model = ui->tablePaiement->model();

    ui->lineEdit_ID_Paiement->setText(model->index(row, 0).data().toString());
    ui->comboBox_TypeFrais->setCurrentText(model->index(row, 1).data().toString());
    ui->comboBox_ModePaiement->setCurrentText(model->index(row, 2).data().toString());
    ui->dateEdit->setDate(QDate::fromString(model->index(row, 3).data().toString(), "dd/MM/yyyy"));
    ui->lineEdit_Montant->setText(model->index(row, 4).data().toString());

    QString devise = model->index(row, 5).data().toString();
    int indexDevise = ui->comboBox_Devise->findText(devise, Qt::MatchStartsWith);
    if (indexDevise != -1) ui->comboBox_Devise->setCurrentIndex(indexDevise);

    // Normalize status to uppercase for robust comparison
    QString statut = model->index(row, 6).data().toString().toUpper().trimmed();
    if (statut == "PAYE")   ui->radioButton_paye->setChecked(true);
    else if (statut == "ANNULE") ui->radioButton_annule->setChecked(true);
    else                         ui->radioButton_attente->setChecked(true);
}

void SmartResearch::on_expoSession_2_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}


// ============================================================
// === ARDUINO PAYMENT VALIDATION — 3-LAYER ARCHITECTURE ======
// ============================================================

// --- LAYER 1: SERIAL LAYER — Reception & ID Capture ---
// --- LAYER 1: SERIAL LAYER ---
void SmartResearch::readArduinoData()
{
    dataBuffer.append(serial->readAll());

    while (dataBuffer.contains('\n')) {
        int pos = dataBuffer.indexOf('\n');
        QString line = QString::fromLatin1(dataBuffer.left(pos)).trimmed();
        dataBuffer.remove(0, pos + 1);

        if (line.isEmpty()) continue;

        qDebug() << "[SERIAL] RAW In:" << line;

        if (line == "BUTTON_PRESSED") {
            QModelIndex idx = ui->tablePaiement->currentIndex();
            if (idx.isValid()) {
                int selectedId = ui->tablePaiement->model()
                ->index(idx.row(), 0).data().toInt();

                paiement p_check;
                if (p_check.rechercherParId(selectedId)) {
                    QString status = p_check.getStatutPaiement().toUpper().trimmed();
                    if (status == "PAYE") {
                        qDebug() << "[SERIAL] Ignored: already PAYE for ID:" << selectedId;
                        QMessageBox::warning(this, tr("Arduino"), tr("Paiement déjà confirmé."));
                        return;
                    } else if (status == "ANNULE") {
                        qDebug() << "[SERIAL] Ignored: already ANNULE for ID:" << selectedId;
                        QMessageBox::warning(this, tr("Arduino"), tr("Paiement déjà annulé."));
                        return;
                    }
                }

                pendingPaiementId = selectedId;
                arduinoBusy = true;
                qDebug() << "[SERIAL] Scan started for ID:" << pendingPaiementId;

            } else {
                qDebug() << "[SERIAL] Scan ignored: No selection";
                QMessageBox::warning(this, tr("Arduino"),
                                     tr("Veuillez choisir un paiement dans le tableau !"));
            }
            continue;
        }

        // Only process "1" or "0" during an active payment validation
        if ((line == "1" || line == "0") && arduinoBusy && pendingPaiementId != -1) {
            emit validationReceived(line, pendingPaiementId);
            continue;
        }

        // Any other numeric line here belongs to User Auth — ignore it in payment context
        qDebug() << "[SERIAL] Skipped (not a payment signal):" << line;
    }
}
// --- LAYER 2: CONTROLLER LAYER — Business Logic & DB Update ---
// --- LAYER 2: CONTROLLER LAYER ---
void SmartResearch::handleValidation(const QString &result, int idPaiement)
{
    if (!arduinoBusy || idPaiement == -1) {
        qDebug() << "[CTRL] Abandon: not busy or invalid ID.";
        return;
    }

    // Direct SQL update — bypass any ORM issues, guaranteed to hit the DB
    QString newStatut = (result == "1") ? "PAYE" : "ANNULE";

    QSqlQuery updateQuery;
    updateQuery.prepare(
        "UPDATE TABLE_PAIEMENT SET STATUT_PAIEMENT = :statut "
        "WHERE ID_PAIEMENT = :id"
        );
    updateQuery.bindValue(":statut", newStatut);
    updateQuery.bindValue(":id", idPaiement);

    bool success = updateQuery.exec();

    if (success && updateQuery.numRowsAffected() > 0) {
        qDebug() << "[CTRL] DB updated — ID:" << idPaiement
                 << "-> Statut:" << newStatut;
        QString msg = (result == "1")
                          ? tr("Paiement ID %1 confirmé avec succès → PAYE")
                                .arg(idPaiement)
                          : tr("Paiement ID %1 annulé avec succès → ANNULE")
                                .arg(idPaiement);
        emit validationFinished(msg, true);
    } else {
        QString errMsg = updateQuery.lastError().text();
        qDebug() << "[CTRL] DB update FAILED for ID:" << idPaiement
                 << "| Error:" << errMsg;
        emit validationFinished(
            tr("Échec mise à jour DB pour ID %1: %2").arg(idPaiement).arg(errMsg),
            false
            );
    }

    arduinoBusy = false;
    pendingPaiementId = -1;
}

// --- LAYER 3: UI LAYER — Messages & Table Refresh ---
void SmartResearch::showValidationResult(const QString &message, bool success)
{
    if (success) {
        QMessageBox::information(this, tr("Arduino — Succès"), message);
    } else {
        QMessageBox::warning(this, tr("Arduino — Erreur"), message);
    }

    // Reload table directly from DB to reflect the new status
    paiement p_refresh;
    QSqlQueryModel *freshModel = p_refresh.afficher();
    ui->tablePaiement->setModel(freshModel);
    ui->tablePaiement->resizeColumnsToContents();
    ui->tablePaiement->horizontalHeader()->setStretchLastSection(true);

    qDebug() << "[UI] Interface refreshed.";
}

// ============================================================
// === END GESTION PAIEMENT ===================================
// ============================================================




void SmartResearch::on_GestionUtilisateurs_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
    ui->tableWidget_10->setModel(Utmp.afficher());
}

void SmartResearch::on_GestionPublications_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
    ui->tableWidget_9->setModel(Ptmp.afficher());
}

void SmartResearch::on_GestionSession_clicked() {
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
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage6);
}

void SmartResearch::on_btnLogin_main_clicked()
{
    ui->groupBox->setVisible(true);
    ui->label_10->setVisible(true);
    ui->TableaudeBoard->setVisible(true);
    ui->stackedWidget->setGeometry(200, 100, 1221, 621);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
    if (ui->txtPassword_login) ui->txtPassword_login->clear();
    if (ui->txtUsername_login) ui->txtUsername_login->clear();
}

// --- Gestion Publication Slots ---

void SmartResearch::on_enregistrer_clicked() {
    int id = ui->Id_utilisateur->text().toInt();
    QString titre = ui->titrePub->text();
    QString auteurs = ui->auteurPub->text();
    QString abstract = ui->abstractPub->text();
    QString type = ui->comboBox_typePub->currentText();
    QString mots_cles = ui->mot_clePub->text();
    QString statut = "";
    if (ui->radioButton_statut_attente->isChecked()) statut = "En attente";
    else if (ui->radioButton_statut_accepte->isChecked()) statut = "Accepté";
    else if (ui->radioButton_statut_rejete->isChecked()) statut = "Rejeté";
    QDate date = ui->datePub->date();

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

    if (titre.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Titre' est obligatoire.");
        return;
    }
    QRegularExpression rePub("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!rePub.match(titre).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Titre' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (auteurs.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Auteurs' est obligatoire.");
        return;
    }
    if (!rePub.match(auteurs).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Auteurs' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (abstract.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Abstract' est obligatoire.");
        return;
    }
    if (!rePub.match(abstract).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Abstract' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (ui->comboBox_typePub->currentIndex() == -1 || ui->comboBox_typePub->currentText() == "Aucun type disponible") {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner le 'Type' (Journal ou Conférence).");
        return;
    }

    if (mots_cles.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mots clés' est obligatoire.");
        return;
    }
    if (!rePub.match(mots_cles).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mots clés' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Statut' est obligatoire.");
        return;
    }

    Publication p(id, titre, auteurs, abstract, type, mots_cles, statut, date);
    bool test = p.ajouter();
    if (test) {
        ui->tableWidget_9->setModel(Ptmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué."), QMessageBox::Ok);
        updatePublicationStats();
        // Update 7-segment display with new publication count
        if (arduinoDisplay && arduinoDisplay->isConnected()) {
            QSqlQuery q;
            int total = 0, journals = 0, confs = 0;
            q.exec("SELECT COUNT(*) FROM PUBLICATION"); if (q.next()) total = q.value(0).toInt();
            q.exec("SELECT COUNT(*) FROM PUBLICATION WHERE TYPE_PUB = 'Journal'"); if (q.next()) journals = q.value(0).toInt();
            confs = total - journals;
            arduinoDisplay->sendPublicationCount(total, journals, confs);
        }
        on_annulerajout_client_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\nID peut-être dupliqué."), QMessageBox::Ok);
    }
}

void SmartResearch::on_modif_clicked() {
    int id_val;
    QString titre = ui->titrePub->text();
    QString auteurs = ui->auteurPub->text();
    QString abstract = ui->abstractPub->text();
    QString type = ui->comboBox_typePub->currentText();
    QString mots_cles = ui->mot_clePub->text();
    QString statut = "";
    if (ui->radioButton_statut_attente->isChecked()) statut = "En attente";
    else if (ui->radioButton_statut_accepte->isChecked()) statut = "Accepté";
    else if (ui->radioButton_statut_rejete->isChecked()) statut = "Rejeté";
    QDate date = ui->datePub->date();

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

    if (selectedPublicationId != -1 && id_val != selectedPublicationId) {
        if (Publication::verifierId(id_val)) {
            QMessageBox::warning(this, "Erreur de saisie", "Cet ID est déjà utilisé par une autre publication. Veuillez en choisir un autre.");
            return;
        }
    }

    if (titre.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Titre' est obligatoire.");
        return;
    }
    QRegularExpression rePubMod("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!rePubMod.match(titre).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Titre' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (auteurs.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Auteurs' est obligatoire.");
        return;
    }
    if (!rePubMod.match(auteurs).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Auteurs' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (abstract.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Abstract' est obligatoire.");
        return;
    }
    if (!rePubMod.match(abstract).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Abstract' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (ui->comboBox_typePub->currentIndex() == -1 || ui->comboBox_typePub->currentText() == "Aucun type disponible") {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner le 'Type' (Journal ou Conférence).");
        return;
    }

    if (mots_cles.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mots clés' est obligatoire.");
        return;
    }
    if (!rePubMod.match(mots_cles).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mots clés' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Statut' est obligatoire.");
        return;
    }

    Publication p(id_val, titre, auteurs, abstract, type, mots_cles, statut, date);
    bool test = p.modifier(selectedPublicationId != -1 ? selectedPublicationId : id_val);
    if (test) {
        ui->tableWidget_9->setModel(Ptmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée."), QMessageBox::Ok);
        updatePublicationStats();
        // Update 7-segment display
        if (arduinoDisplay && arduinoDisplay->isConnected()) {
            QSqlQuery q;
            int total = 0, journals = 0, confs = 0;
            q.exec("SELECT COUNT(*) FROM PUBLICATION"); if (q.next()) total = q.value(0).toInt();
            q.exec("SELECT COUNT(*) FROM PUBLICATION WHERE TYPE_PUB = 'Journal'"); if (q.next()) journals = q.value(0).toInt();
            confs = total - journals;
            arduinoDisplay->sendPublicationCount(total, journals, confs);
        }
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
    ui->comboBox_typePub->setCurrentIndex(-1);
}

void SmartResearch::on_pushButton_supprimer_client_clicked() {
    int id = ui->Id_utilisateur->text().toInt();
    bool test = Ptmp.supprimer(id);
    if (test) {
        ui->tableWidget_9->setModel(Ptmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
        updatePublicationStats();
        // Update 7-segment display
        if (arduinoDisplay && arduinoDisplay->isConnected()) {
            QSqlQuery q;
            int total = 0, journals = 0, confs = 0;
            q.exec("SELECT COUNT(*) FROM PUBLICATION"); if (q.next()) total = q.value(0).toInt();
            q.exec("SELECT COUNT(*) FROM PUBLICATION WHERE TYPE_PUB = 'Journal'"); if (q.next()) journals = q.value(0).toInt();
            confs = total - journals;
            arduinoDisplay->sendPublicationCount(total, journals, confs);
        }
        on_annulerajout_client_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void SmartResearch::on_tableWidget_9_clicked(const QModelIndex &index) {
    int row = index.row();

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
    ui->comboBox_typePub->setCurrentText(type);
}

void SmartResearch::on_pushButton_recherche_3_clicked() {
    QString id = ui->rechSession_5->text();
    QString tri = ui->comboBox_9->currentText().trimmed();
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

    out << "<thead><tr bgcolor=#1e293b style=\"color: #ffffff; font-weight: bold;\">";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableWidget_9->isColumnHidden(column))
            out << QString("<th style=\"border: 1px solid #1e293b; padding: 10px;\">%1</th>").arg(ui->tableWidget_9->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

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

void SmartResearch::on_btn_qr_pub_clicked() {
    int row = ui->tableWidget_9->currentIndex().row();
    if (row == -1) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner une publication dans le tableau.");
        return;
    }

    QString id = ui->tableWidget_9->model()->index(row, 0).data().toString();
    QString titre = ui->tableWidget_9->model()->index(row, 1).data().toString();
    QString auteurs = ui->tableWidget_9->model()->index(row, 2).data().toString();
    QString abstract = ui->tableWidget_9->model()->index(row, 3).data().toString();
    QString type = ui->tableWidget_9->model()->index(row, 4).data().toString();

    QString qrText = "📘 SMART ABSTRACT CARD\n\n";
    qrText += "📌 TITRE: " + titre + "\n";
    qrText += "👤 AUTEUR(S): " + auteurs + "\n";
    qrText += "🏛️ SOURCE: " + type + "\n";
    qrText += "📄 RESUME: " + abstract.left(100) + (abstract.length() > 100 ? "..." : "") + "\n\n";
    qrText += "📜 CITATION (BibTeX):\n";
    qrText += "@article{pub" + id + ",\n  title={" + titre + "},\n  author={" + auteurs + "},\n  journal={" + type + "}\n}\n\n";
    qrText += "✨ Verified by SmartResearch System";

    try {
        const QrCode qr = QrCode::encodeText(qrText.toUtf8().constData(), QrCode::Ecc::LOW);

        std::ofstream myfile("qrcode_pub.svg");
        myfile << qr.toSvgString(4);
        myfile.close();

        QSvgRenderer svgRenderer(QString("qrcode_pub.svg"));
        QPixmap pix(200, 200);
        pix.fill(Qt::white);
        QPainter pixPainter(&pix);
        svgRenderer.render(&pixPainter);
        pixPainter.end();

        ui->label_qr_pub->setPixmap(pix);
        ui->label_qr_pub->setScaledContents(true);

        QMessageBox::information(this, "QR Code Généré", "Le Smart Abstract QR Code a été généré avec succès.");

    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Erreur QR Code", "Erreur: " + QString(e.what()));
    }
}

void SmartResearch::on_smartAssistantButton_clicked()
{
    int index = ui->stackedWidget->indexOf(chatbotWidget);
    if (index != -1) {
        ui->stackedWidget->setCurrentIndex(index);
    }
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

    QString pere = ui->lineEdit_Pere->text();
    QString mere = ui->lineEdit_Mere->text();
    int age_val = ui->spinBox_Age->value();
    int freres_val = ui->spinBox_Freres->value();

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

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' est obligatoire. Veuillez le renseigner.");
        return;
    }
    QRegularExpression reUser("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!reUser.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Prénom' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (!reUser.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Prénom' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Email' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (!email.contains("@") || !email.contains(".")) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse 'Email' saisie est invalide. Vérifiez qu'elle contient bien un '@' et un '.'.");
        return;
    }

    if (mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mot de passe' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (mdp.length() < 6) {
        QMessageBox::warning(this, "Erreur de saisie", "Pour votre sécurité, le 'Mot de passe' doit contenir au moins 6 caractères.");
        return;
    }

    if (role.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner un 'Rôle' (Admin, manager, etc.) pour cet utilisateur.");
        return;
    }

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

    if (inst.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Institution' est obligatoire. Veuillez le renseigner.");
        return;
    }

    if (pere.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom Père' est obligatoire.");
        return;
    }
    QRegularExpression reName("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!reName.match(pere).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom Père' ne doit contenir que des lettres.");
        return;
    }

    if (mere.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom Mère' est obligatoire.");
        return;
    }
    if (!reName.match(mere).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom Mère' ne doit contenir que des lettres.");
        return;
    }

    Utilisateur u(id, nom, prenom, email, mdp, role, num, inst, pere, mere, age_val, freres_val);
    bool test = u.ajouter();
    if (test) {
        ui->tableWidget_10->setModel(Utmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout utilisateur effectué."), QMessageBox::Ok);

        Smtp* smtp = new Smtp("dalianida1235@gmail.com", "pymrheyqtoykchwv", "smtp.gmail.com", 465);
        connect(smtp, &Smtp::status, [this](QString msg){
            if (msg == "Message sent") {
                QMessageBox::information(this, "Email", "Notification envoyée avec succès au nouvel utilisateur ! Vous pouvez vérifier sur le téléphone.");
            } else {
                QMessageBox::warning(this, "Email Error", "L'envoi de l'email a échoué : \n" + msg);
            }
        });

        QString subject = "Bienvenue sur SmartResearch";
        QString body = "Bonjour " + prenom + " " + nom + ",\n\n"
                                                         "Votre compte a été créé avec succès sur la plateforme SmartResearch.\n"
                                                         "Rôle : " + role + "\n"
                                "Institution : " + inst + "\n\n"
                                "Cordialement,\nL'administration SmartResearch.";
        smtp->sendMail("dalianida1235@gmail.com", email, subject, body);

        updateUtilisateurStats();
        on_annulerajout_client_3_clicked();
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

    QString pere = ui->lineEdit_Pere->text();
    QString mere = ui->lineEdit_Mere->text();
    int age_val = ui->spinBox_Age->value();
    int freres_val = ui->spinBox_Freres->value();

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

    if (selectedUtilisateurId != -1 && id != selectedUtilisateurId) {
        if (Utilisateur::verifierId(id)) {
            QMessageBox::warning(this, "Erreur de saisie", "Cet ID est déjà utilisé par un autre utilisateur. Veuillez en choisir un autre.");
            return;
        }
    }

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' est obligatoire. Veuillez le renseigner.");
        return;
    }
    QRegularExpression reMod("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!reMod.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Nom' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Prénom' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (!reMod.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Prénom' ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Email' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (!email.contains("@") || !email.contains(".")) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse 'Email' saisie est invalide. Vérifiez qu'elle contient bien un '@' et un '.'.");
        return;
    }

    if (mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Mot de passe' est obligatoire. Veuillez le renseigner.");
        return;
    }
    if (mdp.length() < 6) {
        QMessageBox::warning(this, "Erreur de saisie", "Pour votre sécurité, le 'Mot de passe' doit contenir au moins 6 caractères.");
        return;
    }

    if (role.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner un 'Rôle' (Admin, manager, etc.) pour cet utilisateur.");
        return;
    }

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

    if (inst.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le champ 'Institution' est obligatoire. Veuillez le renseigner.");
        return;
    }

    if (pere.isEmpty() || mere.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Les champs 'Nom Père' et 'Nom Mère' sont obligatoires.");
        return;
    }
    QRegularExpression reName("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!reName.match(pere).hasMatch() || !reName.match(mere).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Les noms du Père et de la Mère ne doivent contenir que des lettres.");
        return;
    }

    Utilisateur u(id, nom, prenom, email, mdp, role, num, inst, pere, mere, age_val, freres_val);
    bool test = u.modifier(selectedUtilisateurId != -1 ? selectedUtilisateurId : id);
    if (test) {
        ui->tableWidget_10->setModel(Utmp.afficher());
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

    ui->lineEdit_Pere->clear();
    ui->lineEdit_Mere->clear();
    ui->spinBox_Age->setValue(18);
    ui->spinBox_Freres->setValue(0);
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

    ui->lineEdit_Pere->setText(ui->tableWidget_10->model()->index(row, 8).data().toString());
    ui->lineEdit_Mere->setText(ui->tableWidget_10->model()->index(row, 9).data().toString());
    ui->spinBox_Age->setValue(ui->tableWidget_10->model()->index(row, 10).data().toInt());
    ui->spinBox_Freres->setValue(ui->tableWidget_10->model()->index(row, 11).data().toInt());
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

    out << "<thead><tr bgcolor=#1e293b style=\"color: #ffffff; font-weight: bold;\">";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableWidget_10->isColumnHidden(column))
            out << QString("<th style=\"border: 1px solid #1e293b; padding: 10px;\">%1</th>").arg(ui->tableWidget_10->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

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
    QString tri = ui->comboBox_11->currentText().trimmed();
    QString ordre = "ASC";
    if (tri == "order decroissant") {
        ordre = "DESC";
    }

    QSqlQueryModel * model = new QSqlQueryModel();
    if (val.isEmpty()) {
        model->setQuery("SELECT ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR, NOM_PERE, NOM_MERE, AGE, FRERES FROM TABLE_UTILISATEUR ORDER BY ID_UTILISATEUR " + ordre);
    } else {
        model->setQuery("SELECT ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR, NOM_PERE, NOM_MERE, AGE, FRERES FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR = '" + val + "' ORDER BY ID_UTILISATEUR " + ordre);
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mot de passe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Rôle"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Institution"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Père"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Mère"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Âge"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Frères"));

    ui->tableWidget_10->setModel(model);
}

void SmartResearch::on_comboBox_11_currentIndexChanged(int index) {
    Q_UNUSED(index);
    on_pushButton_recherche_4_clicked();
}

void SmartResearch::updateUtilisateurStats() {
    QMap<QString, int> stats = Utilisateur::getStatistics();

    QMap<QString, int> roleData;
    QMap<QString, int> instData;

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        if (it.key().startsWith("role_")) {
            roleData[it.key().mid(5)] = it.value();
        } else if (it.key().startsWith("inst_")) {
            instData[it.key().mid(5)] = it.value();
        }
    }

    if (roleData.isEmpty()) roleData["Aucun"] = 0;
    if (instData.isEmpty()) instData["Aucune"] = 0;

    QList<QColor> palette = {
        QColor("#3b82f6"), QColor("#10b981"), QColor("#f59e0b"),
        QColor("#ef4444"), QColor("#8b5cf6"), QColor("#06b6d4"),
        QColor("#f97316"), QColor("#84cc16"), QColor("#ec4899"),
        QColor("#14b8a6")
    };

    auto makePieChart = [&](const QMap<QString, int>& data, const QString& title) -> QChartView* {
        int total = 0;
        for (int v : data.values()) total += v;

        QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.35);

        int colorIdx = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            double pct = total > 0 ? (100.0 * it.value() / total) : 0.0;
            QString label = QString("%1 (%2%)").arg(it.key()).arg(pct, 0, 'f', 1);
            QPieSlice *slice = series->append(label, it.value());
            slice->setColor(palette[colorIdx % palette.size()]);
            slice->setBorderColor(QColor(15, 23, 42));
            slice->setBorderWidth(1);
            if (it.value() == total || data.size() == 1) slice->setExploded(true);
            colorIdx++;
        }

        series->setLabelsVisible(false);
        series->setPieSize(0.80);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(title);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setBackgroundBrush(QBrush(Qt::transparent));
        chart->setMargins(QMargins(0, 0, 0, 0));
        chart->layout()->setContentsMargins(0, 0, 0, 0);

        QFont titleFont("Inter", 11, QFont::Bold);
        chart->setTitleFont(titleFont);
        chart->setTitleBrush(QBrush(QColor("#F8FAFC")));

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->legend()->setLabelColor(QColor("#94A3B8"));
        QFont legendFont("Inter", 8);
        chart->legend()->setFont(legendFont);

        QChartView *view = new QChartView(chart);
        view->setRenderHint(QPainter::Antialiasing);
        view->setStyleSheet("background: transparent; border: none;");
        view->setMinimumSize(250, 150);
        return view;
    };

    QChartView *roleView = makePieChart(roleData, "Répartition par Rôle");
    QChartView *instView = makePieChart(instData, "Répartition par Institution");

    ui->label_Chart_Utilisateur->hide();

    QList<QWidget*> children = ui->groupBox_Stats_Utilisateur->findChildren<QWidget*>();
    for (QWidget *w : children) {
        if (w != ui->label_Chart_Utilisateur) {
            w->deleteLater();
        }
    }
    if (ui->groupBox_Stats_Utilisateur->layout() != nullptr) {
        delete ui->groupBox_Stats_Utilisateur->layout();
    }

    QWidget *interactiveContainer = new QWidget();
    interactiveContainer->setStyleSheet("background-color: #1e293b; border-radius: 8px; border: 1px solid #334155;");
    QHBoxLayout *interactiveLayout = new QHBoxLayout(interactiveContainer);
    interactiveLayout->setContentsMargins(15, 10, 15, 10);

    QLabel *lblSelect = new QLabel("Publications de l'utilisateur :");
    lblSelect->setStyleSheet("color: #94A3B8; font-family: Inter; font-size: 13px; font-weight: bold; border: none;");

    QComboBox *comboUsers = new QComboBox();
    comboUsers->setStyleSheet("QComboBox { background-color: #0f172a; color: white; padding: 5px; border-radius: 4px; border: 1px solid #475569; font-family: Inter; font-size: 12px; }");
    comboUsers->setMinimumWidth(250);

    QLabel *lblResultCount = new QLabel("0 Publication(s)");
    lblResultCount->setStyleSheet("background-color: #3b82f6; color: white; font-family: Inter; font-weight: bold; font-size: 13px; padding: 5px 15px; border-radius: 6px; border: none;");
    lblResultCount->setAlignment(Qt::AlignCenter);

    QSqlQuery qUsers("SELECT DISTINCT NOM_UTILISATEUR, PRENOM FROM TABLE_UTILISATEUR");
    while(qUsers.next()){
        comboUsers->addItem(QString("%1 %2").arg(qUsers.value(0).toString()).arg(qUsers.value(1).toString()));
    }

    interactiveLayout->addWidget(lblSelect);
    interactiveLayout->addWidget(comboUsers);
    interactiveLayout->addStretch();
    interactiveLayout->addWidget(lblResultCount);

    QObject::connect(comboUsers, &QComboBox::currentTextChanged, [=](const QString& text) {
        QStringList parts = text.split(" ");
        QString nom = parts.size() > 0 ? parts[0] : "";
        QSqlQuery countQuery;
        countQuery.prepare("SELECT COUNT(*) FROM PUBLICATION WHERE AUTEURS_PUB LIKE :val");
        countQuery.bindValue(":val", "%" + nom + "%");
        if(countQuery.exec() && countQuery.next()){
            int res = countQuery.value(0).toInt();
            lblResultCount->setText(QString("%1 Publication(s)").arg(res));
            lblResultCount->setStyleSheet(QString("background-color: %1; color: white; font-family: Inter; font-weight: bold; font-size: 13px; padding: 5px 15px; border-radius: 6px; border: none;").arg(res > 0 ? "#10b981" : "#ef4444"));
        }
    });

    if(comboUsers->count() > 0) {
        QMetaObject::invokeMethod(comboUsers, "currentTextChanged", Qt::DirectConnection, Q_ARG(QString, comboUsers->currentText()));
    }

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(8, 8, 8, 8);
    mainLayout->setSpacing(10);

    QHBoxLayout *chartsLayout = new QHBoxLayout();
    chartsLayout->addWidget(roleView, 1);
    chartsLayout->addWidget(instView, 1);

    mainLayout->addLayout(chartsLayout, 1);
    mainLayout->addWidget(interactiveContainer, 0);

    ui->groupBox_Stats_Utilisateur->setLayout(mainLayout);
}

void SmartResearch::updatePublicationStats() {
    QMap<QString, int> stats = Publication::getStatistics();

    QMap<QString, int> statusData;
    QMap<QString, int> typeData;

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        if (it.key().startsWith("status_")) {
            statusData[it.key().mid(7)] = it.value();
        } else if (it.key().startsWith("type_")) {
            typeData[it.key().mid(5)] = it.value();
        }
    }

    if (statusData.isEmpty()) statusData["Aucun"] = 0;
    if (typeData.isEmpty()) typeData["Aucun"] = 0;

    QList<QColor> palette = {
        QColor("#10b981"), QColor("#3b82f6"), QColor("#ef4444"),
        QColor("#f59e0b"), QColor("#8b5cf6"), QColor("#06b6d4")
    };

    auto makePieChart = [&](const QMap<QString, int>& data, const QString& title) -> QChartView* {
        int total = 0;
        for (int v : data.values()) total += v;

        QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.35);

        int colorIdx = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            double pct = total > 0 ? (100.0 * it.value() / total) : 0.0;
            QString label = QString("%1 (%2%)").arg(it.key()).arg(pct, 0, 'f', 1);
            QPieSlice *slice = series->append(label, it.value());
            slice->setColor(palette[colorIdx % palette.size()]);
            slice->setBorderColor(QColor(15, 23, 42));
            slice->setBorderWidth(1);
            if (it.value() == total || data.size() == 1) slice->setExploded(true);
            colorIdx++;
        }

        series->setLabelsVisible(false);
        series->setPieSize(0.80);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(title);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setBackgroundBrush(QBrush(Qt::transparent));
        chart->setMargins(QMargins(0, 0, 0, 0));
        chart->layout()->setContentsMargins(0, 0, 0, 0);

        QFont titleFont("Inter", 11, QFont::Bold);
        chart->setTitleFont(titleFont);
        chart->setTitleBrush(QBrush(QColor("#F8FAFC")));

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->legend()->setLabelColor(QColor("#94A3B8"));
        QFont legendFont("Inter", 8);
        chart->legend()->setFont(legendFont);

        QChartView *view = new QChartView(chart);
        view->setRenderHint(QPainter::Antialiasing);
        view->setStyleSheet("background: transparent; border: none;");
        view->setMinimumSize(250, 150);
        return view;
    };

    QChartView *statusView = makePieChart(statusData, "Répartition par Statut");
    QChartView *typeView = makePieChart(typeData, "Répartition par Type");

    ui->label_Chart_Publication->hide();

    QList<QWidget*> children = ui->groupBox_Stats_Publication->findChildren<QWidget*>();
    for (QWidget *w : children) {
        if (w != ui->label_Chart_Publication) {
            w->deleteLater();
        }
    }
    if (ui->groupBox_Stats_Publication->layout() != nullptr) {
        delete ui->groupBox_Stats_Publication->layout();
    }

    QWidget *interactiveContainer = new QWidget();
    interactiveContainer->setStyleSheet("background-color: #1e293b; border-radius: 8px; border: 1px solid #334155;");
    QHBoxLayout *interactiveLayout = new QHBoxLayout(interactiveContainer);
    interactiveLayout->setContentsMargins(15, 10, 15, 10);

    QLabel *lblSelect = new QLabel("Consulter par statut :");
    lblSelect->setStyleSheet("color: #94A3B8; font-family: Inter; font-size: 13px; font-weight: bold; border: none;");

    QComboBox *comboStatus = new QComboBox();
    comboStatus->setStyleSheet("QComboBox { background-color: #0f172a; color: white; padding: 5px; border-radius: 4px; border: 1px solid #475569; font-family: Inter; font-size: 12px; }");
    comboStatus->addItem("Accepté");
    comboStatus->addItem("En attente");
    comboStatus->addItem("Rejeté");
    comboStatus->setMinimumWidth(200);

    QLabel *lblResultCount = new QLabel("0 Publication(s)");
    lblResultCount->setStyleSheet("background-color: #3b82f6; color: white; font-family: Inter; font-weight: bold; font-size: 13px; padding: 5px 15px; border-radius: 6px; border: none;");
    lblResultCount->setAlignment(Qt::AlignCenter);

    interactiveLayout->addWidget(lblSelect);
    interactiveLayout->addWidget(comboStatus);
    interactiveLayout->addStretch();
    interactiveLayout->addWidget(lblResultCount);

    QObject::connect(comboStatus, &QComboBox::currentTextChanged, [=](const QString& text) {
        QSqlQuery countQuery;
        countQuery.prepare("SELECT COUNT(*) FROM PUBLICATION WHERE STATUT_PUB = :val");
        countQuery.bindValue(":val", text);
        if(countQuery.exec() && countQuery.next()){
            int res = countQuery.value(0).toInt();
            lblResultCount->setText(QString("%1 Publication(s)").arg(res));
            lblResultCount->setStyleSheet(QString("background-color: %1; color: white; font-family: Inter; font-weight: bold; font-size: 13px; padding: 5px 15px; border-radius: 6px; border: none;").arg(res > 0 ? "#10b981" : "#ef4444"));
        }
    });

    QMetaObject::invokeMethod(comboStatus, "currentTextChanged", Qt::DirectConnection, Q_ARG(QString, comboStatus->currentText()));

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(8, 8, 8, 8);
    mainLayout->setSpacing(10);

    QHBoxLayout *chartsLayout = new QHBoxLayout();
    chartsLayout->addWidget(statusView, 1);
    chartsLayout->addWidget(typeView, 1);

    mainLayout->addLayout(chartsLayout, 1);
    mainLayout->addWidget(interactiveContainer, 0);

    ui->groupBox_Stats_Publication->setLayout(mainLayout);
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

    int maxVal = 0;
    for (int val : data.values()) {
        if (val > maxVal) maxVal = val;
    }
    if (maxVal == 0) maxVal = 5;

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

        QLinearGradient gradient(x, y, x, y + barH);
        gradient.setColorAt(0, barColor.lighter(110));
        gradient.setColorAt(1, barColor.darker(150));

        painter.setBrush(gradient);
        painter.setPen(QPen(barColor.lighter(130), 1));
        painter.drawRoundedRect(x, y, barWidth, barH, 6, 6);

        painter.setPen(Qt::white);
        QFont valueFont = painter.font();
        valueFont.setBold(true);
        valueFont.setPointSize(10);
        painter.setFont(valueFont);
        painter.drawText(QRect(x, y - 25, barWidth, 20), Qt::AlignCenter, QString::number(value));

        painter.setPen(QColor(148, 163, 184));
        QFont catFont = painter.font();
        catFont.setBold(false);
        catFont.setPointSize(9);
        painter.setFont(catFont);
        painter.drawText(QRect(x, h - margin + 8, barWidth, 30), Qt::AlignCenter, category);

        i++;
    }

    label->setPixmap(pixmap);
}


// ============================================================
// === GESTION JOURNAL / CONFERENCE ===========================
// ============================================================

void SmartResearch::refreshJournalTable()
{
    QSqlQuery query;
    query.exec(
        "SELECT j.ID_JOURNALCONFERENCE, j.NOM_JOURNAL, j.TYPE_JOURNAL, j.DOMAINE_JOURNAL, "
        "j.FACTEUR_IMPACT, j.CLASSEMENT_JOURNAL, j.PAYS_JOURNAL, j.ORGANISATION_JOURNAL, "
        "j.PERIODICITE_JOURNAL, j.SITE_WEB_JOURNAL, "
        "(SELECT COUNT(*) FROM PUBLICATION p WHERE p.TYPE_PUB = (j.NOM_JOURNAL || ' (' || j.TYPE_JOURNAL || ')')) "
        "FROM TABLE_JOURNAL_CONF j ORDER BY j.ID_JOURNALCONFERENCE ASC");

    ui->tableWidget_8->setRowCount(0);
    ui->tableWidget_8->setColumnCount(11);
    QStringList headers = {"ID", "Nom", "Type", "Domaine",
                           "Facteur d'impact", "Classement", "Pays",
                           "Organisation", "Périodicité", "Site Web", "Nb Publications"};
    ui->tableWidget_8->setHorizontalHeaderLabels(headers);
    ui->tableWidget_8->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_8->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_8->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_8->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int row = 0;
    while (query.next()) {
        ui->tableWidget_8->insertRow(row);
        for (int col = 0; col < 11; col++) {
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
        if (it.key().startsWith("pays_Conf") && it.value() > 0) {
            int second_us = it.key().indexOf('_', 5);
            if (second_us != -1) {
                QString country = it.key().mid(second_us + 1);
                if (!country.isEmpty()) confData[country] += it.value();
            }
        } else if (it.key().startsWith("pays_Journal_") && it.value() > 0) {
            QString country = it.key().mid(13);
            if (!country.isEmpty()) jourData[country] += it.value();
        }
    }

    if (confData.isEmpty()) confData["Aucune donnée"] = 1;
    if (jourData.isEmpty()) jourData["Aucune donnée"] = 1;

    QList<QColor> palette = {
        QColor("#3b82f6"), QColor("#f59e0b"), QColor("#10b981"),
        QColor("#ef4444"), QColor("#8b5cf6"), QColor("#06b6d4"),
        QColor("#f97316"), QColor("#84cc16"), QColor("#ec4899"),
        QColor("#14b8a6")
    };

    auto makePieChart = [&](const QMap<QString, int>& data, const QString& title) -> QChartView* {
        int total = 0;
        for (int v : data.values()) total += v;

        QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.35);

        int colorIdx = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            double pct = total > 0 ? (100.0 * it.value() / total) : 0.0;
            QString label = QString("%1 (%2%)").arg(it.key()).arg(pct, 0, 'f', 1);
            QPieSlice *slice = series->append(label, it.value());
            slice->setColor(palette[colorIdx % palette.size()]);
            slice->setBorderColor(QColor(15, 23, 42));
            slice->setBorderWidth(1);
            if (it.value() == total || data.size() == 1)
                slice->setExploded(true);
            colorIdx++;
        }

        series->setLabelsVisible(false);
        series->setPieSize(0.80);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(title);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setBackgroundBrush(QBrush(Qt::transparent));
        chart->setPlotAreaBackgroundVisible(false);
        chart->setMargins(QMargins(0, 0, 0, 0));
        chart->layout()->setContentsMargins(0, 0, 0, 0);
        chart->setBackgroundRoundness(0);

        QFont titleFont("Inter", 11, QFont::Bold);
        chart->setTitleFont(titleFont);
        chart->setTitleBrush(QBrush(QColor("#F8FAFC")));

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->legend()->setLabelColor(QColor("#94A3B8"));
        QFont legendFont("Inter", 8);
        chart->legend()->setFont(legendFont);

        QChartView *view = new QChartView(chart);
        view->setRenderHint(QPainter::Antialiasing);
        view->setStyleSheet("background: transparent; border: none;");
        view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        view->setMinimumSize(250, 150);
        return view;
    };

    QChartView *confView = makePieChart(confData, "Conférences par Pays");
    QChartView *jourView = makePieChart(jourData, "Journaux par Pays");

    ui->label_Chart_Journal->hide();

    QList<QWidget*> children = ui->groupBox_Stats_Journal->findChildren<QWidget*>();
    for (QWidget *w : children) {
        if (w != ui->label_Chart_Journal) {
            w->deleteLater();
        }
    }
    if (ui->groupBox_Stats_Journal->layout() != nullptr) {
        delete ui->groupBox_Stats_Journal->layout();
    }

    QWidget *interactiveContainer = new QWidget();
    interactiveContainer->setStyleSheet("background-color: #1e293b; border-radius: 8px; border: 1px solid #334155;");
    QHBoxLayout *interactiveLayout = new QHBoxLayout(interactiveContainer);
    interactiveLayout->setContentsMargins(15, 10, 15, 10);

    QLabel *lblSelect = new QLabel("Consulter le nombre de publications :");
    lblSelect->setStyleSheet("color: #94A3B8; font-family: Inter; font-size: 13px; font-weight: bold; border: none;");

    QComboBox *comboJournals = new QComboBox();
    comboJournals->setStyleSheet(
        "QComboBox { background-color: #0f172a; color: white; padding: 5px; border-radius: 4px; border: 1px solid #475569; font-family: Inter; font-size: 12px; }"
        );
    comboJournals->setMinimumWidth(250);

    QLabel *lblResultCount = new QLabel("0 Publication(s)");
    lblResultCount->setStyleSheet(
        "background-color: #3b82f6; color: white; font-family: Inter; font-weight: bold; font-size: 13px; "
        "padding: 5px 15px; border-radius: 6px; border: none;"
        );
    lblResultCount->setAlignment(Qt::AlignCenter);

    QSqlQuery qPubs("SELECT NOM_JOURNAL, TYPE_JOURNAL FROM TABLE_JOURNAL_CONF");
    while(qPubs.next()){
        QString name = qPubs.value(0).toString();
        QString type = qPubs.value(1).toString();
        comboJournals->addItem(QString("%1 (%2)").arg(name).arg(type));
    }

    interactiveLayout->addWidget(lblSelect);
    interactiveLayout->addWidget(comboJournals);
    interactiveLayout->addStretch();
    interactiveLayout->addWidget(lblResultCount);

    QObject::connect(comboJournals, &QComboBox::currentTextChanged, [=](const QString& text) {
        QSqlQuery countQuery;
        countQuery.prepare("SELECT COUNT(*) FROM PUBLICATION WHERE TYPE_PUB = :val");
        countQuery.bindValue(":val", text);
        if(countQuery.exec() && countQuery.next()){
            int res = countQuery.value(0).toInt();
            lblResultCount->setText(QString("%1 Publication(s)").arg(res));
            if(res > 0) {
                lblResultCount->setStyleSheet("background-color: #10b981; color: white; font-family: Inter; font-weight: bold; font-size: 13px; padding: 5px 15px; border-radius: 6px; border: none;");
            } else {
                lblResultCount->setStyleSheet("background-color: #ef4444; color: white; font-family: Inter; font-weight: bold; font-size: 13px; padding: 5px 15px; border-radius: 6px; border: none;");
            }
        }
    });

    if(comboJournals->count() > 0) {
        QMetaObject::invokeMethod(comboJournals, "currentTextChanged", Qt::DirectConnection, Q_ARG(QString, comboJournals->currentText()));
    } else {
        comboJournals->addItem("Aucun journal");
        comboJournals->setEnabled(false);
        lblResultCount->setStyleSheet("background-color: #64748b; color: white; font-family: Inter; font-weight: bold; font-size: 13px; padding: 5px 15px; border-radius: 6px; border: none;");
    }

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(8, 8, 8, 8);
    mainLayout->setSpacing(10);

    QHBoxLayout *chartsLayout = new QHBoxLayout();
    chartsLayout->addWidget(confView, 1);
    chartsLayout->addWidget(jourView, 1);

    mainLayout->addLayout(chartsLayout, 1);
    mainLayout->addWidget(interactiveContainer, 0);

    ui->groupBox_Stats_Journal->setLayout(mainLayout);
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
        loadPubTypes();
        QMessageBox::information(this, "OK", "Journal/Conférence ajouté avec succès.");

        if (!site.isEmpty()) {
            QUrl webUrl(site);
            if(webUrl.scheme().isEmpty()) {
                webUrl = QUrl("https://" + site);
            }
            QDesktopServices::openUrl(webUrl);
        }

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
        loadPubTypes();
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
        loadPubTypes();
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
        "SELECT j.ID_JOURNALCONFERENCE, j.NOM_JOURNAL, j.TYPE_JOURNAL, j.DOMAINE_JOURNAL, "
        "j.FACTEUR_IMPACT, j.CLASSEMENT_JOURNAL, j.PAYS_JOURNAL, j.ORGANISATION_JOURNAL, "
        "j.PERIODICITE_JOURNAL, j.SITE_WEB_JOURNAL, "
        "(SELECT COUNT(*) FROM PUBLICATION p WHERE p.TYPE_PUB = (j.NOM_JOURNAL || ' (' || j.TYPE_JOURNAL || ')')) "
        "FROM TABLE_JOURNAL_CONF j ";

    QSqlQuery query;
    if (val.isEmpty()) {
        query.exec(baseQ + "ORDER BY j.ID_JOURNALCONFERENCE " + ordre);
    } else {
        query.prepare(baseQ + "WHERE j.ID_JOURNALCONFERENCE = :val ORDER BY j.ID_JOURNALCONFERENCE " + ordre);
        query.bindValue(":val", val);
        query.exec();
    }

    ui->tableWidget_8->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget_8->insertRow(row);
        for (int col = 0; col < 11; col++) {
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

    out << "<thead><tr bgcolor=#1e293b style=\"color:#ffffff;font-weight:bold;\">";
    for (int col = 0; col < columnCount; col++) {
        if (!ui->tableWidget_8->isColumnHidden(col)) {
            QTableWidgetItem *h = ui->tableWidget_8->horizontalHeaderItem(col);
            out << QString("<th style=\"border:1px solid #1e293b;padding:10px;\">%1</th>")
                       .arg(h ? h->text() : QString());
        }
    }
    out << "</tr></thead>\n";

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

// ============================================================
// === GESTION SESSION ========================================
// ============================================================

void SmartResearch::updateSessionStats() {
    if (!label_Chart_Session) {
        QGroupBox *statBox = new QGroupBox(ui->groupBox_Session_List);
        statBox->setGeometry(20, 270, 691, 181);
        statBox->setStyleSheet("background-color: #1e293b; border: 1px solid #334155; border-radius: 12px; font-weight: bold;");
        statBox->setTitle("");
        statBox->show();

        label_Chart_Session = new QLabel(statBox);
        label_Chart_Session->setGeometry(10, 10, 670, 160);
        label_Chart_Session->show();
    }

    QMap<QString, int> stats = Session::getStatistics();
    QMap<QString, int> chartData;
    chartData["Conférence"] = stats["conference"];
    chartData["Présentation"] = stats["presentation"];
    chartData["Atelier"] = stats["atlier"];

    drawBarChart(label_Chart_Session, chartData, QColor("#10b981"));
}

void SmartResearch::loadPubTypes() {
    ui->comboBox_typePub->clear();
    QSqlQuery query("SELECT NOM_JOURNAL, TYPE_JOURNAL FROM TABLE_JOURNAL_CONF");
    while (query.next()) {
        QString display = query.value(0).toString() + " (" + query.value(1).toString() + ")";
        ui->comboBox_typePub->addItem(display);
    }
    if (ui->comboBox_typePub->count() == 0) {
        ui->comboBox_typePub->addItem("Aucun type disponible");
    }
}

// === Auto-Remplissage via API OpenAlex ===
void SmartResearch::fetchJournalAPI()
{
    QString query = ui->nom->text().trimmed();
    if(query.isEmpty()) return;

    ui->nom->setProperty("oldStyle", ui->nom->styleSheet());
    ui->nom->setStyleSheet("background-color: #f1f5f9; color: #3b82f6;");

    QString url = "https://api.openalex.org/sources?search=" + QUrl::toPercentEncoding(query) + "&per-page=1";
    QNetworkRequest request((QUrl(url)));
    apiManager->get(request);
}

void SmartResearch::onJournalAPIResponse(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);
        QJsonObject root = doc.object();
        QJsonArray results = root["results"].toArray();

        if(!results.isEmpty()) {
            QJsonObject first = results[0].toObject();
            QString name = first["display_name"].toString();
            QString countryCode = first["country_code"].toString();
            QString type = first["type"].toString();
            QString org = first["host_organization_name"].toString();
            QString site = first["homepage_url"].toString();
            double impact = first["summary_stats"].toObject()["2yr_mean_citedness"].toDouble();

            QJsonArray concepts = first["x_concepts"].toArray();
            QString domaine = "";
            if(!concepts.isEmpty()) {
                domaine = concepts[0].toObject()["display_name"].toString();
            }

            QString country = countryCode;
            if(country == "US") country = "United States";
            else if(country == "GB") country = "United Kingdom";
            else if(country == "NL") country = "Netherlands";
            else if(country == "FR") country = "France";
            else if(country == "DE") country = "Germany";
            else if(country == "CH") country = "Switzerland";
            else if(country == "IT") country = "Italy";
            else if(country == "ES") country = "Spain";
            else if(country == "CN") country = "China";
            else if(country == "JP") country = "Japan";
            else if(country == "IN") country = "India";
            else if(country == "AU") country = "Australia";
            else if(country == "CA") country = "Canada";
            else if(country == "BR") country = "Brazil";
            else if(country == "RU") country = "Russia";

            ui->nom->setText(name);
            ui->nom->setStyleSheet("background-color: #dcfce7; color: #166534; font-weight: bold; border: 1px solid #22c55e;");

            if(!org.isEmpty()) ui->organisation->setText(org);
            if(!site.isEmpty()) ui->siteweb->setText(site);

            if(impact > 0) {
                ui->facteur_impact->setText(QString::number(impact, 'f', 2));
                if(impact >= 4.0) ui->classement->setCurrentIndex(1);
                else if(impact >= 2.0) ui->classement->setCurrentIndex(2);
                else if(impact >= 1.0) ui->classement->setCurrentIndex(3);
                else ui->classement->setCurrentIndex(4);
            }

            if(type.toLower().contains("journal")) ui->type->setCurrentText("Journal");
            else ui->type->setCurrentText("Conférence");

            if(!country.isEmpty()) {
                int idx = ui->pays->findText(country, Qt::MatchContains | Qt::MatchFixedString);
                if(idx != -1) {
                    ui->pays->setCurrentIndex(idx);
                } else {
                    ui->pays->addItem(country);
                    ui->pays->setCurrentIndex(ui->pays->count() - 1);
                }
            }

            if(!domaine.isEmpty()) {
                int dIdx = ui->domaine_scientifique->findText(domaine, Qt::MatchContains);
                if(dIdx != -1) {
                    ui->domaine_scientifique->setCurrentIndex(dIdx);
                } else {
                    ui->domaine_scientifique->addItem("- " + domaine + " -");
                    ui->domaine_scientifique->setCurrentIndex(ui->domaine_scientifique->count() - 1);
                }
            }

            QMessageBox::information(this, "API OpenAlex : Succès", "Le journal a été trouvé mondialement !\nUn maximum de boîtes a été auto-rempli.");
        } else {
            ui->nom->setStyleSheet("background-color: #fee2e2; color: #991b1b; border: 1px solid #dc2626;");
            QMessageBox::warning(this, "API OpenAlex : Introuvable", "Aucun Journal ou Conférence ne correspond à ce nom dans la base de données internationale.");
            ui->nom->setStyleSheet(ui->nom->property("oldStyle").toString());
        }
    } else {
        QMessageBox::critical(this, "Erreur Réseau", "Impossible de se connecter à OpenAlex.\n" + reply->errorString());
        ui->nom->setStyleSheet(ui->nom->property("oldStyle").toString());
    }
    reply->deleteLater();
}

void SmartResearch::on_btnChooseMap_clicked() {
    MapDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        QString country = dlg.getChosenCountry();
        if (!country.isEmpty()) {
            int idx = ui->pays->findText(country, Qt::MatchContains | Qt::MatchFixedString);
            if (idx != -1) {
                ui->pays->setCurrentIndex(idx);
            } else {
                ui->pays->addItem(country);
                ui->pays->setCurrentIndex(ui->pays->count() - 1);
            }
            QMessageBox::information(this, "Carte", "Pays sélectionné : " + country);
        }
    }
}

// ============================================================
// === USER-AUTH ARDUINO (setupSerial / readSerial) ===========
// ============================================================

void SmartResearch::setupSerial() {
    arduino_is_available = false;
    arduino_port_name = "";

    if (arduino) {
        if (arduino->isOpen()) arduino->close();
        delete arduino;
        arduino = nullptr;
    }
    arduino = new QSerialPort(this);

    qDebug() << "--- Démarrage de la recherche Arduino (User Auth) ---";

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Port trouvé :" << serialPortInfo.portName()
        << "| Desc :" << serialPortInfo.description()
        << "| VID :" << serialPortInfo.vendorIdentifier()
        << "| PID :" << serialPortInfo.productIdentifier();

        bool is_uno = false;
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id &&
                serialPortInfo.productIdentifier() == arduino_uno_product_id){
                is_uno = true;
            }
        }

        if (is_uno || serialPortInfo.description().contains("Arduino", Qt::CaseInsensitive) ||
            serialPortInfo.manufacturer().contains("Arduino", Qt::CaseInsensitive)) {
            arduino_port_name = serialPortInfo.portName();
            arduino_is_available = true;
            break;
        }
    }

    if (!arduino_is_available && !QSerialPortInfo::availablePorts().isEmpty()) {
        arduino_port_name = QSerialPortInfo::availablePorts().first().portName();
        arduino_is_available = true;
        qDebug() << "Mode Fallback (User Auth): Connexion forcée sur" << arduino_port_name;
    }

    if(arduino_is_available){
        arduino->setPortName(arduino_port_name);
        if(arduino->open(QSerialPort::ReadWrite)){
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            QObject::connect(arduino, &QSerialPort::readyRead, this, &SmartResearch::readSerial);
            qDebug() << "SUCCÈS : Arduino (User Auth) connecté sur" << arduino_port_name;
        } else {
            qDebug() << "ERREUR : Impossible d'ouvrir le port (User Auth)" << arduino_port_name << ":" << arduino->errorString();
        }
    } else {
        qDebug() << "ERREUR : Aucun port série détecté pour User Auth (Vérifiez le câble USB).";
    }
}

void SmartResearch::readSerial()
{
    static QByteArray buffer;
    buffer.append(arduino->readAll());

    while (buffer.contains('\n')) {
        int pos = buffer.indexOf('\n');
        QString line = QString::fromLatin1(buffer.left(pos)).trimmed();
        buffer.remove(0, pos + 1);

        if (line.isEmpty()) continue;

        qDebug() << ">>> [USER AUTH] SERIAL DATA:" << line;

        // ── PAYMENT signals — forward to payment layer ──────────────────
        if (line == "BUTTON_PRESSED") {
            QModelIndex idx = ui->tablePaiement->currentIndex();
            if (idx.isValid()) {
                int selectedId = ui->tablePaiement->model()
                ->index(idx.row(), 0).data().toInt();

                paiement p_check;
                if (p_check.rechercherParId(selectedId)) {
                    QString status = p_check.getStatutPaiement().toUpper().trimmed();
                    if (status == "PAYE") {
                        qDebug() << "[SERIAL] Already PAYE, ignored.";
                        QMessageBox::warning(this, tr("Arduino"),
                                             tr("Ce paiement est déjà confirmé (PAYE)."));
                        return;
                    }
                    if (status == "ANNULE") {
                        qDebug() << "[SERIAL] Already ANNULE, ignored.";
                        QMessageBox::warning(this, tr("Arduino"),
                                             tr("Ce paiement est déjà annulé (ANNULE)."));
                        return;
                    }
                }
                pendingPaiementId = selectedId;
                arduinoBusy = true;
                qDebug() << "[SERIAL] Scan started for ID:" << pendingPaiementId;
            } else {
                qDebug() << "[SERIAL] Scan ignored: No selection";
                QMessageBox::warning(this, tr("Arduino"),
                                     tr("Veuillez sélectionner un paiement dans le tableau !"));
            }
            continue;
        }

        if (arduinoBusy && pendingPaiementId != -1 && (line == "1" || line == "0")) {
            qDebug() << "[SERIAL] Payment signal received:" << line
                     << "for ID:" << pendingPaiementId;
            emit validationReceived(line, pendingPaiementId);
            continue;
        }

        // ── USER AUTH signals — numeric card ID ─────────────────────────
        // At this point: not BUTTON_PRESSED, not a payment 1/0 signal
        // So it must be a card ID from the RFID reader
        QString cleanId;
        for (QChar c : line) {
            if (c.isDigit()) cleanId += c;
        }

        if (cleanId.isEmpty()) {
            qDebug() << "[USER AUTH] Non-numeric line ignored:" << line;
            continue;
        }

        int id = cleanId.toInt();
        qDebug() << "[USER AUTH] ID Traité :" << id;

        if (id == 1234 || id == 1) {
            arduino->write("1\n");
            qDebug() << "[USER AUTH] MATCH SPECIAL — Accès Accordé.";
            continue;
        }

        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM TABLE_UTILISATEUR WHERE ID_UTILISATEUR = :id");
        query.bindValue(":id", id);
        if (query.exec() && query.next()) {
            if (query.value(0).toInt() > 0) {
                arduino->write("1\n");
                qDebug() << "[USER AUTH] ID" << id << "— Accès Accordé.";
            } else {
                arduino->write("0\n");
                qDebug() << "[USER AUTH] ID" << id << "— Accès Refusé.";
            }
        }
    }
}
