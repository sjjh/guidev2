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

/**
 * Realizes a animation curve with ease in out ease out using beziere curves
 */
class EaseInOutAnimationCurve: public AnimationCurve
{
    public:
    
        /**
         * Creates and initializes a new ease in and out animation curve.
         */
        EaseInOutAnimationCurve(int = 0, QVariant = 0, QVariant = 0);
    
    protected:
    
        double offsetForTime(int);
    
        /**
         * Calculates the quadratic beziere curve value using the four points provided as well as a time value.
         */
        QPointF calculateQuadraticBezier(QPointF,QPointF,QPointF,QPointF, double);
    
        /**
         * The control points for the beziere curve.
         */
        QPointF p1, p2, p3, p4, p5, p6, p7, p8;
};

#endif /* defined(__guidev2__EaseInOutAnimationCurve__) */
