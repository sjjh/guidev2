//
//  BasicAnimation.cpp
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#include "BasicAnimation.h"
#include <QSize>
#include <QRect>
#include "EaseInOutAnimationCurve.h"

BasicAnimation::BasicAnimation(QObject* target, QString property):Animation(target,property)
{
    this->startValue = target->property(property.toStdString().c_str());
    this->endValue = 0;    
    this->animationCurve = new EaseInOutAnimationCurve(duration, startValue, endValue);
}

BasicAnimation::~BasicAnimation()
{
    delete animationCurve;
}
    
void BasicAnimation::setAnimationCurve(AnimationCurve* animationCurve)
{
    this->animationCurve = animationCurve;
}

void BasicAnimation::setStartValue(QVariant startValue)
{
    if(startValue.type() == target->property(propertyName.toStdString().c_str()).type())
    {
        this->startValue = startValue;
        this->animationCurve->setStartValue(startValue);
    }
}

void BasicAnimation::setEndValue(QVariant endValue)
{
    if(startValue.type() == endValue.type())
    {
        this->endValue = endValue;
        this->animationCurve->setEndValue(endValue);
    }
}
    
QVariant BasicAnimation::valueForTime(int time)
{    
    return animationCurve->valueForTimeOffset(time);
}