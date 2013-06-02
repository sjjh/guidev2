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
#include "Model/JSONDataSource.h"
#include "IntroViewController.h"
#include "SelectPupilViewController.h"
#include "UndoRedoViewController.h"
#include "MainMenuViewController.h"
#include <QFile>
#include "QuizViewController.h"

ClockApp::ClockApp(int &argc, char **argv):QApplication(argc, argv)
{
    undoRedoWindow = NULL;
    undoRedoViewController = NULL;
    mainWindow = NULL;
    this->dataSource = new JSONDataSource();
    
    mainMenuViewController = new MainMenuViewController(this);
    activeViewController = mainMenuViewController;
    quizViewController = NULL;
}

ClockApp::~ClockApp()
{
    delete mainWindow;
    delete undoRedoViewController;
    delete this->dataSource;
    delete mainMenuViewController;
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
    
    // Show active view controller
    
    mainWindow->centralWidget()->layout()->addWidget(activeViewController->getView());
    
    mainWindow->show();
}

void ClockApp::showUndoRedoPlayGround()
{
   if(!undoRedoViewController)
    {
        undoRedoViewController = new UndoRedoViewController(this);
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

void ClockApp::showQuiz(Quiz quiz)
{
    quizViewController = new QuizViewController(this, quiz);
    activeViewController->getView()->setHidden(true);
    activeViewController = quizViewController;
    mainWindow->centralWidget()->layout()->addWidget(activeViewController->getView());
}

void ClockApp::quitQuiz()
{
    mainMenuViewController->getView()->setHidden(false);
    delete activeViewController->getView();
    delete activeViewController;
    
    activeViewController = mainMenuViewController;
    quizViewController = NULL;
}
