#include "smartresearch.h"
#include "login.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "connection.h"
#include <QApplication>
#include <QObject>
#include <QMessageBox>
#include <QStyleFactory>
#include <QPalette>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    bool test = Connection::instance()->createConnect();

    if (test) {
        Connection::instance()->setupTables();

        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click OK to continue."), QMessageBox::Ok);

        // 2. Configuration du Style et de la Palette
        a.setStyle(QStyleFactory::create("Fusion"));
        QPalette palette;
        palette.setColor(QPalette::Window, Qt::white);
        palette.setColor(QPalette::WindowText, Qt::black);
        palette.setColor(QPalette::Base, Qt::white);
        palette.setColor(QPalette::AlternateBase, QColor(245, 245, 245));
        palette.setColor(QPalette::Text, Qt::black);
        palette.setColor(QPalette::Button, QColor(240, 240, 240));
        palette.setColor(QPalette::ButtonText, Qt::black);
        palette.setColor(QPalette::Highlight, QColor(0, 120, 215));
        palette.setColor(QPalette::HighlightedText, Qt::white);
        a.setPalette(palette);

        // Création automatique de la table "log" pour la connexion/inscription
        QSqlQuery query;
        // On essaie de créer la table. Si elle existe déjà, la base Oracle retournera une erreur qu'on peut ignorer.
        if (!query.exec("CREATE TABLE log (USERNAME VARCHAR2(100) PRIMARY KEY, PASSWORD VARCHAR2(100), NOM_PERE VARCHAR2(100), NOM_MERE VARCHAR2(100), AGE NUMBER, FRERES NUMBER)")) {
             qDebug() << "La table log existe déjà ou erreur :" << query.lastError().text();
        }

        // 3. Gestion des fenêtres : On affiche Login en premier
        Login *loginWindow = new Login();
        
        // Quand la connexion réussit, on affiche la page principale
        QObject::connect(loginWindow, &Login::loginSuccessful, [=]() {
            SmartResearch *w = new SmartResearch();
            w->show();
        });

        loginWindow->show();

        return a.exec();

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

        return 0; // On quitte l'application car la base est indispensable
    }
}
