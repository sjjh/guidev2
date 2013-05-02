//
//  Clock.cpp
//  guidev2
//
//  Created by Jens Meder on 28.03.13.
//
//

#include "Clock.h"

Clock::Clock()
{
    this->time = QTime::currentTime();
}

Clock::~Clock()
{
    
}

void Clock::setTime(QTime time)
{
    this->time = time;
    
    repaint();
}

QTime Clock::getTime()
{
    return this->time;
}