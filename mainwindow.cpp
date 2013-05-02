#include "mainwindow.h"
#include <qmenu.h>
#include <qmenubar.h>
#include <qaction.h>
#include <qboxlayout.h>

#define WINDOW_TITLE    "Clock"
#define BUTTON_TITLE    "Update time"

#define WINDOW_HEIGHT   200
#define WINDOW_WIDTH    300

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    // Setup window
    
    this->setWindowTitle(WINDOW_TITLE);
    this->setMinimumSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // Create layout and central widget for window
    
    QHBoxLayout* layout = new QHBoxLayout();
    
    QWidget* centralWidget = new QWidget();
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
    
    // Add TestWidget -> draws a red circle *woohoo*
    
    clock = new AnalogClock();
    centralWidget->layout()->addWidget(clock);
}

