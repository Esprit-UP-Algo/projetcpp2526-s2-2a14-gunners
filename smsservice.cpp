#include "smsservice.h"
#include <QDebug>
#include <QEventLoop>
#include <QMessageBox>
#include <QUrlQuery>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

SmsService::SmsService() {}

void SmsService::sendSMS(QString phoneNumber, QString message) {
  QNetworkAccessManager manager;

  // Auth placeholders
  QString accountSid =
      "ACc33b16801f744bfc8c372236fa2dce9d"; // REPLACE WITH ACTUAL TWILIO SID
  QString authToken =
      "6e0d27f9e1c4ce1f2674d85154b137a0"; // REPLACE WITH ACTUAL TWILIO TOKEN
  QString twilioNumber = "+13205250958";  // REPLACE WITH ACTUAL TWILIO PHONE

  // Ensure phoneNumber starts with Twilio's accepted format (E.164)
  if (phoneNumber.startsWith("00")) {
    phoneNumber.replace(0, 2, "+"); // Replace 00 with + (e.g. 00216 -> +216)
  } else if (!phoneNumber.startsWith("+")) {
    phoneNumber = "+216" + phoneNumber; // Fallback to prepending +216
  }

  QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + accountSid +
           "/Messages.json");
  QNetworkRequest request(url);

  QString concatenated = accountSid + ":" + authToken;
  QByteArray data = concatenated.toUtf8().toBase64();
  QByteArray headerData = "Basic " + data;
  request.setRawHeader("Authorization", headerData);
  request.setHeader(QNetworkRequest::ContentTypeHeader,
                    "application/x-www-form-urlencoded");

  QUrlQuery query;
  query.addQueryItem("To", phoneNumber);
  query.addQueryItem("From", twilioNumber);
  query.addQueryItem("Body", message);

  // Execute synchronous POST request
  QNetworkReply *reply =
      manager.post(request, query.toString(QUrl::FullyEncoded).toUtf8());
  QEventLoop loop;
  QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  loop.exec(); // Wait for network to finish

  int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
  qDebug() << "HTTP Status:" << httpStatus;
  
  QByteArray responseData = reply->readAll();
  qDebug() << "Response:" << responseData;

  if (reply->error() != QNetworkReply::NoError || httpStatus >= 400) {
    qDebug() << "SMS Error: " << reply->errorString();
    QMessageBox::warning(nullptr, "Erreur SMS",
                         "Le reviewer a été ajouté avec succès, mais l'envoi "
                         "du SMS a échoué.\nErreur: " + reply->errorString() + 
                         "\nStatut HTTP: " + QString::number(httpStatus));
  } else {
    qDebug() << "SMS Sent Successfully!";
  }

  reply->deleteLater();
}
