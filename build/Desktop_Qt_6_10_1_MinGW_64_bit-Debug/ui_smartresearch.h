/********************************************************************************
** Form generated from reading UI file 'smartresearch.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTRESEARCH_H
#define UI_SMARTRESEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
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

class Ui_SmartResearch
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox;
    QPushButton *GestionUtilisateurs;
    QPushButton *GestionPublications;
    QPushButton *GestionReviewer;
    QPushButton *GestionJournalconference;
    QPushButton *GestionSession;
    QLabel *label_10;
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
    QLabel *label_4;
    QLineEdit *abstractPub;
    QLabel *label_5;
    QFormLayout *formLayout_2;
    QRadioButton *radioButton_Admin_3;
    QRadioButton *radioButton_Admin_4;
    QLabel *label_6;
    QLineEdit *mot_clePub;
    QLabel *label_7;
    QLineEdit *statutPub;
    QDateEdit *datePub;
    QLabel *label_8;
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
    QWidget *tab_utilisateur;
    QGroupBox *groupBox_Utilisateur_Form;
    QWidget *formLayoutWidget_Utilisateur;
    QFormLayout *formLayout_Utilisateur;
    QLabel *label_ID_Utilisateur;
    QLineEdit *lineEdit_ID_Utilisateur;
    QLabel *label_Nom_Utilisateur;
    QLineEdit *lineEdit_Nom_Utilisateur;
    QLabel *label_Email_Utilisateur;
    QLineEdit *lineEdit_Email_Utilisateur;
    QLabel *label_Mdp_Utilisateur;
    QLineEdit *lineEdit_Mdp_Utilisateur;
    QLabel *label_Role_Utilisateur;
    QHBoxLayout *horizontalLayout_Role;
    QRadioButton *radioButton_Admin_2;
    QRadioButton *radioButton_Admin;
    QRadioButton *radioButton_Chercheur;
    QLabel *label_Mot_de_passe;
    QLineEdit *lineEdit_Institution_Utilisateur;
    QLabel *label_num;
    QLineEdit *lineEdit_Institution_Utilisateur_2;
    QLabel *label_Institution;
    QLineEdit *lineEdit_Institution_Utilisateur_3;
    QPushButton *btn_Enregistrer_Utilisateur;
    QPushButton *btn_Modifier_Utilisateur;
    QPushButton *btn_Annuler_Utilisateur;
    QGroupBox *groupBox_Utilisateur_List;
    QLineEdit *lineEdit_Recherche_Utilisateur;
    QPushButton *btn_Recherche_Utilisateur;
    QPushButton *btn_Trie_Utilisateur;
    QTableView *tableView_Utilisateur;
    QPushButton *btn_Supprimer_Utilisateur;
    QPushButton *btn_Exportation_Utilisateur;
    QPushButton *btn_Statistique_Utilisateur;
    QPushButton *btn_Quitter_Utilisateur;
    QWidget *tab_session;
    QGroupBox *groupBox_session;
    QLabel *label_session_title;
    QLabel *label_session_hint;
    QLabel *TableaudeBoard;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SmartResearch)
    {
        if (SmartResearch->objectName().isEmpty())
            SmartResearch->setObjectName("SmartResearch");
        SmartResearch->resize(1488, 857);
        SmartResearch->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
        SmartResearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        centralwidget = new QWidget(SmartResearch);
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
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(40, 40, 1421, 711));
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
        groupBox->setGeometry(QRect(10, 100, 191, 611));
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
        GestionUtilisateurs = new QPushButton(groupBox);
        GestionUtilisateurs->setObjectName("GestionUtilisateurs");
        GestionUtilisateurs->setGeometry(QRect(0, 50, 191, 41));
        GestionUtilisateurs->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionPublications = new QPushButton(groupBox);
        GestionPublications->setObjectName("GestionPublications");
        GestionPublications->setGeometry(QRect(0, 140, 191, 41));
        GestionPublications->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionReviewer = new QPushButton(groupBox);
        GestionReviewer->setObjectName("GestionReviewer");
        GestionReviewer->setGeometry(QRect(0, 230, 191, 41));
        GestionReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionJournalconference = new QPushButton(groupBox);
        GestionJournalconference->setObjectName("GestionJournalconference");
        GestionJournalconference->setGeometry(QRect(0, 310, 191, 61));
        GestionJournalconference->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionSession = new QPushButton(groupBox);
        GestionSession->setObjectName("GestionSession");
        GestionSession->setGeometry(QRect(0, 420, 191, 41));
        GestionSession->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1170, 10, 201, 101));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        label_10->setScaledContents(true);
        tabWidget = new QTabWidget(groupBox_4);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(200, 100, 1221, 621));
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
        formLayoutWidget->setGeometry(QRect(20, 40, 411, 331));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        idPub = new QLineEdit(formLayoutWidget);
        idPub->setObjectName("idPub");
        idPub->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
        idPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, idPub);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_9);

        Id_utilisateur = new QLineEdit(formLayoutWidget);
        Id_utilisateur->setObjectName("Id_utilisateur");
        Id_utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, Id_utilisateur);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_2);

        titrePub = new QLineEdit(formLayoutWidget);
        titrePub->setObjectName("titrePub");
        titrePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, titrePub);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_3);

        auteurPub = new QLineEdit(formLayoutWidget);
        auteurPub->setObjectName("auteurPub");
        auteurPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, auteurPub);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_4);

        abstractPub = new QLineEdit(formLayoutWidget);
        abstractPub->setObjectName("abstractPub");
        abstractPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, abstractPub);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_5);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        radioButton_Admin_3 = new QRadioButton(formLayoutWidget);
        radioButton_Admin_3->setObjectName("radioButton_Admin_3");
        radioButton_Admin_3->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, radioButton_Admin_3);

        radioButton_Admin_4 = new QRadioButton(formLayoutWidget);
        radioButton_Admin_4->setObjectName("radioButton_Admin_4");
        radioButton_Admin_4->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, radioButton_Admin_4);


        formLayout->setLayout(5, QFormLayout::ItemRole::FieldRole, formLayout_2);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_6);

        mot_clePub = new QLineEdit(formLayoutWidget);
        mot_clePub->setObjectName("mot_clePub");
        mot_clePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, mot_clePub);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, label_7);

        statutPub = new QLineEdit(formLayoutWidget);
        statutPub->setObjectName("statutPub");
        statutPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, statutPub);

        datePub = new QDateEdit(formLayoutWidget);
        datePub->setObjectName("datePub");
        datePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, datePub);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, label_8);

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
        groupBox_3->setGeometry(QRect(460, 10, 711, 541));
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
        tab_utilisateur = new QWidget();
        tab_utilisateur->setObjectName("tab_utilisateur");
        groupBox_Utilisateur_Form = new QGroupBox(tab_utilisateur);
        groupBox_Utilisateur_Form->setObjectName("groupBox_Utilisateur_Form");
        groupBox_Utilisateur_Form->setGeometry(QRect(0, 10, 451, 541));
        groupBox_Utilisateur_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168); border: #A8D3F0;"));
        formLayoutWidget_Utilisateur = new QWidget(groupBox_Utilisateur_Form);
        formLayoutWidget_Utilisateur->setObjectName("formLayoutWidget_Utilisateur");
        formLayoutWidget_Utilisateur->setGeometry(QRect(20, 50, 411, 301));
        formLayout_Utilisateur = new QFormLayout(formLayoutWidget_Utilisateur);
        formLayout_Utilisateur->setObjectName("formLayout_Utilisateur");
        formLayout_Utilisateur->setContentsMargins(0, 0, 0, 0);
        label_ID_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_ID_Utilisateur->setObjectName("label_ID_Utilisateur");

        formLayout_Utilisateur->setWidget(0, QFormLayout::ItemRole::LabelRole, label_ID_Utilisateur);

        lineEdit_ID_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_ID_Utilisateur->setObjectName("lineEdit_ID_Utilisateur");
        lineEdit_ID_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_ID_Utilisateur);

        label_Nom_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Nom_Utilisateur->setObjectName("label_Nom_Utilisateur");

        formLayout_Utilisateur->setWidget(1, QFormLayout::ItemRole::LabelRole, label_Nom_Utilisateur);

        lineEdit_Nom_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Nom_Utilisateur->setObjectName("lineEdit_Nom_Utilisateur");
        lineEdit_Nom_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_Nom_Utilisateur);

        label_Email_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Email_Utilisateur->setObjectName("label_Email_Utilisateur");

        formLayout_Utilisateur->setWidget(2, QFormLayout::ItemRole::LabelRole, label_Email_Utilisateur);

        lineEdit_Email_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Email_Utilisateur->setObjectName("lineEdit_Email_Utilisateur");
        lineEdit_Email_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_Email_Utilisateur);

        label_Mdp_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Mdp_Utilisateur->setObjectName("label_Mdp_Utilisateur");

        formLayout_Utilisateur->setWidget(3, QFormLayout::ItemRole::LabelRole, label_Mdp_Utilisateur);

        lineEdit_Mdp_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Mdp_Utilisateur->setObjectName("lineEdit_Mdp_Utilisateur");
        lineEdit_Mdp_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_Mdp_Utilisateur->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout_Utilisateur->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_Mdp_Utilisateur);

        label_Role_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Role_Utilisateur->setObjectName("label_Role_Utilisateur");

        formLayout_Utilisateur->setWidget(4, QFormLayout::ItemRole::LabelRole, label_Role_Utilisateur);

        horizontalLayout_Role = new QHBoxLayout();
        horizontalLayout_Role->setObjectName("horizontalLayout_Role");
        radioButton_Admin_2 = new QRadioButton(formLayoutWidget_Utilisateur);
        radioButton_Admin_2->setObjectName("radioButton_Admin_2");
        radioButton_Admin_2->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role->addWidget(radioButton_Admin_2);

        radioButton_Admin = new QRadioButton(formLayoutWidget_Utilisateur);
        radioButton_Admin->setObjectName("radioButton_Admin");
        radioButton_Admin->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role->addWidget(radioButton_Admin);

        radioButton_Chercheur = new QRadioButton(formLayoutWidget_Utilisateur);
        radioButton_Chercheur->setObjectName("radioButton_Chercheur");
        radioButton_Chercheur->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role->addWidget(radioButton_Chercheur);


        formLayout_Utilisateur->setLayout(4, QFormLayout::ItemRole::FieldRole, horizontalLayout_Role);

        label_Mot_de_passe = new QLabel(formLayoutWidget_Utilisateur);
        label_Mot_de_passe->setObjectName("label_Mot_de_passe");

        formLayout_Utilisateur->setWidget(5, QFormLayout::ItemRole::LabelRole, label_Mot_de_passe);

        lineEdit_Institution_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Institution_Utilisateur->setObjectName("lineEdit_Institution_Utilisateur");
        lineEdit_Institution_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(5, QFormLayout::ItemRole::FieldRole, lineEdit_Institution_Utilisateur);

        label_num = new QLabel(formLayoutWidget_Utilisateur);
        label_num->setObjectName("label_num");

        formLayout_Utilisateur->setWidget(6, QFormLayout::ItemRole::LabelRole, label_num);

        lineEdit_Institution_Utilisateur_2 = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Institution_Utilisateur_2->setObjectName("lineEdit_Institution_Utilisateur_2");
        lineEdit_Institution_Utilisateur_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(6, QFormLayout::ItemRole::FieldRole, lineEdit_Institution_Utilisateur_2);

        label_Institution = new QLabel(formLayoutWidget_Utilisateur);
        label_Institution->setObjectName("label_Institution");

        formLayout_Utilisateur->setWidget(7, QFormLayout::ItemRole::LabelRole, label_Institution);

        lineEdit_Institution_Utilisateur_3 = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Institution_Utilisateur_3->setObjectName("lineEdit_Institution_Utilisateur_3");
        lineEdit_Institution_Utilisateur_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(7, QFormLayout::ItemRole::FieldRole, lineEdit_Institution_Utilisateur_3);

        btn_Enregistrer_Utilisateur = new QPushButton(groupBox_Utilisateur_Form);
        btn_Enregistrer_Utilisateur->setObjectName("btn_Enregistrer_Utilisateur");
        btn_Enregistrer_Utilisateur->setGeometry(QRect(40, 400, 150, 41));
        btn_Enregistrer_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        btn_Modifier_Utilisateur = new QPushButton(groupBox_Utilisateur_Form);
        btn_Modifier_Utilisateur->setObjectName("btn_Modifier_Utilisateur");
        btn_Modifier_Utilisateur->setGeometry(QRect(240, 400, 150, 41));
        btn_Modifier_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        btn_Annuler_Utilisateur = new QPushButton(groupBox_Utilisateur_Form);
        btn_Annuler_Utilisateur->setObjectName("btn_Annuler_Utilisateur");
        btn_Annuler_Utilisateur->setGeometry(QRect(150, 460, 150, 41));
        btn_Annuler_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        groupBox_Utilisateur_List = new QGroupBox(tab_utilisateur);
        groupBox_Utilisateur_List->setObjectName("groupBox_Utilisateur_List");
        groupBox_Utilisateur_List->setGeometry(QRect(460, 10, 711, 541));
        groupBox_Utilisateur_List->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168); border: #A8D3F0;\n"
"        QGroupBox { border: 2px solid #2c3e50; border-radius: 15px; margin-top: 20px; font-weight: bold; color: #2c3e50; }\n"
"        QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 10px; }\n"
"        "));
        lineEdit_Recherche_Utilisateur = new QLineEdit(groupBox_Utilisateur_List);
        lineEdit_Recherche_Utilisateur->setObjectName("lineEdit_Recherche_Utilisateur");
        lineEdit_Recherche_Utilisateur->setGeometry(QRect(10, 40, 161, 26));
        lineEdit_Recherche_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        btn_Recherche_Utilisateur = new QPushButton(groupBox_Utilisateur_List);
        btn_Recherche_Utilisateur->setObjectName("btn_Recherche_Utilisateur");
        btn_Recherche_Utilisateur->setGeometry(QRect(180, 38, 150, 31));
        btn_Recherche_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        btn_Trie_Utilisateur = new QPushButton(groupBox_Utilisateur_List);
        btn_Trie_Utilisateur->setObjectName("btn_Trie_Utilisateur");
        btn_Trie_Utilisateur->setGeometry(QRect(560, 40, 150, 31));
        btn_Trie_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        tableView_Utilisateur = new QTableView(groupBox_Utilisateur_List);
        tableView_Utilisateur->setObjectName("tableView_Utilisateur");
        tableView_Utilisateur->setGeometry(QRect(10, 80, 691, 341));
        tableView_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        btn_Supprimer_Utilisateur = new QPushButton(groupBox_Utilisateur_List);
        btn_Supprimer_Utilisateur->setObjectName("btn_Supprimer_Utilisateur");
        btn_Supprimer_Utilisateur->setGeometry(QRect(40, 440, 150, 41));
        btn_Supprimer_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        btn_Exportation_Utilisateur = new QPushButton(groupBox_Utilisateur_List);
        btn_Exportation_Utilisateur->setObjectName("btn_Exportation_Utilisateur");
        btn_Exportation_Utilisateur->setGeometry(QRect(390, 440, 150, 31));
        btn_Exportation_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        btn_Statistique_Utilisateur = new QPushButton(groupBox_Utilisateur_List);
        btn_Statistique_Utilisateur->setObjectName("btn_Statistique_Utilisateur");
        btn_Statistique_Utilisateur->setGeometry(QRect(560, 440, 150, 31));
        btn_Statistique_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        btn_Quitter_Utilisateur = new QPushButton(groupBox_Utilisateur_List);
        btn_Quitter_Utilisateur->setObjectName("btn_Quitter_Utilisateur");
        btn_Quitter_Utilisateur->setGeometry(QRect(480, 480, 150, 31));
        btn_Quitter_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        tabWidget->addTab(tab_utilisateur, QString());
        tab_session = new QWidget();
        tab_session->setObjectName("tab_session");
        groupBox_session = new QGroupBox(tab_session);
        groupBox_session->setObjectName("groupBox_session");
        groupBox_session->setGeometry(QRect(0, 10, 1171, 541));
        groupBox_session->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168); border: #A8D3F0;"));
        label_session_title = new QLabel(groupBox_session);
        label_session_title->setObjectName("label_session_title");
        label_session_title->setGeometry(QRect(20, 20, 500, 30));
        label_session_hint = new QLabel(groupBox_session);
        label_session_hint->setObjectName("label_session_hint");
        label_session_hint->setGeometry(QRect(20, 60, 900, 30));
        label_session_hint->setStyleSheet(QString::fromUtf8("color: white;"));
        tabWidget->addTab(tab_session, QString());
        TableaudeBoard = new QLabel(groupBox_4);
        TableaudeBoard->setObjectName("TableaudeBoard");
        TableaudeBoard->setGeometry(QRect(30, 70, 141, 41));
        TableaudeBoard->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"font: 300 9pt \"Segoe UI\";\n"
""));
        SmartResearch->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SmartResearch);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1488, 26));
        SmartResearch->setMenuBar(menubar);
        statusbar = new QStatusBar(SmartResearch);
        statusbar->setObjectName("statusbar");
        SmartResearch->setStatusBar(statusbar);

        retranslateUi(SmartResearch);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SmartResearch);
    } // setupUi

    void retranslateUi(QMainWindow *SmartResearch)
    {
        SmartResearch->setWindowTitle(QCoreApplication::translate("SmartResearch", "SmartResearch", nullptr));
        groupBox_4->setTitle(QString());
        groupBox->setTitle(QString());
        GestionUtilisateurs->setText(QCoreApplication::translate("SmartResearch", "Gestion Utilisateur", nullptr));
        GestionPublications->setText(QCoreApplication::translate("SmartResearch", "Gestion Publication", nullptr));
        GestionReviewer->setText(QCoreApplication::translate("SmartResearch", "Gestion Reviewer", nullptr));
        GestionJournalconference->setText(QCoreApplication::translate("SmartResearch", "Gestion Journal/\n"
"Conf\303\251rence", nullptr));
        GestionSession->setText(QCoreApplication::translate("SmartResearch", "Gestion Session", nullptr));
        label_10->setText(QString());
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID_Utilisateur</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Titre</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Auteurs</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Abstract</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        radioButton_Admin_3->setText(QCoreApplication::translate("SmartResearch", "Conf\303\251rence", nullptr));
        radioButton_Admin_4->setText(QCoreApplication::translate("SmartResearch", "Journal", nullptr));
        label_6->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mots cl\303\251s</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Statut</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Date de soumission</span></p></body></html>", nullptr));
        enregistrer->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modif->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annuler->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_3->setTitle(QString());
        recherchePub->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        statPub->setText(QCoreApplication::translate("SmartResearch", "Statistique ", nullptr));
        SuppPub->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        quitterPub->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        expoPub->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        triePub->setText(QCoreApplication::translate("SmartResearch", "Trie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SmartResearch", "Gestion Publication", nullptr));
        groupBox_Utilisateur_Form->setTitle(QString());
        label_ID_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_Nom_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_Email_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Email</span></p></body></html>", nullptr));
        label_Mdp_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mot de passe</span></p></body></html>", nullptr));
        label_Role_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Role</span></p></body></html>", nullptr));
        radioButton_Admin_2->setText(QCoreApplication::translate("SmartResearch", "Admin", nullptr));
        radioButton_Admin->setText(QCoreApplication::translate("SmartResearch", "editer", nullptr));
        radioButton_Chercheur->setText(QCoreApplication::translate("SmartResearch", "reviewer", nullptr));
        label_Mot_de_passe->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mot de passe user</span></p></body></html>", nullptr));
        label_num->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Num</span></p></body></html>", nullptr));
        label_Institution->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Institution</span></p></body></html>", nullptr));
        btn_Enregistrer_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        btn_Modifier_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        btn_Annuler_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_Utilisateur_List->setTitle(QString());
        btn_Recherche_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        btn_Trie_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Trie", nullptr));
        btn_Supprimer_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        btn_Exportation_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        btn_Statistique_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Statistique", nullptr));
        btn_Quitter_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_utilisateur), QCoreApplication::translate("SmartResearch", "Gestion Utilisateur", nullptr));
        groupBox_session->setTitle(QString());
        label_session_title->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">Module Gestion Session</span></p></body></html>", nullptr));
        label_session_hint->setText(QCoreApplication::translate("SmartResearch", "Placeholder: navigation OK. L\342\200\231UI GestionSession sera int\303\251gr\303\251e ensuite.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_session), QCoreApplication::translate("SmartResearch", "Gestion Session", nullptr));
        TableaudeBoard->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#ffffff;\">Tableau de Board</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmartResearch: public Ui_SmartResearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTRESEARCH_H
