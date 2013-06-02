//
//  AnalogDigitalView.h
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#ifndef __guidev2__AnalogDigitalView__
#define __guidev2__AnalogDigitalView__

#include <iostream>
#include <QWidget>
#include "AnalogClock.h"
#include "FlipClock.h"

class AnalogDigitalView: public QWidget
{
    public:
    
        AnalogDigitalView();
    
        AnalogClock* analogClock();
        FlipClock* flipClock();
    
    private:
    
        AnalogClock* _analog;
        FlipClock* _flip;
};

#endif /* defined(__guidev2__AnalogDigitalView__) */
