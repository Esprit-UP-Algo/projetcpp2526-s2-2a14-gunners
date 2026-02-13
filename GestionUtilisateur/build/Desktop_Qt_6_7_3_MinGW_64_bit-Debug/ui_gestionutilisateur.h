/********************************************************************************
** Form generated from reading UI file 'gestionutilisateur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONUTILISATEUR_H
#define UI_GESTIONUTILISATEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestionutilisateur
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *idPub;
    QLabel *label_9;
    QLineEdit *Id_utilisateur;
    QLabel *label_2;
    QLineEdit *titrePub;
    QLabel *label_3;
    QLineEdit *auteurPub;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *statutPub;
    QFormLayout *formLayout_2;
    QRadioButton *conferencePub;
    QRadioButton *journalPub;
    QPushButton *enregistrer;
    QPushButton *modif;
    QPushButton *annuler;
    QGroupBox *groupBox_3;
    QLineEdit *rechPub;
    QPushButton *recherchePub;
    QPushButton *statPub;
    QPushButton *SuppPub;
    QPushButton *quitterPub;
    QTableView *tableViewPub;
    QPushButton *expoPub;
    QPushButton *triePub;
    QLabel *TableaudeBoard;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox;
    QLabel *GestionUtilisateurs;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gestionutilisateur)
    {
        if (gestionutilisateur->objectName().isEmpty())
            gestionutilisateur->setObjectName("gestionutilisateur");
        gestionutilisateur->resize(1470, 842);
        gestionutilisateur->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
        gestionutilisateur->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* La couleur de fond (bleu pro) */\n"
"    background-color: #2c3e50; \n"
"    \n"
"    /* La couleur du texte */\n"
"    color: white;\n"
"    \n"
"    /* L'ARRONDI : plus le chiffre est grand, plus c'est rond */\n"
"    border-radius: 15px;\n"
"    \n"
"    /* Une bordure fine pour d\303\251finir la forme */\n"
"    border: 1px solid #34495e;\n"
"    \n"
"    /* Espacement interne pour que le texte ne touche pas les bords */\n"
"    padding: 5px 15px;\n"
"}\n"
"\n"
"/* Effet au survol de la souris */\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}\n"
""));
        centralwidget = new QWidget(gestionutilisateur);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* La couleur de fond (bleu pro) */\n"
