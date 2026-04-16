#ifndef JOURNAL_H
#define JOURNAL_H

#include <QString>
#include <QSqlQuery>
#include <QMap>

class Journal
{
    int     id_journal;
    QString nom_journal;
    QString type_journal;
    QString domaine_journal;       // DB: DOMAINE_JOURNAL
    QString facteur_impact;        // DB: FACTEUR_IMPACT (NUMBER, stored as string)
    QString classement_journal;    // DB: CLASSEMENT_JOURNAL
    QString pays_journal;
    QString organisation_journal;
    QString periodicite_journal;
    QString site_web_journal;      // DB: SITE_WEB_JOURNAL

public:
    Journal();
    Journal(int, QString, QString, QString, QString,
            QString, QString, QString, QString, QString);

    // Getters
    int     get_id_journal()            const;
    QString get_nom_journal()           const;
    QString get_type_journal()          const;
    QString get_domaine_journal()       const;
    QString get_facteur_impact()        const;
    QString get_classement_journal()    const;
    QString get_pays_journal()          const;
    QString get_organisation_journal()  const;
    QString get_periodicite_journal()   const;
    QString get_site_web_journal()      const;

    // Setters
    void set_id_journal(int);
    void set_nom_journal(QString);
    void set_type_journal(QString);
    void set_domaine_journal(QString);
    void set_facteur_impact(QString);
    void set_classement_journal(QString);
    void set_pays_journal(QString);
    void set_organisation_journal(QString);
    void set_periodicite_journal(QString);
    void set_site_web_journal(QString);

    // CRUD  (table: JOURNALCONFERENCE, PK: ID_JOURNALCONFERENCE)
    bool ajouter();
    bool supprimer(int id);
    bool modifier(int originalId);
    static bool verifierId(int id);
    static QMap<QString, int> getStatistics();
};

#endif // JOURNAL_H
