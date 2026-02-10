#include "gestionreviewer.h"
#include <QApplication>
#include <QFile>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set application style
    a.setStyle(QStyleFactory::create("Fusion"));

    // Set application information
    a.setApplicationName("Smart Research - Gestion Reviewer");
    a.setApplicationVersion("1.0.0");
    a.setOrganizationName("ESPRIT Gunners");

    // Create and show main window
    GestionReviewer w;
    w.show();

    return a.exec();
}
