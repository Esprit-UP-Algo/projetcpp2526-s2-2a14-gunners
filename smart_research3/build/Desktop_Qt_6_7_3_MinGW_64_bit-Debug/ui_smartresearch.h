/********************************************************************************
** Form generated from reading UI file 'smartresearch.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTRESEARCH_H
#define UI_SMARTRESEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *GestionSession_2;
    QLabel *label_10;
    QStackedWidget *stackedWidget;
    QWidget *page_login;
    QVBoxLayout *verticalLayout_login;
    QSpacerItem *verticalSpacer_login_top;
    QLabel *lblLogo_login;
    QGridLayout *gridLayout_login_form;
    QLabel *label_username_login;
    QLineEdit *txtUsername_login;
    QLabel *label_password_login;
    QLineEdit *txtPassword_login;
    QPushButton *btnLogin_main;
    QSpacerItem *verticalSpacer_login_bottom;
    QWidget *stackedWidgetPage1;
    QGroupBox *groupBox_Utilisateur_Form;
    QWidget *formLayoutWidget_Utilisateur;
    QFormLayout *formLayout_Utilisateur;
    QLabel *label_ID_Utilisateur;
    QLineEdit *lineEdit_ID_Utilisateur;
    QLabel *label_Nom_Utilisateur;
    QLineEdit *lineEdit_Nom_Utilisateur;
    QLabel *label_Prenom_Utilisateur;
    QLineEdit *lineEdit_Prenom_Utilisateur;
    QLabel *label_Email_Utilisateur;
    QLineEdit *lineEdit_Email_Utilisateur;
    QLabel *label_Mdp_Utilisateur;
    QLineEdit *lineEdit_Mdp_Utilisateur;
    QLabel *label_Role_Utilisateur;
    QHBoxLayout *horizontalLayout_Role;
    QRadioButton *radioButton_Admin_7;
    QRadioButton *radioButton_Admin_2;
    QRadioButton *radioButton_Admin;
    QRadioButton *radioButton_Chercheur;
    QLabel *label_num;
    QLineEdit *lineEdit_Institution_Utilisateur_2;
    QLabel *label_Institution;
    QLineEdit *lineEdit_Institution_Utilisateur_3;
    QPushButton *btn_Enregistrer_Utilisateur;
    QPushButton *modif_3;
    QPushButton *annulerajout_client_3;
    QGroupBox *groupBox_Session_List_6;
    QTableView *tableWidget_10;
    QGroupBox *groupBox_Stats_Utilisateur;
    QLabel *label_Chart_Utilisateur;
    QPushButton *pushButton_supprimer_client_2;
    QPushButton *pushButton_pdfclient;
    QPushButton *quitterSession_7;
    QPushButton *pushButton_recherche_4;
    QLineEdit *rechSession_7;
    QComboBox *comboBox_11;
    QWidget *stackedWidgetPage2;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
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
    QHBoxLayout *horizontalLayout_statut;
    QRadioButton *radioButton_statut_attente;
    QRadioButton *radioButton_statut_accepte;
    QRadioButton *radioButton_statut_rejete;
    QLabel *label_8;
    QDateEdit *datePub;
    QPushButton *enregistrer;
    QPushButton *modif;
    QPushButton *annulerajout_client;
    QGroupBox *groupBox_Session_List_5;
    QComboBox *comboBox_9;
    QTableView *tableWidget_9;
    QGroupBox *groupBox_Stats_Publication;
    QLabel *label_Chart_Publication;
    QPushButton *pushButton_recherche_3;
    QLineEdit *rechSession_5;
    QPushButton *pushButton_supprimer_client;
    QPushButton *expoSession_5;
    QPushButton *quitterSession_5;
    QWidget *stackedWidgetPage3;
    QGroupBox *groupBox_Journal_Form;
    QWidget *formLayoutWidget_Journal;
    QFormLayout *formLayout_Journal;
    QLabel *label_Journal_id;
    QLineEdit *id;
    QLabel *label_Journal_nom;
    QLineEdit *nom;
    QLabel *label_Journal_type;
    QComboBox *type;
    QLabel *label_Journal_domaine;
    QComboBox *domaine_scientifique;
    QLabel *label_Journal_facteur;
    QLineEdit *facteur_impact;
    QLabel *label_Journal_classement;
    QComboBox *classement;
    QLabel *label_Journal_pays;
    QComboBox *pays;
    QLabel *label_Journal_organisation;
    QLineEdit *organisation;
    QLabel *label_Journal_periodicite;
    QComboBox *periodicite;
    QLabel *label_Journal_siteweb;
    QLineEdit *siteweb;
    QPushButton *enregistrer1;
    QPushButton *modif1;
    QPushButton *annuler;
    QGroupBox *groupBox_Session_List_4;
    QLineEdit *rechSession_4;
    QPushButton *rechercheSession_4;
    QPushButton *SuppSession_4;
    QPushButton *quitterSession_4;
    QPushButton *expoSession_4;
    QComboBox *comboBox_8;
    QTableWidget *tableWidget_8;
    QGroupBox *groupBox_Stats_Journal;
    QLabel *label_Chart_Journal;
    QWidget *stackedWidgetPage4;
    QGroupBox *groupBox_Reviewer_Form;
    QWidget *formLayoutWidget_Reviewer;
    QFormLayout *formLayout_Reviewer;
    QLabel *label_Rev_ID;
    QLineEdit *idReviewer;
    QLabel *label_Rev_Nom;
    QLineEdit *nomReviewer;
    QLabel *label_Rev_Email;
    QLineEdit *emailReviewer;
    QLabel *label_Rev_Spec;
    QLineEdit *specialiteReviewer;
    QLabel *label_Rev_Inst;
    QLineEdit *institutionReviewer;
    QLabel *label_Rev_Statut;
    QFormLayout *formLayout_Rev_Statut;
    QRadioButton *actifReviewer;
    QRadioButton *inactifReviewer;
    QPushButton *enregistrerReviewer;
    QPushButton *modifierReviewer;
    QPushButton *annulerReviewer;
    QGroupBox *groupBox_Session_List_3;
    QLineEdit *rechSession_3;
    QPushButton *rechercheSession_3;
    QPushButton *SuppSession_3;
    QPushButton *quitterSession_3;
    QPushButton *expoSession_3;
    QComboBox *comboBox_7;
    QTableWidget *tableWidget_7;
    QWidget *stackedWidgetPage5;
    QGroupBox *groupBox_Session_Form;
    QWidget *formLayoutWidget_Session;
    QFormLayout *formLayout_Session;
    QLabel *label_S_ID;
    QLineEdit *idSession;
    QLabel *label_S_Titre;
    QLineEdit *Id_utilisateur_Session;
    QLabel *label_S_Date;
    QLabel *label_S_Lieu;
    QLineEdit *abstractSession;
    QLabel *label_S_Type;
    QLabel *label_S_ListPub;
    QLabel *label_S_ListRev;
    QDateEdit *dateSession;
    QHBoxLayout *horizontalLayout_Role_2;
    QRadioButton *radioButton_Admin_5;
    QRadioButton *radioButton_Admin_6;
    QRadioButton *radioButton_Chercheur_2;
    QLineEdit *lineEdit_publications;
    QLineEdit *lineEdit_reviewers;
    QPushButton *enregistrerSession;
    QPushButton *modifSession;
    QPushButton *annulerSession;
    QGroupBox *groupBox_Session_List;
    QLineEdit *rechSession;
    QPushButton *rechercheSession;
    QPushButton *SuppSession;
    QPushButton *quitterSession;
    QPushButton *expoSession;
    QComboBox *comboBox_5;
    QTableView *tableWidget_5;
    QWidget *stackedWidgetPage6;
    QGroupBox *groupBox_Paiement_Form;
    QWidget *formLayoutWidget_Utilisateur_2;
    QFormLayout *formLayout_Utilisateur_4;
    QLabel *label_ID_Utilisateur_4;
    QLineEdit *lineEdit_ID_Utilisateur_4;
    QLabel *label_Nom_Utilisateur_4;
    QLineEdit *lineEdit_Nom_Utilisateur_4;
    QLabel *label_Email_Utilisateur_4;
    QLineEdit *lineEdit_Email_Utilisateur_4;
    QLabel *label_Mdp_Utilisateur_4;
    QLineEdit *lineEdit_Mdp_Utilisateur_4;
    QLabel *label_Role_Utilisateur_4;
    QLineEdit *lineEdit_Institution_Utilisateur_11;
    QLabel *label_Mot_de_passe_4;
    QLineEdit *lineEdit_Institution_Utilisateur_10;
    QLabel *label_num_4;
    QHBoxLayout *horizontalLayout_Role_4;
    QRadioButton *radioButton_Chercheur_4;
    QRadioButton *radioButton_Admin_10;
    QRadioButton *radioButton_Admin_9;
    QLabel *label_Role_Utilisateur_5;
    QDateEdit *dateEdit;
    QPushButton *btn_Enregistrer_Utilisateur_2;
    QPushButton *btn_Modifier_Utilisateur_2;
    QPushButton *btn_Annuler_Utilisateur_2;
    QGroupBox *groupBox_Session_List_2;
    QLineEdit *rechSession_2;
    QPushButton *rechercheSession_2;
    QPushButton *SuppSession_2;
    QPushButton *quitterSession_2;
    QPushButton *expoSession_2;
    QComboBox *comboBox_6;
    QTableWidget *tableWidget_6;
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
"    /* Une bordure fine pour d\303\203\302\251finir la forme */\n"
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
"    /* Une bordure fine pour d\303\203\302\251finir la forme */\n"
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
"    /* Une bordure fine pour d\303\203\302\251finir la forme */\n"
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
"    /* Une bordure fine pour d\303\203\302\251finir la forme */\n"
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
        GestionUtilisateurs->setGeometry(QRect(0, 50, 181, 41));
        GestionUtilisateurs->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionPublications = new QPushButton(groupBox);
        GestionPublications->setObjectName("GestionPublications");
        GestionPublications->setGeometry(QRect(0, 140, 181, 41));
        GestionPublications->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionReviewer = new QPushButton(groupBox);
        GestionReviewer->setObjectName("GestionReviewer");
        GestionReviewer->setGeometry(QRect(0, 230, 181, 41));
        GestionReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionJournalconference = new QPushButton(groupBox);
        GestionJournalconference->setObjectName("GestionJournalconference");
        GestionJournalconference->setGeometry(QRect(0, 310, 181, 61));
        GestionJournalconference->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionSession = new QPushButton(groupBox);
        GestionSession->setObjectName("GestionSession");
        GestionSession->setGeometry(QRect(0, 420, 181, 41));
        GestionSession->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        GestionSession_2 = new QPushButton(groupBox);
        GestionSession_2->setObjectName("GestionSession_2");
        GestionSession_2->setGeometry(QRect(0, 490, 181, 41));
        GestionSession_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1230, 0, 201, 101));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        label_10->setScaledContents(true);
        stackedWidget = new QStackedWidget(groupBox_4);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(200, 100, 1221, 621));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #D8E2E9;\n"
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
"    /* Une bordure fine pour d\303\203\302\251finir la forme */\n"
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
        page_login = new QWidget();
        page_login->setObjectName("page_login");
        verticalLayout_login = new QVBoxLayout(page_login);
        verticalLayout_login->setObjectName("verticalLayout_login");
        verticalSpacer_login_top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_login->addItem(verticalSpacer_login_top);

        lblLogo_login = new QLabel(page_login);
        lblLogo_login->setObjectName("lblLogo_login");
        lblLogo_login->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        lblLogo_login->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_login->addWidget(lblLogo_login);

        gridLayout_login_form = new QGridLayout();
        gridLayout_login_form->setObjectName("gridLayout_login_form");
        gridLayout_login_form->setHorizontalSpacing(20);
        gridLayout_login_form->setVerticalSpacing(15);
        gridLayout_login_form->setContentsMargins(200, -1, 200, -1);
        label_username_login = new QLabel(page_login);
        label_username_login->setObjectName("label_username_login");
        label_username_login->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_login_form->addWidget(label_username_login, 0, 0, 1, 1);

        txtUsername_login = new QLineEdit(page_login);
        txtUsername_login->setObjectName("txtUsername_login");
        txtUsername_login->setMinimumSize(QSize(250, 40));
        txtUsername_login->setStyleSheet(QString::fromUtf8("border: 2px solid #ccc; border-radius: 5px; padding: 5px;"));

        gridLayout_login_form->addWidget(txtUsername_login, 0, 1, 1, 1);

        label_password_login = new QLabel(page_login);
        label_password_login->setObjectName("label_password_login");
        label_password_login->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_login_form->addWidget(label_password_login, 1, 0, 1, 1);

        txtPassword_login = new QLineEdit(page_login);
        txtPassword_login->setObjectName("txtPassword_login");
        txtPassword_login->setMinimumSize(QSize(250, 40));
        txtPassword_login->setStyleSheet(QString::fromUtf8("border: 2px solid #ccc; border-radius: 5px; padding: 5px;"));
        txtPassword_login->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_login_form->addWidget(txtPassword_login, 1, 1, 1, 1);


        verticalLayout_login->addLayout(gridLayout_login_form);

        btnLogin_main = new QPushButton(page_login);
        btnLogin_main->setObjectName("btnLogin_main");
        btnLogin_main->setMinimumSize(QSize(150, 45));
        btnLogin_main->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnLogin_main->setStyleSheet(QString::fromUtf8("background-color: #0078D7; color: white; border-radius: 10px; font-size: 16px; font-weight: bold;"));

        verticalLayout_login->addWidget(btnLogin_main);

        verticalSpacer_login_bottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_login->addItem(verticalSpacer_login_bottom);

        stackedWidget->addWidget(page_login);
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName("stackedWidgetPage1");
        groupBox_Utilisateur_Form = new QGroupBox(stackedWidgetPage1);
        groupBox_Utilisateur_Form->setObjectName("groupBox_Utilisateur_Form");
        groupBox_Utilisateur_Form->setGeometry(QRect(0, 10, 471, 541));
        groupBox_Utilisateur_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\203\302\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\203\302\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        formLayoutWidget_Utilisateur = new QWidget(groupBox_Utilisateur_Form);
        formLayoutWidget_Utilisateur->setObjectName("formLayoutWidget_Utilisateur");
        formLayoutWidget_Utilisateur->setGeometry(QRect(20, 40, 447, 261));
        formLayout_Utilisateur = new QFormLayout(formLayoutWidget_Utilisateur);
        formLayout_Utilisateur->setObjectName("formLayout_Utilisateur");
        formLayout_Utilisateur->setContentsMargins(0, 0, 0, 0);
        label_ID_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_ID_Utilisateur->setObjectName("label_ID_Utilisateur");

        formLayout_Utilisateur->setWidget(0, QFormLayout::LabelRole, label_ID_Utilisateur);

        lineEdit_ID_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_ID_Utilisateur->setObjectName("lineEdit_ID_Utilisateur");
        lineEdit_ID_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(0, QFormLayout::FieldRole, lineEdit_ID_Utilisateur);

        label_Nom_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Nom_Utilisateur->setObjectName("label_Nom_Utilisateur");

        formLayout_Utilisateur->setWidget(1, QFormLayout::LabelRole, label_Nom_Utilisateur);

        lineEdit_Nom_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Nom_Utilisateur->setObjectName("lineEdit_Nom_Utilisateur");
        lineEdit_Nom_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(1, QFormLayout::FieldRole, lineEdit_Nom_Utilisateur);

        label_Prenom_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Prenom_Utilisateur->setObjectName("label_Prenom_Utilisateur");

        formLayout_Utilisateur->setWidget(2, QFormLayout::LabelRole, label_Prenom_Utilisateur);

        lineEdit_Prenom_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Prenom_Utilisateur->setObjectName("lineEdit_Prenom_Utilisateur");
        lineEdit_Prenom_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(2, QFormLayout::FieldRole, lineEdit_Prenom_Utilisateur);

        label_Email_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Email_Utilisateur->setObjectName("label_Email_Utilisateur");

        formLayout_Utilisateur->setWidget(3, QFormLayout::LabelRole, label_Email_Utilisateur);

        lineEdit_Email_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Email_Utilisateur->setObjectName("lineEdit_Email_Utilisateur");
        lineEdit_Email_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(3, QFormLayout::FieldRole, lineEdit_Email_Utilisateur);

        label_Mdp_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Mdp_Utilisateur->setObjectName("label_Mdp_Utilisateur");

        formLayout_Utilisateur->setWidget(4, QFormLayout::LabelRole, label_Mdp_Utilisateur);

        lineEdit_Mdp_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Mdp_Utilisateur->setObjectName("lineEdit_Mdp_Utilisateur");
        lineEdit_Mdp_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_Mdp_Utilisateur->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout_Utilisateur->setWidget(4, QFormLayout::FieldRole, lineEdit_Mdp_Utilisateur);

        label_Role_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Role_Utilisateur->setObjectName("label_Role_Utilisateur");

        formLayout_Utilisateur->setWidget(5, QFormLayout::LabelRole, label_Role_Utilisateur);

        horizontalLayout_Role = new QHBoxLayout();
        horizontalLayout_Role->setObjectName("horizontalLayout_Role");
        radioButton_Admin_7 = new QRadioButton(formLayoutWidget_Utilisateur);
        radioButton_Admin_7->setObjectName("radioButton_Admin_7");
        radioButton_Admin_7->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role->addWidget(radioButton_Admin_7);

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


        formLayout_Utilisateur->setLayout(5, QFormLayout::FieldRole, horizontalLayout_Role);

        label_num = new QLabel(formLayoutWidget_Utilisateur);
        label_num->setObjectName("label_num");

        formLayout_Utilisateur->setWidget(6, QFormLayout::LabelRole, label_num);

        lineEdit_Institution_Utilisateur_2 = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Institution_Utilisateur_2->setObjectName("lineEdit_Institution_Utilisateur_2");
        lineEdit_Institution_Utilisateur_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(6, QFormLayout::FieldRole, lineEdit_Institution_Utilisateur_2);

        label_Institution = new QLabel(formLayoutWidget_Utilisateur);
        label_Institution->setObjectName("label_Institution");

        formLayout_Utilisateur->setWidget(7, QFormLayout::LabelRole, label_Institution);

        lineEdit_Institution_Utilisateur_3 = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Institution_Utilisateur_3->setObjectName("lineEdit_Institution_Utilisateur_3");
        lineEdit_Institution_Utilisateur_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(7, QFormLayout::FieldRole, lineEdit_Institution_Utilisateur_3);

        btn_Enregistrer_Utilisateur = new QPushButton(groupBox_Utilisateur_Form);
        btn_Enregistrer_Utilisateur->setObjectName("btn_Enregistrer_Utilisateur");
        btn_Enregistrer_Utilisateur->setGeometry(QRect(40, 400, 150, 41));
        btn_Enregistrer_Utilisateur->setMinimumSize(QSize(0, 0));
        btn_Enregistrer_Utilisateur->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"	\n"
