#include "smartrearch.h"

#include <QApplication>

#include <QApplication>
#include <QStyleFactory>
#include <QPalette>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // 🔵 Forcer le style clair
    a.setStyle(QStyleFactory::create("Fusion"));

    // 🔵 Palette blanche
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
    SmartResearch w;
    w.show();
    return a.exec();
}
