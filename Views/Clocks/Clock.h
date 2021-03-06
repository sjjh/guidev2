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
#include "Animation.h"

/**
 *  Base class for all clock representations.
 */
class Clock: public QWidget
{
    Q_OBJECT
    
    Q_PROPERTY(QTime time READ getTime WRITE setTime)
    
    public:
    
        /**
         * Sets the time of the clock
         */
        virtual void setTime(QTime time);
    
        /**
         * Sets the time of the clock with animation
         */
        virtual void setTime(QTime, bool) = 0;
    
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
        virtual void init() = 0;
    
        Animation* animation;
};

#endif /* defined(__guidev2__Clock__) */
