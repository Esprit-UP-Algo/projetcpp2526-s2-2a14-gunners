#ifndef JOURNAL_H
#define JOURNAL_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class Journal {
  int id_journal;
  QString nom;
  QString type;
  QString domaine_scientifique;
  QString facteur_impact;
  QString classement;
  QString pays;
  QString organisation;
  QString periodicite;
  QString siteweb;

public:
  Journal();
  Journal(int id_journal, const QString& nom, const QString& type,
          const QString& domaine_scientifique, const QString& facteur_impact,
          const QString& classement, const QString& pays, const QString& organisation,
          const QString& periodicite, const QString& siteweb);

  bool ajouter();
  QSqlQueryModel *afficher() const;
  bool supprimer(int id);
  bool modifier(int id);
  QSqlQueryModel *trier() const;
  QSqlQueryModel *rechercher(const QString& rech) const;
};

#endif // JOURNAL_H
