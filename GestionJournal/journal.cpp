#include "journal.h"
#include <QDebug>
#include <QSqlError>

Journal::Journal() : id_journal(0) {}

Journal::Journal(int id_journal, const QString& nom, const QString& type,
                 const QString& domaine_scientifique, const QString& facteur_impact,
                 const QString& classement, const QString& pays, const QString& organisation,
                 const QString& periodicite, const QString& siteweb)
    : id_journal(id_journal), nom(nom), type(type),
      domaine_scientifique(domaine_scientifique), facteur_impact(facteur_impact),
      classement(classement), pays(pays), organisation(organisation),
      periodicite(periodicite), siteweb(siteweb) {}

bool Journal::ajouter() {
  QSqlQuery query;

  bool testPrepare = query.prepare(
      "INSERT INTO TABLE_JOURNAL_CONF (ID_JOURNALCONFERENCE, NOM_JOURNAL, "
      "TYPE_JOURNAL, DOMAINE_JOURNAL, "
      "FACTEUR_IMPACT, CLASSEMENT_JOURNAL, PAYS_JOURNAL, ORGANISATION_JOURNAL, "
      "PERIODICITE_JOURNAL, SITE_WEB_JOURNAL) "
      "VALUES (:id_journal, :nom, :type, :domaine_scientifique, "
      ":facteur_impact, :classement, :pays, :organisation, :periodicite, "
      ":siteweb)");

  if (!testPrepare) {
    qDebug() << "Erreur de PREPARATION (verifiez les noms de colonnes):"
             << query.lastError().text();
  }

  query.bindValue(":id_journal", id_journal);
  query.bindValue(":nom", nom);
  query.bindValue(":type", type);
  query.bindValue(":domaine_scientifique", domaine_scientifique);
  query.bindValue(":facteur_impact", facteur_impact.toFloat());
  query.bindValue(":classement", classement);
  query.bindValue(":pays", pays);
  query.bindValue(":organisation", organisation);
  query.bindValue(":periodicite", periodicite);
  query.bindValue(":siteweb", siteweb);

  bool test = query.exec();
  if (!test) {
    qDebug() << "Erreur d'ajout dans la base de données:"
             << query.lastError().text();
  }
  return test;
}

QSqlQueryModel *Journal::afficher() const {
  QSqlQueryModel *model = new QSqlQueryModel();
  model->setQuery("SELECT * FROM TABLE_JOURNAL_CONF");

  // Check if the query retrieved any records or failed
  if (model->lastError().isValid()) {
    qDebug() << "Erreur Afficher:" << model->lastError().text();
    return model;
  }

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Domaine Scientifique"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Facteur d'impact"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Classement"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Pays"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Organisation"));
  model->setHeaderData(8, Qt::Horizontal, QObject::tr("Périodicité"));
  model->setHeaderData(9, Qt::Horizontal, QObject::tr("Site Web"));
  return model;
}

bool Journal::supprimer(int id) {
  QSqlQuery query;
  query.prepare(
      "DELETE FROM TABLE_JOURNAL_CONF WHERE ID_JOURNALCONFERENCE = :id");
  query.bindValue(":id", id);
  return query.exec();
}

bool Journal::modifier(int id) {
  QSqlQuery query;

  query.prepare(
      "UPDATE TABLE_JOURNAL_CONF SET NOM_JOURNAL = :nom, TYPE_JOURNAL = :type, "
      "DOMAINE_JOURNAL = :domaine_scientifique, FACTEUR_IMPACT = "
      ":facteur_impact, "
      "CLASSEMENT_JOURNAL = :classement, PAYS_JOURNAL = :pays, "
      "ORGANISATION_JOURNAL = :organisation, "
      "PERIODICITE_JOURNAL = :periodicite, SITE_WEB_JOURNAL = :siteweb "
      "WHERE ID_JOURNALCONFERENCE = :id");

  query.bindValue(":id", id);
  query.bindValue(":nom", nom);
  query.bindValue(":type", type);
  query.bindValue(":domaine_scientifique", domaine_scientifique);
  query.bindValue(":facteur_impact", facteur_impact.toFloat());
  query.bindValue(":classement", classement);
  query.bindValue(":pays", pays);
  query.bindValue(":organisation", organisation);
  query.bindValue(":periodicite", periodicite);
  query.bindValue(":siteweb", siteweb);

  return query.exec();
}

QSqlQueryModel *Journal::trier() const {
  QSqlQueryModel *model = new QSqlQueryModel();
  // Sort by NOM_JOURNAL ascending by default.
  model->setQuery("SELECT * FROM TABLE_JOURNAL_CONF ORDER BY NOM_JOURNAL ASC");

  if (model->lastError().isValid()) {
    return model;
  }

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Domaine Scientifique"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Facteur d'impact"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Classement"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Pays"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Organisation"));
  model->setHeaderData(8, Qt::Horizontal, QObject::tr("Périodicité"));
  model->setHeaderData(9, Qt::Horizontal, QObject::tr("Site Web"));
  return model;
}

QSqlQueryModel *Journal::rechercher(const QString& rech) const {
  QSqlQueryModel *model = new QSqlQueryModel();
  QSqlQuery query;
  query.prepare("SELECT * FROM TABLE_JOURNAL_CONF WHERE NOM_JOURNAL LIKE :rech "
                "OR TYPE_JOURNAL LIKE :rech");
  query.bindValue(":rech", "%" + rech + "%");
  query.exec();

  model->setQuery(query);

  if (model->lastError().isValid()) {
    return model;
  }

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Domaine Scientifique"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Facteur d'impact"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Classement"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Pays"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Organisation"));
  model->setHeaderData(8, Qt::Horizontal, QObject::tr("Périodicité"));
  model->setHeaderData(9, Qt::Horizontal, QObject::tr("Site Web"));
  return model;
}
