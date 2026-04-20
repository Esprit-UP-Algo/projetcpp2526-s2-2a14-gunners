#include "gestionsession.h"
#include "ui_smartresearch.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QListWidgetItem>
#include <QDate>

GestionSession::GestionSession(Ui::SmartResearch *ui, QObject *parent)
    : QObject(parent)
    , ui(ui)
{
    // Initial loading
    loadAllPublications();
    loadAllReviewers();
    loadSessionsTable();

    // Connections
    connect(ui->tableWidget_Sessions, &QTableWidget::itemClicked, this, &GestionSession::on_tableWidget_Sessions_itemClicked);
    connect(ui->btn_AssocierPublications, &QPushButton::clicked, this, &GestionSession::on_btn_AssocierPublications_clicked);
    connect(ui->btn_AssocierReviewers, &QPushButton::clicked, this, &GestionSession::on_btn_AssocierReviewers_clicked);
    connect(ui->btn_RetirerPub, &QPushButton::clicked, this, &GestionSession::on_btn_RetirerPub_clicked);
    connect(ui->btn_RetirerRev, &QPushButton::clicked, this, &GestionSession::on_btn_RetirerRev_clicked);
    connect(ui->btn_Enregistrer, &QPushButton::clicked, this, &GestionSession::on_btn_Enregistrer_clicked);
    connect(ui->rechercheSession, &QPushButton::clicked, this, &GestionSession::on_rechercheSession_clicked);
    connect(ui->quitterSession, &QPushButton::clicked, this, &GestionSession::on_quitterSession_clicked);
    connect(ui->annuler_2, &QPushButton::clicked, this, &GestionSession::on_annuler_2_clicked);
}

GestionSession::~GestionSession()
{
}

void GestionSession::loadAllPublications()
{
    ui->list_Publications->clear();
    QSqlQuery query("SELECT ID_PUB, TITRE_PUB FROM PUBLICATION ORDER BY TITRE_PUB ASC");
    while (query.next()) {
        QListWidgetItem *item = new QListWidgetItem(query.value("TITRE_PUB").toString());
        item->setData(Qt::UserRole, query.value("ID_PUB").toInt());
        ui->list_Publications->addItem(item);
    }
}

void GestionSession::loadAllReviewers()
{
    ui->list_Reviewers->clear();
    QSqlQuery query("SELECT ID_REVIEWER, NOM_REVIEWER AS NOM FROM TABLE_REVIEWER ORDER BY NOM_REVIEWER ASC");
    while (query.next()) {
        QListWidgetItem *item = new QListWidgetItem(query.value("NOM").toString());
        item->setData(Qt::UserRole, query.value("ID_REVIEWER").toInt());
        ui->list_Reviewers->addItem(item);
    }
}

void GestionSession::loadSessionsTable()
{
    ui->tableWidget_Sessions->setRowCount(0);
    QSqlQuery query("SELECT * FROM TABLE_SESSION ORDER BY ID_SESSION DESC");
    
    int row = 0;
    while (query.next()) {
        int sessionId = query.value("ID_SESSION").toInt();
        ui->tableWidget_Sessions->insertRow(row);
        
        ui->tableWidget_Sessions->setItem(row, 0, new QTableWidgetItem(QString::number(sessionId)));
        ui->tableWidget_Sessions->setItem(row, 1, new QTableWidgetItem(query.value("TITRE_SESSION").toString()));
        ui->tableWidget_Sessions->setItem(row, 2, new QTableWidgetItem(query.value("DATE_SESSION").toDate().toString("yyyy-MM-dd")));
        ui->tableWidget_Sessions->setItem(row, 3, new QTableWidgetItem(query.value("LIEU_SESSION").toString()));
        ui->tableWidget_Sessions->setItem(row, 4, new QTableWidgetItem(query.value("TYPE_SESSION").toString()));
        
        // Dynamic strings for associations
        ui->tableWidget_Sessions->setItem(row, 5, new QTableWidgetItem(getPublicationsString(sessionId)));
        ui->tableWidget_Sessions->setItem(row, 6, new QTableWidgetItem(getReviewersString(sessionId)));
        
        row++;
    }
    applyRowColoring();
}

