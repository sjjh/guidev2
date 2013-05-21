//
//  EaseInOutAnimationCurve.cpp
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#include "EaseInOutAnimationCurve.h"

EaseInOutAnimationCurve::EaseInOutAnimationCurve(int duration, QVariant startValue, QVariant endValue):AnimationCurve(duration, startValue, endValue)
{    
    p1 = QPointF(0,0);    
    p4 = QPointF(0.3, 0.2);
    p5 = QPointF(0.7, 0.8);
    p8 = QPointF(1,1);
    
    float slope = (p5.y() - p4.y()) / (p5.x() - p4.x());
    float b = - 0.2 / slope + 0.3;
    
    p2 = QPointF(b,0);
    p3 = QPointF(b,0);
    p6 = QPointF(1 + b, 1);
    p7 = QPointF(1 + b, 1);
}

double EaseInOutAnimationCurve::offsetForTime(int time)
{
    double t = (double) time / duration;
    
    // Calculates ease in curve part
    
    if(t <= p4.x())
    {
        double offset = t / p4.x();
        return calculateQuadraticBezier(p1, p2, p3, p4, offset).y();
    }
    
    // Calculates the linear middle path between ease in and ease out
    
    if(t <= p5.x())
    {
        double offset = (t - p4.x()) / (p5.x() - p4.x());
        return (p4 + (p5 - p4) * offset).y() ;
    }
    
    // Calculates the ease out part
    
    double offset = (t - p5.x()) / (1 - p5.x());
    
    return calculateQuadraticBezier(p5, p6, p7, p8, offset).y();
}

QPointF EaseInOutAnimationCurve::calculateQuadraticBezier(QPointF p1, QPointF p2, QPointF p3, QPointF p4, double t)
{
    QPointF q1, q2, q3, r1, r2;
    
    q1 = p1 + (p2 - p1) * t;
    q2 = p2 + (p3 - p2) * t;
    q3 = p3 + (p4 - p3) * t;

    r1 = q1 + (q2 - q1) * t;
    r2 = q2 + (q3 - q2) * t;

    return r1 + (r2 - r1) * t;
}