#include <utility>
#include "paiement.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QObject>
#include <QSqlError>

// ==================== CONSTRUCTEURS ====================

paiement::paiement()
{
    this->idPaiement = 0;
    this->typeFraisPaiement = "";
    this->modePaiement = "";
    this->datePaiement = "";
    this->montantPaiement = "";
    this->devicePaiement = "";
    this->statutPaiement = "EN ATTENTE";
}

paiement::paiement(int idPaiement, QString typeFraisPaiement, QString modePaiement,
                   QString datePaiement, QString montantPaiement, QString devicePaiement,
                   QString statutPaiement)
{
    this->idPaiement = idPaiement;
    this->typeFraisPaiement = typeFraisPaiement;
    this->modePaiement = modePaiement;
    this->datePaiement = datePaiement;
    this->montantPaiement = montantPaiement;
    this->devicePaiement = devicePaiement;
    this->statutPaiement = statutPaiement;
}

// ==================== GETTERS ====================

int paiement::getIdPaiement() const
{
    return idPaiement;
}

QString paiement::getTypeFraisPaiement() const
{
    return typeFraisPaiement;
}

QString paiement::getModePaiement() const
{
    return modePaiement;
}

QString paiement::getDatePaiement() const
{
    return datePaiement;
}

QString paiement::getMontantPaiement() const
{
    return montantPaiement;
}

QString paiement::getDevicePaiement() const
{
    return devicePaiement;
}

QString paiement::getStatutPaiement() const
{
    return statutPaiement;
}

// ==================== SETTERS ====================

void paiement::setIdPaiement(int idPaiement)
{
    this->idPaiement = idPaiement;
}

void paiement::setTypeFraisPaiement(const QString &typeFraisPaiement)
{
    this->typeFraisPaiement = typeFraisPaiement;
}

void paiement::setModePaiement(const QString &modePaiement)
{
    this->modePaiement = modePaiement;
}

void paiement::setDatePaiement(const QString &datePaiement)
{
    this->datePaiement = datePaiement;
}

void paiement::setMontantPaiement(const QString &montantPaiement)
{
    this->montantPaiement = montantPaiement;
}

void paiement::setDevicePaiement(const QString &devicePaiement)
{
    this->devicePaiement = devicePaiement;
}

void paiement::setStatutPaiement(const QString &statutPaiement)
{
    this->statutPaiement = statutPaiement;
}

// ==================== CRUD OPERATIONS ====================

bool paiement::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO TABLE_PAIEMENT (ID_PAIEMENT, TYPE_FRAIS_PAIEMENT, "
                  "MODE_PAIEMENT, DATE_PAIEMENTUMN3, MONTANT_PAIEMENT, DEVICE_PAIEMENT, "
                  "STATUT_PAIEMENT) "
                  "VALUES (:id, :type_frais, :mode, TO_DATE(:date_paiement, 'DD/MM/YYYY'), :montant, "
                  ":device, :statut)");

    query.bindValue(":id", idPaiement);
    query.bindValue(":type_frais", typeFraisPaiement);
    query.bindValue(":mode", modePaiement);
    query.bindValue(":date_paiement", datePaiement);
    query.bindValue(":montant", montantPaiement);
    query.bindValue(":device", devicePaiement);
    query.bindValue(":statut", statutPaiement);

    if (!query.exec()) {
        qDebug() << "Erreur ajout paiement:" << query.lastError().text();
        return false;
    }
    return true;
}

bool paiement::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE TABLE_PAIEMENT SET "
                  "TYPE_FRAIS_PAIEMENT = :type_frais, "
                  "MODE_PAIEMENT = :mode, "
                  "DATE_PAIEMENTUMN3 = TO_DATE(:date_paiement, 'DD/MM/YYYY'), "
                  "MONTANT_PAIEMENT = :montant, "
                  "DEVICE_PAIEMENT = :device, "
                  "STATUT_PAIEMENT = :statut "
                  "WHERE ID_PAIEMENT = :id");

    query.bindValue(":id", idPaiement);
    query.bindValue(":type_frais", typeFraisPaiement);
    query.bindValue(":mode", modePaiement);
    query.bindValue(":date_paiement", datePaiement);
    query.bindValue(":montant", montantPaiement);
    query.bindValue(":device", devicePaiement);
    query.bindValue(":statut", statutPaiement);

    if (!query.exec()) {
        lastError = query.lastError().text();
        qDebug() << "Erreur modification paiement:" << lastError;
        return false;
    }
    return true;
}

bool paiement::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM TABLE_PAIEMENT WHERE ID_PAIEMENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur suppression paiement:" << query.lastError().text();
        return false;
    }
    return true;
}

// ==================== AFFICHAGE ====================

QSqlQueryModel* paiement::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT ID_PAIEMENT, TYPE_FRAIS_PAIEMENT, MODE_PAIEMENT, TO_CHAR(DATE_PAIEMENTUMN3, 'DD/MM/YYYY'), MONTANT_PAIEMENT, DEVICE_PAIEMENT, STATUT_PAIEMENT FROM TABLE_PAIEMENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DEVICE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("STATUT"));

    return model;
}

// ==================== RECHERCHE ====================

