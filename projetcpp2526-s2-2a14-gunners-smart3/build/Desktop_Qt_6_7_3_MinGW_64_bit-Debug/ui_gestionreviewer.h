/********************************************************************************
** Form generated from reading UI file 'gestionreviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONREVIEWER_H
#define UI_GESTIONREVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_GestionReviewer
{
public:
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *idReviewer;
    QLabel *label_2;
    QLineEdit *nomReviewer;
    QLabel *label_3;
    QLineEdit *emailReviewer;
    QLabel *label_4;
    QLineEdit *specialiteReviewer;
    QLabel *label_5;
    QLineEdit *institutionReviewer;
    QLabel *label_6;
    QFormLayout *formLayout_2;
    QRadioButton *actifReviewer;
    QRadioButton *inactifReviewer;
    QPushButton *enregistrerReviewer;
    QPushButton *modifierReviewer;
    QPushButton *annulerReviewer;
    QGroupBox *groupBox_3;
    QLineEdit *rechercheLineEdit;
    QPushButton *rechercherButton;
    QPushButton *refreshButton_2;
    QPushButton *trieButton;
    QTableView *tableViewReviewer;
    QPushButton *supprimerReviewerButton;
    QPushButton *assignerPublicationButton;
    QPushButton *rapportButton;

    void setupUi(QWidget *GestionReviewer)
    {
        if (GestionReviewer->objectName().isEmpty())
            GestionReviewer->setObjectName("GestionReviewer");
        GestionReviewer->resize(1221, 621);
        GestionReviewer->setStyleSheet(QString::fromUtf8("background-color: #D8E2E9;\n"
"QPushButton {\n"
"    background-color: #2c3e50;\n"
"    color: white;\n"
"    border-radius: 15px;\n"
"    border: 1px solid #34495e;\n"
"    padding: 5px 15px;\n"
"}\n"
"QPushButton:hover { background-color: #34495e; }"));
        groupBox_2 = new QGroupBox(GestionReviewer);
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

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        idReviewer = new QLineEdit(formLayoutWidget);
        idReviewer->setObjectName("idReviewer");
        idReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, idReviewer);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        nomReviewer = new QLineEdit(formLayoutWidget);
        nomReviewer->setObjectName("nomReviewer");
        nomReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nomReviewer);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        emailReviewer = new QLineEdit(formLayoutWidget);
        emailReviewer->setObjectName("emailReviewer");
        emailReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, emailReviewer);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        specialiteReviewer = new QLineEdit(formLayoutWidget);
        specialiteReviewer->setObjectName("specialiteReviewer");
        specialiteReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, specialiteReviewer);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        institutionReviewer = new QLineEdit(formLayoutWidget);
        institutionReviewer->setObjectName("institutionReviewer");
        institutionReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(4, QFormLayout::FieldRole, institutionReviewer);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        actifReviewer = new QRadioButton(formLayoutWidget);
        actifReviewer->setObjectName("actifReviewer");
        actifReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, actifReviewer);

        inactifReviewer = new QRadioButton(formLayoutWidget);
        inactifReviewer->setObjectName("inactifReviewer");
        inactifReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, inactifReviewer);


        formLayout->setLayout(5, QFormLayout::FieldRole, formLayout_2);

        enregistrerReviewer = new QPushButton(groupBox_2);
        enregistrerReviewer->setObjectName("enregistrerReviewer");
        enregistrerReviewer->setGeometry(QRect(40, 400, 150, 41));
        enregistrerReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        modifierReviewer = new QPushButton(groupBox_2);
        modifierReviewer->setObjectName("modifierReviewer");
        modifierReviewer->setGeometry(QRect(240, 400, 150, 41));
        modifierReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        annulerReviewer = new QPushButton(groupBox_2);
        annulerReviewer->setObjectName("annulerReviewer");
        annulerReviewer->setGeometry(QRect(150, 460, 150, 41));
        annulerReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        groupBox_3 = new QGroupBox(GestionReviewer);
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
        rechercheLineEdit = new QLineEdit(groupBox_3);
        rechercheLineEdit->setObjectName("rechercheLineEdit");
        rechercheLineEdit->setGeometry(QRect(10, 40, 161, 26));
        rechercheLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        rechercherButton = new QPushButton(groupBox_3);
        rechercherButton->setObjectName("rechercherButton");
        rechercherButton->setGeometry(QRect(180, 38, 150, 31));
        rechercherButton->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        refreshButton_2 = new QPushButton(groupBox_3);
        refreshButton_2->setObjectName("refreshButton_2");
        refreshButton_2->setGeometry(QRect(449, 40, 111, 31));
        refreshButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        trieButton = new QPushButton(groupBox_3);
        trieButton->setObjectName("trieButton");
        trieButton->setGeometry(QRect(569, 40, 121, 31));
        trieButton->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        tableViewReviewer = new QTableView(groupBox_3);
        tableViewReviewer->setObjectName("tableViewReviewer");
        tableViewReviewer->setGeometry(QRect(10, 80, 691, 341));
        tableViewReviewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        supprimerReviewerButton = new QPushButton(groupBox_3);
        supprimerReviewerButton->setObjectName("supprimerReviewerButton");
        supprimerReviewerButton->setGeometry(QRect(40, 440, 150, 41));
        supprimerReviewerButton->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 14, 0);"));
        assignerPublicationButton = new QPushButton(groupBox_3);
        assignerPublicationButton->setObjectName("assignerPublicationButton");
        assignerPublicationButton->setGeometry(QRect(210, 450, 150, 31));
        assignerPublicationButton->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));
        rapportButton = new QPushButton(groupBox_3);
        rapportButton->setObjectName("rapportButton");
        rapportButton->setGeometry(QRect(380, 450, 150, 31));
        rapportButton->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 151, 255);"));

        retranslateUi(GestionReviewer);

        QMetaObject::connectSlotsByName(GestionReviewer);
    } // setupUi

    void retranslateUi(QWidget *GestionReviewer)
    {
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("GestionReviewer", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">ID</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("GestionReviewer", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Nom</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("GestionReviewer", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Email</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("GestionReviewer", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Sp\303\251cialit\303\251</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("GestionReviewer", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Institution</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("GestionReviewer", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">Statut</span></p></body></html>", nullptr));
        actifReviewer->setText(QCoreApplication::translate("GestionReviewer", "Actif", nullptr));
        inactifReviewer->setText(QCoreApplication::translate("GestionReviewer", "Inactif", nullptr));
        enregistrerReviewer->setText(QCoreApplication::translate("GestionReviewer", "Enregistrer", nullptr));
        modifierReviewer->setText(QCoreApplication::translate("GestionReviewer", "Modifier", nullptr));
        annulerReviewer->setText(QCoreApplication::translate("GestionReviewer", "Annuler", nullptr));
        groupBox_3->setTitle(QString());
        rechercherButton->setText(QCoreApplication::translate("GestionReviewer", "Rechercher", nullptr));
        refreshButton_2->setText(QCoreApplication::translate("GestionReviewer", "Refresh", nullptr));
        trieButton->setText(QCoreApplication::translate("GestionReviewer", "Trier", nullptr));
        supprimerReviewerButton->setText(QCoreApplication::translate("GestionReviewer", "Supprimer", nullptr));
        assignerPublicationButton->setText(QCoreApplication::translate("GestionReviewer", "Assigner", nullptr));
        rapportButton->setText(QCoreApplication::translate("GestionReviewer", "Statistique", nullptr));
        (void)GestionReviewer;
    } // retranslateUi

};

namespace Ui {
    class GestionReviewer: public Ui_GestionReviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONREVIEWER_H
