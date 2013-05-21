//
//  LinearAnimationCurve.h
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#ifndef __guidev2__LinearAnimationCurve__
#define __guidev2__LinearAnimationCurve__

#include <iostream>
#include "AnimationCurve.h"

/**
 * Realizes a simple linear animation curve.
 */
class LinearAnimationCurve: public AnimationCurve
{
    public:
    
        /**
         * Creates and initializes the linear animation curve.
         */
        LinearAnimationCurve(int = 0,QVariant = 0, QVariant = 0);
    
    protected:
    
        virtual double offsetForTime(int);
};

#endif /* defined(__guidev2__LinearAnimationCurve__) */
