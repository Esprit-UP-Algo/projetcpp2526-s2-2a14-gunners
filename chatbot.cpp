#include "chatbot.h"
#include <QScrollBar>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

Chatbot::Chatbot(QWidget *parent) : QWidget(parent), currentRole("Non connecté")
{
    setupUI();
    appendMessage("Assistant", "Bienvenue dans <b>SmartResearch Assistant</b> !<br><br>Je suis votre interface intelligente unifiant la <b>Gestion des Utilisateurs</b> et la <b>Gestion des Publications</b>.");
    appendMessage("Assistant", "<b>Voici ce que je peux faire :</b><br>"
                               "• <b>Lister</b> les publications ou utilisateurs<br>"
                               "• <b>Rechercher</b> par ID, nom, titre, mot-clé...<br>"
                               "• <b>Afficher les statistiques</b> (par statut, type, rôle...)<br>"
                               "• <b>Filtrer</b> les publications par auteur ou statut<br>"
                               "• <b>Filtrer</b> les utilisateurs par rôle<br>"
                               "• <b>Naviguer</b> directement vers les pages de gestion<br><br>"
                               "Utilisez les <b>boutons rapides</b> ci-dessus ou tapez votre demande en langage naturel !");
}

void Chatbot::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Header Area
    QFrame *headerFrame = new QFrame();
    headerFrame->setFixedHeight(60);
    headerFrame->setStyleSheet("background-color: rgb(0, 36, 168); border-bottom: 2px solid #334155;");
    QHBoxLayout *headerLayout = new QHBoxLayout(headerFrame);
    
    QLabel *titleLabel = new QLabel("SmartResearch Assistant");
    titleLabel->setStyleSheet("color: white; font-size: 18px; font-weight: bold;");
    
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();

    // Quick Buttons Area
    QFrame *btnFrame = new QFrame();
    btnFrame->setStyleSheet("background-color: #f1f5f9; padding: 10px;");
    QHBoxLayout *btnLayout = new QHBoxLayout(btnFrame);
    btnLayout->setSpacing(10);
    
    QStringList buttons = {"Publications", "Utilisateurs", "Stats Pubs", "Stats Users", "Chercher Pub", "Chercher User", "Aide"};
    for (const QString &text : buttons) {
        QPushButton *btn = new QPushButton(text);
        btn->setCursor(Qt::PointingHandCursor);
        btn->setStyleSheet("QPushButton {"
                           "background-color: #334155;"
                           "color: white;"
                           "border-radius: 15px;"
                           "padding: 8px 15px;"
                           "font-weight: bold;"
                           "font-size: 12px;"
                           "}"
                           "QPushButton:hover {"
                           "background-color: #475569;"
                           "}");
        connect(btn, &QPushButton::clicked, this, &Chatbot::onQuickButtonClicked);
        btnLayout->addWidget(btn);
    }
    btnLayout->addStretch();

    // Chat Log
    chatLog = new QTextBrowser();
    chatLog->setStyleSheet("background-color: white; border: none; padding: 20px; font-size: 14px; line-height: 1.6;");
    chatLog->setOpenExternalLinks(true);

    // Input Area
    QFrame *inputFrame = new QFrame();
    inputFrame->setStyleSheet("background-color: #f8fafc; border-top: 1px solid #e2e8f0; padding: 15px;");
    QHBoxLayout *inputLayout = new QHBoxLayout(inputFrame);
    
    inputField = new QLineEdit();
    inputField->setPlaceholderText("Tapez votre message ici... (ex: lister publications, chercher utilisateur Ahmed)");
    inputField->setStyleSheet("QLineEdit {"
                              "background-color: white;"
                              "border: 1px solid #cbd5e1;"
                              "border-radius: 20px;"
                              "padding: 10px 20px;"
                              "font-size: 14px;"
                              "}"
                              "QLineEdit:focus {"
                              "border: 2px solid #3b82f6;"
                              "}");
    
    sendButton = new QPushButton("Envoyer");
    sendButton->setCursor(Qt::PointingHandCursor);
    sendButton->setStyleSheet("QPushButton {"
                              "background-color: #3b82f6;"
                              "color: white;"
                              "border-radius: 20px;"
                              "padding: 10px 25px;"
                              "font-weight: bold;"
                              "}"
                              "QPushButton:hover {"
                              "background-color: #2563eb;"
                              "}");

    inputLayout->addWidget(inputField);
    inputLayout->addWidget(sendButton);

    mainLayout->addWidget(headerFrame);
    mainLayout->addWidget(btnFrame);
    mainLayout->addWidget(chatLog);
    mainLayout->addWidget(inputFrame);

    connect(sendButton, &QPushButton::clicked, this, &Chatbot::onSendClicked);
    connect(inputField, &QLineEdit::returnPressed, this, &Chatbot::onSendClicked);
}

