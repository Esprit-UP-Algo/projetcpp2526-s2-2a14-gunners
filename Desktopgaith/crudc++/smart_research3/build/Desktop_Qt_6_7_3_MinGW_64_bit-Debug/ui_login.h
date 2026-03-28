/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_top;
    QHBoxLayout *horizontalLayout_logo;
    QSpacerItem *horizontalSpacer_logo_left;
    QLabel *lblLogo;
    QSpacerItem *horizontalSpacer_logo_right;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_form;
    QLabel *label_username;
    QLineEdit *txtUsername;
    QLabel *label_password;
    QLineEdit *txtPassword;
    QLabel *lblForgotPassword;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_button;
    QSpacerItem *horizontalSpacer_btn_left;
    QPushButton *btnLogin;
    QSpacerItem *horizontalSpacer_btn_right;
    QSpacerItem *verticalSpacer_bottom;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(800, 600);
        Login->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(85, 0, 255);\n"
"	background-color: #E6F4FC; /* Light blue background */\n"
"	font-family: \"Segoe UI\", sans-serif;\n"
"}\n"
"\n"
"QLineEdit {\n"
"	border: 2px solid #A0D0E0;\n"
"	border-radius: 10px;\n"
"	padding: 8px;\n"
"	background-color: white;\n"
"	color: #333;\n"
"	font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"	border: 2px solid #0078D7;\n"
"}\n"
"\n"
"QPushButton#btnLogin {\n"
"	background-color: transparent;\n"
"	border: 2px solid #0078D7;\n"
"	border-radius: 20px;\n"
"	color: #0078D7;\n"
"	font-size: 16px;\n"
"	padding: 10px 40px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#btnLogin:hover {\n"
"	background-color: #0078D7;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton#btnLogin:pressed {\n"
"	background-color: #005a9e;\n"
"	border-color: #005a9e;\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	color: #333;\n"
"    font-size: 14px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_top);

        horizontalLayout_logo = new QHBoxLayout();
        horizontalLayout_logo->setObjectName("horizontalLayout_logo");
        horizontalSpacer_logo_left = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_logo->addItem(horizontalSpacer_logo_left);

        lblLogo = new QLabel(Login);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        lblLogo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_logo->addWidget(lblLogo);

        horizontalSpacer_logo_right = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_logo->addItem(horizontalSpacer_logo_right);


        verticalLayout->addLayout(horizontalLayout_logo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout_form = new QGridLayout();
        gridLayout_form->setObjectName("gridLayout_form");
        gridLayout_form->setHorizontalSpacing(20);
        gridLayout_form->setVerticalSpacing(15);
        gridLayout_form->setContentsMargins(100, -1, 100, -1);
        label_username = new QLabel(Login);
        label_username->setObjectName("label_username");
        label_username->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_form->addWidget(label_username, 0, 0, 1, 1);

        txtUsername = new QLineEdit(Login);
        txtUsername->setObjectName("txtUsername");
        txtUsername->setMinimumSize(QSize(250, 40));

        gridLayout_form->addWidget(txtUsername, 0, 1, 1, 1);

        label_password = new QLabel(Login);
        label_password->setObjectName("label_password");
        label_password->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_form->addWidget(label_password, 1, 0, 1, 1);

        txtPassword = new QLineEdit(Login);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setMinimumSize(QSize(250, 40));
        txtPassword->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_form->addWidget(txtPassword, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_form);

        lblForgotPassword = new QLabel(Login);
        lblForgotPassword->setObjectName("lblForgotPassword");
        lblForgotPassword->setStyleSheet(QString::fromUtf8("color: #555; font-size: 12px; margin-top: 5px;"));
        lblForgotPassword->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lblForgotPassword);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_button = new QHBoxLayout();
        horizontalLayout_button->setObjectName("horizontalLayout_button");
        horizontalSpacer_btn_left = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_button->addItem(horizontalSpacer_btn_left);

        btnLogin = new QPushButton(Login);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_button->addWidget(btnLogin);

        horizontalSpacer_btn_right = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_button->addItem(horizontalSpacer_btn_right);


        verticalLayout->addLayout(horizontalLayout_button);

        verticalSpacer_bottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_bottom);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "SmartResearch - Login", nullptr));
        lblLogo->setText(QString());
        label_username->setText(QCoreApplication::translate("Login", "Nom d'utilisateur", nullptr));
        label_password->setText(QCoreApplication::translate("Login", "Mot de passe", nullptr));
        lblForgotPassword->setText(QCoreApplication::translate("Login", "Mot de passe oubli\303\251 ?", nullptr));
        btnLogin->setText(QCoreApplication::translate("Login", "Entrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
