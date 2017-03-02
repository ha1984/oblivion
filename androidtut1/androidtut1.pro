#-------------------------------------------------
#
# Project created by QtCreator 2017-02-23T16:18:12
#
#-------------------------------------------------

QT       += core gui \
           multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = androidtut1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    digitalclock.cpp

HEADERS  += mainwindow.h \
    digitalclock.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    resources/plane3.png

RESOURCES += \
    res.qrc

