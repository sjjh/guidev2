//
//  AnalogClock.h
//  guidev2
//
//  Created by Jens Meder on 28.03.13.
//
//

#ifndef __guidev2__AnalogClock__
#define __guidev2__AnalogClock__

#include "Clock.h"
#include <iostream>
#include <QPen>

class AnalogClock: public Clock
{
    public:
        AnalogClock();
        ~AnalogClock();
    
        void setHourArmBrush(QBrush brush);
        QBrush getHourArmBrush();
    
        void setMinuteArmBrush(QBrush brush);
        QBrush getMinuteArmBrush();
    
        void setHourTickBrush(QBrush brush);
        QBrush getHourTickBrush();
    
        void setMinuteTickBrush(QBrush brush);
        QBrush getMinuteTickBrush();
    
        void setLabelPen(QPen pen);
        QPen getLabelPen();
    
        void setBackgroundBrush(QBrush brush);
        QBrush getBackgroundBrush();

        virtual void paintEvent(QPaintEvent*);
    
    private:
    
        QBrush  hourArmBrush;
        QBrush  minuteArmBrush;
        QBrush  hourTickBrush;
        QBrush  minuteTickBrush;
        QPen    labelPen;
        QBrush  backgroundBrush;
    
        void drawArm(QPainter* painter, int radius, float angle, int width, int length, QBrush* brush);
        void drawTick(QPainter* painter, int radius, float angle, int width, int length, QBrush* brush);
};

#endif /* defined(__guidev2__AnalogClock__) */
