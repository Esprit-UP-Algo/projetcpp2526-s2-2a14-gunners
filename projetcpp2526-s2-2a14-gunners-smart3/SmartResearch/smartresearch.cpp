#include "smartresearch.h"
#include "ui_smartresearch.h"

#include "gestionsession.h"

#include <QPixmap>

SmartResearch::SmartResearch(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SmartResearch)
{
    ui->setupUi(this);

    // --- Logo (resource first) ---
    QPixmap logo(":/logo.png");
    if (!logo.isNull()) {
        ui->label_10->setPixmap(logo);
        ui->label_10->setScaledContents(true);
    }

    // --- Add GestionSession page as a TAB (no new window) ---
    sessionWidget = new GestionSession(this);
    sessionTabIndex = ui->tabWidget->addTab(sessionWidget, tr("Gestion Session"));

    // IMPORTANT: do NOT create extra connects to a non-existing ui->tab_session.
    // Rely on Qt auto-connect slot: on_GestionSession_clicked()
}

SmartResearch::~SmartResearch()
{
    delete ui;
}

void SmartResearch::on_quitterPub_clicked()
{
    close();
}

void SmartResearch::on_GestionUtilisateurs_clicked()
{
    // Your designer tab for users is named: tab_utilisateur
    ui->tabWidget->setCurrentWidget(ui->tab_utilisateur);
}

void SmartResearch::on_GestionPublications_clicked()
{
    // Your designer tab for publications is named: tab
    ui->tabWidget->setCurrentWidget(ui->tab);
}

void SmartResearch::on_GestionSession_clicked()
{
    // Go to the embedded Gestion Session tab
    ui->tabWidget->setCurrentIndex(sessionTabIndex);
}
