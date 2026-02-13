#include "gestionpublication.h"
#include "ui_gestionpublication.h"

GestionPublication::GestionPublication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionPublication)
{
    ui->setupUi(this);
}

GestionPublication::~GestionPublication()
{
    delete ui;
}




void GestionPublication::on_quitterPub_clicked()
{
    this->close();
}

