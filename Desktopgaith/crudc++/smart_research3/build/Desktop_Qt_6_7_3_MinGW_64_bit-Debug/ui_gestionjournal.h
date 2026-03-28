/********************************************************************************
** Form generated from reading UI file 'gestionjournal.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONJOURNAL_H
#define UI_GESTIONJOURNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionJournal
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *id;
    QLabel *label_nom;
    QLineEdit *nom;
    QLabel *label_type;
    QLineEdit *type;
    QLabel *label_domaine;
    QLineEdit *domaine_scientifique;
    QLabel *label_facteur;
    QLineEdit *facteur_impact;
    QLabel *label_classement;
    QLineEdit *classement;
    QLabel *label_pays;
    QLineEdit *pays;
    QLabel *label_organisation;
    QLineEdit *organisation;
    QLabel *label_periodicite;
    QLineEdit *periodicite;
    QLabel *label_siteweb;
    QLineEdit *siteweb;
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
    QPushButton *refreshPub;
    QPushButton *triePub;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QWidget *GestionJournal)
    {
        if (GestionJournal->objectName().isEmpty())
            GestionJournal->setObjectName("GestionJournal");
        GestionJournal->resize(1470, 842);
        GestionJournal->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
        GestionJournal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        centralwidget = new QWidget(GestionJournal);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1221, 621));
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
        tabWidget->setGeometry(QRect(10, 40, 1211, 601));
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
        label_id = new QLabel(formLayoutWidget);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_id);

        id = new QLineEdit(formLayoutWidget);
        id->setObjectName("id");
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, id);

        label_nom = new QLabel(formLayoutWidget);
        label_nom->setObjectName("label_nom");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_nom);

        nom = new QLineEdit(formLayoutWidget);
        nom->setObjectName("nom");
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nom);

        label_type = new QLabel(formLayoutWidget);
        label_type->setObjectName("label_type");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_type);

        type = new QLineEdit(formLayoutWidget);
        type->setObjectName("type");
        type->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, type);

        label_domaine = new QLabel(formLayoutWidget);
        label_domaine->setObjectName("label_domaine");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_domaine);

        domaine_scientifique = new QLineEdit(formLayoutWidget);
        domaine_scientifique->setObjectName("domaine_scientifique");
        domaine_scientifique->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, domaine_scientifique);

        label_facteur = new QLabel(formLayoutWidget);
        label_facteur->setObjectName("label_facteur");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_facteur);

        facteur_impact = new QLineEdit(formLayoutWidget);
        facteur_impact->setObjectName("facteur_impact");
        facteur_impact->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(4, QFormLayout::FieldRole, facteur_impact);

        label_classement = new QLabel(formLayoutWidget);
        label_classement->setObjectName("label_classement");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_classement);

        classement = new QLineEdit(formLayoutWidget);
        classement->setObjectName("classement");
        classement->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(5, QFormLayout::FieldRole, classement);

        label_pays = new QLabel(formLayoutWidget);
        label_pays->setObjectName("label_pays");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_pays);

        pays = new QLineEdit(formLayoutWidget);
        pays->setObjectName("pays");
        pays->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(6, QFormLayout::FieldRole, pays);

        label_organisation = new QLabel(formLayoutWidget);
        label_organisation->setObjectName("label_organisation");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_organisation);

        organisation = new QLineEdit(formLayoutWidget);
        organisation->setObjectName("organisation");
        organisation->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(7, QFormLayout::FieldRole, organisation);

        label_periodicite = new QLabel(formLayoutWidget);
        label_periodicite->setObjectName("label_periodicite");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_periodicite);

        periodicite = new QLineEdit(formLayoutWidget);
        periodicite->setObjectName("periodicite");
        periodicite->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(8, QFormLayout::FieldRole, periodicite);

        label_siteweb = new QLabel(formLayoutWidget);
        label_siteweb->setObjectName("label_siteweb");

        formLayout->setWidget(9, QFormLayout::LabelRole, label_siteweb);

        siteweb = new QLineEdit(formLayoutWidget);
        siteweb->setObjectName("siteweb");
        siteweb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(9, QFormLayout::FieldRole, siteweb);

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
        refreshPub = new QPushButton(groupBox_3);
        refreshPub->setObjectName("refreshPub");
        refreshPub->setGeometry(QRect(400, 40, 150, 31));
        refreshPub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        triePub = new QPushButton(groupBox_3);
        triePub->setObjectName("triePub");
        triePub->setGeometry(QRect(560, 40, 150, 31));
        triePub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        tabWidget->addTab(tab, QString());
        menubar = new QMenuBar(GestionJournal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1470, 26));
        statusbar = new QStatusBar(GestionJournal);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 25));

        retranslateUi(GestionJournal);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GestionJournal);
    } // setupUi

    void retranslateUi(QWidget *GestionJournal)
    {
        GestionJournal->setWindowTitle(QCoreApplication::translate("GestionJournal", "Gestion Conf\303\251rence ou Journal", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("GestionJournal", "Ajout une conf\303\251rence ou journal", nullptr));
        label_id->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Id</span></p></body></html>", nullptr));
        label_nom->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_type->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        label_domaine->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Domaine Scientifique</span></p></body></html>", nullptr));
        label_facteur->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Facteur d'impact</span></p></body></html>", nullptr));
        label_classement->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Classement</span></p></body></html>", nullptr));
        label_pays->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Pays</span></p></body></html>", nullptr));
        label_organisation->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Organisation</span></p></body></html>", nullptr));
        label_periodicite->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">P\303\251riodicit\303\251</span></p></body></html>", nullptr));
        label_siteweb->setText(QCoreApplication::translate("GestionJournal", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Site Web</span></p></body></html>", nullptr));
        enregistrer->setText(QCoreApplication::translate("GestionJournal", "Enregistrer", nullptr));
        modif->setText(QCoreApplication::translate("GestionJournal", "Modifier", nullptr));
        annuler->setText(QCoreApplication::translate("GestionJournal", "Annuler", nullptr));
        groupBox_3->setTitle(QString());
        recherchePub->setText(QCoreApplication::translate("GestionJournal", "Recherche", nullptr));
        statPub->setText(QCoreApplication::translate("GestionJournal", "Statistique ", nullptr));
        SuppPub->setText(QCoreApplication::translate("GestionJournal", "Supprimer", nullptr));
        quitterPub->setText(QCoreApplication::translate("GestionJournal", "Quitter", nullptr));
        expoPub->setText(QCoreApplication::translate("GestionJournal", "Exportation", nullptr));
        refreshPub->setText(QCoreApplication::translate("GestionJournal", "Refresh", nullptr));
        triePub->setText(QCoreApplication::translate("GestionJournal", "Trie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("GestionJournal", "Gestion Conf\303\251rence ou Journal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionJournal: public Ui_GestionJournal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONJOURNAL_H
