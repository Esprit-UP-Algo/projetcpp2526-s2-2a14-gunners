#include "connection.h"
#include <QSqlError>
#include <QDebug>

// Initialisation du pointeur d'instance
Connection* Connection::p_instance = nullptr;

// Constructeur privé
Connection::Connection()
{
    // Initialisation de la base de données
    db = QSqlDatabase::addDatabase("QODBC");
}

// Méthode statique pour obtenir l'instance unique
Connection* Connection::instance()
{
    if (p_instance == nullptr) {
        p_instance = new Connection();
    }
    return p_instance;
}

// Méthode pour établir la connexion
bool Connection::createConnect()
{
    bool test = false;

    db.setDatabaseName("gunners");//inserer le nom de la source de données
    db.setUserName("gunners");//inserer nom de l'utilisateur
    db.setPassword("gunners8");//inserer mot de passe de cet utilisateur

    if (db.open()) {
        test = true;
        qDebug() << "Connexion à la base de données réussie";
    } else {
        qDebug() << "Erreur de connexion:" << db.lastError().text();
    }

    return test;
}

// Fermer la connexion
void Connection::closeConnection()
{
    if (db.isOpen()) {
        db.close();
    }
}

void Connection::setupTables()
{
    if (!db.isOpen()) return;

    QSqlQuery query;
    
    // 1. Ensure TABLE_UTILISATEUR has the security columns
    // We try to add them one by one. If they exist, the error is ignored.
    query.exec("ALTER TABLE TABLE_UTILISATEUR ADD (NOM_PERE VARCHAR2(100))");
    query.exec("ALTER TABLE TABLE_UTILISATEUR ADD (NOM_MERE VARCHAR2(100))");
    query.exec("ALTER TABLE TABLE_UTILISATEUR ADD (AGE NUMBER)");
    query.exec("ALTER TABLE TABLE_UTILISATEUR ADD (FRERES NUMBER)");

    // 2. Auto-Seed Super Admin
    query.exec("SELECT COUNT(*) FROM TABLE_UTILISATEUR");
    if (query.next() && query.value(0).toInt() == 0) {
        qDebug() << "TABLE_UTILISATEUR is empty. Seeding default Super Admin...";
        // Password is 'admin', Email is 'admin@smartresearch.com'
        QString seedSql = "INSERT INTO TABLE_UTILISATEUR (ID_UTILISATEUR, NOM_UTILISATEUR, PRENOM, EMAIL_UTILISATEUR, MDP_UTILISATEUR, ROLE_UTILISATEUR, NUM_UTILISATEUR, INSTITUTION_UTILISATEUR, NOM_PERE, NOM_MERE, AGE, FRERES) "
                          "VALUES (1, 'Admin', 'Super', 'admin@smartresearch.com', 'admin', 'Admin', 0, 'SmartResearch HQ', 'Root', 'System', 99, 0)";
        if (!query.exec(seedSql)) {
            qDebug() << "Failed to seed admin:" << query.lastError().text();
        } else {
            qDebug() << "Super Admin seeded successfully.";
        }
    }

    // 3. Create session relation tables
    query.exec("CREATE TABLE session_publications ("
               "id_session INT, "
               "id_pub INT, "
               "PRIMARY KEY (id_session, id_pub), "
               "FOREIGN KEY (id_session) REFERENCES TABLE_SESSION(ID_SESSION) ON DELETE CASCADE, "
               "FOREIGN KEY (id_pub) REFERENCES PUBLICATION(ID_PUB) ON DELETE CASCADE"
               ")");

    query.exec("CREATE TABLE session_reviewers ("
               "id_session INT, "
               "id_reviewer INT, "
               "PRIMARY KEY (id_session, id_reviewer), "
               "FOREIGN KEY (id_session) REFERENCES TABLE_SESSION(ID_SESSION) ON DELETE CASCADE, "
               "FOREIGN KEY (id_reviewer) REFERENCES TABLE_REVIEWER(ID_REVIEWER) ON DELETE CASCADE"
               ")");
}

// Destructeur privé

Connection::~Connection()
{
    closeConnection();
}
