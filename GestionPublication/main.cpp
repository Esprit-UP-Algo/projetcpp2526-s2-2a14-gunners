#include "gestionpublication.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GestionPublication w;
    w.show();
    return a.exec();
}

