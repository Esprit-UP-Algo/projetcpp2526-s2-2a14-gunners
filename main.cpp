#include "gstionjournal.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  GestionJournal w;
  w.show();
  return a.exec();
}
