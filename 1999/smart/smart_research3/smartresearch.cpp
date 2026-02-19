#include "smartresearch.h"
#include "ui_smartresearch.h"

#include "gestionsession.h"

#include <QPixmap>
#include <QVBoxLayout>

SmartResearch::SmartResearch(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartResearch) {
  ui->setupUi(this);

  // --- Logo (resource first) ---
  QPixmap logo(":/logo.png");
  if (!logo.isNull()) {
    ui->label_10->setPixmap(logo);
    ui->label_10->setScaledContents(true);
  }

  // --- Embed GestionSession into the existing tab_session from UI ---
  // GestionSession is a controller, not a widget (UI is in smartresearch.ui)
  sessionController = new GestionSession(ui, this);

  // IMPORTANT: do NOT create extra connects to a non-existing ui->tab_session.
  // Rely on Qt auto-connect slot: on_GestionSession_clicked()

  // --- Initial Login State ---
  // Hide the sidebar, top logo, and "Tableau de Board" label
  ui->groupBox->setVisible(false);
  ui->label_10->setVisible(false);
  ui->TableaudeBoard->setVisible(false);
  
  // Resize stackedWidget to cover the sidebar area
  // Original geometry: x=200, y=100, w=1221, h=621
  // New geometry:      x=10,  y=100, w=1411, h=621 (covering the 190px gap)
  ui->stackedWidget->setGeometry(10, 100, 1411, 621);
  
  // Ensure we start on the login page (index 0)
  ui->stackedWidget->setCurrentIndex(0); 
}

SmartResearch::~SmartResearch() {
  delete ui;
}

void SmartResearch::on_quitterPub_clicked() { close(); }

void SmartResearch::on_GestionUtilisateurs_clicked() {
  // Your designer tab for users is named: stackedWidgetPage1
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
}

void SmartResearch::on_GestionPublications_clicked() {
  // Your designer tab for publications is named: stackedWidgetPage2
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
  // If you prefer the separate window:
  // publicationWindow->show();
}

void SmartResearch::on_GestionSession_clicked() {
  // Go to the embedded Gestion Session tab (stackedWidgetPage5 from UI)
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage5);
}

void SmartResearch::on_GestionJournalconference_clicked() {
  // Go to the embedded Gestion Journal tab
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage3);
}

void SmartResearch::on_GestionReviewer_clicked() {
  ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);
}

void SmartResearch::on_GestionSession_2_clicked()
{
    // Go to the embedded Gestion Paiement tab
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage6);
}

void SmartResearch::on_btnLogin_main_clicked()
{
    // Simple transition: Show sidebar, logo, and "Tableau de Board" label
    ui->groupBox->setVisible(true);
    ui->label_10->setVisible(true);
    ui->TableaudeBoard->setVisible(true);
    
    // Restore stackedWidget geometry
    ui->stackedWidget->setGeometry(200, 100, 1221, 621);
    
    // Switch to the User Management page (or whatever is your default main page)
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
    
    // Optional: Clear fields
    if (ui->txtPassword_login) ui->txtPassword_login->clear();
    if (ui->txtUsername_login) ui->txtUsername_login->clear();
}
