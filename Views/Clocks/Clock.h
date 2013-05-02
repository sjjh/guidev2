/**
 *
 *   Created by Jens Meder on 28.03.13.
 *
 */

#ifndef __guidev2__Clock__
#define __guidev2__Clock__

#include <iostream>
#include <qwidget.h>
#include <ctime>
#include <QTime>

/**
 *  Base class for all clock representations.
 */
class Clock: public QWidget
{
    public:
    
        /**
         * Sets the time of the clock
         */
        void setTime(QTime time);
    
        /**
         * Returns the time of the clock
         */
        QTime getTime();
    
        /**
         * Destroys the Clock object and performs necessary clean up.
         */
        virtual ~Clock();

    protected:
    
        QTime time;
    
        /**
         * Creates a new clock instance.
         */
        Clock();
};

#endif /* defined(__guidev2__Clock__) */
