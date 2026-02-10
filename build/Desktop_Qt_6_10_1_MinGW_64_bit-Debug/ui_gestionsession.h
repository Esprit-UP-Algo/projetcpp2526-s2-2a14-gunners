/********************************************************************************
** Form generated from reading UI file 'gestionsession.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONSESSION_H
#define UI_GESTIONSESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionSession
{
public:
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *idPub;
    QLabel *label_9;
    QLineEdit *Id_utilisateur;
    QLabel *label_3;
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

    void setupUi(QWidget *GestionSession)
    {
        if (GestionSession->objectName().isEmpty())
            GestionSession->setObjectName("GestionSession");
        GestionSession->resize(1221, 621);
        GestionSession->setStyleSheet(QString::fromUtf8("background-color: #D8E2E9;\n"
"QPushButton {\n"
"    background-color: #2c3e50;\n"
"    color: white;\n"
"    border-radius: 15px;\n"
"    border: 1px solid #34495e;\n"
"    padding: 5px 15px;\n"
"}\n"
"QPushButton:hover { background-color: #34495e; }"));
        groupBox_2 = new QGroupBox(GestionSession);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 10, 451, 541));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 36, 168);\n"
"border: #A8D3F0;"));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 50, 411, 261));
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

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        abstractPub = new QLineEdit(formLayoutWidget);
        abstractPub->setObjectName("abstractPub");
        abstractPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, abstractPub);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        conferencePub = new QRadioButton(formLayoutWidget);
        conferencePub->setObjectName("conferencePub");
        conferencePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, conferencePub);

        journalPub = new QRadioButton(formLayoutWidget);
        journalPub->setObjectName("journalPub");
        journalPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, journalPub);


        formLayout->setLayout(4, QFormLayout::ItemRole::FieldRole, formLayout_2);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        mot_clePub = new QLineEdit(formLayoutWidget);
        mot_clePub->setObjectName("mot_clePub");
        mot_clePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, mot_clePub);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_7);

        statutPub = new QLineEdit(formLayoutWidget);
        statutPub->setObjectName("statutPub");
        statutPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, statutPub);

        datePub = new QDateEdit(formLayoutWidget);
        datePub->setObjectName("datePub");
        datePub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, datePub);

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
        groupBox_3 = new QGroupBox(GestionSession);
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
        statPub->setGeometry(QRect(550, 450, 150, 31));
        statPub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        SuppPub = new QPushButton(groupBox_3);
        SuppPub->setObjectName("SuppPub");
        SuppPub->setGeometry(QRect(40, 440, 150, 41));
        SuppPub->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        quitterPub = new QPushButton(groupBox_3);
        quitterPub->setObjectName("quitterPub");
        quitterPub->setGeometry(QRect(480, 490, 150, 31));
        quitterPub->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);\n"
""));
        tableViewPub = new QTableView(groupBox_3);
        tableViewPub->setObjectName("tableViewPub");
        tableViewPub->setGeometry(QRect(10, 80, 691, 341));
        tableViewPub->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        expoPub = new QPushButton(groupBox_3);
        expoPub->setObjectName("expoPub");
        expoPub->setGeometry(QRect(390, 450, 150, 31));
        expoPub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        refreshPub = new QPushButton(groupBox_3);
        refreshPub->setObjectName("refreshPub");
        refreshPub->setGeometry(QRect(449, 40, 111, 31));
        refreshPub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));
        triePub = new QPushButton(groupBox_3);
        triePub->setObjectName("triePub");
        triePub->setGeometry(QRect(569, 40, 121, 31));
        triePub->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);\n"
""));

        retranslateUi(GestionSession);

        QMetaObject::connectSlotsByName(GestionSession);
    } // setupUi

    void retranslateUi(QWidget *GestionSession)
    {
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("GestionSession", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("GestionSession", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Titre:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("GestionSession", "<html><head/><body><p><span style=\" font-weight:700;\">Date:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("GestionSession", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Lieu</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("GestionSession", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Type</span></p></body></html>", nullptr));
        conferencePub->setText(QCoreApplication::translate("GestionSession", "Conf\303\251rence", nullptr));
        journalPub->setText(QCoreApplication::translate("GestionSession", "Journal", nullptr));
        label_6->setText(QCoreApplication::translate("GestionSession", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Liste des publication:</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("GestionSession", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Liste des reviewes:</span></p></body></html>", nullptr));
        enregistrer->setText(QCoreApplication::translate("GestionSession", "Enregistrer", nullptr));
        modif->setText(QCoreApplication::translate("GestionSession", "Modifier", nullptr));
        annuler->setText(QCoreApplication::translate("GestionSession", "Annuler", nullptr));
        groupBox_3->setTitle(QString());
        recherchePub->setText(QCoreApplication::translate("GestionSession", "Recherche", nullptr));
        statPub->setText(QCoreApplication::translate("GestionSession", "Statistique ", nullptr));
        SuppPub->setText(QCoreApplication::translate("GestionSession", "Supprimer", nullptr));
        quitterPub->setText(QCoreApplication::translate("GestionSession", "Quitter", nullptr));
        expoPub->setText(QCoreApplication::translate("GestionSession", "Exportation", nullptr));
        refreshPub->setText(QCoreApplication::translate("GestionSession", "Refresh", nullptr));
        triePub->setText(QCoreApplication::translate("GestionSession", "Trie", nullptr));
        (void)GestionSession;
    } // retranslateUi

};

namespace Ui {
    class GestionSession: public Ui_GestionSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONSESSION_H
