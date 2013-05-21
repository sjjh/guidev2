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

/**
 * Base class for all animation curves used within linear animations.
 */
class AnimationCurve
{
    protected:
    
        /**
         * Creates and initializes a new animation curve.
         */
        AnimationCurve(int = 0, QVariant = 0, QVariant = 0);        
    
        /**
         * The start value of the animation.
         */
        QVariant startValue;
    
        /**
         * The end value of the animation.
         */
        QVariant endValue;
    
        /**
         * The duration of the animation.
         */
        int duration;
    
    public:
    
        /**
         * Abstract method which needs to be implemented to calculate the offset value for a certain time value. 
         */
        virtual double offsetForTime(int) = 0;
    
        /**
         * Calculates the value for a certain time value.
         */
        QVariant valueForTimeOffset(int);
    
        /**
         * Returns the start value of the animation.
         */
        QVariant getStartValue();
    
        /**
         * Returns the end value of the animation.
         */
        QVariant getEndValue();
    
        /**
         * Sets the start value of the animation.
         */
        void setStartValue(QVariant);
    
        /**
         * Sets the end value of the animation.
         */
        void setEndValue(QVariant);
    
        /**
         * Sets the duration of the animation.
         */
        void setDuration(int);
    
        /**
         * Provides clean up functioniality.
         */
        virtual ~AnimationCurve();
};

#endif /* defined(__guidev2__AnimationCurve__) */
