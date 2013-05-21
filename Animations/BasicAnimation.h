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

/**
 *
 * Realizes linear animations which can be adapted by specifying different start and end value as well as duration and animation curves.
 *
 */

class BasicAnimation: public Animation
{
    public:
    
        /**
         * Creates and initializes a new Basic animation
         */
        BasicAnimation(QObject*, const char*);
    
        /**
         * Provides clean up functioniality.
         */
        virtual ~BasicAnimation();
    
        /**
         * Sets animation curve
         */
        void setAnimationCurve(AnimationCurve*);
    
        /**
         * Sets the start value of the animation
         */
        void setStartValue(QVariant);
    
        /**
         * Sets the end value of the animation
         */
        void setEndValue(QVariant);
    
        /**
         * Sets the duration of the animation.
         */
        virtual void setDuration(int);
    
    protected:
    
        /**
         * The start value of the animation
         */
        QVariant startValue;
    
        /**
         * The end value of the animation
         */
        QVariant endValue;
    
        /**
         * The animation curve used to calculate the
         */
        AnimationCurve* animationCurve;
    
        virtual QVariant valueForTime(int);
        
};

#endif /* defined(__guidev2__BasicAnimation__) */
