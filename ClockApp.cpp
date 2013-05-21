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
#include "Model/DataSource.h"
#include "Model/DummyDataSource.h"

ClockApp::ClockApp(int &argc, char **argv):QApplication(argc, argv)
{
    undoRedoWindow = NULL;
    undoRedoViewController = NULL;
    mainWindow = NULL;
    this->dataSource = new DummyDataSource();
}

ClockApp::~ClockApp()
{
    delete mainWindow;
    delete undoRedoViewController;
    delete this->dataSource;
    delete introViewController;
}

void ClockApp::showMainWindow()
{
    mainWindow = new MainWindow();
    
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
    
    // Setup first view controller
    
    introViewController = new IntroViewController();
    
    mainWindow->centralWidget()->layout()->addWidget(introViewController->getView());
    
    mainWindow->show();
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


DataSource* ClockApp::getDataSource()
{
    return this->dataSource;
}
