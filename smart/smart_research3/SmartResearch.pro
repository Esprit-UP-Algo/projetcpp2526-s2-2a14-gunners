QT += core gui widgets sql

CONFIG += c++11

TEMPLATE = app
TARGET = SmartResearch

SOURCES += \
    main.cpp \
    smartresearch.cpp \
    gestionsession.cpp \
    login.cpp

HEADERS += \
    smartresearch.h \
    gestionsession.h \
    login.h

FORMS += \
    smartresearch.ui \
    login.ui

RESOURCES += \
    ../ressources.qrc \
    ressources.qrc

UI_DIR = .
