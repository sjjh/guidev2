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

class Animation: public QObject
{
    Q_OBJECT

    public:
    
        void setDuration(int);
        void setRepeatCount(int);
        void start();
        void stop();
    
    protected:
    
        Animation(QObject*, QString);
        virtual ~Animation();
    
        QObject* target;
        QString propertyName;

        int duration;
        int repeatCount;
        virtual QVariant valueForTime(int) = 0;
    
    private:
    
        QThread* animationThread;
        QTimer* animationTimer;
        QTime* startTime;
    
    private slots:
    
        void updateValue();
        void threadTerminated();

};

#endif /* defined(__guidev2__Animation__) */
