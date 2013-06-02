#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T10:55:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clocks
TEMPLATE = app

INCLUDEPATH = Controller/ViewControllers \
Model \
Controller/ViewControllers/DataModel \
Controller \
UndoRedo \
Animations \
Views \
Views/Clocks


SOURCES += main.cpp\
        mainwindow.cpp \
    NotificationCenter.cpp \
    ClockApp.cpp \
    Model/Pupil.cpp \
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
    Views/IntroView.cpp \
    Model/DummyDataSource.cpp \
    Views/SelectPupilView.cpp \
    Views/MainMenuView.cpp \
    Model/JSONDataSource.cpp \
    Model/DataSource.cpp \
    Controller/QuizQuestion.cpp \
    Controller/QuizGenerator.cpp \
    Controller/Quiz.cpp \
    Controller/ViewControllers/ViewController.cpp \
    Controller/ViewControllers/SelectPupilViewController.cpp \
    Controller/ViewControllers/MainMenuViewController.cpp \
    Controller/ViewControllers/IntroViewController.cpp \
    Controller/ViewControllers/DataModel/PupilListModel.cpp \
    Controller/AdjustQuizQuestion.cpp \
    Views/QuizView.cpp \
    Controller/ViewControllers/QuizViewController.cpp

HEADERS  += mainwindow.h \
    NotificationCenter.h \
    ClockApp.h \
    Model/Pupil.h \
    Model/DataSource.h \
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
    Views/IntroView.h \
    Model/DummyDataSource.h \
    Views/SelectPupilView.h \
    Views/MainMenuView.h \
    Model/JSONDataSource.h \
    Controller/QuizQuestion.h \
    Controller/QuizGenerator.h \
    Controller/Quiz.h \
    Controller/ViewControllers/DataModel/PupilListModel.h \
    Controller/ViewControllers/ViewController.h \
    Controller/ViewControllers/SelectPupilViewController.h \
    Controller/ViewControllers/MainMenuViewController.h \
    Controller/ViewControllers/IntroViewController.h \
    Controller/AdjustQuizQuestion.h \
    Views/QuizView.h \
    Controller/ViewControllers/QuizViewController.h

RESOURCES += \
    Clocks.qrc
