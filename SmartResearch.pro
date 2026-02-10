QT += core gui widgets

CONFIG += c++11

TEMPLATE = app
TARGET = SmartResearch

SOURCES += \
    main.cpp \
    smartresearch.cpp \
    gestionsession.cpp

HEADERS += \
    smartresearch.h \
    gestionsession.h

FORMS += \
    smartresearch.ui \
    gestionsession.ui

RESOURCES += \
    ressources.qrc
