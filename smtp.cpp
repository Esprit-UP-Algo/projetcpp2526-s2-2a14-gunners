#include "smtp.h"

Smtp::Smtp( const QString &user, const QString &pass, const QString &host, int port, int timeout )
{    
    socket = new QSslSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorReceived(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    this->user = user;
    this->pass = pass;
    this->host = host;
    this->port = port;
    this->timeout = timeout;
}

void Smtp::sendMail(const QString &from, const QString &to, const QString &subject, const QString &body)
{
    // --- Vérification de la compatibilité SSL ---
    if (!QSslSocket::supportsSsl()) {
        emit status("SSL Error: Votre installation Qt ne supporte pas SSL. Vérifiez que OpenSSL (libssl & libcrypto DLLs) est installé et dans le PATH.");
        qDebug() << "SSL Support is missing!";
        return;
    }

    message = "To: " + to + "\n";
    message.append("From: " + from + "\n");
    message.append("Subject: " + subject + "\n");
    message.append(body);
    message.replace( QString( "\n" ), QString( "\r\n" ) );
    message.replace( QString( "\r\n.\r\n" ), QString( "\r\n..\r\n" ) );
    this->from = from;
    rcpt = to;
    state = Init;
    
    qDebug() << "Connecting to " << host << ":" << port << " ...";
    socket->connectToHostEncrypted(host, port);
    if (!socket->waitForConnected(timeout)) {
         qDebug() << "Connection timeout: " << socket->errorString();
         emit status("Timeout: " + socket->errorString());
     }

    t = new QTextStream( socket );
}

Smtp::~Smtp()
{
    delete t;
    delete socket;
}

void Smtp::stateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() <<"stateChanged " << socketState;
}

void Smtp::errorReceived(QAbstractSocket::SocketError socketError)
{
    qDebug() << "error " << socketError;
    emit status("Socket Error: " + socket->errorString());
}

void Smtp::disconnected()
{
    qDebug() <<"disconnected";
    qDebug() << "error "  << socket->errorString();
}

void Smtp::connected()
{
    qDebug() << "Connected ";
}

void Smtp::readyRead()
{
     qDebug() <<"readyRead";
    // SMTP is a line-oriented protocol
    QString responseLine;
    while(socket->canReadLine())
    {
        responseLine = socket->readLine();
        response += responseLine;
    }

    if (state == Init && responseLine.startsWith("220"))
    {
        // banner was received, now we can send EHLO
        *t << "EHLO localhost" <<"\r\n";
        t->flush();
        state = HandShake;
    }
    else if (state == HandShake && responseLine.startsWith("250"))
    {
        *t << "AUTH LOGIN" << "\r\n";
        t->flush();
        state = Auth;
    }
    else if (state == Auth && responseLine.startsWith("334"))
    {
        *t << QByteArray().append(user.toUtf8()).toBase64()  << "\r\n";
        t->flush();

        state = User;
    }
    else if (state == User && responseLine.startsWith("334"))
    {
        *t << QByteArray().append(pass.toUtf8()).toBase64() << "\r\n";
        t->flush();

        state = Pass;
    }
    else if (state == Pass && responseLine.startsWith("235"))
    {
        *t << "MAIL FROM:<" << from << ">" << "\r\n";
        t->flush();
        state = Mail;
    }
    else if (state == Mail && responseLine.startsWith("250"))
    {
        *t << "RCPT TO:<" << rcpt << ">" << "\r\n";
        t->flush();
        state = Rcpt;
    }
    else if (state == Rcpt && responseLine.startsWith("250"))
    {
        *t << "DATA" << "\r\n";
        t->flush();
        state = Data;
    }
    else if (state == Data && responseLine.startsWith("354"))
    {
        *t << message << "\r\n.\r\n";
        t->flush();
        state = Body;
    }
    else if (state == Body && responseLine.startsWith("250"))
    {
        *t << "QUIT" << "\r\n";
        t->flush();
        state = Quit;
    }
    else if (state == Quit && responseLine.startsWith("221"))
    {
        state = Close;
        emit status( tr( "Message sent" ) );
    }

    response = "";
}
