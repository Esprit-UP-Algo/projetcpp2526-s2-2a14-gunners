#ifndef GESTIONREVIEWER_H
#define GESTIONREVIEWER_H

#include <QObject>
#include "smartresearch.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QSqlQueryModel>

namespace Ui {
class SmartResearch;
}

class Reviewer;

class GestionReviewer : public QObject
{
    Q_OBJECT

public:
    explicit GestionReviewer(Ui::SmartResearch *ui, QObject *parent = nullptr);
    ~GestionReviewer();

    void updateReviewerStats();

public slots:
    void on_enregistrerReviewer_clicked();
    void on_modifierReviewer_clicked();
    void on_supprimerReviewerButton_clicked();
    void on_rechercherButton_clicked();
    void on_annulerReviewer_clicked();
    void on_uploadPhotoBtn_clicked();
    void on_quitterSession_3_clicked();
    void on_expoSession_3_clicked();
    void on_tableWidget_7_clicked(const QModelIndex &index);
    void on_comboBox_7_currentIndexChanged(int index);

private slots:
    void on_pushButton_pdfclient_2_clicked();

private:
    Ui::SmartResearch *ui;
    int selectedReviewerId;
    
    // Charts
    QFrame *statsPanel = nullptr;
    QLabel *userNameLabel = nullptr;
    QLineEdit *userNameReviewer = nullptr;
    QChartView *barChartView = nullptr;
    
    void applyModernTheme();
    void clearForm();
    void ensureUserNameField();
    void populateReviewerTable(QSqlQueryModel *model);
    void refreshTable();
    bool validateForm();
    void setupCharts();
    void afficherReviewers();
    void rechercherReviewer();
    void trierReviewers();
    void updateStatistics();
};

#endif // GESTIONREVIEWER_H