"	 background-color: rgb(16, 151, 255);   /* normal state */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        modif_3 = new QPushButton(groupBox_Utilisateur_Form);
        modif_3->setObjectName("modif_3");
        modif_3->setGeometry(QRect(280, 400, 150, 41));
        modif_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(16, 151, 255);   /* normal state */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        annulerajout_client_3 = new QPushButton(groupBox_Utilisateur_Form);
        annulerajout_client_3->setObjectName("annulerajout_client_3");
        annulerajout_client_3->setGeometry(QRect(120, 470, 221, 41));
        annulerajout_client_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"\n"
"	\n"
"	\n"
"	background-color: rgb(66, 206, 164);\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(140, 0, 0);\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        annulerajout_client_3->setIcon(icon);
        groupBox_Session_List_6 = new QGroupBox(stackedWidgetPage1);
        groupBox_Session_List_6->setObjectName("groupBox_Session_List_6");
        groupBox_Session_List_6->setGeometry(QRect(480, 10, 751, 541));
        groupBox_Session_List_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\203\302\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\203\302\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        tableWidget_10 = new QTableView(groupBox_Session_List_6);
        tableWidget_10->setObjectName("tableWidget_10");
        tableWidget_10->setGeometry(QRect(20, 110, 681, 151));
        tableWidget_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_Stats_Utilisateur = new QGroupBox(groupBox_Session_List_6);
        groupBox_Stats_Utilisateur->setObjectName("groupBox_Stats_Utilisateur");
        groupBox_Stats_Utilisateur->setGeometry(QRect(20, 270, 691, 181));
        groupBox_Stats_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: #1e293b; border: 1px solid #334155; border-radius: 12px; font-weight: bold;"));
        label_Chart_Utilisateur = new QLabel(groupBox_Stats_Utilisateur);
        label_Chart_Utilisateur->setObjectName("label_Chart_Utilisateur");
        label_Chart_Utilisateur->setGeometry(QRect(10, 10, 670, 160));
        pushButton_supprimer_client_2 = new QPushButton(groupBox_Session_List_6);
        pushButton_supprimer_client_2->setObjectName("pushButton_supprimer_client_2");
        pushButton_supprimer_client_2->setGeometry(QRect(30, 470, 61, 51));
        pushButton_supprimer_client_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"	background-color: rgb(209, 14, 0);\n"
"\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(209, 14, 0);\n"
";\n"
"}\n"
""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        pushButton_supprimer_client_2->setIcon(icon1);
        pushButton_pdfclient = new QPushButton(groupBox_Session_List_6);
        pushButton_pdfclient->setObjectName("pushButton_pdfclient");
        pushButton_pdfclient->setGeometry(QRect(100, 470, 191, 51));
        pushButton_pdfclient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(16, 151, 255);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #059669;\n"
"}\n"
""));
        quitterSession_7 = new QPushButton(groupBox_Session_List_6);
        quitterSession_7->setObjectName("quitterSession_7");
        quitterSession_7->setGeometry(QRect(550, 470, 131, 51));
        quitterSession_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"	background-color: rgb(209, 14, 0);\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(140, 0, 0);\n"
"}\n"
"\n"
""));
        pushButton_recherche_4 = new QPushButton(groupBox_Session_List_6);
        pushButton_recherche_4->setObjectName("pushButton_recherche_4");
        pushButton_recherche_4->setGeometry(QRect(210, 30, 121, 41));
        pushButton_recherche_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(16, 151, 255);   /* normal state */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        pushButton_recherche_4->setIcon(icon2);
        rechSession_7 = new QLineEdit(groupBox_Session_List_6);
        rechSession_7->setObjectName("rechSession_7");
        rechSession_7->setGeometry(QRect(30, 30, 171, 41));
        rechSession_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    /* dark background */\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: #1f2937;              /* typed text color */\n"
