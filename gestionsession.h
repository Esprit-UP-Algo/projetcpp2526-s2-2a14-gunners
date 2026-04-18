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

private slots:


    void on_btn_Annuler_paiement_clicked();

    void on_pushButton_recherche_5_clicked();



    void on_quitterSession_2_clicked();

    void on_expoSession_2_clicked();





private:
    Ui::SmartResearch *ui;
};

#endif // GESTIONSESSION_H
