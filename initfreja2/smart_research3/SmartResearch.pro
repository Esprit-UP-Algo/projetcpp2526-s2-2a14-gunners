QT += core gui widgets sql

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
    session.cpp

HEADERS += \
    connection.h \
    smartresearch.h \
    gestionsession.h \
    publication.h \
    utilisateur.h \
    journal.h \
    session.h

FORMS += \
    smartresearch.ui

RESOURCES += \
    ressources.qrc

UI_DIR = .
