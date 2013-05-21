//
//  Animation.h
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#ifndef __guidev2__Animation__
#define __guidev2__Animation__

#include <iostream>
#include <QObject>
#include <QTimer>
#include <QThread>
#include <QVariant>
#include <QTime>

/**
 * Base class for all animations.
 */
class Animation: public QObject
{
    Q_OBJECT

    public:
    
        /**
         * Sets the duration for the animation.
         */
        virtual void setDuration(int);
    
        /**
         * Sets the repeat count for the animation.
         */
        void setRepeatCount(int);
    
        /**
         * Starts the animation.
         */
        void start();
    
        /**
         * Stops the animation.
         */
        void stop();
    
        /**
         * Provides clean up functioniality.
         */
        virtual ~Animation();
    
    protected:
    
        /**
         * Creates and initializes a new animation.
         */
        Animation(QObject*, const char*);
    
        /**
         * The target object of the animation.
         */
        QObject* target;
    
        /**
         * The name of the property to be animated.
         */
        const char* propertyName;

        /**
         * Indicates if the animation is currently running in reverse.
         */
        bool isReversed;
    
        /**
         * Inidicates if the animation can be reversed.
         */
        bool reversable;
    
        /**
         * The duration of the animation.
         */
        int duration;
    
        /**
         * The repeat count of the animation.
         */
        int repeatCount;
    
        virtual QVariant valueForTime(int) = 0;
    
    private:
    
        /** 
         * The thread on which the animation is running.
         */
        QThread* animationThread;
    
        /**
         * The timer used to fire in intervals.
         */
        QTimer* animationTimer;
    
        /**
         * The start time of the animation.
         */
        QTime* startTime;
    
        /**
         * Represents the current repeat count.
         */
        int currentRepeatIteration;
    
    private slots:
    
        /**
         * Callback slot which fires when the timer fires.
         */
        void updateValue();
    
        /**
         * Called when the thread has been terminated.
         */
        void threadTerminated();

};

#endif /* defined(__guidev2__Animation__) */
