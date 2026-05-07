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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QLabel *label_Pere;
    QLineEdit *lineEdit_Pere;
    QLabel *label_Mere;
    QLineEdit *lineEdit_Mere;
    QLabel *label_Age;
    QSpinBox *spinBox_Age;
    QLabel *label_Freres;
    QSpinBox *spinBox_Freres;
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
    QComboBox *comboBox_typePub;
    QLabel *label_6;
    QLineEdit *mot_clePub;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_statut;
    QRadioButton *radioButton_statut_attente;
    QRadioButton *radioButton_statut_accepte;
    QRadioButton *radioButton_statut_rejete;
    QLabel *label_8;
    QDateEdit *datePub;
    QLabel *label_qr_pub;
    QPushButton *enregistrer;
    QPushButton *modif;
    QPushButton *annulerajout_client;
    QGroupBox *groupBox_Session_List_5;
    QComboBox *comboBox_9;
    QTableView *tableWidget_9;
    QGroupBox *groupBox_Stats_Publication;
    QLabel *label_Chart_Publication;
    QPushButton *pushButton_recherche_3;
    QPushButton *smartAssistantButton;
    QLineEdit *rechSession_5;
    QPushButton *pushButton_supprimer_client;
    QPushButton *btn_qr_pub;
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
    QLabel *label_Rev_Phone;
    QLineEdit *phoneReviewer;
    QLabel *label_Rev_Photo;
    QHBoxLayout *horizontalLayout_Photo;
    QPushButton *uploadPhotoBtn;
    QLineEdit *photoPathReviewer;
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
    QVBoxLayout *verticalLayout_SessionForm;
    QFormLayout *formLayout_Session;
    QLabel *label_S_ID;
    QLineEdit *lineEdit_ID;
    QLabel *label_S_Titre;
    QLineEdit *lineEdit_Titre;
    QLabel *label_S_Date;
    QDateEdit *dateEdit_Date;
    QLabel *label_S_Lieu;
    QLineEdit *lineEdit_Lieu;
    QLabel *label_S_Type;
    QComboBox *comboBox_Type;
    QHBoxLayout *horizontalLayout_Assoc;
    QVBoxLayout *verticalLayout_Pubs;
    QLabel *lbl_AllPubs;
    QListWidget *list_Publications;
    QPushButton *btn_AssocierPublications;
    QLabel *lbl_SessPubs;
    QListWidget *list_SessionPubs;
    QPushButton *btn_RetirerPub;
    QVBoxLayout *verticalLayout_Revs;
    QLabel *lbl_AllRevs;
    QListWidget *list_Reviewers;
    QPushButton *btn_AssocierReviewers;
    QLabel *lbl_SessRevs;
    QListWidget *list_SessionRevs;
    QPushButton *btn_RetirerRev;
    QHBoxLayout *horizontalLayout_Buttons;
    QPushButton *btn_Enregistrer;
    QPushButton *annuler_2;
    QGroupBox *groupBox_Session_List;
    QVBoxLayout *verticalLayout_SessionList;
    QHBoxLayout *horizontalLayout_Search;
    QLineEdit *rechSession;
    QPushButton *rechercheSession;
    QTableWidget *tableWidget_Sessions;
    QHBoxLayout *horizontalLayout_ListBtns;
    QPushButton *SuppSession;
    QPushButton *expoSession;
    QPushButton *quitterSession;
    QWidget *stackedWidgetPage6;
    QGroupBox *groupBox_Session_List_2;
    QLineEdit *lineEdit_recherchPaiement;
    QPushButton *pushButton_supprimer_paiement;
    QTableView *tablePaiement;
    QPushButton *pushButton_recherche_5;
    QPushButton *quitterSession_2;
    QLabel *QRCODE_3;
    QPushButton *qr;
    QPushButton *pb_excel;
    QComboBox *comboBoxPaiement;
    QPushButton *expoSession_2;
    QGroupBox *groupBox_Paiement_Form;
    QWidget *formLayoutWidget_Utilisateur_2;
    QFormLayout *formLayout_Utilisateur_4;
    QLabel *label_ID_Utilisateur_4;
    QLineEdit *lineEdit_ID_Paiement;
    QLabel *label_Nom_Utilisateur_4;
    QComboBox *comboBox_TypeFrais;
    QLabel *label_Email_Utilisateur_4;
    QLineEdit *lineEdit_Montant;
    QLabel *label_Mdp_Utilisateur_4;
    QComboBox *comboBox_Devise;
    QLabel *label_Mot_de_passe_4;
    QComboBox *comboBox_ModePaiement;
    QLabel *label_Role_Utilisateur_5;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_Role_4;
    QRadioButton *radioButton_paye;
    QRadioButton *radioButton_annule;
    QRadioButton *radioButton_attente;
    QPushButton *btn_Modifier_paiement;
    QPushButton *btn_Enregistrer_paiement;
    QPushButton *btn_Annuler_paiement;
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
        formLayoutWidget_Utilisateur->setGeometry(QRect(20, 40, 451, 367));
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

        label_Pere = new QLabel(formLayoutWidget_Utilisateur);
        label_Pere->setObjectName("label_Pere");

        formLayout_Utilisateur->setWidget(8, QFormLayout::LabelRole, label_Pere);

        lineEdit_Pere = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Pere->setObjectName("lineEdit_Pere");
        lineEdit_Pere->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(8, QFormLayout::FieldRole, lineEdit_Pere);

        label_Mere = new QLabel(formLayoutWidget_Utilisateur);
        label_Mere->setObjectName("label_Mere");

        formLayout_Utilisateur->setWidget(9, QFormLayout::LabelRole, label_Mere);

        lineEdit_Mere = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Mere->setObjectName("lineEdit_Mere");
        lineEdit_Mere->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(9, QFormLayout::FieldRole, lineEdit_Mere);

        label_Age = new QLabel(formLayoutWidget_Utilisateur);
        label_Age->setObjectName("label_Age");

        formLayout_Utilisateur->setWidget(10, QFormLayout::LabelRole, label_Age);

        spinBox_Age = new QSpinBox(formLayoutWidget_Utilisateur);
        spinBox_Age->setObjectName("spinBox_Age");
        spinBox_Age->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBox_Age->setMinimum(1);
        spinBox_Age->setMaximum(120);
        spinBox_Age->setValue(18);

        formLayout_Utilisateur->setWidget(10, QFormLayout::FieldRole, spinBox_Age);

        label_Freres = new QLabel(formLayoutWidget_Utilisateur);
        label_Freres->setObjectName("label_Freres");

        formLayout_Utilisateur->setWidget(11, QFormLayout::LabelRole, label_Freres);

        spinBox_Freres = new QSpinBox(formLayoutWidget_Utilisateur);
        spinBox_Freres->setObjectName("spinBox_Freres");
        spinBox_Freres->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBox_Freres->setMaximum(50);

        formLayout_Utilisateur->setWidget(11, QFormLayout::FieldRole, spinBox_Freres);

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
"    background-color: rgb(66, 206, 164);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgb(140, 0, 0);\n"
"}"));
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
        label_Chart_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: transparent; border: none;"));
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
        formLayoutWidget->setGeometry(QRect(20, 40, 435, 261));
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

        comboBox_typePub = new QComboBox(formLayoutWidget);
        comboBox_typePub->setObjectName("comboBox_typePub");
        comboBox_typePub->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_typePub);

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

        label_qr_pub = new QLabel(groupBox_2);
        label_qr_pub->setObjectName("label_qr_pub");
        label_qr_pub->setGeometry(QRect(175, 265, 120, 120));
        label_qr_pub->setStyleSheet(QString::fromUtf8("background-color: white; border-radius: 12px; border: 2px solid #3b82f6;"));
        label_qr_pub->setScaledContents(true);
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
        smartAssistantButton = new QPushButton(groupBox_Session_List_5);
        smartAssistantButton->setObjectName("smartAssistantButton");
        smartAssistantButton->setGeometry(QRect(340, 30, 171, 41));
        smartAssistantButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #10b981;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #059669;\n"
