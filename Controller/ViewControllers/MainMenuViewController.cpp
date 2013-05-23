//
//  MainMenuViewController.cpp
//  guidev2
//
//  Created by Jens Meder on 21.05.13.
//
//

#include "MainMenuViewController.h"
#include "IntroViewController.h"
#include "SelectPupilViewController.h"
#include "MainMenuView.h"

MainMenuViewController::MainMenuViewController(ClockApp* app):ViewController(app)
{
    introViewController = new IntroViewController(app);
    selectPupilViewController = new SelectPupilViewController(app);
    
    MainMenuView* mainMenuView = new MainMenuView();
    
    mainMenuView->getTabs()->addTab(introViewController->getView(), "Learn");
    mainMenuView->getTabs()->addTab(selectPupilViewController->getView(), "Exercise");
    
    view = mainMenuView;
}

MainMenuViewController::~MainMenuViewController()
{
    delete introViewController;
    delete selectPupilViewController;
}
