#include "mainwindow.h"
#include <qmenu.h>
#include <qmenubar.h>
#include <qaction.h>
#include <qboxlayout.h>
#include "BasicAnimation.h"
#include <QString>
#include "LinearAnimationCurve.h"
#include "IntroViewController.h"

#define WINDOW_TITLE    "Clock"

#define WINDOW_HEIGHT   300
#define WINDOW_WIDTH    800

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    // Setup window
    
    this->setWindowTitle(WINDOW_TITLE);
    this->setMinimumSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // Create layout and central widget for window
    
    QVBoxLayout* layout = new QVBoxLayout();
    
    QWidget* centralWidget = new QWidget();
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
    
    // Add TestWidget -> draws a red circle *woohoo*
    
//    clock = new AnalogClock(QTime(12,15));

    QTime t = QTime::currentTime();
    t.setHMS(t.hour() - 3,3, 0);

    analog = new AnalogClock();
    centralWidget->layout()->addWidget(analog);
    
    digital = new FlipClock();

    centralWidget->layout()->addWidget(digital);
    
    connect(analog, SIGNAL(timeChanged(Clock*)), this, SLOT(timeChanged(Clock*)));
    connect(digital, SIGNAL(timeChanged(Clock*)),this, SLOT(timeChanged(Clock*)));

    centralWidget->layout()->addWidget((new IntroViewController())->getView());
}

void MainWindow::timeChanged(Clock * c)
{
    if(c == analog)
    {
        digital->setTime(analog->getTime());
    }
    else
    {
        analog->setTime(digital->getTime());
    }
}

