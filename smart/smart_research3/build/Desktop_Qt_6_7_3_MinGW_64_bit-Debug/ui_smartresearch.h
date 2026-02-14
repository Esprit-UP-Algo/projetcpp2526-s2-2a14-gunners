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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QPushButton *GestionSession_2;
    QLabel *label_10;
    QTabWidget *tabWidget;
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
    QTableView *tableView_Utilisateur;
    QPushButton *btn_Supprimer_Utilisateur;
    QPushButton *btn_Exportation_Utilisateur;
    QPushButton *btn_Statistique_Utilisateur;
    QPushButton *btn_Quitter_Utilisateur;
    QComboBox *comboBox;
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
    QComboBox *comboBox_2;
    QWidget *tab_journal;
    QGroupBox *groupBox_Journal_Form;
    QWidget *formLayoutWidget_Journal;
    QFormLayout *formLayout_Journal;
    QLabel *label_Journal_id;
    QLineEdit *id;
    QLabel *label_Journal_nom;
    QLineEdit *nom;
    QLabel *label_Journal_type;
    QLineEdit *type;
    QLabel *label_Journal_domaine;
    QLineEdit *domaine_scientifique;
    QLabel *label_Journal_facteur;
    QLineEdit *facteur_impact;
    QLabel *label_Journal_classement;
    QLineEdit *classement;
    QLabel *label_Journal_pays;
    QLineEdit *pays;
    QLabel *label_Journal_organisation;
    QLineEdit *organisation;
    QLabel *label_Journal_periodicite;
    QLineEdit *periodicite;
    QLabel *label_Journal_siteweb;
    QLineEdit *siteweb;
    QPushButton *enregistrer1;
    QPushButton *modif1;
    QPushButton *annuler1;
    QGroupBox *groupBox_Journal_List;
    QLineEdit *rechPub1;
    QPushButton *recherchePub1;
    QPushButton *statPub1;
    QPushButton *SuppPub1;
    QPushButton *quitterPub1;
    QTableView *tableViewPub1;
    QPushButton *expoPub1;
    QComboBox *comboBox_3;
    QWidget *tab_reviewer;
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
    QGroupBox *groupBox_Reviewer_List;
    QLineEdit *rechercheLineEdit;
    QPushButton *rechercherButton;
    QTableView *tableViewReviewer;
    QPushButton *supprimerReviewerButton;
    QPushButton *assignerPublicationButton;
    QPushButton *rapportButton;
    QComboBox *comboBox_4;
    QWidget *tab_session;
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
    QFormLayout *formLayout_2_Session;
    QRadioButton *conferenceSession;
    QRadioButton *journalSession;
    QLabel *label_S_ListPub;
    QLineEdit *mot_cleSession;
    QLabel *label_S_ListRev;
    QLineEdit *statutSession;
    QDateEdit *dateSession;
    QPushButton *enregistrerSession;
    QPushButton *modifSession;
    QPushButton *annulerSession;
    QGroupBox *groupBox_Session_List;
    QLineEdit *rechSession;
    QPushButton *rechercheSession;
    QPushButton *statSession;
    QPushButton *SuppSession;
    QPushButton *quitterSession;
    QTableView *tableViewSession;
    QPushButton *expoSession;
    QComboBox *comboBox_5;
    QWidget *tab_paiement;
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
    QGroupBox *groupBox_Paiement_List;
    QLineEdit *lineEdit_recherche_paie;
    QPushButton *pushButton_recherche_paie;
    QPushButton *pushButton_pdf_paie;
    QPushButton *pushButton_stat_paie;
    QTableView *tableView_Utilisateur_2;
    QComboBox *comboBox_6;
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
        GestionSession_2 = new QPushButton(groupBox);
        GestionSession_2->setObjectName("GestionSession_2");
        GestionSession_2->setGeometry(QRect(0, 490, 191, 41));
        GestionSession_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
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

        label_Email_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Email_Utilisateur->setObjectName("label_Email_Utilisateur");

        formLayout_Utilisateur->setWidget(2, QFormLayout::LabelRole, label_Email_Utilisateur);

        lineEdit_Email_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Email_Utilisateur->setObjectName("lineEdit_Email_Utilisateur");
        lineEdit_Email_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(2, QFormLayout::FieldRole, lineEdit_Email_Utilisateur);

        label_Mdp_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Mdp_Utilisateur->setObjectName("label_Mdp_Utilisateur");

        formLayout_Utilisateur->setWidget(3, QFormLayout::LabelRole, label_Mdp_Utilisateur);

        lineEdit_Mdp_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Mdp_Utilisateur->setObjectName("lineEdit_Mdp_Utilisateur");
        lineEdit_Mdp_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_Mdp_Utilisateur->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout_Utilisateur->setWidget(3, QFormLayout::FieldRole, lineEdit_Mdp_Utilisateur);

        label_Role_Utilisateur = new QLabel(formLayoutWidget_Utilisateur);
        label_Role_Utilisateur->setObjectName("label_Role_Utilisateur");

        formLayout_Utilisateur->setWidget(4, QFormLayout::LabelRole, label_Role_Utilisateur);

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


        formLayout_Utilisateur->setLayout(4, QFormLayout::FieldRole, horizontalLayout_Role);

        label_Mot_de_passe = new QLabel(formLayoutWidget_Utilisateur);
        label_Mot_de_passe->setObjectName("label_Mot_de_passe");

        formLayout_Utilisateur->setWidget(5, QFormLayout::LabelRole, label_Mot_de_passe);

        lineEdit_Institution_Utilisateur = new QLineEdit(formLayoutWidget_Utilisateur);
        lineEdit_Institution_Utilisateur->setObjectName("lineEdit_Institution_Utilisateur");
        lineEdit_Institution_Utilisateur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Utilisateur->setWidget(5, QFormLayout::FieldRole, lineEdit_Institution_Utilisateur);

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
        comboBox = new QComboBox(groupBox_Utilisateur_List);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(540, 30, 76, 26));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 127));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush6(QColor(127, 127, 127, 127));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        comboBox->setPalette(palette);
        tabWidget->addTab(tab_utilisateur, QString());
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

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        abstractPub = new QLineEdit(formLayoutWidget);
        abstractPub->setObjectName("abstractPub");
        abstractPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout->setWidget(4, QFormLayout::FieldRole, abstractPub);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

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


        formLayout->setLayout(5, QFormLayout::FieldRole, formLayout_2);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        mot_clePub = new QLineEdit(formLayoutWidget);
        mot_clePub->setObjectName("mot_clePub");
        mot_clePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(6, QFormLayout::FieldRole, mot_clePub);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        statutPub = new QLineEdit(formLayoutWidget);
        statutPub->setObjectName("statutPub");
        statutPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(7, QFormLayout::FieldRole, statutPub);

        datePub = new QDateEdit(formLayoutWidget);
        datePub->setObjectName("datePub");
        datePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(8, QFormLayout::FieldRole, datePub);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

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
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(600, 40, 76, 26));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush7(QColor(0, 36, 168, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        comboBox_2->setPalette(palette1);
        tabWidget->addTab(tab, QString());
        tab_journal = new QWidget();
        tab_journal->setObjectName("tab_journal");
        groupBox_Journal_Form = new QGroupBox(tab_journal);
        groupBox_Journal_Form->setObjectName("groupBox_Journal_Form");
        groupBox_Journal_Form->setGeometry(QRect(0, 10, 451, 541));
        groupBox_Journal_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;"));
        formLayoutWidget_Journal = new QWidget(groupBox_Journal_Form);
        formLayoutWidget_Journal->setObjectName("formLayoutWidget_Journal");
        formLayoutWidget_Journal->setGeometry(QRect(20, 40, 411, 331));
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

        type = new QLineEdit(formLayoutWidget_Journal);
        type->setObjectName("type");
        type->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Journal->setWidget(2, QFormLayout::FieldRole, type);

        label_Journal_domaine = new QLabel(formLayoutWidget_Journal);
        label_Journal_domaine->setObjectName("label_Journal_domaine");

        formLayout_Journal->setWidget(3, QFormLayout::LabelRole, label_Journal_domaine);

        domaine_scientifique = new QLineEdit(formLayoutWidget_Journal);
        domaine_scientifique->setObjectName("domaine_scientifique");
        domaine_scientifique->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

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

        classement = new QLineEdit(formLayoutWidget_Journal);
        classement->setObjectName("classement");
        classement->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Journal->setWidget(5, QFormLayout::FieldRole, classement);

        label_Journal_pays = new QLabel(formLayoutWidget_Journal);
        label_Journal_pays->setObjectName("label_Journal_pays");

        formLayout_Journal->setWidget(6, QFormLayout::LabelRole, label_Journal_pays);

        pays = new QLineEdit(formLayoutWidget_Journal);
        pays->setObjectName("pays");
        pays->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

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

        periodicite = new QLineEdit(formLayoutWidget_Journal);
        periodicite->setObjectName("periodicite");
        periodicite->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

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
        enregistrer1->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        modif1 = new QPushButton(groupBox_Journal_Form);
        modif1->setObjectName("modif1");
        modif1->setGeometry(QRect(240, 400, 150, 41));
        modif1->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        annuler1 = new QPushButton(groupBox_Journal_Form);
        annuler1->setObjectName("annuler1");
        annuler1->setGeometry(QRect(150, 460, 150, 41));
        annuler1->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        groupBox_Journal_List = new QGroupBox(tab_journal);
        groupBox_Journal_List->setObjectName("groupBox_Journal_List");
        groupBox_Journal_List->setGeometry(QRect(460, 10, 711, 541));
        groupBox_Journal_List->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
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
        rechPub1 = new QLineEdit(groupBox_Journal_List);
        rechPub1->setObjectName("rechPub1");
        rechPub1->setGeometry(QRect(10, 40, 161, 26));
        rechPub1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        recherchePub1 = new QPushButton(groupBox_Journal_List);
        recherchePub1->setObjectName("recherchePub1");
        recherchePub1->setGeometry(QRect(180, 38, 150, 31));
        recherchePub1->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        statPub1 = new QPushButton(groupBox_Journal_List);
        statPub1->setObjectName("statPub1");
        statPub1->setGeometry(QRect(560, 440, 150, 31));
        statPub1->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        SuppPub1 = new QPushButton(groupBox_Journal_List);
        SuppPub1->setObjectName("SuppPub1");
        SuppPub1->setGeometry(QRect(40, 440, 150, 41));
        SuppPub1->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        quitterPub1 = new QPushButton(groupBox_Journal_List);
        quitterPub1->setObjectName("quitterPub1");
        quitterPub1->setGeometry(QRect(480, 480, 150, 31));
        quitterPub1->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        tableViewPub1 = new QTableView(groupBox_Journal_List);
        tableViewPub1->setObjectName("tableViewPub1");
        tableViewPub1->setGeometry(QRect(10, 80, 691, 341));
        tableViewPub1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        expoPub1 = new QPushButton(groupBox_Journal_List);
        expoPub1->setObjectName("expoPub1");
        expoPub1->setGeometry(QRect(390, 440, 150, 31));
        expoPub1->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        comboBox_3 = new QComboBox(groupBox_Journal_List);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(610, 40, 76, 26));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        comboBox_3->setPalette(palette2);
        tabWidget->addTab(tab_journal, QString());
        tab_reviewer = new QWidget();
        tab_reviewer->setObjectName("tab_reviewer");
        groupBox_Reviewer_Form = new QGroupBox(tab_reviewer);
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
        groupBox_Reviewer_List = new QGroupBox(tab_reviewer);
        groupBox_Reviewer_List->setObjectName("groupBox_Reviewer_List");
        groupBox_Reviewer_List->setGeometry(QRect(460, 10, 711, 541));
        groupBox_Reviewer_List->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
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
        rechercheLineEdit = new QLineEdit(groupBox_Reviewer_List);
        rechercheLineEdit->setObjectName("rechercheLineEdit");
        rechercheLineEdit->setGeometry(QRect(10, 40, 161, 26));
        rechercheLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        rechercherButton = new QPushButton(groupBox_Reviewer_List);
        rechercherButton->setObjectName("rechercherButton");
        rechercherButton->setGeometry(QRect(180, 38, 150, 31));
        rechercherButton->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        tableViewReviewer = new QTableView(groupBox_Reviewer_List);
        tableViewReviewer->setObjectName("tableViewReviewer");
        tableViewReviewer->setGeometry(QRect(10, 80, 691, 341));
        tableViewReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        supprimerReviewerButton = new QPushButton(groupBox_Reviewer_List);
        supprimerReviewerButton->setObjectName("supprimerReviewerButton");
        supprimerReviewerButton->setGeometry(QRect(40, 440, 150, 41));
        supprimerReviewerButton->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        assignerPublicationButton = new QPushButton(groupBox_Reviewer_List);
        assignerPublicationButton->setObjectName("assignerPublicationButton");
        assignerPublicationButton->setGeometry(QRect(210, 450, 150, 31));
        assignerPublicationButton->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        rapportButton = new QPushButton(groupBox_Reviewer_List);
        rapportButton->setObjectName("rapportButton");
        rapportButton->setGeometry(QRect(380, 450, 150, 31));
        rapportButton->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        comboBox_4 = new QComboBox(groupBox_Reviewer_List);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(600, 40, 76, 26));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        comboBox_4->setPalette(palette3);
        tabWidget->addTab(tab_reviewer, QString());
        tab_session = new QWidget();
        tab_session->setObjectName("tab_session");
        groupBox_Session_Form = new QGroupBox(tab_session);
        groupBox_Session_Form->setObjectName("groupBox_Session_Form");
        groupBox_Session_Form->setGeometry(QRect(0, 10, 461, 541));
        groupBox_Session_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;"));
        formLayoutWidget_Session = new QWidget(groupBox_Session_Form);
        formLayoutWidget_Session->setObjectName("formLayoutWidget_Session");
        formLayoutWidget_Session->setGeometry(QRect(20, 50, 411, 261));
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

        formLayout_2_Session = new QFormLayout();
        formLayout_2_Session->setObjectName("formLayout_2_Session");
        conferenceSession = new QRadioButton(formLayoutWidget_Session);
        conferenceSession->setObjectName("conferenceSession");
        conferenceSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout_2_Session->setWidget(0, QFormLayout::LabelRole, conferenceSession);

        journalSession = new QRadioButton(formLayoutWidget_Session);
        journalSession->setObjectName("journalSession");
        journalSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout_2_Session->setWidget(0, QFormLayout::FieldRole, journalSession);


        formLayout_Session->setLayout(4, QFormLayout::FieldRole, formLayout_2_Session);

        label_S_ListPub = new QLabel(formLayoutWidget_Session);
        label_S_ListPub->setObjectName("label_S_ListPub");

        formLayout_Session->setWidget(5, QFormLayout::LabelRole, label_S_ListPub);

        mot_cleSession = new QLineEdit(formLayoutWidget_Session);
        mot_cleSession->setObjectName("mot_cleSession");
        mot_cleSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(5, QFormLayout::FieldRole, mot_cleSession);

        label_S_ListRev = new QLabel(formLayoutWidget_Session);
        label_S_ListRev->setObjectName("label_S_ListRev");

        formLayout_Session->setWidget(6, QFormLayout::LabelRole, label_S_ListRev);

        statutSession = new QLineEdit(formLayoutWidget_Session);
        statutSession->setObjectName("statutSession");
        statutSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(6, QFormLayout::FieldRole, statutSession);

        dateSession = new QDateEdit(formLayoutWidget_Session);
        dateSession->setObjectName("dateSession");
        dateSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_Session->setWidget(2, QFormLayout::FieldRole, dateSession);

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
        groupBox_Session_List = new QGroupBox(tab_session);
        groupBox_Session_List->setObjectName("groupBox_Session_List");
        groupBox_Session_List->setGeometry(QRect(470, 10, 711, 541));
        groupBox_Session_List->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
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
        rechSession = new QLineEdit(groupBox_Session_List);
        rechSession->setObjectName("rechSession");
        rechSession->setGeometry(QRect(10, 40, 161, 26));
        rechSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        rechercheSession = new QPushButton(groupBox_Session_List);
        rechercheSession->setObjectName("rechercheSession");
        rechercheSession->setGeometry(QRect(180, 38, 150, 31));
        rechercheSession->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        statSession = new QPushButton(groupBox_Session_List);
        statSession->setObjectName("statSession");
        statSession->setGeometry(QRect(550, 450, 150, 31));
        statSession->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
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
        tableViewSession = new QTableView(groupBox_Session_List);
        tableViewSession->setObjectName("tableViewSession");
        tableViewSession->setGeometry(QRect(10, 80, 691, 341));
        tableViewSession->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        expoSession = new QPushButton(groupBox_Session_List);
        expoSession->setObjectName("expoSession");
        expoSession->setGeometry(QRect(390, 450, 150, 31));
        expoSession->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        comboBox_5 = new QComboBox(groupBox_Session_List);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(610, 40, 76, 26));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        comboBox_5->setPalette(palette4);
        tabWidget->addTab(tab_session, QString());
        tab_paiement = new QWidget();
        tab_paiement->setObjectName("tab_paiement");
        groupBox_Paiement_Form = new QGroupBox(tab_paiement);
        groupBox_Paiement_Form->setObjectName("groupBox_Paiement_Form");
        groupBox_Paiement_Form->setGeometry(QRect(10, 10, 431, 541));
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
        groupBox_Paiement_List = new QGroupBox(tab_paiement);
        groupBox_Paiement_List->setObjectName("groupBox_Paiement_List");
        groupBox_Paiement_List->setGeometry(QRect(450, 10, 721, 541));
        groupBox_Paiement_List->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168); border: #A8D3F0;\n"