"    border: 2px solid #3b82f6;   /* blue border */\n"
"    border-radius: 8px;\n"
"    \n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: white;                /* placeholder text color */\n"
"}\n"
""));
        comboBox_11 = new QComboBox(groupBox_Session_List_6);
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->setObjectName("comboBox_11");
        comboBox_11->setGeometry(QRect(520, 30, 181, 41));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(30, 41, 59, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        QBrush brush6(QColor(255, 255, 255, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush);
        comboBox_11->setPalette(palette);
        comboBox_11->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #334155;\n"
"    border-radius: 8px;\n"
"    padding: 2px 10px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #3b82f6;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #334155;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #3b82f6;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: white;\n"
"    color: white;\n"
"}"));
        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName("stackedWidgetPage2");
        groupBox_2 = new QGroupBox(stackedWidgetPage2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 10, 471, 541));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;"));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 40, 432, 261));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_9);

        Id_utilisateur = new QLineEdit(formLayoutWidget);
        Id_utilisateur->setObjectName("Id_utilisateur");
        Id_utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Id_utilisateur);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        titrePub = new QLineEdit(formLayoutWidget);
        titrePub->setObjectName("titrePub");
        titrePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, titrePub);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        auteurPub = new QLineEdit(formLayoutWidget);
        auteurPub->setObjectName("auteurPub");
        auteurPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, auteurPub);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        abstractPub = new QLineEdit(formLayoutWidget);
        abstractPub->setObjectName("abstractPub");
        abstractPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout->setWidget(3, QFormLayout::FieldRole, abstractPub);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        radioButton_Admin_3 = new QRadioButton(formLayoutWidget);
        radioButton_Admin_3->setObjectName("radioButton_Admin_3");
        radioButton_Admin_3->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, radioButton_Admin_3);

        radioButton_Admin_4 = new QRadioButton(formLayoutWidget);
        radioButton_Admin_4->setObjectName("radioButton_Admin_4");
        radioButton_Admin_4->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, radioButton_Admin_4);


        formLayout->setLayout(4, QFormLayout::FieldRole, formLayout_2);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        mot_clePub = new QLineEdit(formLayoutWidget);
        mot_clePub->setObjectName("mot_clePub");
        mot_clePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(5, QFormLayout::FieldRole, mot_clePub);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        horizontalLayout_statut = new QHBoxLayout();
        horizontalLayout_statut->setObjectName("horizontalLayout_statut");
        radioButton_statut_attente = new QRadioButton(formLayoutWidget);
        radioButton_statut_attente->setObjectName("radioButton_statut_attente");
        radioButton_statut_attente->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_statut->addWidget(radioButton_statut_attente);

        radioButton_statut_accepte = new QRadioButton(formLayoutWidget);
        radioButton_statut_accepte->setObjectName("radioButton_statut_accepte");
        radioButton_statut_accepte->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_statut->addWidget(radioButton_statut_accepte);

        radioButton_statut_rejete = new QRadioButton(formLayoutWidget);
        radioButton_statut_rejete->setObjectName("radioButton_statut_rejete");
        radioButton_statut_rejete->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_statut->addWidget(radioButton_statut_rejete);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_statut);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        datePub = new QDateEdit(formLayoutWidget);
        datePub->setObjectName("datePub");
        datePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(7, QFormLayout::FieldRole, datePub);

        enregistrer = new QPushButton(groupBox_2);
        enregistrer->setObjectName("enregistrer");
        enregistrer->setGeometry(QRect(40, 400, 150, 41));
        enregistrer->setMinimumSize(QSize(0, 0));
        enregistrer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"	\n"
"	 background-color: rgb(16, 151, 255);   /* normal state */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        modif = new QPushButton(groupBox_2);
        modif->setObjectName("modif");
        modif->setGeometry(QRect(280, 400, 150, 41));
        modif->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(16, 151, 255);   /* normal state */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        annulerajout_client = new QPushButton(groupBox_2);
        annulerajout_client->setObjectName("annulerajout_client");
        annulerajout_client->setGeometry(QRect(120, 470, 221, 41));
        annulerajout_client->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"	background-color: rgb(66, 206, 164);\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(140, 0, 0);\n"
"}\n"
""));
        annulerajout_client->setIcon(icon);
        groupBox_Session_List_5 = new QGroupBox(stackedWidgetPage2);
        groupBox_Session_List_5->setObjectName("groupBox_Session_List_5");
        groupBox_Session_List_5->setGeometry(QRect(480, 10, 741, 541));
        groupBox_Session_List_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\203\302\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\203\302\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        comboBox_9 = new QComboBox(groupBox_Session_List_5);
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->setObjectName("comboBox_9");
        comboBox_9->setGeometry(QRect(520, 30, 181, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush);
        comboBox_9->setPalette(palette1);
        comboBox_9->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #334155;\n"
"    border-radius: 8px;\n"
"    padding: 2px 10px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #3b82f6;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #334155;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #3b82f6;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: white;\n"
"    color: white;\n"
"}"));
        tableWidget_9 = new QTableView(groupBox_Session_List_5);
        tableWidget_9->setObjectName("tableWidget_9");
        tableWidget_9->setGeometry(QRect(20, 110, 681, 151));
        tableWidget_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_Stats_Publication = new QGroupBox(groupBox_Session_List_5);
        groupBox_Stats_Publication->setObjectName("groupBox_Stats_Publication");
        groupBox_Stats_Publication->setGeometry(QRect(20, 270, 691, 181));
        groupBox_Stats_Publication->setStyleSheet(QString::fromUtf8("background-color: #1e293b; border: 1px solid #334155; border-radius: 12px; font-weight: bold;"));
        label_Chart_Publication = new QLabel(groupBox_Stats_Publication);
        label_Chart_Publication->setObjectName("label_Chart_Publication");
        label_Chart_Publication->setGeometry(QRect(10, 10, 671, 161));
        pushButton_recherche_3 = new QPushButton(groupBox_Session_List_5);
        pushButton_recherche_3->setObjectName("pushButton_recherche_3");
        pushButton_recherche_3->setGeometry(QRect(210, 30, 121, 41));
        pushButton_recherche_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(16, 151, 255);   /* normal state */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        pushButton_recherche_3->setIcon(icon2);
        rechSession_5 = new QLineEdit(groupBox_Session_List_5);
        rechSession_5->setObjectName("rechSession_5");
        rechSession_5->setGeometry(QRect(30, 30, 171, 41));
        rechSession_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    /* dark background */\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: #1f2937;              /* typed text color */\n"
"    border: 2px solid #3b82f6;   /* blue border */\n"
"    border-radius: 8px;\n"
"    \n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: white;                /* placeholder text color */\n"
"}\n"
""));
        pushButton_supprimer_client = new QPushButton(groupBox_Session_List_5);
        pushButton_supprimer_client->setObjectName("pushButton_supprimer_client");
        pushButton_supprimer_client->setGeometry(QRect(30, 470, 61, 51));
        pushButton_supprimer_client->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"	background-color: rgb(209, 14, 0);\n"
"\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(209, 14, 0);\n"
";\n"
"}\n"
""));
        pushButton_supprimer_client->setIcon(icon1);
        expoSession_5 = new QPushButton(groupBox_Session_List_5);
        expoSession_5->setObjectName("expoSession_5");
        expoSession_5->setGeometry(QRect(100, 470, 191, 51));
        expoSession_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(16, 151, 255);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #059669;\n"
"}\n"
""));
        quitterSession_5 = new QPushButton(groupBox_Session_List_5);
        quitterSession_5->setObjectName("quitterSession_5");
        quitterSession_5->setGeometry(QRect(550, 470, 131, 51));
        quitterSession_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"	background-color: rgb(209, 14, 0);\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(140, 0, 0);\n"
"}\n"
"\n"
""));
        stackedWidget->addWidget(stackedWidgetPage2);
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName("stackedWidgetPage3");
        groupBox_Journal_Form = new QGroupBox(stackedWidgetPage3);
        groupBox_Journal_Form->setObjectName("groupBox_Journal_Form");
        groupBox_Journal_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\203\302\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\203\302\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        groupBox_Journal_Form->setGeometry(QRect(0, 10, 471, 541));
        formLayoutWidget_Journal = new QWidget(groupBox_Journal_Form);
        formLayoutWidget_Journal->setObjectName("formLayoutWidget_Journal");
        formLayoutWidget_Journal->setGeometry(QRect(20, 40, 447, 261));
        formLayout_Journal = new QFormLayout(formLayoutWidget_Journal);
        formLayout_Journal->setObjectName("formLayout_Journal");
        formLayout_Journal->setContentsMargins(0, 0, 0, 0);
        label_Journal_id = new QLabel(formLayoutWidget_Journal);
        label_Journal_id->setObjectName("label_Journal_id");

        formLayout_Journal->setWidget(0, QFormLayout::LabelRole, label_Journal_id);

        id = new QLineEdit(formLayoutWidget_Journal);
        id->setObjectName("id");
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Journal->setWidget(0, QFormLayout::FieldRole, id);

        label_Journal_nom = new QLabel(formLayoutWidget_Journal);
        label_Journal_nom->setObjectName("label_Journal_nom");

        formLayout_Journal->setWidget(1, QFormLayout::LabelRole, label_Journal_nom);

        nom = new QLineEdit(formLayoutWidget_Journal);
        nom->setObjectName("nom");
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Journal->setWidget(1, QFormLayout::FieldRole, nom);

        label_Journal_type = new QLabel(formLayoutWidget_Journal);
        label_Journal_type->setObjectName("label_Journal_type");

        formLayout_Journal->setWidget(2, QFormLayout::LabelRole, label_Journal_type);

        type = new QComboBox(formLayoutWidget_Journal);
        type->setObjectName("type");
        type->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #334155;\n"
"    border-radius: 8px;\n"
"    padding: 2px 10px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #3b82f6;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #334155;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #3b82f6;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: white;\n"
"    color: white;\n"
"}"));

        formLayout_Journal->setWidget(2, QFormLayout::FieldRole, type);

        label_Journal_domaine = new QLabel(formLayoutWidget_Journal);
        label_Journal_domaine->setObjectName("label_Journal_domaine");

        formLayout_Journal->setWidget(3, QFormLayout::LabelRole, label_Journal_domaine);

        domaine_scientifique = new QComboBox(formLayoutWidget_Journal);
        domaine_scientifique->setObjectName("domaine_scientifique");
        domaine_scientifique->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #334155;\n"
"    border-radius: 8px;\n"
"    padding: 2px 10px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #3b82f6;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #334155;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #3b82f6;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: white;\n"
"    color: white;\n"
"}"));

        formLayout_Journal->setWidget(3, QFormLayout::FieldRole, domaine_scientifique);

        label_Journal_facteur = new QLabel(formLayoutWidget_Journal);
        label_Journal_facteur->setObjectName("label_Journal_facteur");

        formLayout_Journal->setWidget(4, QFormLayout::LabelRole, label_Journal_facteur);

        facteur_impact = new QLineEdit(formLayoutWidget_Journal);
        facteur_impact->setObjectName("facteur_impact");
        facteur_impact->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Journal->setWidget(4, QFormLayout::FieldRole, facteur_impact);

        label_Journal_classement = new QLabel(formLayoutWidget_Journal);
        label_Journal_classement->setObjectName("label_Journal_classement");

        formLayout_Journal->setWidget(5, QFormLayout::LabelRole, label_Journal_classement);

        classement = new QComboBox(formLayoutWidget_Journal);
        classement->setObjectName("classement");
        classement->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #334155;\n"
"    border-radius: 8px;\n"
"    padding: 2px 10px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #3b82f6;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #334155;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #3b82f6;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: white;\n"
"    color: white;\n"
"}"));

        formLayout_Journal->setWidget(5, QFormLayout::FieldRole, classement);

        label_Journal_pays = new QLabel(formLayoutWidget_Journal);
        label_Journal_pays->setObjectName("label_Journal_pays");

        formLayout_Journal->setWidget(6, QFormLayout::LabelRole, label_Journal_pays);

        pays = new QComboBox(formLayoutWidget_Journal);
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->addItem(QString());
        pays->setObjectName("pays");
        pays->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #334155;\n"
