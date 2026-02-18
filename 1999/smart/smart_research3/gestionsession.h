#ifndef GESTIONSESSION_H
#define GESTIONSESSION_H

#include <QObject>
#include "smartresearch.h" // Need full definition for Ui::SmartResearch usage if we can't forward declare inner class easily or just forward declare Ui::SmartResearch correctly

namespace Ui {
class SmartResearch;
}

class GestionSession : public QObject
{
    Q_OBJECT

public:
    explicit GestionSession(Ui::SmartResearch *ui, QObject *parent = nullptr);
    ~GestionSession();

public slots:
    void on_quitterSession_clicked();

private:
    Ui::SmartResearch *ui;
};

#endif // GESTIONSESSION_H
