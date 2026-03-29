#ifndef GESTIONPUBLICATION_H
#define GESTIONPUBLICATION_H

#include <QObject>
#include <QModelIndex>
#include "publication.h"

// Forward declaration de l'UI
namespace Ui {
class SmartResearch;
}

class GestionPublication : public QObject
{
    Q_OBJECT

public:
    explicit GestionPublication(Ui::SmartResearch *ui, QObject *parent = nullptr);
    ~GestionPublication();

public slots:
    void afficher_page();
    void on_enregistrer_clicked();
    void on_modif_clicked();
    void on_annulerajout_client_clicked();
    void on_pushButton_supprimer_client_clicked();
    void on_pushButton_recherche_3_clicked();
    void on_comboBox_9_currentIndexChanged(int index);
    void on_tableWidget_9_clicked(const QModelIndex &index);
    void on_expoSession_5_clicked();

private:
    Ui::SmartResearch *ui;
    Publication Ptmp;
};

#endif // GESTIONPUBLICATION_H
