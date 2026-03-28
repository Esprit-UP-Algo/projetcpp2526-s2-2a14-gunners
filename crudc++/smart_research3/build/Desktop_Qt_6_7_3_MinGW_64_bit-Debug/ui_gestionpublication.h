/********************************************************************************
** Form generated from reading UI file 'gestionpublication.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONPUBLICATION_H
#define UI_GESTIONPUBLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
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

class Ui_GestionPublication
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
    QLabel *label_4;
    QLineEdit *abstractPub;
    QLabel *label_5;
    QFormLayout *formLayout_2;
    QRadioButton *conferencePub;
    QRadioButton *journalPub;
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
    QPushButton *refreshPub;
    QPushButton *triePub;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GestionPublication)
    {
        if (GestionPublication->objectName().isEmpty())
            GestionPublication->setObjectName("GestionPublication");
        GestionPublication->resize(1470, 842);
        GestionPublication->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
        GestionPublication->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        centralwidget = new QWidget(GestionPublication);
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
        GestionPublication->setCentralWidget(centralwidget);
        tabWidget->raise();
        menubar = new QMenuBar(GestionPublication);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1470, 26));
        GestionPublication->setMenuBar(menubar);
        statusbar = new QStatusBar(GestionPublication);
        statusbar->setObjectName("statusbar");
        GestionPublication->setStatusBar(statusbar);

        retranslateUi(GestionPublication);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GestionPublication);
    } // setupUi

    void retranslateUi(QMainWindow *GestionPublication)
    {
        GestionPublication->setWindowTitle(QCoreApplication::translate("GestionPublication", "GestionPublication", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID_Utilisateur</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Titre</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Auteurs</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Abstract</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        conferencePub->setText(QCoreApplication::translate("GestionPublication", "Conf\303\251rence", nullptr));
        journalPub->setText(QCoreApplication::translate("GestionPublication", "Journal", nullptr));
        label_6->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Mots cl\303\251s</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Statut</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("GestionPublication", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Date de soumission</span></p></body></html>", nullptr));
        enregistrer->setText(QCoreApplication::translate("GestionPublication", "Enregistrer", nullptr));
        modif->setText(QCoreApplication::translate("GestionPublication", "Modifier", nullptr));
        annuler->setText(QCoreApplication::translate("GestionPublication", "Annuler", nullptr));
        groupBox_3->setTitle(QString());
        recherchePub->setText(QCoreApplication::translate("GestionPublication", "Recherche", nullptr));
        statPub->setText(QCoreApplication::translate("GestionPublication", "Statistique ", nullptr));
        SuppPub->setText(QCoreApplication::translate("GestionPublication", "Supprimer", nullptr));
        quitterPub->setText(QCoreApplication::translate("GestionPublication", "Quitter", nullptr));
        expoPub->setText(QCoreApplication::translate("GestionPublication", "Exportation", nullptr));
        refreshPub->setText(QCoreApplication::translate("GestionPublication", "Refresh", nullptr));
        triePub->setText(QCoreApplication::translate("GestionPublication", "Trie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("GestionPublication", "Gestion Publication", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionPublication: public Ui_GestionPublication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONPUBLICATION_H
