//
//  main.cpp
//  devgui2
//
//  Created by Jens Meder on 27.03.13.
//
//

#include <QtWidgets/qapplication.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
