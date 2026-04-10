#include "journal.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

// -------------------------------------------------------
// Constructors
// -------------------------------------------------------

Journal::Journal()
{
    id_journal            = 0;
    nom_journal           = "";
    type_journal          = "";
    domaine_journal       = "";
    facteur_impact        = "";
    classement_journal    = "";
    pays_journal          = "";
    organisation_journal  = "";
    periodicite_journal   = "";
    site_web_journal      = "";
}

Journal::Journal(int id, QString nom, QString type, QString domaine, QString facteur,
                 QString cls, QString pays, QString org, QString periodicite, QString siteweb)
{
    id_journal            = id;
    nom_journal           = nom;
    type_journal          = type;
    domaine_journal       = domaine;
    facteur_impact        = facteur;
    classement_journal    = cls;
    pays_journal          = pays;
    organisation_journal  = org;
    periodicite_journal   = periodicite;
    site_web_journal      = siteweb;
}

// -------------------------------------------------------
// Getters
// -------------------------------------------------------
int     Journal::get_id_journal()           const { return id_journal; }
QString Journal::get_nom_journal()          const { return nom_journal; }
QString Journal::get_type_journal()         const { return type_journal; }
QString Journal::get_domaine_journal()      const { return domaine_journal; }
QString Journal::get_facteur_impact()       const { return facteur_impact; }
QString Journal::get_classement_journal()   const { return classement_journal; }
QString Journal::get_pays_journal()         const { return pays_journal; }
QString Journal::get_organisation_journal() const { return organisation_journal; }
QString Journal::get_periodicite_journal()  const { return periodicite_journal; }
QString Journal::get_site_web_journal()     const { return site_web_journal; }

// -------------------------------------------------------
// Setters
// -------------------------------------------------------
void Journal::set_id_journal(int v)               { id_journal            = v; }
void Journal::set_nom_journal(QString v)           { nom_journal           = v; }
void Journal::set_type_journal(QString v)          { type_journal          = v; }
void Journal::set_domaine_journal(QString v)       { domaine_journal       = v; }
void Journal::set_facteur_impact(QString v)        { facteur_impact        = v; }
void Journal::set_classement_journal(QString v)    { classement_journal    = v; }
void Journal::set_pays_journal(QString v)          { pays_journal          = v; }
void Journal::set_organisation_journal(QString v)  { organisation_journal  = v; }
void Journal::set_periodicite_journal(QString v)   { periodicite_journal   = v; }
void Journal::set_site_web_journal(QString v)      { site_web_journal      = v; }

// -------------------------------------------------------
// Helper: escape single quotes in string values
// -------------------------------------------------------
static QString esc(const QString &s) {
    return QString(s).replace("'", "''");
}

// -------------------------------------------------------
// CRUD — AJOUTER
// Uses direct exec() to avoid Oracle ODBC S1010
// "Function sequence error" caused by prepare()/bindValue()
// -------------------------------------------------------
bool Journal::ajouter()
{
    // FACTEUR_IMPACT is NUMBER in Oracle — use toDouble(), fallback to 0
    double facteur_num = facteur_impact.isEmpty() ? 0.0 : facteur_impact.toDouble();

    QString sql = QString(
        "INSERT INTO TABLE_JOURNAL_CONF "
        "(ID_JOURNALCONFERENCE, NOM_JOURNAL, TYPE_JOURNAL, DOMAINE_JOURNAL, "
        " FACTEUR_IMPACT, CLASSEMENT_JOURNAL, PAYS_JOURNAL, ORGANISATION_JOURNAL, "
        " PERIODICITE_JOURNAL, SITE_WEB_JOURNAL) "
        "VALUES (%1, '%2', '%3', '%4', %5, '%6', '%7', '%8', '%9', '%10')")
        .arg(id_journal)
        .arg(esc(nom_journal))
        .arg(esc(type_journal))
        .arg(esc(domaine_journal))
        .arg(facteur_num)
        .arg(esc(classement_journal))
        .arg(esc(pays_journal))
        .arg(esc(organisation_journal))
        .arg(esc(periodicite_journal))
        .arg(esc(site_web_journal));

    QSqlQuery query;
    if (!query.exec(sql)) {
        qDebug() << "[Journal] Erreur ajouter:" << query.lastError().text();
        qDebug() << "SQL:" << sql;
        return false;
    }
    return true;
}

// -------------------------------------------------------
// CRUD — SUPPRIMER
// -------------------------------------------------------
bool Journal::supprimer(int id)
{
    QString sql = QString("DELETE FROM TABLE_JOURNAL_CONF WHERE ID_JOURNALCONFERENCE = %1")
                      .arg(id);
    QSqlQuery query;
    if (!query.exec(sql)) {
        qDebug() << "[Journal] Erreur supprimer:" << query.lastError().text();
        return false;
    }
    return true;
}

// -------------------------------------------------------
// CRUD — MODIFIER
// -------------------------------------------------------
bool Journal::modifier(int originalId)
{
    double facteur_num = facteur_impact.isEmpty() ? 0.0 : facteur_impact.toDouble();

    QString sql = QString(
        "UPDATE TABLE_JOURNAL_CONF SET "
        "  ID_JOURNALCONFERENCE = %1, "
        "  NOM_JOURNAL          = '%2', "
        "  TYPE_JOURNAL         = '%3', "
        "  DOMAINE_JOURNAL      = '%4', "
        "  FACTEUR_IMPACT       = %5, "
        "  CLASSEMENT_JOURNAL   = '%6', "
        "  PAYS_JOURNAL         = '%7', "
        "  ORGANISATION_JOURNAL = '%8', "
        "  PERIODICITE_JOURNAL  = '%9', "
        "  SITE_WEB_JOURNAL     = '%10' "
        "WHERE ID_JOURNALCONFERENCE = %11")
        .arg(id_journal)
        .arg(esc(nom_journal))
        .arg(esc(type_journal))
        .arg(esc(domaine_journal))
        .arg(facteur_num)
        .arg(esc(classement_journal))
        .arg(esc(pays_journal))
        .arg(esc(organisation_journal))
        .arg(esc(periodicite_journal))
        .arg(esc(site_web_journal))
        .arg(originalId);

    QSqlQuery query;
    if (!query.exec(sql)) {
        qDebug() << "[Journal] Erreur modifier:" << query.lastError().text();
        qDebug() << "SQL:" << sql;
        return false;
    }
    return true;
}

// -------------------------------------------------------
// Vérification d'existence de l'ID
// -------------------------------------------------------
bool Journal::verifierId(int id)
{
    QString sql = QString("SELECT ID_JOURNALCONFERENCE FROM TABLE_JOURNAL_CONF "
                          "WHERE ID_JOURNALCONFERENCE = %1").arg(id);
    QSqlQuery query;
    return (query.exec(sql) && query.next());
}

QMap<QString, int> Journal::getStatistics() {
    QMap<QString, int> stats;
    QSqlQuery query;
    // --- Graphique pour les types ---
    query.exec("SELECT TYPE_JOURNAL, COUNT(*) FROM TABLE_JOURNAL_CONF GROUP BY TYPE_JOURNAL");
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        stats["type_" + type] = count;
    }
    
    // --- Graphique pour les pays ---
    query.exec("SELECT PAYS_JOURNAL, COUNT(*) FROM TABLE_JOURNAL_CONF GROUP BY PAYS_JOURNAL");
    while (query.next()) {
        QString pays = query.value(0).toString();
        int count = query.value(1).toInt();
        stats["pays_" + pays] = count;
    }
    
    return stats;
}