"    border-radius: 8px;\n"
"    padding: 2px 10px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #3b82f6;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #334155;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #3b82f6;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: white;\n"
"    color: white;\n"
"}"));

        formLayout_Journal->setWidget(6, QFormLayout::FieldRole, pays);

        label_Journal_organisation = new QLabel(formLayoutWidget_Journal);
        label_Journal_organisation->setObjectName("label_Journal_organisation");

        formLayout_Journal->setWidget(7, QFormLayout::LabelRole, label_Journal_organisation);

        organisation = new QLineEdit(formLayoutWidget_Journal);
        organisation->setObjectName("organisation");
        organisation->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Journal->setWidget(7, QFormLayout::FieldRole, organisation);

        label_Journal_periodicite = new QLabel(formLayoutWidget_Journal);
        label_Journal_periodicite->setObjectName("label_Journal_periodicite");

        formLayout_Journal->setWidget(8, QFormLayout::LabelRole, label_Journal_periodicite);

        periodicite = new QComboBox(formLayoutWidget_Journal);
        periodicite->setObjectName("periodicite");
        periodicite->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #334155;\n"
"    border-radius: 8px;\n"
"    padding: 2px 10px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #3b82f6;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #334155;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #3b82f6;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: white;\n"
"    color: white;\n"
"}"));

        formLayout_Journal->setWidget(8, QFormLayout::FieldRole, periodicite);

        label_Journal_siteweb = new QLabel(formLayoutWidget_Journal);
        label_Journal_siteweb->setObjectName("label_Journal_siteweb");

        formLayout_Journal->setWidget(9, QFormLayout::LabelRole, label_Journal_siteweb);

        siteweb = new QLineEdit(formLayoutWidget_Journal);
        siteweb->setObjectName("siteweb");
        siteweb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Journal->setWidget(9, QFormLayout::FieldRole, siteweb);

        enregistrer1 = new QPushButton(groupBox_Journal_Form);
        enregistrer1->setObjectName("enregistrer1");
        enregistrer1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"	\n"
"	 background-color: rgb(16, 151, 255);   /* normal state */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        enregistrer1->setGeometry(QRect(40, 400, 150, 41));
        enregistrer1->setMinimumSize(QSize(0, 0));
        modif1 = new QPushButton(groupBox_Journal_Form);
        modif1->setObjectName("modif1");
        modif1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(16, 151, 255);   /* normal state */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        modif1->setGeometry(QRect(280, 400, 150, 41));
        annuler = new QPushButton(groupBox_Journal_Form);
        annuler->setObjectName("annuler");
        annuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"\n"
"	\n"
"	\n"
"	background-color: rgb(66, 206, 164);\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(140, 0, 0);\n"
"}\n"
""));
        annuler->setGeometry(QRect(120, 470, 221, 41));
        annuler->setIcon(icon);
        groupBox_Session_List_4 = new QGroupBox(stackedWidgetPage3);
        groupBox_Session_List_4->setObjectName("groupBox_Session_List_4");
        groupBox_Session_List_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\203\302\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\203\302\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        groupBox_Session_List_4->setGeometry(QRect(480, 10, 751, 541));
        rechSession_4 = new QLineEdit(groupBox_Session_List_4);
        rechSession_4->setObjectName("rechSession_4");
        rechSession_4->setGeometry(QRect(30, 30, 171, 41));
        rechSession_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    /* dark background */\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: #1f2937;              /* typed text color */\n"
"    border: 2px solid #3b82f6;   /* blue border */\n"
"    border-radius: 8px;\n"
"    \n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: white;                /* placeholder text color */\n"
"}\n"
""));
        rechercheSession_4 = new QPushButton(groupBox_Session_List_4);
        rechercheSession_4->setObjectName("rechercheSession_4");
        rechercheSession_4->setIcon(icon2);
        rechercheSession_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(16, 151, 255);   /* normal state */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;   /* darker on hover */\n"
"}\n"
""));
        rechercheSession_4->setGeometry(QRect(210, 30, 121, 41));
        SuppSession_4 = new QPushButton(groupBox_Session_List_4);
        SuppSession_4->setObjectName("SuppSession_4");
        SuppSession_4->setIcon(icon1);
        SuppSession_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"	background-color: rgb(209, 14, 0);\n"
"\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(209, 14, 0);\n"
";\n"
"}\n"
""));
        SuppSession_4->setGeometry(QRect(30, 470, 61, 51));
        quitterSession_4 = new QPushButton(groupBox_Session_List_4);
        quitterSession_4->setObjectName("quitterSession_4");
        quitterSession_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"	background-color: rgb(209, 14, 0);\n"
"	\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"      /* darker on hover */\n"
"	background-color: rgb(140, 0, 0);\n"
"}\n"
"\n"
""));
        quitterSession_4->setGeometry(QRect(550, 470, 131, 51));
        expoSession_4 = new QPushButton(groupBox_Session_List_4);
        expoSession_4->setObjectName("expoSession_4");
        expoSession_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(16, 151, 255);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #059669;\n"
