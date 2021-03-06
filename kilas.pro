#-------------------------------------------------
#
# Project created by QtCreator 2014-02-12T14:22:34
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kilas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    club.cpp \
    clubmanager.cpp \
    athlete.cpp \
    testing/test.cpp \
    athletemanager.cpp \
    group.cpp \
    team.cpp \
    meeting.cpp \
    teammanager.cpp

HEADERS  += mainwindow.h \
    club.h \
    globals.h \
    clubmanager.h \
    athlete.h \
    testing/test.h \
    athletemanager.h \
    group.h \
    team.h \
    meeting.h \
    teammanager.h

FORMS    += mainwindow.ui
