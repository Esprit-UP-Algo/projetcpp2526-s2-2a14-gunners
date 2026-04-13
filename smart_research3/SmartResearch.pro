QT += core gui widgets sql network

CONFIG += c++11

TEMPLATE = app
TARGET = SmartResearch

SOURCES += \
    connection.cpp \
    main.cpp \
    smartresearch.cpp \
    gestionsession.cpp \
    publication.cpp \
    utilisateur.cpp \
    journal.cpp \
    session.cpp \
    smtp.cpp \
    login.cpp

HEADERS += \
    connection.h \
    smartresearch.h \
    gestionsession.h \
    publication.h \
    utilisateur.h \
    journal.h \
    session.h \
    smtp.h \
    login.h

FORMS += \
    smartresearch.ui \
    login.ui

RESOURCES += \
    ressources.qrc

UI_DIR = .