"}\n"
""));
        expoSession_4->setGeometry(QRect(100, 470, 191, 51));
        comboBox_8 = new QComboBox(groupBox_Session_List_4);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName("comboBox_8");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        QBrush brush8(QColor(127, 127, 127, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush);
        comboBox_8->setPalette(palette2);
        comboBox_8->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #334155;\n"
"    border-radius: 8px;\n"
"    padding: 2px 10px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #3b82f6;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #334155;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e293b;\n"
"    border: 1px solid #3b82f6;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: white;\n"
"    color: white;\n"
"}"));
        comboBox_8->setGeometry(QRect(520, 30, 181, 41));
        tableWidget_8 = new QTableWidget(groupBox_Session_List_4);
        tableWidget_8->setObjectName("tableWidget_8");
        tableWidget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget_8->setGeometry(QRect(20, 110, 681, 151));
        groupBox_Stats_Journal = new QGroupBox(groupBox_Session_List_4);
        groupBox_Stats_Journal->setObjectName("groupBox_Stats_Journal");
        groupBox_Stats_Journal->setGeometry(QRect(20, 270, 691, 181));
        groupBox_Stats_Journal->setStyleSheet(QString::fromUtf8("background-color: #1e293b; border: 1px solid #334155; border-radius: 12px; font-weight: bold;"));
        label_Chart_Journal = new QLabel(groupBox_Stats_Journal);
        label_Chart_Journal->setObjectName("label_Chart_Journal");
        label_Chart_Journal->setGeometry(QRect(10, 10, 670, 160));
        stackedWidget->addWidget(stackedWidgetPage3);
        stackedWidgetPage4 = new QWidget();
        stackedWidgetPage4->setObjectName("stackedWidgetPage4");
        groupBox_Reviewer_Form = new QGroupBox(stackedWidgetPage4);
        groupBox_Reviewer_Form->setObjectName("groupBox_Reviewer_Form");
        groupBox_Reviewer_Form->setGeometry(QRect(0, 10, 451, 541));
        groupBox_Reviewer_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;"));
        formLayoutWidget_Reviewer = new QWidget(groupBox_Reviewer_Form);
        formLayoutWidget_Reviewer->setObjectName("formLayoutWidget_Reviewer");
        formLayoutWidget_Reviewer->setGeometry(QRect(20, 50, 411, 261));
        formLayout_Reviewer = new QFormLayout(formLayoutWidget_Reviewer);
        formLayout_Reviewer->setObjectName("formLayout_Reviewer");
        formLayout_Reviewer->setContentsMargins(0, 0, 0, 0);
        label_Rev_ID = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_ID->setObjectName("label_Rev_ID");

        formLayout_Reviewer->setWidget(0, QFormLayout::LabelRole, label_Rev_ID);

        idReviewer = new QLineEdit(formLayoutWidget_Reviewer);
        idReviewer->setObjectName("idReviewer");
        idReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Reviewer->setWidget(0, QFormLayout::FieldRole, idReviewer);

        label_Rev_Nom = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_Nom->setObjectName("label_Rev_Nom");

        formLayout_Reviewer->setWidget(1, QFormLayout::LabelRole, label_Rev_Nom);

        nomReviewer = new QLineEdit(formLayoutWidget_Reviewer);
        nomReviewer->setObjectName("nomReviewer");
        nomReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Reviewer->setWidget(1, QFormLayout::FieldRole, nomReviewer);

        label_Rev_Email = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_Email->setObjectName("label_Rev_Email");

        formLayout_Reviewer->setWidget(2, QFormLayout::LabelRole, label_Rev_Email);

        emailReviewer = new QLineEdit(formLayoutWidget_Reviewer);
        emailReviewer->setObjectName("emailReviewer");
        emailReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Reviewer->setWidget(2, QFormLayout::FieldRole, emailReviewer);

        label_Rev_Spec = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_Spec->setObjectName("label_Rev_Spec");

        formLayout_Reviewer->setWidget(3, QFormLayout::LabelRole, label_Rev_Spec);

        specialiteReviewer = new QLineEdit(formLayoutWidget_Reviewer);
        specialiteReviewer->setObjectName("specialiteReviewer");
        specialiteReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Reviewer->setWidget(3, QFormLayout::FieldRole, specialiteReviewer);

        label_Rev_Inst = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_Inst->setObjectName("label_Rev_Inst");

        formLayout_Reviewer->setWidget(4, QFormLayout::LabelRole, label_Rev_Inst);

        institutionReviewer = new QLineEdit(formLayoutWidget_Reviewer);
        institutionReviewer->setObjectName("institutionReviewer");
        institutionReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Reviewer->setWidget(4, QFormLayout::FieldRole, institutionReviewer);

        label_Rev_Statut = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_Statut->setObjectName("label_Rev_Statut");

        formLayout_Reviewer->setWidget(5, QFormLayout::LabelRole, label_Rev_Statut);

        formLayout_Rev_Statut = new QFormLayout();
        formLayout_Rev_Statut->setObjectName("formLayout_Rev_Statut");
        actifReviewer = new QRadioButton(formLayoutWidget_Reviewer);
        actifReviewer->setObjectName("actifReviewer");
        actifReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Rev_Statut->setWidget(0, QFormLayout::LabelRole, actifReviewer);

        inactifReviewer = new QRadioButton(formLayoutWidget_Reviewer);
        inactifReviewer->setObjectName("inactifReviewer");
        inactifReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Rev_Statut->setWidget(0, QFormLayout::FieldRole, inactifReviewer);


        formLayout_Reviewer->setLayout(5, QFormLayout::FieldRole, formLayout_Rev_Statut);

        enregistrerReviewer = new QPushButton(groupBox_Reviewer_Form);
        enregistrerReviewer->setObjectName("enregistrerReviewer");
        enregistrerReviewer->setGeometry(QRect(40, 400, 150, 41));
        enregistrerReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        modifierReviewer = new QPushButton(groupBox_Reviewer_Form);
        modifierReviewer->setObjectName("modifierReviewer");
        modifierReviewer->setGeometry(QRect(240, 400, 150, 41));
        modifierReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        annulerReviewer = new QPushButton(groupBox_Reviewer_Form);
        annulerReviewer->setObjectName("annulerReviewer");
        annulerReviewer->setGeometry(QRect(150, 460, 150, 41));
        annulerReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        groupBox_Session_List_3 = new QGroupBox(stackedWidgetPage4);
        groupBox_Session_List_3->setObjectName("groupBox_Session_List_3");
        groupBox_Session_List_3->setGeometry(QRect(460, 10, 741, 541));
        groupBox_Session_List_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\203\302\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\203\302\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        rechSession_3 = new QLineEdit(groupBox_Session_List_3);
        rechSession_3->setObjectName("rechSession_3");
        rechSession_3->setGeometry(QRect(10, 40, 161, 26));
        rechSession_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        rechercheSession_3 = new QPushButton(groupBox_Session_List_3);
        rechercheSession_3->setObjectName("rechercheSession_3");
        rechercheSession_3->setGeometry(QRect(180, 38, 150, 31));
        rechercheSession_3->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        SuppSession_3 = new QPushButton(groupBox_Session_List_3);
        SuppSession_3->setObjectName("SuppSession_3");
        SuppSession_3->setGeometry(QRect(40, 440, 150, 41));
        SuppSession_3->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        quitterSession_3 = new QPushButton(groupBox_Session_List_3);
        quitterSession_3->setObjectName("quitterSession_3");
        quitterSession_3->setGeometry(QRect(480, 490, 150, 31));
        quitterSession_3->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        expoSession_3 = new QPushButton(groupBox_Session_List_3);
        expoSession_3->setObjectName("expoSession_3");
        expoSession_3->setGeometry(QRect(480, 450, 150, 31));
        expoSession_3->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        comboBox_7 = new QComboBox(groupBox_Session_List_3);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName("comboBox_7");
        comboBox_7->setGeometry(QRect(550, 40, 141, 26));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::Accent, brush);
        comboBox_7->setPalette(palette3);
        comboBox_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget_7 = new QTableWidget(groupBox_Session_List_3);
        tableWidget_7->setObjectName("tableWidget_7");
        tableWidget_7->setGeometry(QRect(20, 110, 641, 241));
        tableWidget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(stackedWidgetPage4);
        stackedWidgetPage5 = new QWidget();
        stackedWidgetPage5->setObjectName("stackedWidgetPage5");
        groupBox_Session_Form = new QGroupBox(stackedWidgetPage5);
        groupBox_Session_Form->setObjectName("groupBox_Session_Form");
        groupBox_Session_Form->setGeometry(QRect(0, 10, 451, 541));
        groupBox_Session_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;"));
        formLayoutWidget_Session = new QWidget(groupBox_Session_Form);
        formLayoutWidget_Session->setObjectName("formLayoutWidget_Session");
        formLayoutWidget_Session->setGeometry(QRect(20, 50, 475, 311));
        formLayout_Session = new QFormLayout(formLayoutWidget_Session);
        formLayout_Session->setObjectName("formLayout_Session");
        formLayout_Session->setContentsMargins(0, 0, 0, 0);
        label_S_ID = new QLabel(formLayoutWidget_Session);
        label_S_ID->setObjectName("label_S_ID");

        formLayout_Session->setWidget(0, QFormLayout::LabelRole, label_S_ID);

        idSession = new QLineEdit(formLayoutWidget_Session);
        idSession->setObjectName("idSession");
        idSession->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
        idSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout_Session->setWidget(0, QFormLayout::FieldRole, idSession);

        label_S_Titre = new QLabel(formLayoutWidget_Session);
        label_S_Titre->setObjectName("label_S_Titre");

        formLayout_Session->setWidget(1, QFormLayout::LabelRole, label_S_Titre);

        Id_utilisateur_Session = new QLineEdit(formLayoutWidget_Session);
        Id_utilisateur_Session->setObjectName("Id_utilisateur_Session");
        Id_utilisateur_Session->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(1, QFormLayout::FieldRole, Id_utilisateur_Session);

        label_S_Date = new QLabel(formLayoutWidget_Session);
        label_S_Date->setObjectName("label_S_Date");

        formLayout_Session->setWidget(2, QFormLayout::LabelRole, label_S_Date);

        label_S_Lieu = new QLabel(formLayoutWidget_Session);
        label_S_Lieu->setObjectName("label_S_Lieu");

        formLayout_Session->setWidget(3, QFormLayout::LabelRole, label_S_Lieu);

        abstractSession = new QLineEdit(formLayoutWidget_Session);
        abstractSession->setObjectName("abstractSession");
        abstractSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout_Session->setWidget(3, QFormLayout::FieldRole, abstractSession);

        label_S_Type = new QLabel(formLayoutWidget_Session);
        label_S_Type->setObjectName("label_S_Type");

        formLayout_Session->setWidget(4, QFormLayout::LabelRole, label_S_Type);

        label_S_ListPub = new QLabel(formLayoutWidget_Session);
        label_S_ListPub->setObjectName("label_S_ListPub");

        formLayout_Session->setWidget(5, QFormLayout::LabelRole, label_S_ListPub);

        label_S_ListRev = new QLabel(formLayoutWidget_Session);
        label_S_ListRev->setObjectName("label_S_ListRev");

        formLayout_Session->setWidget(6, QFormLayout::LabelRole, label_S_ListRev);

        dateSession = new QDateEdit(formLayoutWidget_Session);
        dateSession->setObjectName("dateSession");
        dateSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(2, QFormLayout::FieldRole, dateSession);

        horizontalLayout_Role_2 = new QHBoxLayout();
        horizontalLayout_Role_2->setObjectName("horizontalLayout_Role_2");
        radioButton_Admin_5 = new QRadioButton(formLayoutWidget_Session);
        radioButton_Admin_5->setObjectName("radioButton_Admin_5");
        radioButton_Admin_5->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_2->addWidget(radioButton_Admin_5);

        radioButton_Admin_6 = new QRadioButton(formLayoutWidget_Session);
        radioButton_Admin_6->setObjectName("radioButton_Admin_6");
        radioButton_Admin_6->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_2->addWidget(radioButton_Admin_6);

        radioButton_Chercheur_2 = new QRadioButton(formLayoutWidget_Session);
        radioButton_Chercheur_2->setObjectName("radioButton_Chercheur_2");
        radioButton_Chercheur_2->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_2->addWidget(radioButton_Chercheur_2);


        formLayout_Session->setLayout(4, QFormLayout::FieldRole, horizontalLayout_Role_2);

        lineEdit_publications = new QLineEdit(formLayoutWidget_Session);
        lineEdit_publications->setObjectName("lineEdit_publications");
        lineEdit_publications->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(5, QFormLayout::FieldRole, lineEdit_publications);

        lineEdit_reviewers = new QLineEdit(formLayoutWidget_Session);
        lineEdit_reviewers->setObjectName("lineEdit_reviewers");
        lineEdit_reviewers->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(6, QFormLayout::FieldRole, lineEdit_reviewers);

        enregistrerSession = new QPushButton(groupBox_Session_Form);
        enregistrerSession->setObjectName("enregistrerSession");
        enregistrerSession->setGeometry(QRect(40, 400, 150, 41));
        enregistrerSession->setMinimumSize(QSize(0, 0));
        enregistrerSession->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        modifSession = new QPushButton(groupBox_Session_Form);
        modifSession->setObjectName("modifSession");
        modifSession->setGeometry(QRect(240, 400, 150, 41));
        modifSession->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        annulerSession = new QPushButton(groupBox_Session_Form);
        annulerSession->setObjectName("annulerSession");
        annulerSession->setGeometry(QRect(150, 460, 150, 41));
        annulerSession->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        groupBox_Session_List = new QGroupBox(stackedWidgetPage5);
        groupBox_Session_List->setObjectName("groupBox_Session_List");
        groupBox_Session_List->setGeometry(QRect(460, 10, 741, 541));
        groupBox_Session_List->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\203\302\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\203\302\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        rechSession = new QLineEdit(groupBox_Session_List);
        rechSession->setObjectName("rechSession");
        rechSession->setGeometry(QRect(10, 40, 161, 26));
        rechSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        rechercheSession = new QPushButton(groupBox_Session_List);
        rechercheSession->setObjectName("rechercheSession");
        rechercheSession->setGeometry(QRect(180, 38, 150, 31));
        rechercheSession->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        SuppSession = new QPushButton(groupBox_Session_List);
        SuppSession->setObjectName("SuppSession");
        SuppSession->setGeometry(QRect(40, 440, 150, 41));
        SuppSession->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        quitterSession = new QPushButton(groupBox_Session_List);
        quitterSession->setObjectName("quitterSession");
        quitterSession->setGeometry(QRect(480, 490, 150, 31));
        quitterSession->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        expoSession = new QPushButton(groupBox_Session_List);
        expoSession->setObjectName("expoSession");
        expoSession->setGeometry(QRect(480, 450, 150, 31));
        expoSession->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        comboBox_5 = new QComboBox(groupBox_Session_List);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(550, 40, 141, 26));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette4.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::Accent, brush);
        comboBox_5->setPalette(palette4);
        comboBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget_5 = new QTableView(groupBox_Session_List);
        tableWidget_5->setObjectName("tableWidget_5");
        tableWidget_5->setGeometry(QRect(20, 110, 641, 241));
        tableWidget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(stackedWidgetPage5);
        stackedWidgetPage6 = new QWidget();
        stackedWidgetPage6->setObjectName("stackedWidgetPage6");
        groupBox_Paiement_Form = new QGroupBox(stackedWidgetPage6);
        groupBox_Paiement_Form->setObjectName("groupBox_Paiement_Form");
        groupBox_Paiement_Form->setGeometry(QRect(0, 10, 451, 541));
        groupBox_Paiement_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168); border: #A8D3F0;\n"