QString GestionSession::getPublicationsString(int sessionId)
{
    QStringList titles;
    QSqlQuery query;
    query.prepare("SELECT p.TITRE_PUB FROM PUBLICATION p "
                  "JOIN session_publications sp ON p.ID_PUB = sp.id_pub "
                  "WHERE sp.id_session = :sid");
    query.bindValue(":sid", sessionId);
    if (query.exec()) {
        while (query.next()) titles << query.value(0).toString();
    }
    return titles.join(", ");
}

QString GestionSession::getReviewersString(int sessionId)
{
    QStringList names;
    QSqlQuery query;
    query.prepare("SELECT r.NOM_REVIEWER AS NOM FROM TABLE_REVIEWER r "
                  "JOIN session_reviewers sr ON r.ID_REVIEWER = sr.id_reviewer "
                  "WHERE sr.id_session = :sid");
    query.bindValue(":sid", sessionId);
    if (query.exec()) {
        while (query.next()) names << query.value(0).toString();
    }
    return names.join(", ");
}

void GestionSession::on_tableWidget_Sessions_itemClicked(QTableWidgetItem *item)
{
    int row = item->row();
    m_currentSessionId = ui->tableWidget_Sessions->item(row, 0)->text().toInt();
    
    ui->lineEdit_ID->setText(QString::number(m_currentSessionId));
    ui->lineEdit_Titre->setText(ui->tableWidget_Sessions->item(row, 1)->text());
    ui->dateEdit_Date->setDate(QDate::fromString(ui->tableWidget_Sessions->item(row, 2)->text(), "yyyy-MM-dd"));
    ui->lineEdit_Lieu->setText(ui->tableWidget_Sessions->item(row, 3)->text());
    ui->comboBox_Type->setCurrentText(ui->tableWidget_Sessions->item(row, 4)->text());
    
    loadSessionPublications(m_currentSessionId);
    loadSessionReviewers(m_currentSessionId);
}

void GestionSession::loadSessionPublications(int sessionId)
{
    ui->list_SessionPubs->clear();
    QSqlQuery query;
    query.prepare("SELECT p.ID_PUB, p.TITRE_PUB FROM PUBLICATION p "
                  "JOIN session_publications sp ON p.ID_PUB = sp.id_pub "
                  "WHERE sp.id_session = :sid");
    query.bindValue(":sid", sessionId);
    if (query.exec()) {
        while (query.next()) {
            QListWidgetItem *item = new QListWidgetItem(query.value("TITRE_PUB").toString());
            item->setData(Qt::UserRole, query.value("ID_PUB").toInt());
            ui->list_SessionPubs->addItem(item);
        }
    }
}

void GestionSession::loadSessionReviewers(int sessionId)
{
    ui->list_SessionRevs->clear();
    QSqlQuery query;
    query.prepare("SELECT r.ID_REVIEWER, r.NOM_REVIEWER AS NOM FROM TABLE_REVIEWER r "
                  "JOIN session_reviewers sr ON r.ID_REVIEWER = sr.id_reviewer "
                  "WHERE sr.id_session = :sid");
    query.bindValue(":sid", sessionId);
    if (query.exec()) {
        while (query.next()) {
            QListWidgetItem *item = new QListWidgetItem(query.value("NOM").toString());
            item->setData(Qt::UserRole, query.value("ID_REVIEWER").toInt());
            ui->list_SessionRevs->addItem(item);
        }
    }
}

void GestionSession::on_btn_AssocierPublications_clicked()
{
    if (m_currentSessionId == -1) {
        QMessageBox::warning(nullptr, "Attention", "Sélectionnez ou créez une session d'abord");
        return;
    }
    
    QList<QListWidgetItem*> selected = ui->list_Publications->selectedItems();
    for (QListWidgetItem *item : selected) {
        int pubId = item->data(Qt::UserRole).toInt();
        addPublicationAssociation(m_currentSessionId, pubId);
    }
    
    loadSessionPublications(m_currentSessionId);
    loadSessionsTable();
}