"}\n"
""));
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
        btn_qr_pub = new QPushButton(groupBox_Session_List_5);
        btn_qr_pub->setObjectName("btn_qr_pub");
        btn_qr_pub->setGeometry(QRect(310, 470, 221, 51));
        btn_qr_pub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #7c3aed;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6d28d9;\n"
"}"));
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
        groupBox_Journal_Form->setGeometry(QRect(0, 10, 471, 541));
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
        formLayoutWidget_Journal = new QWidget(groupBox_Journal_Form);
        formLayoutWidget_Journal->setObjectName("formLayoutWidget_Journal");
        formLayoutWidget_Journal->setGeometry(QRect(20, 40, 473, 325));
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
        enregistrer1->setGeometry(QRect(40, 400, 150, 41));
        enregistrer1->setMinimumSize(QSize(0, 0));
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
        modif1 = new QPushButton(groupBox_Journal_Form);
        modif1->setObjectName("modif1");
        modif1->setGeometry(QRect(280, 400, 150, 41));
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
        annuler = new QPushButton(groupBox_Journal_Form);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(120, 470, 221, 41));
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
        annuler->setIcon(icon);
        groupBox_Session_List_4 = new QGroupBox(stackedWidgetPage3);
        groupBox_Session_List_4->setObjectName("groupBox_Session_List_4");
        groupBox_Session_List_4->setGeometry(QRect(480, 10, 751, 541));
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
        rechercheSession_4->setGeometry(QRect(210, 30, 121, 41));
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
        rechercheSession_4->setIcon(icon2);
        SuppSession_4 = new QPushButton(groupBox_Session_List_4);
        SuppSession_4->setObjectName("SuppSession_4");
        SuppSession_4->setGeometry(QRect(30, 470, 61, 51));
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
        SuppSession_4->setIcon(icon1);
        quitterSession_4 = new QPushButton(groupBox_Session_List_4);
        quitterSession_4->setObjectName("quitterSession_4");
        quitterSession_4->setGeometry(QRect(550, 470, 131, 51));
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
        expoSession_4 = new QPushButton(groupBox_Session_List_4);
        expoSession_4->setObjectName("expoSession_4");
        expoSession_4->setGeometry(QRect(100, 470, 191, 51));
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
        comboBox_8 = new QComboBox(groupBox_Session_List_4);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName("comboBox_8");
        comboBox_8->setGeometry(QRect(520, 30, 181, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
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
        tableWidget_8 = new QTableWidget(groupBox_Session_List_4);
        tableWidget_8->setObjectName("tableWidget_8");
        tableWidget_8->setGeometry(QRect(20, 110, 681, 151));
        tableWidget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
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
        formLayoutWidget_Reviewer->setGeometry(QRect(20, 30, 411, 300));
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

        label_Rev_Phone = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_Phone->setObjectName("label_Rev_Phone");

        formLayout_Reviewer->setWidget(5, QFormLayout::LabelRole, label_Rev_Phone);

        phoneReviewer = new QLineEdit(formLayoutWidget_Reviewer);
        phoneReviewer->setObjectName("phoneReviewer");
        phoneReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Reviewer->setWidget(5, QFormLayout::FieldRole, phoneReviewer);

        label_Rev_Photo = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_Photo->setObjectName("label_Rev_Photo");

        formLayout_Reviewer->setWidget(6, QFormLayout::LabelRole, label_Rev_Photo);

        horizontalLayout_Photo = new QHBoxLayout();
        horizontalLayout_Photo->setObjectName("horizontalLayout_Photo");
        uploadPhotoBtn = new QPushButton(formLayoutWidget_Reviewer);
        uploadPhotoBtn->setObjectName("uploadPhotoBtn");
        uploadPhotoBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200); color: black;"));

        horizontalLayout_Photo->addWidget(uploadPhotoBtn);

        photoPathReviewer = new QLineEdit(formLayoutWidget_Reviewer);
        photoPathReviewer->setObjectName("photoPathReviewer");
        photoPathReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        photoPathReviewer->setReadOnly(true);

        horizontalLayout_Photo->addWidget(photoPathReviewer);


        formLayout_Reviewer->setLayout(6, QFormLayout::FieldRole, horizontalLayout_Photo);

        label_Rev_Statut = new QLabel(formLayoutWidget_Reviewer);
        label_Rev_Statut->setObjectName("label_Rev_Statut");

        formLayout_Reviewer->setWidget(7, QFormLayout::LabelRole, label_Rev_Statut);

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


        formLayout_Reviewer->setLayout(7, QFormLayout::FieldRole, formLayout_Rev_Statut);

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
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::SolidPattern);
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
        QBrush brush8(QColor(127, 127, 127, 127));
        brush8.setStyle(Qt::SolidPattern);
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
        groupBox_Session_Form->setGeometry(QRect(0, 10, 481, 601));
        groupBox_Session_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168); border: #A8D3F0;"));
        verticalLayout_SessionForm = new QVBoxLayout(groupBox_Session_Form);
        verticalLayout_SessionForm->setObjectName("verticalLayout_SessionForm");
        formLayout_Session = new QFormLayout();
        formLayout_Session->setObjectName("formLayout_Session");
        label_S_ID = new QLabel(groupBox_Session_Form);
        label_S_ID->setObjectName("label_S_ID");

        formLayout_Session->setWidget(0, QFormLayout::LabelRole, label_S_ID);

        lineEdit_ID = new QLineEdit(groupBox_Session_Form);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(0, QFormLayout::FieldRole, lineEdit_ID);

        label_S_Titre = new QLabel(groupBox_Session_Form);
        label_S_Titre->setObjectName("label_S_Titre");

        formLayout_Session->setWidget(1, QFormLayout::LabelRole, label_S_Titre);

        lineEdit_Titre = new QLineEdit(groupBox_Session_Form);
        lineEdit_Titre->setObjectName("lineEdit_Titre");
        lineEdit_Titre->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(1, QFormLayout::FieldRole, lineEdit_Titre);

        label_S_Date = new QLabel(groupBox_Session_Form);
        label_S_Date->setObjectName("label_S_Date");

        formLayout_Session->setWidget(2, QFormLayout::LabelRole, label_S_Date);

        dateEdit_Date = new QDateEdit(groupBox_Session_Form);
        dateEdit_Date->setObjectName("dateEdit_Date");
        dateEdit_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(2, QFormLayout::FieldRole, dateEdit_Date);

        label_S_Lieu = new QLabel(groupBox_Session_Form);
        label_S_Lieu->setObjectName("label_S_Lieu");

        formLayout_Session->setWidget(3, QFormLayout::LabelRole, label_S_Lieu);

        lineEdit_Lieu = new QLineEdit(groupBox_Session_Form);
        lineEdit_Lieu->setObjectName("lineEdit_Lieu");
        lineEdit_Lieu->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(3, QFormLayout::FieldRole, lineEdit_Lieu);

        label_S_Type = new QLabel(groupBox_Session_Form);
        label_S_Type->setObjectName("label_S_Type");

        formLayout_Session->setWidget(4, QFormLayout::LabelRole, label_S_Type);

        comboBox_Type = new QComboBox(groupBox_Session_Form);
        comboBox_Type->addItem(QString());
        comboBox_Type->addItem(QString());
        comboBox_Type->addItem(QString());
        comboBox_Type->setObjectName("comboBox_Type");
        comboBox_Type->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));

        formLayout_Session->setWidget(4, QFormLayout::FieldRole, comboBox_Type);


        verticalLayout_SessionForm->addLayout(formLayout_Session);

        horizontalLayout_Assoc = new QHBoxLayout();
        horizontalLayout_Assoc->setObjectName("horizontalLayout_Assoc");
        verticalLayout_Pubs = new QVBoxLayout();
        verticalLayout_Pubs->setObjectName("verticalLayout_Pubs");
        lbl_AllPubs = new QLabel(groupBox_Session_Form);
        lbl_AllPubs->setObjectName("lbl_AllPubs");

        verticalLayout_Pubs->addWidget(lbl_AllPubs);

        list_Publications = new QListWidget(groupBox_Session_Form);
        list_Publications->setObjectName("list_Publications");
        list_Publications->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));
        list_Publications->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);

        verticalLayout_Pubs->addWidget(list_Publications);

        btn_AssocierPublications = new QPushButton(groupBox_Session_Form);
        btn_AssocierPublications->setObjectName("btn_AssocierPublications");

        verticalLayout_Pubs->addWidget(btn_AssocierPublications);

        lbl_SessPubs = new QLabel(groupBox_Session_Form);
        lbl_SessPubs->setObjectName("lbl_SessPubs");

        verticalLayout_Pubs->addWidget(lbl_SessPubs);

        list_SessionPubs = new QListWidget(groupBox_Session_Form);
        list_SessionPubs->setObjectName("list_SessionPubs");
        list_SessionPubs->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));

        verticalLayout_Pubs->addWidget(list_SessionPubs);

        btn_RetirerPub = new QPushButton(groupBox_Session_Form);
        btn_RetirerPub->setObjectName("btn_RetirerPub");

        verticalLayout_Pubs->addWidget(btn_RetirerPub);


        horizontalLayout_Assoc->addLayout(verticalLayout_Pubs);

        verticalLayout_Revs = new QVBoxLayout();
        verticalLayout_Revs->setObjectName("verticalLayout_Revs");
        lbl_AllRevs = new QLabel(groupBox_Session_Form);
        lbl_AllRevs->setObjectName("lbl_AllRevs");

        verticalLayout_Revs->addWidget(lbl_AllRevs);

        list_Reviewers = new QListWidget(groupBox_Session_Form);
        list_Reviewers->setObjectName("list_Reviewers");
        list_Reviewers->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));
        list_Reviewers->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);

        verticalLayout_Revs->addWidget(list_Reviewers);

        btn_AssocierReviewers = new QPushButton(groupBox_Session_Form);
        btn_AssocierReviewers->setObjectName("btn_AssocierReviewers");

        verticalLayout_Revs->addWidget(btn_AssocierReviewers);

        lbl_SessRevs = new QLabel(groupBox_Session_Form);
        lbl_SessRevs->setObjectName("lbl_SessRevs");

        verticalLayout_Revs->addWidget(lbl_SessRevs);

        list_SessionRevs = new QListWidget(groupBox_Session_Form);
        list_SessionRevs->setObjectName("list_SessionRevs");
        list_SessionRevs->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));

        verticalLayout_Revs->addWidget(list_SessionRevs);

        btn_RetirerRev = new QPushButton(groupBox_Session_Form);
        btn_RetirerRev->setObjectName("btn_RetirerRev");

        verticalLayout_Revs->addWidget(btn_RetirerRev);


        horizontalLayout_Assoc->addLayout(verticalLayout_Revs);


        verticalLayout_SessionForm->addLayout(horizontalLayout_Assoc);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setObjectName("horizontalLayout_Buttons");
        btn_Enregistrer = new QPushButton(groupBox_Session_Form);
        btn_Enregistrer->setObjectName("btn_Enregistrer");
        btn_Enregistrer->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255); color: white; font-weight: bold; border-radius: 8px; padding: 8px;"));

        horizontalLayout_Buttons->addWidget(btn_Enregistrer);

        annuler_2 = new QPushButton(groupBox_Session_Form);
        annuler_2->setObjectName("annuler_2");
        annuler_2->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 206, 164); color: white; font-weight: bold; border-radius: 8px; padding: 8px;"));

        horizontalLayout_Buttons->addWidget(annuler_2);


        verticalLayout_SessionForm->addLayout(horizontalLayout_Buttons);

        groupBox_Session_List = new QGroupBox(stackedWidgetPage5);
        groupBox_Session_List->setObjectName("groupBox_Session_List");
        groupBox_Session_List->setGeometry(QRect(490, 10, 741, 601));
        groupBox_Session_List->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168); border: #A8D3F0;"));
        verticalLayout_SessionList = new QVBoxLayout(groupBox_Session_List);
        verticalLayout_SessionList->setObjectName("verticalLayout_SessionList");
        horizontalLayout_Search = new QHBoxLayout();
        horizontalLayout_Search->setObjectName("horizontalLayout_Search");
        rechSession = new QLineEdit(groupBox_Session_List);
        rechSession->setObjectName("rechSession");
        rechSession->setStyleSheet(QString::fromUtf8("background-color: white;"));

        horizontalLayout_Search->addWidget(rechSession);

        rechercheSession = new QPushButton(groupBox_Session_List);
        rechercheSession->setObjectName("rechercheSession");

        horizontalLayout_Search->addWidget(rechercheSession);


        verticalLayout_SessionList->addLayout(horizontalLayout_Search);

        tableWidget_Sessions = new QTableWidget(groupBox_Session_List);
        if (tableWidget_Sessions->columnCount() < 7)
            tableWidget_Sessions->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Sessions->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Sessions->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Sessions->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Sessions->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Sessions->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Sessions->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Sessions->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_Sessions->setObjectName("tableWidget_Sessions");
        tableWidget_Sessions->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));

        verticalLayout_SessionList->addWidget(tableWidget_Sessions);

        horizontalLayout_ListBtns = new QHBoxLayout();
        horizontalLayout_ListBtns->setObjectName("horizontalLayout_ListBtns");
        SuppSession = new QPushButton(groupBox_Session_List);
        SuppSession->setObjectName("SuppSession");
        SuppSession->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0); color: white;"));

        horizontalLayout_ListBtns->addWidget(SuppSession);

        expoSession = new QPushButton(groupBox_Session_List);
        expoSession->setObjectName("expoSession");

        horizontalLayout_ListBtns->addWidget(expoSession);

        quitterSession = new QPushButton(groupBox_Session_List);
        quitterSession->setObjectName("quitterSession");

        horizontalLayout_ListBtns->addWidget(quitterSession);


        verticalLayout_SessionList->addLayout(horizontalLayout_ListBtns);

        stackedWidget->addWidget(stackedWidgetPage5);
        stackedWidgetPage6 = new QWidget();
        stackedWidgetPage6->setObjectName("stackedWidgetPage6");
        groupBox_Session_List_2 = new QGroupBox(stackedWidgetPage6);
        groupBox_Session_List_2->setObjectName("groupBox_Session_List_2");
        groupBox_Session_List_2->setGeometry(QRect(460, 20, 741, 541));
        groupBox_Session_List_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;\n"
