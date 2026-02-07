#ifndef SMARTRESEARCH_H
#define SMARTRESEARCH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SmartResearch;
}
QT_END_NAMESPACE

class SmartResearch : public QMainWindow
{
    Q_OBJECT

public:
    SmartResearch(QWidget *parent = nullptr);
    ~SmartResearch();

private slots:


    void on_quitterPub_clicked();
    void on_GestionUtilisateurs_clicked();
    void on_GestionPublications_clicked();

private:
    Ui::SmartResearch *ui;
};
#endif // SMARTRESEARCH_H