bool GestionSession::addPublicationAssociation(int sessionId, int pubId)
{
    // Check if exists
    QSqlQuery check;
    check.prepare("SELECT 1 FROM session_publications WHERE id_session = :sid AND id_pub = :pid");
    check.bindValue(":sid", sessionId);
    check.bindValue(":pid", pubId);
    if (check.exec() && check.next()) return false;
    
    QSqlQuery query;
    query.prepare("INSERT INTO session_publications (id_session, id_pub) VALUES (:sid, :pid)");
    query.bindValue(":sid", sessionId);
    query.bindValue(":pid", pubId);
    return query.exec();
}

void GestionSession::on_btn_AssocierReviewers_clicked()
{
    if (m_currentSessionId == -1) {
        QMessageBox::warning(nullptr, "Attention", "Sélectionnez ou créez une session d'abord");
        return;
    }
    
    QList<QListWidgetItem*> selected = ui->list_Reviewers->selectedItems();
    for (QListWidgetItem *item : selected) {
        int revId = item->data(Qt::UserRole).toInt();
        addReviewerAssociation(m_currentSessionId, revId);
    }
    
    loadSessionReviewers(m_currentSessionId);
    loadSessionsTable();
}

bool GestionSession::addReviewerAssociation(int sessionId, int revId)
{
    QSqlQuery check;
    check.prepare("SELECT 1 FROM session_reviewers WHERE id_session = :sid AND id_reviewer = :rid");
    check.bindValue(":sid", sessionId);
    check.bindValue(":rid", revId);
    if (check.exec() && check.next()) return false;
    
    QSqlQuery query;
    query.prepare("INSERT INTO session_reviewers (id_session, id_reviewer) VALUES (:sid, :rid)");
    query.bindValue(":sid", sessionId);
    query.bindValue(":rid", revId);
    return query.exec();
}

void GestionSession::on_btn_RetirerPub_clicked()
{
    if (!ui->list_SessionPubs->currentItem()) return;
    int pubId = ui->list_SessionPubs->currentItem()->data(Qt::UserRole).toInt();
    if (removePublicationAssociation(m_currentSessionId, pubId)) {
        loadSessionPublications(m_currentSessionId);
        loadSessionsTable();
    }
}

bool GestionSession::removePublicationAssociation(int sessionId, int pubId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM session_publications WHERE id_session = :sid AND id_pub = :pid");
    query.bindValue(":sid", sessionId);
    query.bindValue(":pid", pubId);
    return query.exec();
}

void GestionSession::on_btn_RetirerRev_clicked()
{
    if (!ui->list_SessionRevs->currentItem()) return;
    int revId = ui->list_SessionRevs->currentItem()->data(Qt::UserRole).toInt();
    if (removeReviewerAssociation(m_currentSessionId, revId)) {
        loadSessionReviewers(m_currentSessionId);
        loadSessionsTable();
    }
}

bool GestionSession::removeReviewerAssociation(int sessionId, int revId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM session_reviewers WHERE id_session = :sid AND id_reviewer = :rid");
    query.bindValue(":sid", sessionId);
    query.bindValue(":rid", revId);
    return query.exec();
}

void GestionSession::on_btn_Enregistrer_clicked()
{
    QString idStr = ui->lineEdit_ID->text();
    QString titre = ui->lineEdit_Titre->text();
    QDate date = ui->dateEdit_Date->date();
    QString lieu = ui->lineEdit_Lieu->text();
    QString type = ui->comboBox_Type->currentText();
    
    if (titre.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Le titre est obligatoire");
        return;
    }
    
    QSqlQuery query;
    if (idStr.isEmpty() || idStr == "0") {
        query.prepare("INSERT INTO TABLE_SESSION (TITRE_SESSION, DATE_SESSION, LIEU_SESSION, TYPE_SESSION) "
                      "VALUES (:titre, :date, :lieu, :type)");
    } else {
        query.prepare("UPDATE TABLE_SESSION SET TITRE_SESSION = :titre, DATE_SESSION = :date, "
                      "LIEU_SESSION = :lieu, TYPE_SESSION = :type WHERE ID_SESSION = :id");
        query.bindValue(":id", idStr.toInt());
    }
    
    query.bindValue(":titre", titre);
    query.bindValue(":date", date);
    query.bindValue(":lieu", lieu);
    query.bindValue(":type", type);
    
    if (query.exec()) {
        QMessageBox::information(nullptr, "Succès", "Session enregistrée");
        loadSessionsTable();
        clearSessionForm();
    } else {
        QMessageBox::critical(nullptr, "Erreur", query.lastError().text());
    }
}

