//
//  ClockApp.cpp
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#include "ClockApp.h"
#include <QMenuBar>
#include <QAction>
#include <QLayout>
#include <QRect>
#include "BasicAnimation.h"

ClockApp::ClockApp(int &argc, char **argv):QApplication(argc, argv)
{
    undoRedoWindow = NULL;
    undoRedoViewController = NULL;
    mainWindow = NULL;
}

ClockApp::~ClockApp()
{
    delete mainWindow;
    delete undoRedoViewController;
}

void ClockApp::showMainWindow()
{
    mainWindow = new MainWindow();
    mainWindow->show();
    
    // Setup main window menu bar
    
    QMenuBar* menuBar = new QMenuBar();
    
    QMenu* fileMenu = new QMenu("File");
    menuBar->addMenu(fileMenu);
    
    QMenu* helpMenu = new QMenu("Help");
    
    showUndoRedoPlaygroundAction = new QAction("Show undo redo playground",helpMenu);
    connect(showUndoRedoPlaygroundAction, SIGNAL(triggered()), this, SLOT(showUndoRedoPlayGround()));
    
    helpMenu->addAction(showUndoRedoPlaygroundAction);    
    
    menuBar->addMenu(helpMenu);
    
    mainWindow->setMenuBar(menuBar);
}

void ClockApp::showUndoRedoPlayGround()
{
   if(!undoRedoViewController)
    {
        undoRedoViewController = new UndoRedoViewController();
    }
    
    if(!undoRedoWindow)
    {
        undoRedoWindow = new UndoRedoWindow(mainWindow);
        undoRedoWindow->layout()->addWidget(undoRedoViewController->getView());
    }    
    
    undoRedoWindow->setVisible(true);
}
