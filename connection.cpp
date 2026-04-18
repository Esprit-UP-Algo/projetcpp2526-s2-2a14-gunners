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
    
    // Create session_publications table
    // Using a block to catch errors silently if tables exist (ODBC/Oracle specific behavior usually requires separate checks, 
    // but standard SQL 'CREATE TABLE' is safer here).
    query.exec("CREATE TABLE session_publications ("
               "id_session INT, "
               "id_pub INT, "
               "PRIMARY KEY (id_session, id_pub), "
               "FOREIGN KEY (id_session) REFERENCES TABLE_SESSION(ID_SESSION) ON DELETE CASCADE, "
               "FOREIGN KEY (id_pub) REFERENCES PUBLICATION(ID_PUB) ON DELETE CASCADE"
               ")");

    // Create session_reviewers table
    query.exec("CREATE TABLE session_reviewers ("
               "id_session INT, "
               "id_reviewer INT, "
               "PRIMARY KEY (id_session, id_reviewer), "
               "FOREIGN KEY (id_session) REFERENCES TABLE_SESSION(ID_SESSION) ON DELETE CASCADE, "
               "FOREIGN KEY (id_reviewer) REFERENCES REVIEWER(ID_REVIEWER) ON DELETE CASCADE"
               ")");
}

// Destructeur privé

Connection::~Connection()
{
    closeConnection();
}
