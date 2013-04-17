//
//  Clock.h
//  guidev2
//
//  Created by Jens Meder on 28.03.13.
//
//

#ifndef __guidev2__Clock__
#define __guidev2__Clock__

#include <iostream>
#include <qwidget.h>
#include <ctime>
#include <QTime>

class Clock: public QWidget
{
    public:
        void setTime(QTime time);
        QTime getTime();

    protected:
        QTime time;
    
        Clock();
        ~Clock();
};

#endif /* defined(__guidev2__Clock__) */
