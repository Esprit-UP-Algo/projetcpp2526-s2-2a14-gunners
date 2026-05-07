#ifndef SMARTRESEARCH_H
#define SMARTRESEARCH_H
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QMap>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSqlQuery>
#include "mapdialog.h"
#include "arduino_display/arduinocontroller.h"
class GestionSession;
class GestionReviewer;
#include "publication.h"
#include "chatbot.h"
#include "utilisateur.h"
#include "journal.h"
#include "session.h"
#include "smtp.h"
#include "paiement.h"  // ← added
QT_BEGIN_NAMESPACE
namespace Ui {
class SmartResearch;
}
QT_END_NAMESPACE
class SmartResearch : public QMainWindow {
    Q_OBJECT
public:
    explicit SmartResearch(QWidget *parent = nullptr);
    ~SmartResearch();
    void setupPaiementValidators();   // ← added
    void loadPaiementData();          // ← added
    void populatePaiementComboBoxes(); // ← added
    int generatePaiementID();         // ← added

private slots:
    void on_GestionUtilisateurs_clicked();
    void on_GestionPublications_clicked();
    void on_GestionSession_clicked();
    void on_GestionJournalconference_clicked();
    void on_GestionReviewer_clicked();
    void on_GestionSession_2_clicked();
    void on_btnLogin_main_clicked();
    void on_qr_clicked();
    void on_pb_excel_clicked();
    // Journal / Conférence Slots
    void on_enregistrer1_clicked();
    void on_modif1_clicked();
    void on_annuler_clicked();
    void on_SuppSession_4_clicked();
    void on_rechercheSession_4_clicked();
    void on_comboBox_8_currentIndexChanged(int index);
    void on_tableWidget_8_cellClicked(int row, int column);
    void on_expoSession_4_clicked();
    void readArduinoData();
    void handleValidation(const QString &result, int idPaiement); // Controller Layer
    void showValidationResult(const QString &message, bool success); // UI Layer
    void on_btnChooseMap_clicked();

    // Session Slots handled by GestionSession controller
    
    // API OpenAlex AutoFill Feature
    void fetchJournalAPI();
    void onJournalAPIResponse(QNetworkReply *reply);    // Publication Slots
    void on_enregistrer_clicked();
    void on_modif_clicked();
    void on_annulerajout_client_clicked();
    void on_pushButton_supprimer_client_clicked();
    void on_pushButton_recherche_3_clicked();
    void on_comboBox_9_currentIndexChanged(int index);
    void on_tableWidget_9_clicked(const QModelIndex &index);
    void on_expoSession_5_clicked();
    void on_btn_qr_pub_clicked();
    void on_smartAssistantButton_clicked();
    // Utilisateur Slots
    void on_btn_Enregistrer_Utilisateur_clicked();
    void on_modif_3_clicked();
    void on_annulerajout_client_3_clicked();
    void on_pushButton_supprimer_client_2_clicked();
    void on_tableWidget_10_clicked(const QModelIndex &index);
    void on_pushButton_recherche_4_clicked();
    void on_comboBox_11_currentIndexChanged(int index);
    void on_pushButton_pdfclient_clicked();
    // Paiement Slots  ← added block
    void on_btn_Enregistrer_paiement_clicked();
    void on_btn_Modifier_paiement_clicked();
    void on_btn_Annuler_paiement_clicked();
    void on_recherche_clicked();
    void on_tablePaiement_clicked(const QModelIndex &index);
    void on_comboBoxPaiement_currentIndexChanged(int index);
    void on_lineEdit_recherchPaiement_textChanged(const QString &arg1);
    void on_pushButton_supprimer_paiement_clicked();
    void on_quitterSession_2_clicked();
    void on_quitterSession_7_clicked();
    void on_expoSession_2_clicked();
    void on_expoSession_2_linkActivated(const QString &link);
private:
    Ui::SmartResearch *ui;
    GestionSession *sessionController = nullptr;
    GestionReviewer *reviewerController = nullptr;
    Publication Ptmp;
    Utilisateur Utmp;
    Journal Jtmp;
    Session Stmp;
    paiement p;  // ← added
    void updateUtilisateurStats();
    void updatePublicationStats();
    void updateSessionStats();
    void loadPubTypes();
    void refreshJournalTable();
    void updateJournalStats();
    QLabel* label_Chart_Session = nullptr;
    void drawBarChart(QLabel *label, const QMap<QString, int> &data, const QColor &barColor);

    // Session features moved to GestionSession
    int selectedUtilisateurId = -1;
    int selectedPublicationId = -1;
    Chatbot *chatbotWidget;
    int selectedJournalId     = -1;
    QNetworkAccessManager *apiManager;

    // Arduino Serial Handling
    QSerialPort *arduino;
    static const uint16_t arduino_uno_vendor_id = 9025;
    static const uint16_t arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    void setupSerial();
    void initArduino();   // 7-segment display controller
signals:
    void validationReceived(const QString &result, int idPaiement); // Serial -> Controller
    void validationFinished(const QString &message, bool success); // Controller -> UI
    // AFTER (correct — only the slot stays in private slots:)
private slots:
    void readSerial();

private:
    // Arduino Integration (Payment Validation — Keypad/Servo)
    QSerialPort *serial = nullptr;
    QByteArray dataBuffer;
    bool arduinoBusy = false;
    int pendingPaiementId = -1;
    // Arduino Display (7-Segment — Publication Stats)
    ArduinoController *arduinoDisplay = nullptr;
};
#endif // SMARTRESEARCH_H
