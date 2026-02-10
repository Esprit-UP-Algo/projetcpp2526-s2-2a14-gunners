#ifndef GESTIONPUBLICATION_H
#define GESTIONPUBLICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GestionPublication;
}
QT_END_NAMESPACE

class GestionPublication : public QMainWindow
{
    Q_OBJECT

public:
    GestionPublication(QWidget *parent = nullptr);
    ~GestionPublication();

private slots:


    void on_quitterPub_clicked();

private:
    Ui::GestionPublication *ui;
};
#endif // GESTIONPUBLICATION_H
