#include "gestionsession.h"
#include "ui_smartresearch.h" // Access the full UI definition

GestionSession::GestionSession(Ui::SmartResearch *ui, QObject *parent)
    : QObject(parent)
    , ui(ui)
{
    // Connect signals from the main UI widgets
    connect(ui->quitterSession, &QPushButton::clicked, this, &GestionSession::on_quitterSession_clicked);

    // Initial setup if needed (e.g., hiding/showing specific parts)
}

GestionSession::~GestionSession()
{
    // No specific cleanup for ui since it's owned by SmartResearch
}

void GestionSession::on_quitterSession_clicked()
{
    // Close the application window
    // Access the window through one of the widgets we know exists
    if (QWidget *w = ui->centralwidget->window()) {
        w->close();
    }
}
