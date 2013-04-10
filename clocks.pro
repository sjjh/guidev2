#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T10:55:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clocks
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Clocks/Clock.cpp \
    Clocks/AnalogClock.cpp

HEADERS  += mainwindow.h \
    Clocks/Clock.h \
    Clocks/AnalogClock.h

FORMS    += mainwindow.ui
