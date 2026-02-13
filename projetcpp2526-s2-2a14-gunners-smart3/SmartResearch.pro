QT += core gui widgets sql

CONFIG += c++11

TEMPLATE = app
TARGET = SmartResearch

SOURCES += \
    main.cpp \
    smartresearch.cpp \
    gestionsession.cpp \
    gestionreviewer.cpp \
    GestionJournal/gestionjournal.cpp \
    GestionPublication/gestionpublication.cpp

HEADERS += \
    smartresearch.h \
    gestionsession.h \
    gestionreviewer.h \
    GestionJournal/gestionjournal.h \
    GestionPublication/gestionpublication.h

FORMS += \
    smartresearch.ui \
    gestionsession.ui \
    gestionreviewer.ui \
    GestionJournal/gestionjournal.ui \
    GestionPublication/gestionpublication.ui

RESOURCES += \
    ressources.qrc

INCLUDEPATH += GestionJournal GestionPublication
