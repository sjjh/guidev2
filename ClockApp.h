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

class ClockApp: public QApplication
{
    private:
        MainWindow* mainWindow;
    
    public:
        ClockApp(int &argc, char **argv);
        ~ClockApp();
};

#endif /* defined(__guidev2__ClockApp__) */
