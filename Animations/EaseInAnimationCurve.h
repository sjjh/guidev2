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

class EaseInAnimationCurve: public EaseInOutAnimationCurve
{
    public:
    
        EaseInAnimationCurve(int = 0, QVariant = 0, QVariant = 0);

};

#endif /* defined(__guidev2__EaseInAnimationCurve__) */