bool paiement::rechercherParId(int idRecherche)
{
    QSqlQuery query;

    query.prepare("SELECT ID_PAIEMENT, TYPE_FRAIS_PAIEMENT, MODE_PAIEMENT, "
                  "TO_CHAR(DATE_PAIEMENTUMN3, 'DD/MM/YYYY'), MONTANT_PAIEMENT, "
                  "DEVICE_PAIEMENT, STATUT_PAIEMENT FROM TABLE_PAIEMENT "
                  "WHERE ID_PAIEMENT = :id");
    query.bindValue(":id", idRecherche);

    if (!query.exec() || !query.first()) {
        return false;
    }

    this->idPaiement = query.value(0).toInt();
    this->typeFraisPaiement = query.value(1).toString();
    this->modePaiement = query.value(2).toString();
    this->datePaiement = query.value(3).toString();
    this->montantPaiement = query.value(4).toString();
    this->devicePaiement = query.value(5).toString();
    this->statutPaiement = query.value(6).toString();

    return true;
}

QSqlQueryModel* paiement::rechercherParTypeFrais(const QString &typeFrais)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT WHERE TYPE_FRAIS_PAIEMENT LIKE :type");
    query.bindValue(":type", "%" + typeFrais + "%");
    query.exec();

    model->setQuery(std::move(query));
    return model;
}

QSqlQueryModel* paiement::rechercherParModePaiement(const QString &mode)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT WHERE MODE_PAIEMENT LIKE :mode");
    query.bindValue(":mode", "%" + mode + "%");
    query.exec();

    model->setQuery(std::move(query));
    return model;
}

QSqlQueryModel* paiement::rechercherParStatut(const QString &statut)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT WHERE STATUT_PAIEMENT = :statut");
    query.bindValue(":statut", statut);
    query.exec();

    model->setQuery(std::move(query));
    return model;
}

QSqlQueryModel* paiement::rechercherParDevice(const QString &device)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT WHERE DEVICE_PAIEMENT LIKE :device");
    query.bindValue(":device", "%" + device + "%");
    query.exec();

    model->setQuery(std::move(query));
    return model;
}

// ==================== TRI ====================

QSqlQueryModel* paiement::trierParId()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_PAIEMENT, TYPE_FRAIS_PAIEMENT, MODE_PAIEMENT, TO_CHAR(DATE_PAIEMENTUMN3, 'DD/MM/YYYY'), MONTANT_PAIEMENT, DEVICE_PAIEMENT, STATUT_PAIEMENT FROM TABLE_PAIEMENT ORDER BY ID_PAIEMENT ASC");
    query.exec();
    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DEVICE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("STATUT"));

    return model;
}

QSqlQueryModel* paiement::trierParIdDesc()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_PAIEMENT, TYPE_FRAIS_PAIEMENT, MODE_PAIEMENT, TO_CHAR(DATE_PAIEMENTUMN3, 'DD/MM/YYYY'), MONTANT_PAIEMENT, DEVICE_PAIEMENT, STATUT_PAIEMENT FROM TABLE_PAIEMENT ORDER BY ID_PAIEMENT DESC");
    query.exec();
    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DEVICE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("STATUT"));

    return model;
}

QSqlQueryModel* paiement::trierParMontant()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT ORDER BY TO_NUMBER(MONTANT_PAIEMENT) ASC");
    query.exec();
    model->setQuery(std::move(query));

    return model;
}

QSqlQueryModel* paiement::trierParDate()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT ORDER BY TO_DATE(DATE_PAIEMENTUMN3, 'DD/MM/YYYY') DESC");
    query.exec();
    model->setQuery(std::move(query));

    return model;
}

QSqlQueryModel* paiement::trierParTypeFrais()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT ORDER BY TYPE_FRAIS_PAIEMENT ASC");
    query.exec();
    model->setQuery(std::move(query));

    return model;
}

QSqlQueryModel* paiement::trierParModePaiement()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT ORDER BY MODE_PAIEMENT ASC");
    query.exec();
    model->setQuery(std::move(query));

    return model;
}

QSqlQueryModel* paiement::trierParDevice()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE_PAIEMENT ORDER BY DEVICE_PAIEMENT ASC");
    query.exec();
    model->setQuery(std::move(query));

    return model;
}

// ==================== STATISTIQUES ====================

QSqlQueryModel* paiement::statistiquesParStatut()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT STATUT_PAIEMENT, COUNT(*) as NOMBRE, "
                    "SUM(TO_NUMBER(MONTANT_PAIEMENT)) as TOTAL "
                    "FROM TABLE_PAIEMENT GROUP BY STATUT_PAIEMENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("STATUT_PAIEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TOTAL"));

    return model;
}

QSqlQueryModel* paiement::statistiquesParModePaiement()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT MODE_PAIEMENT, COUNT(*) as NOMBRE, "
                    "SUM(TO_NUMBER(MONTANT_PAIEMENT)) as TOTAL "
                    "FROM TABLE_PAIEMENT GROUP BY MODE_PAIEMENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MODE_PAIEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TOTAL"));

    return model;
}

QSqlQueryModel* paiement::statistiquesParTypeFrais()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT TYPE_FRAIS_PAIEMENT, COUNT(*) as NOMBRE, "
                    "SUM(TO_NUMBER(MONTANT_PAIEMENT)) as TOTAL "
                    "FROM TABLE_PAIEMENT GROUP BY TYPE_FRAIS_PAIEMENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE_FRAIS_PAIEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TOTAL"));

    return model;
}

QSqlQueryModel* paiement::statistiquesParDevice()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT DEVICE_PAIEMENT, COUNT(*) as NOMBRE, "
                    "SUM(TO_NUMBER(MONTANT_PAIEMENT)) as TOTAL "
                    "FROM TABLE_PAIEMENT GROUP BY DEVICE_PAIEMENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("DEVICE_PAIEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TOTAL"));

    return model;
}

QString paiement::getLastError() const
{
    return lastError;
}
