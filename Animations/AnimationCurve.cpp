//
//  AnimationCurve.cpp
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#include "AnimationCurve.h"
#include <QTime>
#include <QRect>

AnimationCurve::AnimationCurve(int duration, QVariant startValue, QVariant endValue)
{
    this->duration = duration;
    this->startValue = startValue;
    this->endValue = endValue;
}

AnimationCurve::~AnimationCurve()
{
}

QVariant AnimationCurve::valueForTimeOffset(int time)
{
    double offset = offsetForTime(time);
    
    // Property is of type integer
    
    if(startValue.type() == QVariant::Int)
    {
        return startValue.toInt() + offset * (endValue.toInt() - startValue.toInt());
    }
    
    // Property is of type QTime
    
    else if(startValue.type() == QVariant::Time)
    {
        QTime result(startValue.toTime());
        
        return result.addMSecs(offset * (startValue.toTime().msecsTo(endValue.toTime())));
    }
    
    // Property is of type QSize
    
    else if(startValue.type() == QVariant::Size)
    {
        QSize result;
        result.setHeight(startValue.toSize().height() + (endValue.toSize().height() - startValue.toSize().height()) * offset);
        result.setWidth(startValue.toSize().width() + (endValue.toSize().width() - startValue.toSize().width()) * offset);
        
        return result;
    }
    
    // Property is of type QRect
    
    else if(startValue.type() == QVariant::Rect)
    {
        QRect result(startValue.toRect());
        
        // Calculate size
        
        result.setHeight(startValue.toRect().height() + (endValue.toRect().height() - startValue.toRect().height()) * offset);
        result.setWidth(startValue.toRect().width() + (endValue.toRect().width() - startValue.toRect().width()) * offset);
        
        // Calculate origin
        
        result.setX(startValue.toRect().x() + (endValue.toRect().x() - startValue.toRect().x()) * offset);
        result.setY(startValue.toRect().y() + (endValue.toRect().y() - startValue.toRect().y()) * offset);
        
        return result;
    }
    
    // Property is of type double
    
    else if(startValue.type() == QVariant::Double)
    {
        return startValue.toDouble() + offset * (endValue.toDouble() - startValue.toDouble());
    }
    
    return 0;
}
    
QVariant AnimationCurve::getStartValue()
{
    return this->startValue;
}

QVariant AnimationCurve::getEndValue()
{
    return this->endValue;
}

void AnimationCurve::setStartValue(QVariant startValue)
{
    this->startValue = startValue;
}

void AnimationCurve::setEndValue(QVariant endValue)
{
    this->endValue = endValue;
}

void AnimationCurve::setDuration(int duration)
{
    this->duration = duration;
}