#include "smartresearch.h"

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

        // 3. Gestion des fenêtres
        SmartResearch *w = new SmartResearch();
        w->show();

        return a.exec();

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

        return 0; // On quitte l'application car la base est indispensable
    }
}