"    background-color: #2c3e50; \n"
"    \n"
"    /* La couleur du texte */\n"
"    color: white;\n"
"    \n"
"    /* L'ARRONDI : plus le chiffre est grand, plus c'est rond */\n"
"    border-radius: 15px;\n"
"    \n"
"    /* Une bordure fine pour d\303\251finir la forme */\n"
"    border: 1px solid #34495e;\n"
"    \n"
"    /* Espacement interne pour que le texte ne touche pas les bords */\n"
"    padding: 5px 15px;\n"
"}\n"
"\n"
"/* Effet au survol de la souris */\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(200, 90, 1211, 601));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #D8E2E9;\n"
"QPushButton {\n"
"    /* La couleur de fond (bleu pro) */\n"
"    background-color: #2c3e50; \n"
"    \n"
"    /* La couleur du texte */\n"
"    color: white;\n"
"    \n"
"    /* L'ARRONDI : plus le chiffre est grand, plus c'est rond */\n"
"    border-radius: 15px;\n"
"    \n"
"    /* Une bordure fine pour d\303\251finir la forme */\n"
"    border: 1px solid #34495e;\n"
"    \n"
"    /* Espacement interne pour que le texte ne touche pas les bords */\n"
"    padding: 5px 15px;\n"
"}\n"
"\n"
"/* Effet au survol de la souris */\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 10, 451, 541));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;"));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 40, 411, 271));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        idPub = new QLineEdit(formLayoutWidget);
        idPub->setObjectName("idPub");
        idPub->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
        idPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout->setWidget(0, QFormLayout::FieldRole, idPub);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_9);

        Id_utilisateur = new QLineEdit(formLayoutWidget);
        Id_utilisateur->setObjectName("Id_utilisateur");
        Id_utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Id_utilisateur);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        titrePub = new QLineEdit(formLayoutWidget);
        titrePub->setObjectName("titrePub");
        titrePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, titrePub);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        auteurPub = new QLineEdit(formLayoutWidget);
        auteurPub->setObjectName("auteurPub");
        auteurPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, auteurPub);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        statutPub = new QLineEdit(formLayoutWidget);
        statutPub->setObjectName("statutPub");
        statutPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(5, QFormLayout::FieldRole, statutPub);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        conferencePub = new QRadioButton(formLayoutWidget);
        conferencePub->setObjectName("conferencePub");
        conferencePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, conferencePub);

        journalPub = new QRadioButton(formLayoutWidget);
        journalPub->setObjectName("journalPub");
        journalPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, journalPub);


        formLayout->setLayout(4, QFormLayout::FieldRole, formLayout_2);

        enregistrer = new QPushButton(groupBox_2);
        enregistrer->setObjectName("enregistrer");
        enregistrer->setGeometry(QRect(40, 400, 150, 41));
        enregistrer->setMinimumSize(QSize(0, 0));
        enregistrer->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        modif = new QPushButton(groupBox_2);
        modif->setObjectName("modif");
        modif->setGeometry(QRect(240, 400, 150, 41));
        modif->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        annuler = new QPushButton(groupBox_2);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(150, 460, 150, 41));
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(470, 20, 711, 531));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"/* Style sp\303\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        rechPub = new QLineEdit(groupBox_3);
        rechPub->setObjectName("rechPub");
        rechPub->setGeometry(QRect(10, 40, 161, 26));
        rechPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        recherchePub = new QPushButton(groupBox_3);
        recherchePub->setObjectName("recherchePub");
        recherchePub->setGeometry(QRect(180, 38, 150, 31));
        recherchePub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        statPub = new QPushButton(groupBox_3);
        statPub->setObjectName("statPub");
        statPub->setGeometry(QRect(560, 440, 150, 31));
        statPub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        SuppPub = new QPushButton(groupBox_3);
        SuppPub->setObjectName("SuppPub");
        SuppPub->setGeometry(QRect(40, 440, 150, 41));
        SuppPub->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        quitterPub = new QPushButton(groupBox_3);
        quitterPub->setObjectName("quitterPub");
        quitterPub->setGeometry(QRect(480, 480, 150, 31));
        quitterPub->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        tableViewPub = new QTableView(groupBox_3);
        tableViewPub->setObjectName("tableViewPub");
        tableViewPub->setGeometry(QRect(10, 80, 691, 341));
        tableViewPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        expoPub = new QPushButton(groupBox_3);
        expoPub->setObjectName("expoPub");
        expoPub->setGeometry(QRect(390, 440, 150, 31));
        expoPub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        triePub = new QPushButton(groupBox_3);
        triePub->setObjectName("triePub");
        triePub->setGeometry(QRect(560, 40, 150, 31));
        triePub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        tabWidget->addTab(tab, QString());
        TableaudeBoard = new QLabel(centralwidget);
        TableaudeBoard->setObjectName("TableaudeBoard");
        TableaudeBoard->setGeometry(QRect(30, 60, 141, 41));
        TableaudeBoard->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"font: 300 9pt \"Segoe UI\";\n"
""));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(0, 10, 1421, 711));
        groupBox_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* La couleur de fond (bleu pro) */\n"
