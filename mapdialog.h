#ifndef MAPDIALOG_H
#define MAPDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QMouseEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class MapDialog : public QDialog {
    Q_OBJECT
public:
    explicit MapDialog(QWidget *parent = nullptr);
    QString getChosenCountry() const;

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void onReverseGeocodingResponse(QNetworkReply *reply);

private:
    QLabel *mapLabel;
    QLabel *statusLabel;
    QNetworkAccessManager *netManager;
    QString chosenCountry;
};

#endif // MAPDIALOG_H
