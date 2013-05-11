//
//  AnimationCurve.h
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#ifndef __guidev2__AnimationCurve__
#define __guidev2__AnimationCurve__

#include <iostream>
#include <QVariant>

class AnimationCurve
{
    protected:
    
        AnimationCurve(int = 0, QVariant = 0, QVariant = 0);        
    
        QVariant startValue;
        QVariant endValue;
        int duration;
    
    public:
    
        virtual double offsetForTime(int) = 0;
        QVariant valueForTimeOffset(int);
    
        QVariant getStartValue();
        QVariant getEndValue();
    
        void setStartValue(QVariant);
        void setEndValue(QVariant);
        void setDuration(int);
    
        virtual ~AnimationCurve();
};

#endif /* defined(__guidev2__AnimationCurve__) */
