#include "reviewer.h"
#include "smsservice.h"
#include <QSqlError>

// Helper pour échapper les apostrophes pour Oracle
static QString esc(const QString &s) {
    return QString(s).replace("'", "''");
}

Reviewer::Reviewer()
{
    id_reviewer = 0;
}

Reviewer::Reviewer(int id, QString nom, QString email, QString username, QString telephone, QString photo, QString specialite, QString institution, QString statut)
{
    this->id_reviewer = id;
    this->nom = nom;
    this->email = email;
    this->username = username;
    this->telephone = telephone;
    this->photo_path = photo;
    this->specialite = specialite;
    this->institution = institution;
    this->statut = statut;
}

int Reviewer::get_id() { return id_reviewer; }
QString Reviewer::get_nom() { return nom; }
QString Reviewer::get_email() { return email; }
QString Reviewer::get_username() { return username; }
QString Reviewer::get_telephone() { return telephone; }
QString Reviewer::get_photo() { return photo_path; }
QString Reviewer::get_specialite() { return specialite; }
QString Reviewer::get_institution() { return institution; }
QString Reviewer::get_statut() { return statut; }

void Reviewer::set_id(int id) { this->id_reviewer = id; }
void Reviewer::set_nom(QString n) { nom = n; }
void Reviewer::set_email(QString e) { email = e; }
void Reviewer::set_username(QString u) { username = u; }
void Reviewer::set_telephone(QString t) { telephone = t; }
void Reviewer::set_photo(QString p) { photo_path = p; }
void Reviewer::set_specialite(QString s) { specialite = s; }
void Reviewer::set_institution(QString i) { institution = i; }
void Reviewer::set_statut(QString s) { statut = s; }

bool Reviewer::ajouterReviewer()
{
    QSqlQuery alterQuery;
    alterQuery.exec("ALTER TABLE TABLE_REVIEWER ADD (TELEPHONE_REVIEWER VARCHAR2(50), PHOTO_REVIEWER VARCHAR2(500))");

    QSqlQuery query;
    query.prepare("INSERT INTO TABLE_REVIEWER (ID_REVIEWER, NOM_REVIEWER, EMAIL_REVIEWER, \"SP?CIALIT?_REVIEWER\", "
                  "USER_NAME_REVIEWER, INSTITUTION_REVIEWER, STATUT_REVIEWER, TELEPHONE_REVIEWER, PHOTO_REVIEWER) "
                  "VALUES (:id, :nom, :email, :specialite, :username, :institution, :statut, :telephone, :photo)");

    query.bindValue(":id", id_reviewer);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":specialite", specialite);
    query.bindValue(":username", username);
    query.bindValue(":institution", institution);
    query.bindValue(":statut", statut);
    query.bindValue(":telephone", telephone);
    query.bindValue(":photo", photo_path);

    if (!query.exec()) {
        lastError = query.lastError().text();
        qDebug() << "Erreur d'insertion Reviewer:" << lastError;
        return false;
    }
    
    // Send SMS upon success
    QString message = "Hello " + nom + ", you have been successfully registered as a reviewer in SmartResearch.";
    SmsService::sendSMS(telephone, message);
    
    return true;
}

QSqlQueryModel* Reviewer::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_REVIEWER, NOM_REVIEWER, EMAIL_REVIEWER, USER_NAME_REVIEWER, TELEPHONE_REVIEWER, PHOTO_REVIEWER, \"SP?CIALIT?_REVIEWER\", INSTITUTION_REVIEWER, STATUT_REVIEWER FROM TABLE_REVIEWER ORDER BY ID_REVIEWER ASC");
    
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Username"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Photo"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Spécialité"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Institution"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Statut"));
    
    return model;
}

bool Reviewer::modifier(int originalId)
{
    QSqlQuery query;
    query.prepare("UPDATE TABLE_REVIEWER SET "
                  "ID_REVIEWER = :id, "
                  "NOM_REVIEWER = :nom, "
                  "EMAIL_REVIEWER = :email, "
                  "USER_NAME_REVIEWER = :username, "
                  "TELEPHONE_REVIEWER = :telephone, "
                  "PHOTO_REVIEWER = :photo, "
                  "\"SP?CIALIT?_REVIEWER\" = :specialite, "
                  "INSTITUTION_REVIEWER = :institution, "
                  "STATUT_REVIEWER = :statut "
                  "WHERE ID_REVIEWER = :originalId");

    query.bindValue(":id", id_reviewer);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":username", username);
    query.bindValue(":telephone", telephone);
    query.bindValue(":photo", photo_path);
    query.bindValue(":specialite", specialite);
    query.bindValue(":institution", institution);
    query.bindValue(":statut", statut);
    query.bindValue(":originalId", originalId);

    if (!query.exec()) {
        qDebug() << "Erreur modification Reviewer:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Reviewer::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TABLE_REVIEWER WHERE ID_REVIEWER = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Reviewer::verifierId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID_REVIEWER FROM TABLE_REVIEWER WHERE ID_REVIEWER = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}

QSqlQueryModel* Reviewer::rechercher(QString val, QString critere, QString order)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString sql = "SELECT * FROM TABLE_REVIEWER";
    
    if (!val.isEmpty()) {
        sql += " WHERE ID_REVIEWER LIKE '%" + esc(val) + "%' OR NOM_REVIEWER LIKE '%" + esc(val) + "%' OR EMAIL_REVIEWER LIKE '%" + esc(val) + "%' OR USER_NAME_REVIEWER LIKE '%" + esc(val) + "%' OR TELEPHONE_REVIEWER LIKE '%" + esc(val) + "%'";
    }
    
    sql += " ORDER BY " + critere + " " + order;
    model->setQuery(sql);
    
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Username"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Photo"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Spécialité"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Institution"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Statut"));
    
    return model;
}

QMap<QString, int> Reviewer::getStatistics()
{
    QMap<QString, int> stats;
    QSqlQuery query;

    // Total count
    query.prepare("SELECT COUNT(*) FROM TABLE_REVIEWER");
    if (query.exec() && query.next()) {
        stats["total"] = query.value(0).toInt();
    }

    // Per statut
    QStringList statuts = {"Actif", "Inactif"};
    for (const QString &s : statuts) {
        query.prepare("SELECT COUNT(*) FROM TABLE_REVIEWER WHERE STATUT_REVIEWER = :s");
        query.bindValue(":s", s);
        if (query.exec() && query.next()) {
            stats["Statut_" + s] = query.value(0).toInt();
        }
    }

    // Per specialite
    query.prepare("SELECT \"SP?CIALIT?_REVIEWER\", COUNT(*) FROM TABLE_REVIEWER GROUP BY \"SP?CIALIT?_REVIEWER\"");
    if (query.exec()) {
        while (query.next()) {
            QString spec = query.value(0).toString().trimmed();
            if (!spec.isEmpty())
                stats["Spec_" + spec] = query.value(1).toInt();
        }
    }

    // Per institution
    query.prepare("SELECT INSTITUTION_REVIEWER, COUNT(*) FROM TABLE_REVIEWER GROUP BY INSTITUTION_REVIEWER");
    if (query.exec()) {
        while (query.next()) {
            QString inst = query.value(0).toString().trimmed();
            if (!inst.isEmpty())
                stats["Inst_" + inst] = query.value(1).toInt();
        }
    }

    return stats;
}
