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
  sessionWidget = new GestionSession(this);
  // Find the existing tab_session and embed our widget into it
  QVBoxLayout *sessionLayout = new QVBoxLayout(ui->tab_session);
  sessionLayout->setContentsMargins(0, 0, 0, 0);
  sessionLayout->addWidget(sessionWidget);

  // --- Add GestionJournal page as a TAB ---
  journalWindow = new GestionJournal(this);
  journalTabIndex = ui->tabWidget->addTab(journalWindow, tr("Gestion Journal"));

  // --- Add GestionReviewer page as a TAB ---
  reviewerWindow = new GestionReviewer(this);
  reviewerTabIndex =
      ui->tabWidget->addTab(reviewerWindow, tr("Gestion Reviewer"));

  // --- Initialize other windows (hidden by default) ---
  publicationWindow = new GestionPublication();

  // IMPORTANT: do NOT create extra connects to a non-existing ui->tab_session.
  // Rely on Qt auto-connect slot: on_GestionSession_clicked()
}

SmartResearch::~SmartResearch() {
  delete ui;
  // journalWindow, sessionWidget, and reviewerWindow are children of
  // SmartResearch (or tabWidget) so they are deleted automatically
  delete publicationWindow;
}

void SmartResearch::on_quitterPub_clicked() { close(); }

void SmartResearch::on_GestionUtilisateurs_clicked() {
  // Your designer tab for users is named: tab_utilisateur
  ui->tabWidget->setCurrentWidget(ui->tab_utilisateur);
}

void SmartResearch::on_GestionPublications_clicked() {
  // Your designer tab for publications is named: tab
  ui->tabWidget->setCurrentWidget(ui->tab);
  // If you prefer the separate window:
  // publicationWindow->show();
}

void SmartResearch::on_GestionSession_clicked() {
  // Go to the embedded Gestion Session tab (tab_session from UI)
  ui->tabWidget->setCurrentWidget(ui->tab_session);
}

void SmartResearch::on_GestionJournalconference_clicked() {
  // Go to the embedded Gestion Journal tab
  ui->tabWidget->setCurrentIndex(journalTabIndex);
}

void SmartResearch::on_GestionReviewer_clicked() {
  // Go to the embedded Gestion Reviewer tab
  ui->tabWidget->setCurrentIndex(reviewerTabIndex);
}
