//
//  ClockApp.cpp
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#include "ClockApp.h"

ClockApp::ClockApp(int &argc, char **argv):QApplication(argc, argv)
{
    mainWindow = new MainWindow();
    
    mainWindow->show();
}

ClockApp::~ClockApp()
{
    delete mainWindow;
}