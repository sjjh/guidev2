//
//  EaseOutAnimationCurve.h
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#ifndef __guidev2__EaseOutAnimationCurve__
#define __guidev2__EaseOutAnimationCurve__

#include <iostream>

#include "EaseInOutAnimationCurve.h"

/**
 * Realizes a animation curve with ease out using beziere curves
 */
class EaseOutAnimationCurve: public EaseInOutAnimationCurve
{
    public:
    
        /**
         * Creates and initializes a new ease out animation curve.
         */
        EaseOutAnimationCurve(int = 0, QVariant = 0, QVariant = 0);
};

#endif /* defined(__guidev2__EaseOutAnimationCurve__) */
