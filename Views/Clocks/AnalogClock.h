/**
*
*   Created by Jens Meder on 28.03.13.
*
*/

#ifndef __guidev2__AnalogClock__
#define __guidev2__AnalogClock__

#include "Clock.h"
#include <iostream>
#include <QPen>

/**
 *  Represents an analog clock with a minute and an hour arm. The visual appearance of the clock can be customized.
 */
class AnalogClock: public Clock
{
    public:
    
        /**
         * Creates a new AnalogClock instance.
         */
        AnalogClock();
    
        /**
         * Destroys the AnalogClock object and performs necessary clean up.
         */
        ~AnalogClock();
    
        /**
         * Sets the brush used to draw the hour arm.
         */
        void setHourArmBrush(QBrush brush);
    
        /**
         * Returns the brush used to draw the hour arm.
         */
        QBrush getHourArmBrush();
    
        /**
         * Sets the brush used to draw the minute arm.
         */
        void setMinuteArmBrush(QBrush brush);
    
        /**
         * Returns the brush used to draw the minute arm.
         */
        QBrush getMinuteArmBrush();
    
        /**
         * Sets the brush used to draw the hour ticks.
         */
        void setHourTickBrush(QBrush brush);
    
        /**
         * Returns the brush used to draw hour ticks.
         */
        QBrush getHourTickBrush();
    
        /**
         * Sets the brush used to draw the minute ticks.
         */
        void setMinuteTickBrush(QBrush brush);
    
        /**
         * Returns the brush used to draw the minute ticks.
         */
        QBrush getMinuteTickBrush();
    
        /**
         * Sets the pen used to draw the hour labels.
         */
        void setLabelPen(QPen pen);
    
        /**
         * Returns the pen used to draw hour labels.
         */
        QPen getLabelPen();
    
        /**
         * Sets the brush used to draw the background of the clock.
         */
        void setBackgroundBrush(QBrush brush);
    
        /**
         * Returns the brush used to draw background of the clock.
         */
        QBrush getBackgroundBrush();

        virtual void paintEvent(QPaintEvent*);
    
    private:
    
        QBrush  hourArmBrush;
        QBrush  minuteArmBrush;
        QBrush  hourTickBrush;
        QBrush  minuteTickBrush;
        QPen    labelPen;
        QBrush  backgroundBrush;
    
        /**
         * Draws an arm of the clock.
         */
        void drawArm(QPainter* painter, int radius, float angle, int width, int length, QBrush* brush);
    
        /**
         * Draws ticks around the outer part of the clock background.
         */
        void drawTick(QPainter* painter, int radius, float angle, int width, int length, QBrush* brush);
};

#endif /* defined(__guidev2__AnalogClock__) */
