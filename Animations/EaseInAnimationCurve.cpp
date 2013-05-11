//
//  EaseInAnimationCurve.cpp
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#include "EaseInAnimationCurve.h"

EaseInAnimationCurve::EaseInAnimationCurve(int duration, QVariant startValue, QVariant endValue):EaseInOutAnimationCurve(duration, startValue, endValue)
{    
    p1 = QPointF(0,0);    
    p4 = QPointF(0.3, 0.2);
    p5 = QPointF(1, 1);
    p8 = QPointF(1,1);
    
    float slope = (p5.y() - p4.y()) / (p5.x() - p4.x());
    float b = - 0.2 / slope + 0.3;
    
    p2 = QPointF(b,0);
    p3 = QPointF(b,0);
    p6 = QPointF(1, 1);
    p7 = QPointF(1, 1);
}

