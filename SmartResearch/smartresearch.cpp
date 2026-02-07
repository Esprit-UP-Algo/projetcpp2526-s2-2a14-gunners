#include "smartresearch.h"
#include "ui_smartresearch.h"
#include <QTabBar>

SmartResearch::SmartResearch(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SmartResearch)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();

    // 🔴 Fallback for logo: Try resource first, then absolute path
    QPixmap logo(":/logo.png");
    if (logo.isNull()) {
        // Resource failed, try absolute path
        logo.load("C:/Users/DELL/projetcpp2526-s2-2a14-gunners/SmartResearch/logo.png");
    }

    if (!logo.isNull()) {
        ui->label_10->setPixmap(logo);
        ui->label_10->setScaledContents(true);
    } else {
        // If both fail, set a red background so we know the code is running
        ui->label_10->setStyleSheet("background-color: red; color: white;");
        ui->label_10->setText("Logo not found");
    }
}

SmartResearch::~SmartResearch()
{
    delete ui;
}

void SmartResearch::on_quitterPub_clicked()
{
    this->close();
}

void SmartResearch::on_GestionUtilisateurs_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void SmartResearch::on_GestionPublications_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}
