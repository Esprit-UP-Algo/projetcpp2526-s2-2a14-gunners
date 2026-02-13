#ifndef SMARTRESEARCH_H
#define SMARTRESEARCH_H

#include <QMainWindow>

class GestionSession;

QT_BEGIN_NAMESPACE
namespace Ui { class SmartResearch; }
QT_END_NAMESPACE

class SmartResearch : public QMainWindow
{
    Q_OBJECT

public:
    explicit SmartResearch(QWidget *parent = nullptr);
    ~SmartResearch();

private slots:
    void on_quitterPub_clicked();
    void on_GestionUtilisateurs_clicked();
    void on_GestionPublications_clicked();
    void on_GestionSession_clicked();

private:
    Ui::SmartResearch *ui;

    GestionSession *sessionWidget = nullptr;
    int sessionTabIndex = -1;
};

#endif // SMARTRESEARCH_H
