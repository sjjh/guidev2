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
    NotificationCenter.cpp \
    ClockApp.cpp \
    Model/Pupil.cpp \
    Model/DataSource.cpp \
    ViewControllers/ViewController.cpp \
    Views/Clocks/Clock.cpp \
    Views/Clocks/AnalogClock.cpp

HEADERS  += mainwindow.h \
    NotificationCenter.h \
    ClockApp.h \
    Model/Pupil.h \
    Model/DataSource.h \
    ViewControllers/ViewController.h \
    Views/Clocks/Clock.h \
    Views/Clocks/AnalogClock.h

FORMS    += mainwindow.ui
