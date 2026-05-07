#ifndef ARDUINOCONTROLLER_H
#define ARDUINOCONTROLLER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QTimer>

/**
 * ArduinoController
 * -----------------
 * Manages a QSerialPort connection to an Arduino board and sends
 * publication statistics so they can be displayed on an LCD/7-seg.
 *
 * Protocol (plain text, terminated with '\n'):
 *   Qt  ──► Arduino :  "PUB:<total>:<journals>:<conferences>\n"
 *   Arduino ──► Qt  :  "OK\n"  (optional ACK)
 *
 * Usage:
 *   ArduinoController *ctrl = new ArduinoController(this);
 *   ctrl->autoConnect();          // scans COM ports for an Arduino
 *   ctrl->sendPublicationCount(42, 18, 24);
 */
class ArduinoController : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoController(QObject *parent = nullptr);
    ~ArduinoController();

    // --- Connection management ---
    bool connectToPort(const QString &portName,
                       qint32 baudRate = QSerialPort::Baud9600);
    bool autoConnect();          // Tries all available COM ports
    void disconnect();
    bool isConnected() const;
    QString currentPort() const;

    // --- Data sending ---
    // Sends total count + breakdown (journals vs conferences) to the Arduino
    bool sendPublicationCount(int total, int journals, int conferences);

    // Sends a raw string (must NOT contain newline – one is appended automatically)
    bool sendRaw(const QString &message);

    // --- Static helpers ---
    static QStringList availablePorts();  // Returns list of COM port names

signals:
    void connected(const QString &portName);
    void disconnected();
    void dataReceived(const QString &data);  // ACK / any response from Arduino
    void errorOccurred(const QString &errorMsg);

private slots:
    void onReadyRead();
    void onErrorOccurred(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serial;
    QByteArray   m_readBuffer;
};

#endif // ARDUINOCONTROLLER_H
