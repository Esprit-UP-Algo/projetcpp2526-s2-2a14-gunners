QT += core gui widgets sql

CONFIG += c++11

TEMPLATE = app
TARGET = SmartResearch

SOURCES += \
    main.cpp \
    smartresearch.cpp \
    gestionsession.cpp \
    gestionreviewer.cpp      # RETIREZ gestionreviewer_main.cpp

HEADERS += \
    smartresearch.h \
    gestionsession.h \
    gestionreviewer.h

FORMS += \
    smartresearch.ui \
    gestionsession.ui \
    gestionreviewer.ui

RESOURCES += \
    ressources.qrc
