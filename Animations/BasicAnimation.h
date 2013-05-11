//
//  BasicAnimation.h
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#ifndef __guidev2__BasicAnimation__
#define __guidev2__BasicAnimation__

#include <iostream>
#include "Animation.h"
#include <QString>
#include <QVariant>
#include "AnimationCurve.h"

class BasicAnimation: public Animation
{
    public:
    
        BasicAnimation(QObject*, QString);
        virtual ~BasicAnimation();
    
        void setAnimationCurve(AnimationCurve*);
        void setStartValue(QVariant);
        void setEndValue(QVariant);
    
    protected:
    
        QVariant startValue;
        QVariant endValue;
        AnimationCurve* animationCurve;
    
        virtual QVariant valueForTime(int);
        
};

#endif /* defined(__guidev2__BasicAnimation__) */