"QGroupBox { border: 2px solid #2c3e50; border-radius: 15px; margin-top: 20px; font-weight: bold; color: #2c3e50; }\n"
"QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 10px; }"));
        lineEdit_recherche_paie = new QLineEdit(groupBox_Paiement_List);
        lineEdit_recherche_paie->setObjectName("lineEdit_recherche_paie");
        lineEdit_recherche_paie->setGeometry(QRect(20, 60, 251, 31));
        lineEdit_recherche_paie->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_recherche_paie = new QPushButton(groupBox_Paiement_List);
        pushButton_recherche_paie->setObjectName("pushButton_recherche_paie");
        pushButton_recherche_paie->setGeometry(QRect(280, 60, 91, 31));
        pushButton_recherche_paie->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        pushButton_pdf_paie = new QPushButton(groupBox_Paiement_List);
        pushButton_pdf_paie->setObjectName("pushButton_pdf_paie");
        pushButton_pdf_paie->setGeometry(QRect(480, 480, 101, 31));
        pushButton_pdf_paie->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        pushButton_stat_paie = new QPushButton(groupBox_Paiement_List);
        pushButton_stat_paie->setObjectName("pushButton_stat_paie");
        pushButton_stat_paie->setGeometry(QRect(590, 480, 101, 31));
        pushButton_stat_paie->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        tableView_Utilisateur_2 = new QTableView(groupBox_Paiement_List);
        tableView_Utilisateur_2->setObjectName("tableView_Utilisateur_2");
        tableView_Utilisateur_2->setGeometry(QRect(20, 100, 691, 341));
        tableView_Utilisateur_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_6 = new QComboBox(groupBox_Paiement_List);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName("comboBox_6");
        comboBox_6->setGeometry(QRect(630, 50, 76, 26));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette5.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        comboBox_6->setPalette(palette5);
        tabWidget->addTab(tab_paiement, QString());
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

        tabWidget->setCurrentIndex(5);


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
        btn_Supprimer_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        btn_Exportation_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        btn_Statistique_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Statistique", nullptr));
        btn_Quitter_Utilisateur->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_utilisateur), QCoreApplication::translate("SmartResearch", "Gestion Utilisateur", nullptr));
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
        comboBox_2->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SmartResearch", "Gestion Publication", nullptr));
        groupBox_Journal_Form->setTitle(QString());
        label_Journal_id->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Id</span></p></body></html>", nullptr));
        label_Journal_nom->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_Journal_type->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        label_Journal_domaine->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Domaine Scientifique</span></p></body></html>", nullptr));
        label_Journal_facteur->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Facteur d'impact</span></p></body></html>", nullptr));
        label_Journal_classement->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Classement</span></p></body></html>", nullptr));
        label_Journal_pays->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Pays</span></p></body></html>", nullptr));
        label_Journal_organisation->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Organisation</span></p></body></html>", nullptr));
        label_Journal_periodicite->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">P\303\251riodicit\303\251</span></p></body></html>", nullptr));
        label_Journal_siteweb->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Site Web</span></p></body></html>", nullptr));
        enregistrer1->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modif1->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annuler1->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_Journal_List->setTitle(QString());
        recherchePub1->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        statPub1->setText(QCoreApplication::translate("SmartResearch", "Statistique ", nullptr));
        SuppPub1->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        quitterPub1->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        expoPub1->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_journal), QCoreApplication::translate("SmartResearch", "Gestion Journal/Conf\303\251rence", nullptr));
        groupBox_Reviewer_Form->setTitle(QString());
        label_Rev_ID->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_Rev_Nom->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_Rev_Email->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Email</span></p></body></html>", nullptr));
        label_Rev_Spec->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Sp\303\251cialit\303\251</span></p></body></html>", nullptr));
        label_Rev_Inst->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Institution</span></p></body></html>", nullptr));
        label_Rev_Statut->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Statut</span></p></body></html>", nullptr));
        actifReviewer->setText(QCoreApplication::translate("SmartResearch", "Actif", nullptr));
        inactifReviewer->setText(QCoreApplication::translate("SmartResearch", "Inactif", nullptr));
        enregistrerReviewer->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modifierReviewer->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annulerReviewer->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_Reviewer_List->setTitle(QString());
        rechercherButton->setText(QCoreApplication::translate("SmartResearch", "Rechercher", nullptr));
        supprimerReviewerButton->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        assignerPublicationButton->setText(QCoreApplication::translate("SmartResearch", "Assigner", nullptr));
        rapportButton->setText(QCoreApplication::translate("SmartResearch", "Statistique", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_reviewer), QCoreApplication::translate("SmartResearch", "Gestion Reviewer", nullptr));
        groupBox_Session_Form->setTitle(QString());
        label_S_ID->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_S_Titre->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Titre:</span></p></body></html>", nullptr));
        label_S_Date->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-weight:700;\">Date:</span></p></body></html>", nullptr));
        label_S_Lieu->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Lieu</span></p></body></html>", nullptr));
        label_S_Type->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        conferenceSession->setText(QCoreApplication::translate("SmartResearch", "Conf\303\251rence", nullptr));
        journalSession->setText(QCoreApplication::translate("SmartResearch", "Journal", nullptr));
        label_S_ListPub->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Liste des publication:</span></p></body></html>", nullptr));
        label_S_ListRev->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Liste des reviewes:</span></p></body></html>", nullptr));
        enregistrerSession->setText(QCoreApplication::translate("SmartResearch", "Enregistrer", nullptr));
        modifSession->setText(QCoreApplication::translate("SmartResearch", "Modifier", nullptr));
        annulerSession->setText(QCoreApplication::translate("SmartResearch", "Annuler", nullptr));
        groupBox_Session_List->setTitle(QString());
        rechercheSession->setText(QCoreApplication::translate("SmartResearch", "Recherche", nullptr));
        statSession->setText(QCoreApplication::translate("SmartResearch", "Statistique ", nullptr));
        SuppSession->setText(QCoreApplication::translate("SmartResearch", "Supprimer", nullptr));
        quitterSession->setText(QCoreApplication::translate("SmartResearch", "Quitter", nullptr));
        expoSession->setText(QCoreApplication::translate("SmartResearch", "Exportation", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_session), QCoreApplication::translate("SmartResearch", "Gestion Session", nullptr));
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
        groupBox_Paiement_List->setTitle(QString());
        lineEdit_recherche_paie->setPlaceholderText(QCoreApplication::translate("SmartResearch", "Rechercher...", nullptr));
        pushButton_recherche_paie->setText(QCoreApplication::translate("SmartResearch", "Rechercher", nullptr));
        pushButton_pdf_paie->setText(QCoreApplication::translate("SmartResearch", "PDF", nullptr));
        pushButton_stat_paie->setText(QCoreApplication::translate("SmartResearch", "Statistiques", nullptr));
        comboBox_6->setItemText(0, QCoreApplication::translate("SmartResearch", "order croissant", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("SmartResearch", "order decroissant", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_paiement), QCoreApplication::translate("SmartResearch", "Gestion Paiement", nullptr));
        TableaudeBoard->setText(QCoreApplication::translate("SmartResearch", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#ffffff;\">Tableau de Board</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmartResearch: public Ui_SmartResearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTRESEARCH_H
