//
//  AnalogDigitalAdjustDigitalViewController.h
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#ifndef __guidev2__AnalogDigitalAdjustDigitalViewController__
#define __guidev2__AnalogDigitalAdjustDigitalViewController__

#include <iostream>
#include "ViewController.h"
#include "AdjustQuizQuestion.h"

class AnalogDigitalAdjustViewController: public ViewController
{
    Q_OBJECT

    public:
    
        AnalogDigitalAdjustViewController(ClockApp*, AdjustQuizQuestion*);
    
        void setQuestion(AdjustQuizQuestion*);
    
    private:
    
        bool _adjustDigital;
        AdjustQuizQuestion* _question;
    
        void randomizeClockSelection();
    
    public slots:
    
        void clockChanged(Clock*);
};

#endif /* defined(__guidev2__AnalogDigitalAdjustDigitalViewController__) */