void GestionSession::clearSessionForm()
{
    ui->lineEdit_ID->clear();
    ui->lineEdit_Titre->clear();
    ui->dateEdit_Date->setDate(QDate::currentDate());
    ui->lineEdit_Lieu->clear();
    ui->comboBox_Type->setCurrentIndex(0);
    ui->list_SessionPubs->clear();
    ui->list_SessionRevs->clear();
    ui->list_Publications->clearSelection();
    ui->list_Reviewers->clearSelection();
    m_currentSessionId = -1;
}

void GestionSession::on_rechercheSession_clicked()
{
    QString val = ui->rechSession->text();
    QString triQuery = " ORDER BY ID_SESSION DESC"; // Default
    
    // Check if the tri combo box exists (I might have failed to add it to UI)
    // In Qt, ui->comboBox_TriSessions will be null if not in UI, but usually it's best to check
    // However, if I can't add it to UI, I'll just search.
    
    QString sql = "SELECT * FROM TABLE_SESSION";
    if (!val.isEmpty()) {
        sql += " WHERE TITRE_SESSION LIKE '%" + val + "%' OR LIEU_SESSION LIKE '%" + val + "%'";
    }
    sql += triQuery;

    ui->tableWidget_Sessions->setRowCount(0);
    QSqlQuery query(sql);
    int row = 0;
    while (query.next()) {
        int sessionId = query.value("ID_SESSION").toInt();
        ui->tableWidget_Sessions->insertRow(row);
        ui->tableWidget_Sessions->setItem(row, 0, new QTableWidgetItem(QString::number(sessionId)));
        ui->tableWidget_Sessions->setItem(row, 1, new QTableWidgetItem(query.value("TITRE_SESSION").toString()));
        ui->tableWidget_Sessions->setItem(row, 2, new QTableWidgetItem(query.value("DATE_SESSION").toDate().toString("yyyy-MM-dd")));
        ui->tableWidget_Sessions->setItem(row, 3, new QTableWidgetItem(query.value("LIEU_SESSION").toString()));
        ui->tableWidget_Sessions->setItem(row, 4, new QTableWidgetItem(query.value("TYPE_SESSION").toString()));
        ui->tableWidget_Sessions->setItem(row, 5, new QTableWidgetItem(getPublicationsString(sessionId)));
        ui->tableWidget_Sessions->setItem(row, 6, new QTableWidgetItem(getReviewersString(sessionId)));
        row++;
    }
    applyRowColoring();
}

void GestionSession::applyRowColoring()
{
    QDate today = QDate::currentDate();
    for (int row = 0; row < ui->tableWidget_Sessions->rowCount(); ++row) {
        // La date est dans la colonne 2 (format yyyy-MM-dd)
        QTableWidgetItem *dateItem = ui->tableWidget_Sessions->item(row, 2);
        if (!dateItem) continue;

        QDate sessionDate = QDate::fromString(dateItem->text(), "yyyy-MM-dd");
        if (!sessionDate.isValid()) continue;

        int daysDiff = today.daysTo(sessionDate);
        QColor color;

        if (daysDiff <= 3) {
            color = QColor(144, 238, 144); // VERT
        } else if (daysDiff <= 10) {
            color = QColor(255, 255, 153); // JAUNE
        } else {
            color = QColor(255, 102, 102); // ROUGE
        }

        // Appliquer la couleur à toute la ligne
        for (int col = 0; col < ui->tableWidget_Sessions->columnCount(); ++col) {
            if (ui->tableWidget_Sessions->item(row, col)) {
                ui->tableWidget_Sessions->item(row, col)->setBackground(color);
                ui->tableWidget_Sessions->item(row, col)->setForeground(Qt::black); // Texte lisible
            }
        }
    }
}

void GestionSession::on_quitterSession_clicked()
{
    if (QWidget *w = ui->centralwidget->window()) {
        w->close();
    }
}

void GestionSession::on_annuler_2_clicked()
{
    clearSessionForm();
}





