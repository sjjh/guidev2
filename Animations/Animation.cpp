//
//  Animation.cpp
//  guidev2
//
//  Created by Jens Meder on 10.05.13.
//
//

#include "Animation.h"

#define UPDATE_INTERVAL 20

void Animation::setDuration(int duration)
{
    this->duration = duration;
}

void Animation::setRepeatCount(int repeatCount)
{
    this->repeatCount = repeatCount;
}

void Animation::start()
{
    if (!animationTimer && !animationThread)
    {
        animationTimer = new QTimer(0);
        animationThread = new QThread();
        animationTimer->setInterval(UPDATE_INTERVAL);

        animationTimer->moveToThread(animationThread);
        connect(animationTimer, SIGNAL(timeout()), this, SLOT(updateValue()));
        
        connect(animationThread, SIGNAL(started()), animationTimer, SLOT(start()));
        connect(animationThread, SIGNAL(finished()), this, SLOT(threadTerminated()));
        animationThread->start();
    }
}

void Animation::stop()
{
    animationTimer->stop();
    animationThread->terminate();
    
    currentRepeatIteration = 1;
}

void Animation::threadTerminated()
{
    delete animationTimer;
    delete animationThread;
    
    animationTimer = NULL;
    animationThread = NULL;
    
    delete startTime;
    startTime = NULL;
}
    
Animation::Animation(QObject* target, const char* property)
{
    this->target = target;
    this->propertyName = property;
    this->animationTimer = NULL;
    this->animationThread = NULL;
    this->duration = 3000;
    this->repeatCount = std::numeric_limits<int>().max();
    this->startTime = 0;
    this->currentRepeatIteration = 1;
    this->reversable = true;
    this->isReversed = false;
}

Animation::~Animation()
{
    delete animationThread;
    delete animationTimer;
}

void Animation::updateValue()
{
    if(!startTime)
    {
        startTime = new QTime(QTime::currentTime());
    }
    
    if(startTime->elapsed() >= duration)
    {
        // Current iteration finished
        
        if(isReversed)
        {
            this->target->setProperty(propertyName, valueForTime(duration - startTime->elapsed()));
        }
        else
        {
            this->target->setProperty(propertyName, valueForTime(startTime->elapsed()));
        }
        
        if(reversable && !(currentRepeatIteration > repeatCount))
        {
            if(!isReversed)
            {
                currentRepeatIteration--;
                isReversed = true;
            }
            else
            {
                isReversed = false;
                
            }
        }
        
        // Check if more iterations are coming
        
        if(currentRepeatIteration < repeatCount)
        {
            startTime = 0;
            currentRepeatIteration++;
        }
        else
        {
            stop();
        }
    }
    else
    {
        if(isReversed)
        {
            this->target->setProperty(propertyName, valueForTime(duration - startTime->elapsed()));
        }
        else
        {
            this->target->setProperty(propertyName, valueForTime(startTime->elapsed()));
        }
    }
}