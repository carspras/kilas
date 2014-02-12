#-------------------------------------------------
#
# Project created by QtCreator 2014-02-12T14:22:34
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -std=c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kilas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    club.cpp \
    clubmanager.cpp

HEADERS  += mainwindow.h \
    club.h \
    globals.h \
    clubmanager.h

FORMS    += mainwindow.ui
