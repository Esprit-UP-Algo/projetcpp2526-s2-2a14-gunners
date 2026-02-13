#ifndef GESTIONSESSION_H
#define GESTIONSESSION_H

#include <QWidget>

namespace Ui {
class GestionSession;
}

// Page "Gestion Session" (embedded into SmartResearch QTabWidget)
class GestionSession : public QWidget
{
    Q_OBJECT

public:
    explicit GestionSession(QWidget *parent = nullptr);
    ~GestionSession();

private slots:
    void on_btn_Quitter_Session_clicked();

private:
    Ui::GestionSession *ui;
};

#endif // GESTIONSESSION_H
