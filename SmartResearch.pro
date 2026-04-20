QT += core gui widgets sql network charts
QT += printsupport
QT += svg
CONFIG += c++11

TEMPLATE = app
TARGET = SmartResearch

SOURCES += \
    connection.cpp \
    excel.cpp \
    exportexcel.cpp \
    main.cpp \
    paiement.cpp \
    qrcode.cpp \
    qrcodegeneratordem.cpp \
    qrcodegeneratorworker.cpp \
    qrwidget.cpp \
    smartresearch.cpp \
    gestionsession.cpp \
    publication.cpp \
    utilisateur.cpp \
    journal.cpp \
    session.cpp \
    smtp.cpp \
    login.cpp \
    reviewer.cpp \
    gestionreviewer.cpp \
    smsservice.cpp \
    chatbot.cpp \
    mapdialog.cpp

HEADERS += \
    connection.h \
    excel.h \
    exportexcel.h \
    paiement.h \
    qrcode.h \
    qrwidget.h \
    smartresearch.h \
    gestionsession.h \
    publication.h \
    utilisateur.h \
    journal.h \
    session.h \
    smtp.h \
    login.h \
    reviewer.h \
    gestionreviewer.h \
    smsservice.h \
    chatbot.h \
    mapdialog.h

FORMS += \
    smartresearch.ui \
    login.ui

RESOURCES += \
    ressources.qrc

UI_DIR = .
