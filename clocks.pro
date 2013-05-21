#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T10:55:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clocks
TEMPLATE = app

INCLUDEPATH = ViewControllers \
UndoRedo \
Animations \
Views \
View/Clocks


SOURCES += main.cpp\
        mainwindow.cpp \
    NotificationCenter.cpp \
    ClockApp.cpp \
    Model/Pupil.cpp \
    ViewControllers/ViewController.cpp \
    Views/Clocks/Clock.cpp \
    Views/Clocks/AnalogClock.cpp \
    Views/Clocks/FlipClock.cpp \
    UndoRedo/UndoRedoWindow.cpp \
    UndoRedo/UndoRedoViewController.cpp \
    UndoRedo/UndoRedoManager.cpp \
    UndoRedo/Undoable.cpp \
    UndoRedo/Rectangle.cpp \
    UndoRedo/Drawable.cpp \
    UndoRedo/Circle.cpp \
    UndoRedo/UndoRedoCanvasView.cpp \
    UndoRedo/UndoRedoView.cpp \
    Animations/LinearAnimationCurve.cpp \
    Animations/EaseOutAnimationCurve.cpp \
    Animations/EaseInOutAnimationCurve.cpp \
    Animations/EaseInAnimationCurve.cpp \
    Animations/BasicAnimation.cpp \
    Animations/AnimationCurve.cpp \
    Animations/Animation.cpp \
    ViewControllers/IntroViewController.cpp \
    Views/IntroView.cpp \
    Model/DummyDataSource.cpp \
    ViewControllers/SelectPupilViewController.cpp \
    Views/SelectPupilView.cpp

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
    UndoRedo/UndoRedoManager.h \
    UndoRedo/Undoable.h \
    UndoRedo/Rectangle.h \
    UndoRedo/Drawable.h \
    UndoRedo/Circle.h \
    UndoRedo/UndoRedoCanvasView.h \
    UndoRedo/UndoRedoView.h \
    Animations/LinearAnimationCurve.h \
    Animations/EaseOutAnimationCurve.h \
    Animations/EaseInOutAnimationCurve.h \
    Animations/EaseInAnimationCurve.h \
    Animations/BasicAnimation.h \
    Animations/AnimationCurve.h \
    Animations/Animation.h \
    ViewControllers/IntroViewController.h \
    Views/IntroView.h \
    Model/DummyDataSource.h \
    ViewControllers/SelectPupilViewController.h \
    Views/SelectPupilView.h

RESOURCES += \
    Clocks.qrc
