#include "arduinocontroller.h"
#include <QDebug>
#include <QThread>

// -------------------------------------------------------
// Constructor / Destructor
// -------------------------------------------------------

ArduinoController::ArduinoController(QObject *parent)
    : QObject(parent)
    , m_serial(new QSerialPort(this))
{
    connect(m_serial, &QSerialPort::readyRead,
            this,     &ArduinoController::onReadyRead);
    connect(m_serial, &QSerialPort::errorOccurred,
            this,     &ArduinoController::onErrorOccurred);
}

ArduinoController::~ArduinoController()
{
    disconnect();
}

// -------------------------------------------------------
// Connection management
// -------------------------------------------------------

bool ArduinoController::connectToPort(const QString &portName, qint32 baudRate)
{
    if (m_serial->isOpen())
        m_serial->close();

    m_serial->setPortName(portName);
    m_serial->setBaudRate(baudRate);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!m_serial->open(QIODevice::ReadWrite)) {
        qDebug() << "[Arduino] Failed to open" << portName << ":" << m_serial->errorString();
        emit errorOccurred(tr("Cannot open port %1: %2").arg(portName, m_serial->errorString()));
        return false;
    }

    // Arduino resets on serial connect — wait for it to boot
    QThread::msleep(2000);

    qDebug() << "[Arduino] Connected on" << portName;
    emit connected(portName);
    return true;
}

bool ArduinoController::autoConnect()
{
    // Known Arduino USB vendor IDs
    const QList<quint16> arduinoVIDs = {0x2341, 0x2A03, 0x1A86, 0x0403, 0x10C4};

    // 1st pass: try to match known Arduino vendor IDs
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports) {
        if (arduinoVIDs.contains(info.vendorIdentifier())) {
            qDebug() << "[Arduino] Found device on" << info.portName()
                     << "VID:" << info.vendorIdentifier();
            if (connectToPort(info.portName()))
                return true;
        }
    }

    // 2nd pass: try every available port (fallback)
    for (const QSerialPortInfo &info : ports) {
        qDebug() << "[Arduino] Trying port" << info.portName();
        if (connectToPort(info.portName()))
            return true;
    }

    emit errorOccurred(tr("No Arduino found. Check the USB cable and COM port."));
    return false;
}

void ArduinoController::disconnect()
{
    if (m_serial->isOpen()) {
        m_serial->close();
        emit disconnected();
        qDebug() << "[Arduino] Disconnected.";
    }
}

bool ArduinoController::isConnected() const
{
    return m_serial->isOpen();
}

QString ArduinoController::currentPort() const
{
    return m_serial->portName();
}

// -------------------------------------------------------
// Data sending
// -------------------------------------------------------

bool ArduinoController::sendPublicationCount(int total, int journals, int conferences)
{
    // Protocol: "PUB:<total>:<journals>:<conferences>\n"
    // Example : "PUB:42:18:24\n"
    QString msg = QString("PUB:%1:%2:%3").arg(total).arg(journals).arg(conferences);
    return sendRaw(msg);
}

bool ArduinoController::sendRaw(const QString &message)
{
    if (!m_serial->isOpen()) {
        qDebug() << "[Arduino] sendRaw: port not open.";
        emit errorOccurred(tr("Serial port is not open."));
        return false;
    }

    QByteArray data = (message + "\n").toUtf8();
    qint64 written = m_serial->write(data);

    if (written == -1) {
        qDebug() << "[Arduino] Write error:" << m_serial->errorString();
        emit errorOccurred(tr("Write error: %1").arg(m_serial->errorString()));
        return false;
    }

    m_serial->flush();
    qDebug() << "[Arduino] Sent:" << message;
    return true;
}

// -------------------------------------------------------
// Static helpers
// -------------------------------------------------------

QStringList ArduinoController::availablePorts()
{
    QStringList list;
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
        list << info.portName();
    return list;
}

// -------------------------------------------------------
// Private slots
// -------------------------------------------------------

void ArduinoController::onReadyRead()
{
    m_readBuffer += m_serial->readAll();

    // Parse complete lines
    while (m_readBuffer.contains('\n')) {
        int idx = m_readBuffer.indexOf('\n');
        QString line = QString::fromUtf8(m_readBuffer.left(idx)).trimmed();
        m_readBuffer.remove(0, idx + 1);

        if (!line.isEmpty()) {
            qDebug() << "[Arduino] Received:" << line;
            emit dataReceived(line);
        }
    }
}

void ArduinoController::onErrorOccurred(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::NoError)
        return;

    QString msg = tr("Serial error (%1): %2").arg(error).arg(m_serial->errorString());
    qDebug() << "[Arduino]" << msg;
    emit errorOccurred(msg);

    if (error == QSerialPort::ResourceError) {
        // Device unplugged
        m_serial->close();
        emit disconnected();
    }
}
