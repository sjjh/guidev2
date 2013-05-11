//
//  LinearAnimationCurve.cpp
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#include "LinearAnimationCurve.h"

LinearAnimationCurve::LinearAnimationCurve(int duration,QVariant startValue, QVariant endValue):AnimationCurve(duration, startValue, endValue)
{
}
    
double LinearAnimationCurve::offsetForTime(int time)
{
    return (double) time / duration;
}
