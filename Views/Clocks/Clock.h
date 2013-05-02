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

        /**
         * Creates a new clock instance with the given time
         */
        Clock(QTime time);

        /**
         * initiate a Clock (Colors, ... and all stuff happening in a Constructor)
         * This method needs to be overwritten in subclasses.
         */
        virtual void init();
};

#endif /* defined(__guidev2__Clock__) */