void Chatbot::setRole(const QString &role)
{
    currentRole = role;
    roleLabel->setText("● Rôle : " + currentRole);
}

void Chatbot::onSendClicked()
{
    QString message = inputField->text().trimmed();
    if (message.isEmpty()) return;

    appendMessage("Vous", message, true);
    inputField->clear();
    processMessage(message.toLower());
}

void Chatbot::onQuickButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;
    
    QString text = btn->text();
    appendMessage("Vous", text, true);
    
    if (text == "Publications") handleListerPubs();
    else if (text == "Utilisateurs") handleListerUsers();
    else if (text == "Stats Pubs") handleStatsPubs();
    else if (text == "Stats Users") handleStatsUsers();
    else if (text == "Chercher Pub") handleChercherPub();
    else if (text == "Chercher User") handleChercherUser();
    else if (text == "Aide") handleAide();
}

void Chatbot::appendMessage(const QString &sender, const QString &message, bool isUser)
{
    QString color = isUser ? "#3b82f6" : "#1e293b";
    QString align = isUser ? "right" : "left";
    
    QString html = QString("<div style='margin-bottom: 15px; text-align: %1;'>"
                           "<b style='color: %2;'>%3 :</b><br>"
                           "<span style='color: #334155;'>%4</span>"
                           "</div>").arg(align, color, sender, message);
    
    chatLog->append(html);
    chatLog->verticalScrollBar()->setValue(chatLog->verticalScrollBar()->maximum());
}

void Chatbot::processMessage(const QString &message)
{
    if (message.contains("lister") && message.contains("publication")) handleListerPubs();
    else if (message.contains("lister") && message.contains("utilisateur")) handleListerUsers();
    else if (message.contains("stat") && message.contains("pub")) handleStatsPubs();
    else if (message.contains("stat") && message.contains("user")) handleStatsUsers();
    else if (message.contains("aide")) handleAide();
    else {
        appendMessage("Assistant", "Désolé, je n'ai pas compris votre demande. Essayez d'utiliser les boutons rapides ou tapez 'aide'.");
    }
}

void Chatbot::handleListerPubs()
{
    Publication p;
    QSqlQueryModel *model = p.afficher();
    int count = model->rowCount();
    
    QString res = QString("J'ai trouvé <b>%1</b> publications dans la base de données :<br><ul>").arg(count);
    for (int i = 0; i < qMin(count, 10); ++i) {
        res += QString("<li>ID %1 : <b>%2</b> (par %3)</li>")
                .arg(model->index(i, 0).data().toString())
                .arg(model->index(i, 1).data().toString())
                .arg(model->index(i, 2).data().toString());
    }
    if (count > 10) res += "<li>... et plus encore.</li>";
    res += "</ul>";
    
    appendMessage("Assistant", res);
}

void Chatbot::handleListerUsers()
{
    Utilisateur u;
    QSqlQueryModel *model = u.afficher();
    int count = model->rowCount();
    
    QString res = QString("J'ai trouvé <b>%1</b> utilisateurs :<br><ul>").arg(count);
    for (int i = 0; i < qMin(count, 10); ++i) {
        res += QString("<li>ID %1 : <b>%2 %3</b> (%4)</li>")
                .arg(model->index(i, 0).data().toString())
                .arg(model->index(i, 1).data().toString())
                .arg(model->index(i, 2).data().toString())
                .arg(model->index(i, 5).data().toString());
    }
    if (count > 10) res += "<li>... et plus encore.</li>";
    res += "</ul>";
    
    appendMessage("Assistant", res);
}

void Chatbot::handleStatsPubs()
{
    QMap<QString, int> stats = Publication::getStatistics();
    QString res = "Voici les statistiques des publications par statut :<br><ul>";
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        res += QString("<li>%1 : <b>%2</b></li>").arg(it.key(), QString::number(it.value()));
    }
    res += "</ul>";
    appendMessage("Assistant", res);
}

void Chatbot::handleStatsUsers()
{
    QMap<QString, int> stats = Utilisateur::getStatistics();
    QString res = "Voici les statistiques des utilisateurs par rôle :<br><ul>";
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        res += QString("<li>%1 : <b>%2</b></li>").arg(it.key(), QString::number(it.value()));
    }
    res += "</ul>";
    appendMessage("Assistant", res);
}

void Chatbot::handleChercherPub()
{
    appendMessage("Assistant", "Pour chercher une publication, tapez l'ID ou une partie du titre. (Fonctionnalité en cours de déploiement)");
}

void Chatbot::handleChercherUser()
{
    appendMessage("Assistant", "Pour chercher un utilisateur, tapez son nom ou son email. (Fonctionnalité en cours de déploiement)");
}

void Chatbot::handleAide()
{
    appendMessage("Assistant", "Je peux vous aider à naviguer et à consulter les données. Utilisez les boutons en haut pour les actions rapides.");
}
