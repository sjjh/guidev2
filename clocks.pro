#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T10:55:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clocks
TEMPLATE = app

INCLUDEPATH = ViewControllers


SOURCES += main.cpp\
        mainwindow.cpp \
    NotificationCenter.cpp \
    ClockApp.cpp \
    Model/Pupil.cpp \
    Model/DataSource.cpp \
    ViewControllers/ViewController.cpp \
    Views/Clocks/Clock.cpp \
    Views/Clocks/AnalogClock.cpp \
    Views/Clocks/FlipClock.cpp \
    UndoRedo/UndoRedoWindow.cpp \
    UndoRedo/UndoRedoViewController.cpp \
    UndoRedo/UndoRedoView.cpp \
    UndoRedo/UndoRedoManager.cpp \
    UndoRedo/Undoable.cpp \
    UndoRedo/Rectangle.cpp \
    UndoRedo/Drawable.cpp

HEADERS  += mainwindow.h \
    NotificationCenter.h \
    ClockApp.h \
    Model/Pupil.h \
    Model/DataSource.h \
    ViewControllers/ViewController.h \
    Views/Clocks/Clock.h \
    Views/Clocks/AnalogClock.h \
    Views/Clocks/FlipClock.h \
    UndoRedo/UndoRedoWindow.h \
    UndoRedo/UndoRedoViewController.h \
    UndoRedo/UndoRedoView.h \
    UndoRedo/UndoRedoManager.h \
    UndoRedo/Undoable.h \
    UndoRedo/Rectangle.h \
    UndoRedo/Drawable.h
