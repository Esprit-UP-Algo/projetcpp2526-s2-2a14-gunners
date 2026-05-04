#ifndef CHATBOT_H
#define CHATBOT_H

#include <QWidget>
#include <QTextBrowser>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QFrame>
#include <QMap>
#include <QDate>
#include "publication.h"
#include "utilisateur.h"

class Chatbot : public QWidget
{
    Q_OBJECT
public:
    explicit Chatbot(QWidget *parent = nullptr);
    void setRole(const QString &role);

private slots:
    void onSendClicked();
    void onQuickButtonClicked();

private:
    void setupUI();
    void processMessage(const QString &message);
    void appendMessage(const QString &sender, const QString &message, bool isUser = false);
    
    // UI Elements
    QTextBrowser *chatLog;
    QLineEdit *inputField;
    QPushButton *sendButton;
    QLabel *roleLabel;
    
    // Command Handlers
    void handleListerPubs();
    void handleListerUsers();
    void handleStatsPubs();
    void handleStatsUsers();
    void handleChercherPub();
    void handleChercherUser();
    void handleAide();
    
    QString currentRole;
};

#endif // CHATBOT_H
