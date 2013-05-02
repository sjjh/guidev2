//
//  ClockApp.h
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#ifndef __guidev2__ClockApp__
#define __guidev2__ClockApp__

#include <iostream>
#include <QApplication>
#include "mainwindow.h"

/**
 * Represents the clock application.
 */
class ClockApp: public QApplication
{
    private:
    
        MainWindow* mainWindow;
    
    public:
    
        /**
         * Creates a new ClockApp instance.
         */
        ClockApp(int &argc, char **argv);
    
        /**
         * Destroys the ClockApp object and performs necessary clean up.
         */
        ~ClockApp();
};

#endif /* defined(__guidev2__ClockApp__) */
