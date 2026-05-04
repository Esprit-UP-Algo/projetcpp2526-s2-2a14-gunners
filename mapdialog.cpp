#include "mapdialog.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QUrl>
#include <QNetworkRequest>

MapDialog::MapDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Sélectionner un pays sur la carte");
    setMinimumSize(800, 500);

    QVBoxLayout *layout = new QVBoxLayout(this);
    
    mapLabel = new QLabel(this);
    QPixmap pix(":/worldmap.jpg");
    if (pix.isNull()) {
        mapLabel->setText("Erreur : worldmap.jpg introuvable.");
    } else {
        mapLabel->setPixmap(pix.scaled(800, 400, Qt::KeepAspectRatio));
    }
    mapLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(mapLabel);

    statusLabel = new QLabel("Cliquez sur un pays pour le sélectionner...", this);
    statusLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(statusLabel);

    netManager = new QNetworkAccessManager(this);
    connect(netManager, &QNetworkAccessManager::finished, this, &MapDialog::onReverseGeocodingResponse);
}

QString MapDialog::getChosenCountry() const {
    return chosenCountry;
}

void MapDialog::mousePressEvent(QMouseEvent *event) {
    if (mapLabel->rect().contains(event->pos())) {
        // Calculate relative position on the map image
        QPoint labelPos = mapLabel->mapFrom(this, event->pos());
        double x = labelPos.x();
        double y = labelPos.y();
        double w = mapLabel->width();
        double h = mapLabel->height();

        // Convert to Latitude/Longitude (Equirectangular projection)
        double lon = (x / w) * 360.0 - 180.0;
        double lat = 90.0 - (y / h) * 180.0;

        statusLabel->setText(QString("Recherche du pays (Lat: %1, Lon: %2)...").arg(lat).arg(lon));

        // Call Nominatim API
        QString url = QString("https://nominatim.openstreetmap.org/reverse?lat=%1&lon=%2&format=json&zoom=3&accept-language=fr").arg(lat).arg(lon);
        QNetworkRequest request((QUrl(url)));
        request.setHeader(QNetworkRequest::UserAgentHeader, "SmartResearch-App");
        netManager->get(request);
    }
}

void MapDialog::onReverseGeocodingResponse(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject root = doc.object();
        QJsonObject address = root["address"].toObject();

        if (address.contains("country")) {
            chosenCountry = address["country"].toString();
            statusLabel->setText("Pays détecté : " + chosenCountry);
            
            int ret = QMessageBox::question(this, "Confirmer la sélection", 
                                          QString("Voulez-vous sélectionner l'emplacement : %1 ?").arg(chosenCountry),
                                          QMessageBox::Yes | QMessageBox::No);
            if (ret == QMessageBox::Yes) {
                accept();
            }
        } else {
            statusLabel->setText("Aucun pays détecté. Cliquez sur une zone terrestre.");
        }
    } else {
        statusLabel->setText("Erreur réseau : " + reply->errorString());
    }
    reply->deleteLater();
}
