#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qmainwindow.h>
#include <qpushbutton.h>
#include "Views/Clocks/AnalogClock.h"
#include "Views/Clocks/FlipClock.h"
#include "Views/Clocks/Clock.h"

namespace Ui {
class MainWindow;
}

/**
 * Represents the main window of the application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    public:
    
        /**
         * Creates a new main window instance.
         */
        MainWindow(QWidget *parent = 0);
    
        Clock* getClock();
    
    private:

        Clock* clock;

};

#endif // MAINWINDOW_H
