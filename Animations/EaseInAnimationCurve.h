//
//  EaseInAnimationCurve.h
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#ifndef __guidev2__EaseInAnimationCurve__
#define __guidev2__EaseInAnimationCurve__

#include <iostream>

#include "EaseInOutAnimationCurve.h"
#include <QPointF>

/**
 * Realizes a animation curve with ease in using beziere curves
 */
class EaseInAnimationCurve: public EaseInOutAnimationCurve
{
    public:
    
        /**
         * Creates and intializes a new ease in animation curve.
         */
        EaseInAnimationCurve(int = 0, QVariant = 0, QVariant = 0);

};

#endif /* defined(__guidev2__EaseInAnimationCurve__) */
