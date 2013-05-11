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

class EaseOutAnimationCurve: public EaseInOutAnimationCurve
{
    public:
    
        EaseOutAnimationCurve(int, QVariant, QVariant);
};

#endif /* defined(__guidev2__EaseOutAnimationCurve__) */
