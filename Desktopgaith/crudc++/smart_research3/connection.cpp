#include "connection.h"
#include <QDebug>

Connection::Connection()
{}


bool Connection::createconnect()
{

    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("gunners");//inserer le nom de la source de données
    db.setUserName("gunners");//inserer nom de l'utilisateur
    db.setPassword("gunners8");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