"/* Style pour tous les GroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #2c3e50; /* Couleur de la bordure */\n"
"    border-radius: 15px;      /* M\303\252me arrondi que les boutons */\n"
"    margin-top: 20px;         /* Espace pour le titre en haut */\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"/* Style sp\303\251cifique pour le titre du GroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* Place le titre en haut au centre */\n"
"    padding: 0 10px;\n"
"}"));
        lineEdit_recherchPaiement = new QLineEdit(groupBox_Session_List_2);
        lineEdit_recherchPaiement->setObjectName("lineEdit_recherchPaiement");
        lineEdit_recherchPaiement->setGeometry(QRect(10, 40, 161, 26));
        lineEdit_recherchPaiement->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_supprimer_paiement = new QPushButton(groupBox_Session_List_2);
        pushButton_supprimer_paiement->setObjectName("pushButton_supprimer_paiement");
        pushButton_supprimer_paiement->setGeometry(QRect(10, 450, 61, 51));
        pushButton_supprimer_paiement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_supprimer_paiement->setIcon(icon1);
        tablePaiement = new QTableView(groupBox_Session_List_2);
        tablePaiement->setObjectName("tablePaiement");
        tablePaiement->setGeometry(QRect(45, 111, 671, 301));
        tablePaiement->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_recherche_5 = new QPushButton(groupBox_Session_List_2);
        pushButton_recherche_5->setObjectName("pushButton_recherche_5");
        pushButton_recherche_5->setGeometry(QRect(190, 30, 121, 41));
        pushButton_recherche_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_recherche_5->setIcon(icon2);
        quitterSession_2 = new QPushButton(groupBox_Session_List_2);
        quitterSession_2->setObjectName("quitterSession_2");
        quitterSession_2->setGeometry(QRect(600, 490, 131, 41));
        quitterSession_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QRCODE_3 = new QLabel(groupBox_Session_List_2);
        QRCODE_3->setObjectName("QRCODE_3");
        QRCODE_3->setGeometry(QRect(470, 420, 111, 111));
        qr = new QPushButton(groupBox_Session_List_2);
        qr->setObjectName("qr");
        qr->setGeometry(QRect(280, 480, 150, 41));
        qr->setMinimumSize(QSize(0, 0));
        qr->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pb_excel = new QPushButton(groupBox_Session_List_2);
        pb_excel->setObjectName("pb_excel");
        pb_excel->setGeometry(QRect(280, 430, 150, 41));
        pb_excel->setMinimumSize(QSize(0, 0));
        pb_excel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBoxPaiement = new QComboBox(groupBox_Session_List_2);
        comboBoxPaiement->addItem(QString());
        comboBoxPaiement->addItem(QString());
        comboBoxPaiement->setObjectName("comboBoxPaiement");
        comboBoxPaiement->setGeometry(QRect(550, 20, 181, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette4.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::Accent, brush);
        comboBoxPaiement->setPalette(palette4);
        comboBoxPaiement->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        expoSession_2 = new QPushButton(groupBox_Session_List_2);
        expoSession_2->setObjectName("expoSession_2");
        expoSession_2->setGeometry(QRect(80, 450, 191, 51));
        expoSession_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(16, 151, 255);\n"
"   /* normal state */\n"
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
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::GoDown));
        expoSession_2->setIcon(icon3);
        groupBox_Paiement_Form = new QGroupBox(stackedWidgetPage6);
        groupBox_Paiement_Form->setObjectName("groupBox_Paiement_Form");
        groupBox_Paiement_Form->setGeometry(QRect(0, 20, 451, 541));
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

        lineEdit_ID_Paiement = new QLineEdit(formLayoutWidget_Utilisateur_2);
        lineEdit_ID_Paiement->setObjectName("lineEdit_ID_Paiement");
        lineEdit_ID_Paiement->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_ID_Paiement->setReadOnly(true);

        formLayout_Utilisateur_4->setWidget(0, QFormLayout::FieldRole, lineEdit_ID_Paiement);

        label_Nom_Utilisateur_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Nom_Utilisateur_4->setObjectName("label_Nom_Utilisateur_4");

        formLayout_Utilisateur_4->setWidget(1, QFormLayout::LabelRole, label_Nom_Utilisateur_4);

        comboBox_TypeFrais = new QComboBox(formLayoutWidget_Utilisateur_2);
        comboBox_TypeFrais->setObjectName("comboBox_TypeFrais");
        comboBox_TypeFrais->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(1, QFormLayout::FieldRole, comboBox_TypeFrais);

        label_Email_Utilisateur_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Email_Utilisateur_4->setObjectName("label_Email_Utilisateur_4");

        formLayout_Utilisateur_4->setWidget(2, QFormLayout::LabelRole, label_Email_Utilisateur_4);

        lineEdit_Montant = new QLineEdit(formLayoutWidget_Utilisateur_2);
        lineEdit_Montant->setObjectName("lineEdit_Montant");
        lineEdit_Montant->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(2, QFormLayout::FieldRole, lineEdit_Montant);

        label_Mdp_Utilisateur_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Mdp_Utilisateur_4->setObjectName("label_Mdp_Utilisateur_4");

        formLayout_Utilisateur_4->setWidget(3, QFormLayout::LabelRole, label_Mdp_Utilisateur_4);

        comboBox_Devise = new QComboBox(formLayoutWidget_Utilisateur_2);
        comboBox_Devise->setObjectName("comboBox_Devise");
        comboBox_Devise->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(3, QFormLayout::FieldRole, comboBox_Devise);

        label_Mot_de_passe_4 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Mot_de_passe_4->setObjectName("label_Mot_de_passe_4");

        formLayout_Utilisateur_4->setWidget(4, QFormLayout::LabelRole, label_Mot_de_passe_4);

        comboBox_ModePaiement = new QComboBox(formLayoutWidget_Utilisateur_2);
        comboBox_ModePaiement->setObjectName("comboBox_ModePaiement");
        comboBox_ModePaiement->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(4, QFormLayout::FieldRole, comboBox_ModePaiement);

        label_Role_Utilisateur_5 = new QLabel(formLayoutWidget_Utilisateur_2);
        label_Role_Utilisateur_5->setObjectName("label_Role_Utilisateur_5");

        formLayout_Utilisateur_4->setWidget(5, QFormLayout::LabelRole, label_Role_Utilisateur_5);

        dateEdit = new QDateEdit(formLayoutWidget_Utilisateur_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur_4->setWidget(5, QFormLayout::FieldRole, dateEdit);

        horizontalLayout_Role_4 = new QHBoxLayout();
        horizontalLayout_Role_4->setObjectName("horizontalLayout_Role_4");
        radioButton_paye = new QRadioButton(formLayoutWidget_Utilisateur_2);
        radioButton_paye->setObjectName("radioButton_paye");
        radioButton_paye->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_4->addWidget(radioButton_paye);

        radioButton_annule = new QRadioButton(formLayoutWidget_Utilisateur_2);
        radioButton_annule->setObjectName("radioButton_annule");
        radioButton_annule->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_4->addWidget(radioButton_annule);

        radioButton_attente = new QRadioButton(formLayoutWidget_Utilisateur_2);
        radioButton_attente->setObjectName("radioButton_attente");
        radioButton_attente->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold;"));

        horizontalLayout_Role_4->addWidget(radioButton_attente);


        formLayout_Utilisateur_4->setLayout(6, QFormLayout::FieldRole, horizontalLayout_Role_4);

        btn_Modifier_paiement = new QPushButton(groupBox_Paiement_Form);
        btn_Modifier_paiement->setObjectName("btn_Modifier_paiement");
        btn_Modifier_paiement->setGeometry(QRect(230, 400, 150, 41));
        btn_Modifier_paiement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_Enregistrer_paiement = new QPushButton(groupBox_Paiement_Form);
        btn_Enregistrer_paiement->setObjectName("btn_Enregistrer_paiement");
        btn_Enregistrer_paiement->setGeometry(QRect(30, 400, 150, 41));
        btn_Enregistrer_paiement->setMinimumSize(QSize(0, 0));
        btn_Enregistrer_paiement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_Annuler_paiement = new QPushButton(groupBox_Paiement_Form);
        btn_Annuler_paiement->setObjectName("btn_Annuler_paiement");
        btn_Annuler_paiement->setGeometry(QRect(100, 460, 221, 41));
        btn_Annuler_paiement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(66, 206, 164);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgb(140, 0, 0);\n"
"}"));
        btn_Annuler_paiement->setIcon(icon);
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
        menubar->setGeometry(QRect(0, 0, 1488, 21));
        SmartResearch->setMenuBar(menubar);
        statusbar = new QStatusBar(SmartResearch);
        statusbar->setObjectName("statusbar");
        SmartResearch->setStatusBar(statusbar);

        retranslateUi(SmartResearch);

        stackedWidget->setCurrentIndex(6);


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
        label_Pere->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom P\303\250re</span></p></body></html>", nullptr));
        label_Mere->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom M\303\250re</span></p></body></html>", nullptr));
        label_Age->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">\303\202ge</span></p></body></html>", nullptr));
        label_Freres->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nb Fr\303\250res</span></p></body></html>", nullptr));
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
        label_6->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mots cl\303\251s</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Statut</span></p></body></html>", nullptr));
        radioButton_statut_attente->setText(QCoreApplication::translate("SmartResearch", "En attente", nullptr));
        radioButton_statut_accepte->setText(QCoreApplication::translate("SmartResearch", "Accept\303\251", nullptr));
        radioButton_statut_rejete->setText(QCoreApplication::translate("SmartResearch", "Rejet\303\251", nullptr));
        label_8->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Date de soumission</span></p></body></html>", nullptr));
        label_qr_pub->setText(QString());
        enregistrer->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modif->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annulerajout_client->setText(QString());
        groupBox_Session_List_5->setTitle(QString());
        comboBox_9->setItemText(0, QCoreApplication::translate("SmartResearch", "     order croissant", nullptr));
        comboBox_9->setItemText(1, QCoreApplication::translate("SmartResearch", "     order decroissant", nullptr));

        groupBox_Stats_Publication->setTitle(QString());
        label_Chart_Publication->setText(QString());
        pushButton_recherche_3->setText(QCoreApplication::translate("SmartResearch", "Rechercher:", nullptr));
        smartAssistantButton->setText(QCoreApplication::translate("SmartResearch", "SmartAssistant", nullptr));
        pushButton_supprimer_client->setText(QString());
        btn_qr_pub->setText(QCoreApplication::translate("SmartResearch", "Smart Abstract QR", nullptr));
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
        label_Rev_Phone->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">T\303\251l\303\251phone</span></p></body></html>", nullptr));
        label_Rev_Photo->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Photo</span></p></body></html>", nullptr));
        uploadPhotoBtn->setText(QCoreApplication::translate("SmartResearch", "Parcourir...", nullptr));
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
        comboBox_Type->setItemText(0, QCoreApplication::translate("SmartResearch", "conference", nullptr));
        comboBox_Type->setItemText(1, QCoreApplication::translate("SmartResearch", "presentation", nullptr));
        comboBox_Type->setItemText(2, QCoreApplication::translate("SmartResearch", "atelier", nullptr));

        lbl_AllPubs->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" color:#ffffff;\">Publications disponibles</span></p></body></html>", nullptr));
        btn_AssocierPublications->setText(QCoreApplication::translate("SmartResearch", "Associer", nullptr));
        lbl_SessPubs->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" color:#ffffff;\">Publications associ\303\251es</span></p></body></html>", nullptr));
        btn_RetirerPub->setText(QCoreApplication::translate("SmartResearch", "Retirer", nullptr));
        lbl_AllRevs->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" color:#ffffff;\">Reviewers disponibles</span></p></body></html>", nullptr));
        btn_AssocierReviewers->setText(QCoreApplication::translate("SmartResearch", "Associer", nullptr));
        lbl_SessRevs->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" color:#ffffff;\">Reviewers associ\303\251s</span></p></body></html>", nullptr));
        btn_RetirerRev->setText(QCoreApplication::translate("SmartResearch", "Retirer", nullptr));
        btn_Enregistrer->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        annuler_2->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_Session_List->setTitle(QString());
        rechercheSession->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Sessions->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SmartResearch", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Sessions->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SmartResearch", "Titre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Sessions->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SmartResearch", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Sessions->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SmartResearch", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Sessions->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SmartResearch", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Sessions->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SmartResearch", "Publications", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Sessions->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("SmartResearch", "Reviewers", nullptr));
        SuppSession->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        expoSession->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        quitterSession->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        groupBox_Session_List_2->setTitle(QString());
        pushButton_supprimer_paiement->setText(QString());
        pushButton_recherche_5->setText(QCoreApplication::translate("SmartResearch", "Rechercher:", nullptr));
        quitterSession_2->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        QRCODE_3->setText(QString());
        qr->setText(QCoreApplication::translate("SmartResearch", "QR CODE", nullptr));
        pb_excel->setText(QCoreApplication::translate("SmartResearch", "EXCEL", nullptr));
        comboBoxPaiement->setItemText(0, QCoreApplication::translate("SmartResearch", "     order croissant", nullptr));
        comboBoxPaiement->setItemText(1, QCoreApplication::translate("SmartResearch", "     order decroissant", nullptr));

        expoSession_2->setText(QCoreApplication::translate("SmartResearch", "Exporter format PDF", nullptr));
        groupBox_Paiement_Form->setTitle(QString());
        label_ID_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Paiement_ID</span></p></body></html>", nullptr));
        label_Nom_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type_frais</span></p></body></html>", nullptr));
        label_Email_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Montant</span></p></body></html>", nullptr));
        label_Mdp_Utilisateur_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Devise</span></p></body></html>", nullptr));
        label_Mot_de_passe_4->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mode Paiement</span></p></body></html>", nullptr));
        label_Role_Utilisateur_5->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Date_Paiement</span></p></body></html>", nullptr));
        radioButton_paye->setText(QCoreApplication::translate("SmartResearch", "Pay\303\251", nullptr));
        radioButton_annule->setText(QCoreApplication::translate("SmartResearch", "Annul\303\251", nullptr));
        radioButton_attente->setText(QCoreApplication::translate("SmartResearch", "En Attente", nullptr));
        btn_Modifier_paiement->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        btn_Enregistrer_paiement->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        btn_Annuler_paiement->setText(QString());
        TableaudeBoard->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#ffffff;\">Tableau de Board</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmartResearch: public Ui_SmartResearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTRESEARCH_H
