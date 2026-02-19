QT += core gui widgets sql

CONFIG += c++11

TEMPLATE = app
TARGET = SmartResearch

SOURCES += \
    connection.cpp \
    main.cpp \
    smartresearch.cpp \
    gestionsession.cpp

HEADERS += \
    connection.h \
    smartresearch.h \
    gestionsession.h

FORMS += \
    smartresearch.ui

RESOURCES += \
    ../ressources.qrc \
    ressources.qrc

UI_DIR = .
