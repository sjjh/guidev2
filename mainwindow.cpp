#include "mainwindow.h"
#include <qmenu>
#include <qmenubar>
#include <qaction>
#include <qboxlayout>

#define WINDOW_TITLE    "Clock"
#define BUTTON_TITLE    "Click meeeee"
#define FILE_MENU       "File"
#define RESET_COLOR     "Reset color"

/*
 * Constructor
 */

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    this->setWindowTitle(WINDOW_TITLE);
    this->setMinimumSize(300, 200);
    
    // Create layout and central widget for window
    
    QHBoxLayout* layout = new QHBoxLayout();
    
    QWidget* centralWidget = new QWidget();
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
    
    // Create and add push button
    
    pushButton = new QPushButton();
    pushButton->setText(BUTTON_TITLE);
    
    layout->addWidget(pushButton);
    connect(pushButton, SIGNAL(released()), this, SLOT(handleButton()));
    
    // Add TestWidget -> draws a red circle *woohoo*
    
    clock = new AnalogClock();
    centralWidget->layout()->addWidget(clock);
    
    // Create file menu
    
    QMenu* fileMenu = new QMenu(this);
    QAction* resetColorAction = new QAction(RESET_COLOR,fileMenu);
    connect(resetColorAction, SIGNAL(triggered()), this, SLOT(resetColor()));
    
    fileMenu->setTitle(FILE_MENU);
    fileMenu->addAction(resetColorAction);
    
    // Create menu bar and add file menu
    
    QMenuBar* menuBar = new QMenuBar(this);
    menuBar->setNativeMenuBar(true);
    setMenuBar(menuBar);
    
    menuBar->addMenu(fileMenu);
}

/*
 * Slot for Button release event
 */

void MainWindow::handleButton()
{      
    clock->setTime(QTime::currentTime());
}

/*
 * Slot for Button release event
 */

void MainWindow::resetColor()
{
    // reset background
    
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::transparent);
    centralWidget()->setAutoFillBackground(true);
    centralWidget()->setPalette(Pal);
}


/*
 * Destructor
 */
MainWindow::~MainWindow()
{

}
