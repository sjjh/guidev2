//
//  EaseInOutAnimationCurve.h
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#ifndef __guidev2__EaseInOutAnimationCurve__
#define __guidev2__EaseInOutAnimationCurve__

#include <iostream>

#include "AnimationCurve.h"
#include <QPointF>

class EaseInOutAnimationCurve: public AnimationCurve
{
    public:
    
        EaseInOutAnimationCurve(int = 0, QVariant = 0, QVariant = 0);
    
    protected:
    
        double offsetForTime(int);
        QPointF calculateQuadraticBezier(QPointF,QPointF,QPointF,QPointF, double);
    
        QPointF p1, p2, p3, p4, p5, p6, p7, p8;
};

#endif /* defined(__guidev2__EaseInOutAnimationCurve__) */
