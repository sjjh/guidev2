//
//  main.cpp
//  devgui2
//
//  Created by Jens Meder on 27.03.13.
//
//

#include "ClockApp.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    ClockApp a(argc, argv);
    
    a.showMainWindow();
    
    return a.exec();
}