"QGroupBox { border: 2px solid #2c3e50; border-radius: 15px; margin-top: 20px; font-weight: bold; color: #2c3e50; }\n"
"QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 10px; }"));
        formLayoutWidget_Utilisateur_2 = new QWidget(groupBox_Paiement_Form);
        formLayoutWidget_Utilisateur_2->setObjectName("formLayoutWidget_Utilisateur_2");
        formLayoutWidget_Utilisateur_2->setGeometry(QRect(10, 60, 411, 281));
        formLayout_Utilisateur_4 = new QFormLayout(formLayoutWidget_Utilisateur_2);
        formLayout_Utilisateur_4->setObjectName("formLayout_Utilisateur_4");
        formLayout_Utilisateur_4->setContentsMargins(0, 0, 0, 0);
        label_ID_Utilisateur_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_ID_Utilisateur_4->setObjectName("label_ID_Utilisateur_4");

        formLayout_Utilisateur_4->setWidget(0, QFormLayout::LabelRole, label_ID_Utilisateur_4);

        lineEdit_ID_Utilisateur_4 = new QLineEdit(formLayoutWidget_Utilisateur_2);
        lineEdit_ID_Utilisateur_4->setObjectName("lineEdit_ID_Utilisateur_4");
        lineEdit_ID_Utilisateur_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(0, QFormLayout::FieldRole, lineEdit_ID_Utilisateur_4);

        label_Nom_Utilisateur_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Nom_Utilisateur_4->setObjectName("label_Nom_Utilisateur_4");

        formLayout_Utilisateur_4->setWidget(1, QFormLayout::LabelRole, label_Nom_Utilisateur_4);

        lineEdit_Nom_Utilisateur_4 = new QLineEdit(formLayoutWidget_Utilisateur_2);
        lineEdit_Nom_Utilisateur_4->setObjectName("lineEdit_Nom_Utilisateur_4");
        lineEdit_Nom_Utilisateur_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(1, QFormLayout::FieldRole, lineEdit_Nom_Utilisateur_4);

        label_Email_Utilisateur_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Email_Utilisateur_4->setObjectName("label_Email_Utilisateur_4");

        formLayout_Utilisateur_4->setWidget(2, QFormLayout::LabelRole, label_Email_Utilisateur_4);

        lineEdit_Email_Utilisateur_4 = new QLineEdit(formLayoutWidget_Utilisateur_2);
        lineEdit_Email_Utilisateur_4->setObjectName("lineEdit_Email_Utilisateur_4");
        lineEdit_Email_Utilisateur_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(2, QFormLayout::FieldRole, lineEdit_Email_Utilisateur_4);

        label_Mdp_Utilisateur_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Mdp_Utilisateur_4->setObjectName("label_Mdp_Utilisateur_4");

        formLayout_Utilisateur_4->setWidget(3, QFormLayout::LabelRole, label_Mdp_Utilisateur_4);

        lineEdit_Mdp_Utilisateur_4 = new QLineEdit(formLayoutWidget_Utilisateur_2);
        lineEdit_Mdp_Utilisateur_4->setObjectName("lineEdit_Mdp_Utilisateur_4");
        lineEdit_Mdp_Utilisateur_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_Mdp_Utilisateur_4->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout_Utilisateur_4->setWidget(3, QFormLayout::FieldRole, lineEdit_Mdp_Utilisateur_4);

        label_Role_Utilisateur_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Role_Utilisateur_4->setObjectName("label_Role_Utilisateur_4");

        formLayout_Utilisateur_4->setWidget(4, QFormLayout::LabelRole, label_Role_Utilisateur_4);

        lineEdit_Institution_Utilisateur_11 = new QLineEdit(formLayoutWidget_Utilisateur_2);
        lineEdit_Institution_Utilisateur_11->setObjectName("lineEdit_Institution_Utilisateur_11");
        lineEdit_Institution_Utilisateur_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(4, QFormLayout::FieldRole, lineEdit_Institution_Utilisateur_11);

        label_Mot_de_passe_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Mot_de_passe_4->setObjectName("label_Mot_de_passe_4");

        formLayout_Utilisateur_4->setWidget(5, QFormLayout::LabelRole, label_Mot_de_passe_4);

        lineEdit_Institution_Utilisateur_10 = new QLineEdit(formLayoutWidget_Utilisateur_2);
        lineEdit_Institution_Utilisateur_10->setObjectName("lineEdit_Institution_Utilisateur_10");
        lineEdit_Institution_Utilisateur_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(5, QFormLayout::FieldRole, lineEdit_Institution_Utilisateur_10);

        label_num_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_num_4->setObjectName("label_num_4");

        formLayout_Utilisateur_4->setWidget(7, QFormLayout::LabelRole, label_num_4);

        horizontalLayout_Role_4 = new QHBoxLayout();
        horizontalLayout_Role_4->setObjectName("horizontalLayout_Role_4");
        radioButton_Chercheur_4 = new QRadioButton(formLayoutWidget_Utilisateur_2);
        radioButton_Chercheur_4->setObjectName("radioButton_Chercheur_4");
        radioButton_Chercheur_4->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_4->addWidget(radioButton_Chercheur_4);

        radioButton_Admin_10 = new QRadioButton(formLayoutWidget_Utilisateur_2);
        radioButton_Admin_10->setObjectName("radioButton_Admin_10");
        radioButton_Admin_10->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_4->addWidget(radioButton_Admin_10);

        radioButton_Admin_9 = new QRadioButton(formLayoutWidget_Utilisateur_2);
        radioButton_Admin_9->setObjectName("radioButton_Admin_9");
        radioButton_Admin_9->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_4->addWidget(radioButton_Admin_9);


        formLayout_Utilisateur_4->setLayout(7, QFormLayout::FieldRole, horizontalLayout_Role_4);

        label_Role_Utilisateur_5 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Role_Utilisateur_5->setObjectName("label_Role_Utilisateur_5");

        formLayout_Utilisateur_4->setWidget(6, QFormLayout::LabelRole, label_Role_Utilisateur_5);

        dateEdit = new QDateEdit(formLayoutWidget_Utilisateur_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(6, QFormLayout::FieldRole, dateEdit);

        btn_Enregistrer_Utilisateur_2 = new QPushButton(groupBox_Paiement_Form);
        btn_Enregistrer_Utilisateur_2->setObjectName("btn_Enregistrer_Utilisateur_2");
        btn_Enregistrer_Utilisateur_2->setGeometry(QRect(40, 410, 150, 41));
        btn_Enregistrer_Utilisateur_2->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        btn_Modifier_Utilisateur_2 = new QPushButton(groupBox_Paiement_Form);
        btn_Modifier_Utilisateur_2->setObjectName("btn_Modifier_Utilisateur_2");
        btn_Modifier_Utilisateur_2->setGeometry(QRect(250, 410, 150, 41));
        btn_Modifier_Utilisateur_2->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        btn_Annuler_Utilisateur_2 = new QPushButton(groupBox_Paiement_Form);
        btn_Annuler_Utilisateur_2->setObjectName("btn_Annuler_Utilisateur_2");
        btn_Annuler_Utilisateur_2->setGeometry(QRect(150, 460, 150, 41));
        btn_Annuler_Utilisateur_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        groupBox_Session_List_2 = new QGroupBox(stackedWidgetPage6);
        groupBox_Session_List_2->setObjectName("groupBox_Session_List_2");
        groupBox_Session_List_2->setGeometry(QRect(460, 10, 741, 541));
        groupBox_Session_List_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\203\302\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\203\302\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        rechSession_2 = new QLineEdit(groupBox_Session_List_2);
        rechSession_2->setObjectName("rechSession_2");
        rechSession_2->setGeometry(QRect(10, 40, 161, 26));
        rechSession_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        rechercheSession_2 = new QPushButton(groupBox_Session_List_2);
        rechercheSession_2->setObjectName("rechercheSession_2");
        rechercheSession_2->setGeometry(QRect(180, 38, 150, 31));
        rechercheSession_2->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        SuppSession_2 = new QPushButton(groupBox_Session_List_2);
        SuppSession_2->setObjectName("SuppSession_2");
        SuppSession_2->setGeometry(QRect(40, 440, 150, 41));
        SuppSession_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        quitterSession_2 = new QPushButton(groupBox_Session_List_2);
        quitterSession_2->setObjectName("quitterSession_2");
        quitterSession_2->setGeometry(QRect(480, 490, 150, 31));
        quitterSession_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        expoSession_2 = new QPushButton(groupBox_Session_List_2);
        expoSession_2->setObjectName("expoSession_2");
        expoSession_2->setGeometry(QRect(480, 450, 150, 31));
        expoSession_2->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        comboBox_6 = new QComboBox(groupBox_Session_List_2);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName("comboBox_6");
        comboBox_6->setGeometry(QRect(550, 40, 141, 26));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette5.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::Accent, brush);
        comboBox_6->setPalette(palette5);
        comboBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget_6 = new QTableWidget(groupBox_Session_List_2);
        tableWidget_6->setObjectName("tableWidget_6");
        tableWidget_6->setGeometry(QRect(20, 110, 641, 241));
        tableWidget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(stackedWidgetPage6);
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

        stackedWidget->setCurrentIndex(1);


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
        GestionSession_2->setText(QCoreApplication::translate("SmartResearch", "Gestion Paiement", nullptr));
        label_10->setText(QString());
        lblLogo_login->setText(QString());
        label_username_login->setText(QCoreApplication::translate("SmartResearch", "Nom d'utilisateur", nullptr));
        label_password_login->setText(QCoreApplication::translate("SmartResearch", "Mot de passe", nullptr));
        btnLogin_main->setText(QCoreApplication::translate("SmartResearch", "Connexion", nullptr));
        groupBox_Utilisateur_Form->setTitle(QString());
        label_ID_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_Nom_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_Prenom_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Pr\303\251nom</span></p></body></html>", nullptr));
        label_Email_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Email</span></p></body></html>", nullptr));
        label_Mdp_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mot de passe</span></p></body></html>", nullptr));
        label_Role_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Role</span></p></body></html>", nullptr));
        radioButton_Admin_7->setText(QCoreApplication::translate("SmartResearch", "Admin", nullptr));
        radioButton_Admin_2->setText(QCoreApplication::translate("SmartResearch", "manager", nullptr));
        radioButton_Admin->setText(QCoreApplication::translate("SmartResearch", "editer", nullptr));
        radioButton_Chercheur->setText(QCoreApplication::translate("SmartResearch", "reviewer", nullptr));
        label_num->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Num</span></p></body></html>", nullptr));
        label_Institution->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Institution</span></p></body></html>", nullptr));
        btn_Enregistrer_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modif_3->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annulerajout_client_3->setText(QString());
        groupBox_Session_List_6->setTitle(QString());
        groupBox_Stats_Utilisateur->setTitle(QString());
        label_Chart_Utilisateur->setText(QString());
        pushButton_supprimer_client_2->setText(QString());
        pushButton_pdfclient->setText(QCoreApplication::translate("SmartResearch", "Exporter format PDF", nullptr));
        quitterSession_7->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        pushButton_recherche_4->setText(QCoreApplication::translate("SmartResearch", "Rechercher:", nullptr));
        comboBox_11->setItemText(0, QCoreApplication::translate("SmartResearch", "     order croissant", nullptr));
        comboBox_11->setItemText(1, QCoreApplication::translate("SmartResearch", "     order decroissant", nullptr));

        groupBox_2->setTitle(QString());
        label_9->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID_pub</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Titre</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Auteurs</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Abstract</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        radioButton_Admin_3->setText(QCoreApplication::translate("SmartResearch", "Conf\303\251rence", nullptr));
        radioButton_Admin_4->setText(QCoreApplication::translate("SmartResearch", "Journal", nullptr));
        label_6->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mots cl\303\251s</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Statut</span></p></body></html>", nullptr));
        radioButton_statut_attente->setText(QCoreApplication::translate("SmartResearch", "En attente", nullptr));
        radioButton_statut_accepte->setText(QCoreApplication::translate("SmartResearch", "Accept\303\251", nullptr));
        radioButton_statut_rejete->setText(QCoreApplication::translate("SmartResearch", "Rejet\303\251", nullptr));
        label_8->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Date de soumission</span></p></body></html>", nullptr));
        enregistrer->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modif->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annulerajout_client->setText(QString());
        groupBox_Session_List_5->setTitle(QString());
        comboBox_9->setItemText(0, QCoreApplication::translate("SmartResearch", "     order croissant", nullptr));
        comboBox_9->setItemText(1, QCoreApplication::translate("SmartResearch", "     order decroissant", nullptr));

        groupBox_Stats_Publication->setTitle(QString());
        label_Chart_Publication->setText(QString());
        pushButton_recherche_3->setText(QCoreApplication::translate("SmartResearch", "Rechercher:", nullptr));
        pushButton_supprimer_client->setText(QString());
        expoSession_5->setText(QCoreApplication::translate("SmartResearch", "Exporter format PDF", nullptr));
        quitterSession_5->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        groupBox_Journal_Form->setTitle(QString());
        formLayoutWidget_Journal->setStyleSheet(QString());
        label_Journal_id->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Id</span></p></body></html>", nullptr));
        label_Journal_nom->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_Journal_type->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        label_Journal_domaine->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Domaine Scientifique</span></p></body></html>", nullptr));
        label_Journal_facteur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Facteur d'impact</span></p></body></html>", nullptr));
        label_Journal_classement->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Classement</span></p></body></html>", nullptr));
        label_Journal_pays->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Pays</span></p></body></html>", nullptr));
        pays->setItemText(0, QCoreApplication::translate("SmartResearch", "-- S\303\251lectionner un pays --", nullptr));
        pays->setItemText(1, QCoreApplication::translate("SmartResearch", "Afghanistan", nullptr));
        pays->setItemText(2, QCoreApplication::translate("SmartResearch", "Albania", nullptr));
        pays->setItemText(3, QCoreApplication::translate("SmartResearch", "Algeria", nullptr));
        pays->setItemText(4, QCoreApplication::translate("SmartResearch", "Andorra", nullptr));
        pays->setItemText(5, QCoreApplication::translate("SmartResearch", "Angola", nullptr));
        pays->setItemText(6, QCoreApplication::translate("SmartResearch", "Antigua and Barbuda", nullptr));
        pays->setItemText(7, QCoreApplication::translate("SmartResearch", "Argentina", nullptr));
        pays->setItemText(8, QCoreApplication::translate("SmartResearch", "Armenia", nullptr));
        pays->setItemText(9, QCoreApplication::translate("SmartResearch", "Australia", nullptr));
        pays->setItemText(10, QCoreApplication::translate("SmartResearch", "Austria", nullptr));
        pays->setItemText(11, QCoreApplication::translate("SmartResearch", "Azerbaijan", nullptr));
        pays->setItemText(12, QCoreApplication::translate("SmartResearch", "Bahamas", nullptr));
        pays->setItemText(13, QCoreApplication::translate("SmartResearch", "Bahrain", nullptr));
        pays->setItemText(14, QCoreApplication::translate("SmartResearch", "Bangladesh", nullptr));
        pays->setItemText(15, QCoreApplication::translate("SmartResearch", "Barbados", nullptr));
        pays->setItemText(16, QCoreApplication::translate("SmartResearch", "Belarus", nullptr));
        pays->setItemText(17, QCoreApplication::translate("SmartResearch", "Belgium", nullptr));
        pays->setItemText(18, QCoreApplication::translate("SmartResearch", "Belize", nullptr));
        pays->setItemText(19, QCoreApplication::translate("SmartResearch", "Benin", nullptr));
        pays->setItemText(20, QCoreApplication::translate("SmartResearch", "Bhutan", nullptr));
        pays->setItemText(21, QCoreApplication::translate("SmartResearch", "Bolivia", nullptr));
        pays->setItemText(22, QCoreApplication::translate("SmartResearch", "Bosnia and Herzegovina", nullptr));
        pays->setItemText(23, QCoreApplication::translate("SmartResearch", "Botswana", nullptr));
        pays->setItemText(24, QCoreApplication::translate("SmartResearch", "Brazil", nullptr));
        pays->setItemText(25, QCoreApplication::translate("SmartResearch", "Brunei", nullptr));
        pays->setItemText(26, QCoreApplication::translate("SmartResearch", "Bulgaria", nullptr));
        pays->setItemText(27, QCoreApplication::translate("SmartResearch", "Burkina Faso", nullptr));
        pays->setItemText(28, QCoreApplication::translate("SmartResearch", "Burundi", nullptr));
        pays->setItemText(29, QCoreApplication::translate("SmartResearch", "Cabo Verde", nullptr));
        pays->setItemText(30, QCoreApplication::translate("SmartResearch", "Cambodia", nullptr));
        pays->setItemText(31, QCoreApplication::translate("SmartResearch", "Cameroon", nullptr));
        pays->setItemText(32, QCoreApplication::translate("SmartResearch", "Canada", nullptr));
        pays->setItemText(33, QCoreApplication::translate("SmartResearch", "Central African Republic", nullptr));
        pays->setItemText(34, QCoreApplication::translate("SmartResearch", "Chad", nullptr));
        pays->setItemText(35, QCoreApplication::translate("SmartResearch", "Chile", nullptr));
        pays->setItemText(36, QCoreApplication::translate("SmartResearch", "China", nullptr));
        pays->setItemText(37, QCoreApplication::translate("SmartResearch", "Colombia", nullptr));
        pays->setItemText(38, QCoreApplication::translate("SmartResearch", "Comoros", nullptr));
        pays->setItemText(39, QCoreApplication::translate("SmartResearch", "Congo (Brazzaville)", nullptr));
        pays->setItemText(40, QCoreApplication::translate("SmartResearch", "Congo (Kinshasa)", nullptr));
        pays->setItemText(41, QCoreApplication::translate("SmartResearch", "Costa Rica", nullptr));
        pays->setItemText(42, QCoreApplication::translate("SmartResearch", "Croatia", nullptr));
        pays->setItemText(43, QCoreApplication::translate("SmartResearch", "Cuba", nullptr));
        pays->setItemText(44, QCoreApplication::translate("SmartResearch", "Cyprus", nullptr));
        pays->setItemText(45, QCoreApplication::translate("SmartResearch", "Czech Republic", nullptr));
        pays->setItemText(46, QCoreApplication::translate("SmartResearch", "Denmark", nullptr));
        pays->setItemText(47, QCoreApplication::translate("SmartResearch", "Djibouti", nullptr));
        pays->setItemText(48, QCoreApplication::translate("SmartResearch", "Dominica", nullptr));
        pays->setItemText(49, QCoreApplication::translate("SmartResearch", "Dominican Republic", nullptr));
        pays->setItemText(50, QCoreApplication::translate("SmartResearch", "Ecuador", nullptr));
        pays->setItemText(51, QCoreApplication::translate("SmartResearch", "Egypt", nullptr));
        pays->setItemText(52, QCoreApplication::translate("SmartResearch", "El Salvador", nullptr));
        pays->setItemText(53, QCoreApplication::translate("SmartResearch", "Equatorial Guinea", nullptr));
        pays->setItemText(54, QCoreApplication::translate("SmartResearch", "Eritrea", nullptr));
        pays->setItemText(55, QCoreApplication::translate("SmartResearch", "Estonia", nullptr));
        pays->setItemText(56, QCoreApplication::translate("SmartResearch", "Eswatini", nullptr));
        pays->setItemText(57, QCoreApplication::translate("SmartResearch", "Ethiopia", nullptr));
        pays->setItemText(58, QCoreApplication::translate("SmartResearch", "Fiji", nullptr));
        pays->setItemText(59, QCoreApplication::translate("SmartResearch", "Finland", nullptr));
        pays->setItemText(60, QCoreApplication::translate("SmartResearch", "France", nullptr));
        pays->setItemText(61, QCoreApplication::translate("SmartResearch", "Gabon", nullptr));
        pays->setItemText(62, QCoreApplication::translate("SmartResearch", "Gambia", nullptr));
        pays->setItemText(63, QCoreApplication::translate("SmartResearch", "Georgia", nullptr));
        pays->setItemText(64, QCoreApplication::translate("SmartResearch", "Germany", nullptr));
        pays->setItemText(65, QCoreApplication::translate("SmartResearch", "Ghana", nullptr));
        pays->setItemText(66, QCoreApplication::translate("SmartResearch", "Greece", nullptr));
        pays->setItemText(67, QCoreApplication::translate("SmartResearch", "Grenada", nullptr));
        pays->setItemText(68, QCoreApplication::translate("SmartResearch", "Guatemala", nullptr));
        pays->setItemText(69, QCoreApplication::translate("SmartResearch", "Guinea", nullptr));
        pays->setItemText(70, QCoreApplication::translate("SmartResearch", "Guinea-Bissau", nullptr));
        pays->setItemText(71, QCoreApplication::translate("SmartResearch", "Guyana", nullptr));
        pays->setItemText(72, QCoreApplication::translate("SmartResearch", "Haiti", nullptr));
        pays->setItemText(73, QCoreApplication::translate("SmartResearch", "Honduras", nullptr));
        pays->setItemText(74, QCoreApplication::translate("SmartResearch", "Hungary", nullptr));
        pays->setItemText(75, QCoreApplication::translate("SmartResearch", "Iceland", nullptr));
        pays->setItemText(76, QCoreApplication::translate("SmartResearch", "India", nullptr));
        pays->setItemText(77, QCoreApplication::translate("SmartResearch", "Indonesia", nullptr));
        pays->setItemText(78, QCoreApplication::translate("SmartResearch", "Iran", nullptr));
        pays->setItemText(79, QCoreApplication::translate("SmartResearch", "Iraq", nullptr));
        pays->setItemText(80, QCoreApplication::translate("SmartResearch", "Ireland", nullptr));
        pays->setItemText(81, QCoreApplication::translate("SmartResearch", "Israel", nullptr));
        pays->setItemText(82, QCoreApplication::translate("SmartResearch", "Italy", nullptr));
        pays->setItemText(83, QCoreApplication::translate("SmartResearch", "Ivory Coast", nullptr));
        pays->setItemText(84, QCoreApplication::translate("SmartResearch", "Jamaica", nullptr));
        pays->setItemText(85, QCoreApplication::translate("SmartResearch", "Japan", nullptr));
        pays->setItemText(86, QCoreApplication::translate("SmartResearch", "Jordan", nullptr));
        pays->setItemText(87, QCoreApplication::translate("SmartResearch", "Kazakhstan", nullptr));
        pays->setItemText(88, QCoreApplication::translate("SmartResearch", "Kenya", nullptr));
        pays->setItemText(89, QCoreApplication::translate("SmartResearch", "Kiribati", nullptr));
        pays->setItemText(90, QCoreApplication::translate("SmartResearch", "Kuwait", nullptr));
        pays->setItemText(91, QCoreApplication::translate("SmartResearch", "Kyrgyzstan", nullptr));
        pays->setItemText(92, QCoreApplication::translate("SmartResearch", "Laos", nullptr));
        pays->setItemText(93, QCoreApplication::translate("SmartResearch", "Latvia", nullptr));
        pays->setItemText(94, QCoreApplication::translate("SmartResearch", "Lebanon", nullptr));
        pays->setItemText(95, QCoreApplication::translate("SmartResearch", "Lesotho", nullptr));
        pays->setItemText(96, QCoreApplication::translate("SmartResearch", "Liberia", nullptr));
        pays->setItemText(97, QCoreApplication::translate("SmartResearch", "Libya", nullptr));
        pays->setItemText(98, QCoreApplication::translate("SmartResearch", "Liechtenstein", nullptr));
        pays->setItemText(99, QCoreApplication::translate("SmartResearch", "Lithuania", nullptr));
        pays->setItemText(100, QCoreApplication::translate("SmartResearch", "Luxembourg", nullptr));
        pays->setItemText(101, QCoreApplication::translate("SmartResearch", "Madagascar", nullptr));
        pays->setItemText(102, QCoreApplication::translate("SmartResearch", "Malawi", nullptr));
        pays->setItemText(103, QCoreApplication::translate("SmartResearch", "Malaysia", nullptr));
        pays->setItemText(104, QCoreApplication::translate("SmartResearch", "Maldives", nullptr));
        pays->setItemText(105, QCoreApplication::translate("SmartResearch", "Mali", nullptr));
        pays->setItemText(106, QCoreApplication::translate("SmartResearch", "Malta", nullptr));
        pays->setItemText(107, QCoreApplication::translate("SmartResearch", "Marshall Islands", nullptr));
        pays->setItemText(108, QCoreApplication::translate("SmartResearch", "Mauritania", nullptr));
        pays->setItemText(109, QCoreApplication::translate("SmartResearch", "Mauritius", nullptr));
        pays->setItemText(110, QCoreApplication::translate("SmartResearch", "Mexico", nullptr));
        pays->setItemText(111, QCoreApplication::translate("SmartResearch", "Micronesia", nullptr));
        pays->setItemText(112, QCoreApplication::translate("SmartResearch", "Moldova", nullptr));
        pays->setItemText(113, QCoreApplication::translate("SmartResearch", "Monaco", nullptr));
        pays->setItemText(114, QCoreApplication::translate("SmartResearch", "Mongolia", nullptr));
        pays->setItemText(115, QCoreApplication::translate("SmartResearch", "Montenegro", nullptr));
        pays->setItemText(116, QCoreApplication::translate("SmartResearch", "Morocco", nullptr));
        pays->setItemText(117, QCoreApplication::translate("SmartResearch", "Mozambique", nullptr));
        pays->setItemText(118, QCoreApplication::translate("SmartResearch", "Myanmar", nullptr));
        pays->setItemText(119, QCoreApplication::translate("SmartResearch", "Namibia", nullptr));
        pays->setItemText(120, QCoreApplication::translate("SmartResearch", "Nauru", nullptr));
        pays->setItemText(121, QCoreApplication::translate("SmartResearch", "Nepal", nullptr));
        pays->setItemText(122, QCoreApplication::translate("SmartResearch", "Netherlands", nullptr));
        pays->setItemText(123, QCoreApplication::translate("SmartResearch", "New Zealand", nullptr));
        pays->setItemText(124, QCoreApplication::translate("SmartResearch", "Nicaragua", nullptr));
        pays->setItemText(125, QCoreApplication::translate("SmartResearch", "Niger", nullptr));
        pays->setItemText(126, QCoreApplication::translate("SmartResearch", "Nigeria", nullptr));
        pays->setItemText(127, QCoreApplication::translate("SmartResearch", "North Korea", nullptr));
        pays->setItemText(128, QCoreApplication::translate("SmartResearch", "North Macedonia", nullptr));
        pays->setItemText(129, QCoreApplication::translate("SmartResearch", "Norway", nullptr));
        pays->setItemText(130, QCoreApplication::translate("SmartResearch", "Oman", nullptr));
        pays->setItemText(131, QCoreApplication::translate("SmartResearch", "Pakistan", nullptr));
        pays->setItemText(132, QCoreApplication::translate("SmartResearch", "Palau", nullptr));
        pays->setItemText(133, QCoreApplication::translate("SmartResearch", "Palestine", nullptr));
        pays->setItemText(134, QCoreApplication::translate("SmartResearch", "Panama", nullptr));
        pays->setItemText(135, QCoreApplication::translate("SmartResearch", "Papua New Guinea", nullptr));
        pays->setItemText(136, QCoreApplication::translate("SmartResearch", "Paraguay", nullptr));
        pays->setItemText(137, QCoreApplication::translate("SmartResearch", "Peru", nullptr));
        pays->setItemText(138, QCoreApplication::translate("SmartResearch", "Philippines", nullptr));
        pays->setItemText(139, QCoreApplication::translate("SmartResearch", "Poland", nullptr));
        pays->setItemText(140, QCoreApplication::translate("SmartResearch", "Portugal", nullptr));
        pays->setItemText(141, QCoreApplication::translate("SmartResearch", "Qatar", nullptr));
        pays->setItemText(142, QCoreApplication::translate("SmartResearch", "Romania", nullptr));
        pays->setItemText(143, QCoreApplication::translate("SmartResearch", "Russia", nullptr));
        pays->setItemText(144, QCoreApplication::translate("SmartResearch", "Rwanda", nullptr));
        pays->setItemText(145, QCoreApplication::translate("SmartResearch", "Saint Kitts and Nevis", nullptr));
        pays->setItemText(146, QCoreApplication::translate("SmartResearch", "Saint Lucia", nullptr));
        pays->setItemText(147, QCoreApplication::translate("SmartResearch", "Saint Vincent and the Grenadines", nullptr));
        pays->setItemText(148, QCoreApplication::translate("SmartResearch", "Samoa", nullptr));
        pays->setItemText(149, QCoreApplication::translate("SmartResearch", "San Marino", nullptr));
        pays->setItemText(150, QCoreApplication::translate("SmartResearch", "Sao Tome and Principe", nullptr));
        pays->setItemText(151, QCoreApplication::translate("SmartResearch", "Saudi Arabia", nullptr));
        pays->setItemText(152, QCoreApplication::translate("SmartResearch", "Senegal", nullptr));
        pays->setItemText(153, QCoreApplication::translate("SmartResearch", "Serbia", nullptr));
        pays->setItemText(154, QCoreApplication::translate("SmartResearch", "Seychelles", nullptr));
        pays->setItemText(155, QCoreApplication::translate("SmartResearch", "Sierra Leone", nullptr));
        pays->setItemText(156, QCoreApplication::translate("SmartResearch", "Singapore", nullptr));
        pays->setItemText(157, QCoreApplication::translate("SmartResearch", "Slovakia", nullptr));
        pays->setItemText(158, QCoreApplication::translate("SmartResearch", "Slovenia", nullptr));
        pays->setItemText(159, QCoreApplication::translate("SmartResearch", "Solomon Islands", nullptr));
        pays->setItemText(160, QCoreApplication::translate("SmartResearch", "Somalia", nullptr));
        pays->setItemText(161, QCoreApplication::translate("SmartResearch", "South Africa", nullptr));
        pays->setItemText(162, QCoreApplication::translate("SmartResearch", "South Korea", nullptr));
        pays->setItemText(163, QCoreApplication::translate("SmartResearch", "South Sudan", nullptr));
        pays->setItemText(164, QCoreApplication::translate("SmartResearch", "Spain", nullptr));
        pays->setItemText(165, QCoreApplication::translate("SmartResearch", "Sri Lanka", nullptr));
        pays->setItemText(166, QCoreApplication::translate("SmartResearch", "Sudan", nullptr));
        pays->setItemText(167, QCoreApplication::translate("SmartResearch", "Suriname", nullptr));
        pays->setItemText(168, QCoreApplication::translate("SmartResearch", "Sweden", nullptr));
        pays->setItemText(169, QCoreApplication::translate("SmartResearch", "Switzerland", nullptr));
        pays->setItemText(170, QCoreApplication::translate("SmartResearch", "Syria", nullptr));
        pays->setItemText(171, QCoreApplication::translate("SmartResearch", "Taiwan", nullptr));
        pays->setItemText(172, QCoreApplication::translate("SmartResearch", "Tajikistan", nullptr));
        pays->setItemText(173, QCoreApplication::translate("SmartResearch", "Tanzania", nullptr));
        pays->setItemText(174, QCoreApplication::translate("SmartResearch", "Thailand", nullptr));
        pays->setItemText(175, QCoreApplication::translate("SmartResearch", "Timor-Leste", nullptr));
        pays->setItemText(176, QCoreApplication::translate("SmartResearch", "Togo", nullptr));
        pays->setItemText(177, QCoreApplication::translate("SmartResearch", "Tonga", nullptr));
        pays->setItemText(178, QCoreApplication::translate("SmartResearch", "Trinidad and Tobago", nullptr));
        pays->setItemText(179, QCoreApplication::translate("SmartResearch", "Tunisia", nullptr));
        pays->setItemText(180, QCoreApplication::translate("SmartResearch", "Turkey", nullptr));
        pays->setItemText(181, QCoreApplication::translate("SmartResearch", "Turkmenistan", nullptr));
        pays->setItemText(182, QCoreApplication::translate("SmartResearch", "Tuvalu", nullptr));
        pays->setItemText(183, QCoreApplication::translate("SmartResearch", "Uganda", nullptr));
        pays->setItemText(184, QCoreApplication::translate("SmartResearch", "Ukraine", nullptr));
        pays->setItemText(185, QCoreApplication::translate("SmartResearch", "United Arab Emirates", nullptr));
        pays->setItemText(186, QCoreApplication::translate("SmartResearch", "United Kingdom", nullptr));
        pays->setItemText(187, QCoreApplication::translate("SmartResearch", "United States", nullptr));
        pays->setItemText(188, QCoreApplication::translate("SmartResearch", "Uruguay", nullptr));
        pays->setItemText(189, QCoreApplication::translate("SmartResearch", "Uzbekistan", nullptr));
        pays->setItemText(190, QCoreApplication::translate("SmartResearch", "Vanuatu", nullptr));
        pays->setItemText(191, QCoreApplication::translate("SmartResearch", "Vatican City", nullptr));
        pays->setItemText(192, QCoreApplication::translate("SmartResearch", "Venezuela", nullptr));
        pays->setItemText(193, QCoreApplication::translate("SmartResearch", "Vietnam", nullptr));
        pays->setItemText(194, QCoreApplication::translate("SmartResearch", "Yemen", nullptr));
        pays->setItemText(195, QCoreApplication::translate("SmartResearch", "Zambia", nullptr));
        pays->setItemText(196, QCoreApplication::translate("SmartResearch", "Zimbabwe", nullptr));

        label_Journal_organisation->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Organisation</span></p></body></html>", nullptr));
        label_Journal_periodicite->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">P\303\251riodicit\303\251</span></p></body></html>", nullptr));
        label_Journal_siteweb->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Site Web</span></p></body></html>", nullptr));
        enregistrer1->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modif1->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annuler->setText(QString());
        groupBox_Session_List_4->setTitle(QString());
        rechercheSession_4->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        SuppSession_4->setText(QString());
        quitterSession_4->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        expoSession_4->setText(QCoreApplication::translate("SmartResearch", "Exporter format pdf", nullptr));
        comboBox_8->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_8->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        groupBox_Stats_Journal->setTitle(QString());
        label_Chart_Journal->setText(QString());
        groupBox_Reviewer_Form->setTitle(QString());
        label_Rev_ID->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_Rev_Nom->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_Rev_Email->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Email</span></p></body></html>", nullptr));
        label_Rev_Spec->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Sp\303\203\302\251cialit\303\203\302\251</span></p></body></html>", nullptr));
        label_Rev_Inst->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Institution</span></p></body></html>", nullptr));
        label_Rev_Statut->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Statut</span></p></body></html>", nullptr));
        actifReviewer->setText(QCoreApplication::translate("SmartResearch", "Actif", nullptr));
        inactifReviewer->setText(QCoreApplication::translate("SmartResearch", "Inactif", nullptr));
        enregistrerReviewer->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modifierReviewer->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annulerReviewer->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_Session_List_3->setTitle(QString());
        rechercheSession_3->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        SuppSession_3->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        quitterSession_3->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        expoSession_3->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        groupBox_Session_Form->setTitle(QString());
        label_S_ID->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_S_Titre->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Titre:</span></p></body></html>", nullptr));
        label_S_Date->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-weight:700; color:#ffffff;\">Date:</span></p></body></html>", nullptr));
        label_S_Lieu->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Lieu</span></p></body></html>", nullptr));
        label_S_Type->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        label_S_ListPub->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Liste des publication:</span></p></body></html>", nullptr));
        label_S_ListRev->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Liste des reviewes:</span></p></body></html>", nullptr));
        radioButton_Admin_5->setText(QCoreApplication::translate("SmartResearch", "conference", nullptr));
        radioButton_Admin_6->setText(QCoreApplication::translate("SmartResearch", "presentation", nullptr));
        radioButton_Chercheur_2->setText(QCoreApplication::translate("SmartResearch", "atlier", nullptr));
        enregistrerSession->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modifSession->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annulerSession->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_Session_List->setTitle(QString());
        rechercheSession->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        SuppSession->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        quitterSession->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        expoSession->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        groupBox_Paiement_Form->setTitle(QString());
        label_ID_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Paiement_ID</span></p></body></html>", nullptr));
        label_Nom_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type_frais</span></p></body></html>", nullptr));
        label_Email_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Montant</span></p></body></html>", nullptr));
        label_Mdp_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Devise</span></p></body></html>", nullptr));
        label_Role_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Role</span></p></body></html>", nullptr));
        label_Mot_de_passe_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mot de passe user</span></p></body></html>", nullptr));
        label_num_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Statue_paiement</span></p></body></html>", nullptr));
        radioButton_Chercheur_4->setText(QCoreApplication::translate("SmartResearch", "reviewer", nullptr));
        radioButton_Admin_10->setText(QCoreApplication::translate("SmartResearch", "editer", nullptr));
        radioButton_Admin_9->setText(QCoreApplication::translate("SmartResearch", "Admin", nullptr));
        label_Role_Utilisateur_5->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Role</span></p></body></html>", nullptr));
        btn_Enregistrer_Utilisateur_2->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        btn_Modifier_Utilisateur_2->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        btn_Annuler_Utilisateur_2->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_Session_List_2->setTitle(QString());
        rechercheSession_2->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        SuppSession_2->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        quitterSession_2->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        expoSession_2->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        comboBox_6->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        TableaudeBoard->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#ffffff;\">Tableau de Board</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmartResearch: public Ui_SmartResearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTRESEARCH_H