"    background-color: #2c3e50; \n"
"    \n"
"    /* La couleur du texte */\n"
"    color: white;\n"
"    \n"
"    /* L'ARRONDI : plus le chiffre est grand, plus c'est rond */\n"
"    border-radius: 15px;\n"
"    \n"
"    /* Une bordure fine pour d\303\251finir la forme */\n"
"    border: 1px solid #34495e;\n"
"    \n"
"    /* Espacement interne pour que le texte ne touche pas les bords */\n"
"    padding: 5px 15px;\n"
"}\n"
"\n"
"/* Effet au survol de la souris */\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 70, 191, 611));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: #D8E2E9;\n"
"QPushButton {\n"
"    /* La couleur de fond (bleu pro) */\n"
"    background-color: #2c3e50; \n"
"    \n"
"    /* La couleur du texte */\n"
"    color: white;\n"
"    \n"
"    /* L'ARRONDI : plus le chiffre est grand, plus c'est rond */\n"
"    border-radius: 15px;\n"
"    \n"
"    /* Une bordure fine pour d\303\251finir la forme */\n"
"    border: 1px solid #34495e;\n"
"    \n"
"    /* Espacement interne pour que le texte ne touche pas les bords */\n"
"    padding: 5px 15px;\n"
"}\n"
"\n"
"/* Effet au survol de la souris */\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        GestionUtilisateurs = new QLabel(groupBox);
        GestionUtilisateurs->setObjectName("GestionUtilisateurs");
        GestionUtilisateurs->setGeometry(QRect(0, 50, 191, 41));
        GestionUtilisateurs->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton#btn_menu {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 10px;\n"
"}\n"
""));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1190, 10, 181, 91));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        gestionutilisateur->setCentralWidget(centralwidget);
        groupBox_4->raise();
        tabWidget->raise();
        TableaudeBoard->raise();
        menubar = new QMenuBar(gestionutilisateur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1470, 26));
        gestionutilisateur->setMenuBar(menubar);
        statusbar = new QStatusBar(gestionutilisateur);
        statusbar->setObjectName("statusbar");
        gestionutilisateur->setStatusBar(statusbar);

        retranslateUi(gestionutilisateur);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(gestionutilisateur);
    } // setupUi

    void retranslateUi(QMainWindow *gestionutilisateur)
    {
        gestionutilisateur->setWindowTitle(QCoreApplication::translate("gestionutilisateur", "Gestion Utilisateur", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("gestionutilisateur", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("gestionutilisateur", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("gestionutilisateur", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Email</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("gestionutilisateur", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mot de passe</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("gestionutilisateur", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Role</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("gestionutilisateur", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Institution</span></p></body></html>", nullptr));
        conferencePub->setText(QCoreApplication::translate("gestionutilisateur", "Admin          ", nullptr));
        journalPub->setText(QCoreApplication::translate("gestionutilisateur", "Chercheur", nullptr));
        enregistrer->setText(QCoreApplication::translate("gestionutilisateur", "Enregistrer", nullptr));
        modif->setText(QCoreApplication::translate("gestionutilisateur", "Modifier", nullptr));
        annuler->setText(QCoreApplication::translate("gestionutilisateur", "Annuler", nullptr));
        groupBox_3->setTitle(QString());
        recherchePub->setText(QCoreApplication::translate("gestionutilisateur", "Recherche", nullptr));
        statPub->setText(QCoreApplication::translate("gestionutilisateur", "Statistique ", nullptr));
        SuppPub->setText(QCoreApplication::translate("gestionutilisateur", "Supprimer", nullptr));
        quitterPub->setText(QCoreApplication::translate("gestionutilisateur", "Quitter", nullptr));
        expoPub->setText(QCoreApplication::translate("gestionutilisateur", "Exportation", nullptr));
        triePub->setText(QCoreApplication::translate("gestionutilisateur", "Trie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("gestionutilisateur", "Gestion Utlisateur", nullptr));
        TableaudeBoard->setText(QCoreApplication::translate("gestionutilisateur", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#ffffff;\">Tableau de Board</span></p></body></html>", nullptr));
        groupBox_4->setTitle(QString());
        groupBox->setTitle(QString());
        GestionUtilisateurs->setText(QCoreApplication::translate("gestionutilisateur", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Gestion Utilisateur</span></p></body></html>", nullptr));
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gestionutilisateur: public Ui_gestionutilisateur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONUTILISATEUR_H
