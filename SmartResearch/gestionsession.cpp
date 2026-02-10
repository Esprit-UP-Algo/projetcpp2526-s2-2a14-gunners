#include "gestionsession.h"
#include "ui_gestionsession.h"

#include <QWidget>

GestionSession::GestionSession(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionSession)
{
    ui->setupUi(this);

    // Make the embedded page sit flush inside the tab
    setContentsMargins(0, 0, 0, 0);
}

GestionSession::~GestionSession()
{
    delete ui;
}

void GestionSession::on_btn_Quitter_Session_clicked()
{
    // Close the whole application window (SmartResearch)
    if (QWidget *w = window()) {
        w->close();
    }
}
