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
    utilisateur.cpp

HEADERS += \
    connection.h \
    smartresearch.h \
    gestionsession.h \
    publication.h \
    utilisateur.h

FORMS += \
    smartresearch.ui

RESOURCES += \
    ../ressources.qrc \
    ressources.qrc

UI_DIR = .
