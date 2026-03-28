#ifndef GESTIONREVIEWER_H
#define GESTIONREVIEWER_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class GestionReviewer;
}
QT_END_NAMESPACE

class GestionReviewer : public QWidget
{
    Q_OBJECT

public:
    explicit GestionReviewer(QWidget *parent = nullptr);
    ~GestionReviewer();

private slots:
    void on_enregistrerReviewer_clicked();
    void on_modifierReviewer_clicked();
    void on_supprimerReviewerButton_clicked();
    void on_rechercherButton_clicked();
    void on_assignerPublicationButton_clicked();
    void on_rapportButton_clicked();
    void on_refreshButton_2_clicked();
    void on_annulerReviewer_clicked();
    void on_quitterButton_clicked();
    void on_tableViewReviewer_clicked(const QModelIndex &index);
    void on_actifReviewer_clicked();
    void on_inactifReviewer_clicked();

private:
    Ui::GestionReviewer *ui;
    QSqlDatabase db;
    QSqlTableModel *model;

    void connectDatabase();
    void setupTable();
    void clearForm();
    void loadReviewerData(int id);
    bool validateForm();
    int getSelectedReviewerId();
    void refreshTable();
};

#endif // GESTIONREVIEWER_H
