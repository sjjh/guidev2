//
//  AnalogDigitalAdjustDigitalViewController.cpp
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#include "AnalogDigitalAdjustViewController.h"
#include "AnalogDigitalView.h"

AnalogDigitalAdjustViewController::AnalogDigitalAdjustViewController(ClockApp* app, AdjustQuizQuestion* question):ViewController(app)
{
    AnalogDigitalView* analogDigitalView = new AnalogDigitalView();
    
    view = analogDigitalView;
    
    setQuestion(question);
    
    connect(analogDigitalView->analogClock(), SIGNAL(timeChanged(Clock*)),this, SLOT(clockChanged(Clock*)));
    connect(analogDigitalView->flipClock(), SIGNAL(timeChanged(Clock*)),this, SLOT(clockChanged(Clock*)));
}

void AnalogDigitalAdjustViewController::setQuestion(AdjustQuizQuestion * question)
{
    _question = question;
    
    randomizeClockSelection();
    
    AnalogDigitalView* analogDigitalView = static_cast<AnalogDigitalView*>(view);
    
    if(_adjustDigital)
    {
        analogDigitalView->analogClock()->setTime(_question->correctAnswer());
        analogDigitalView->flipClock()->setTime(QTime(0,0,0));
        
        analogDigitalView->analogClock()->setDisabled(true);
        analogDigitalView->flipClock()->setDisabled(false);
    }
    else
    {
        analogDigitalView->flipClock()->setTime(_question->correctAnswer());
        analogDigitalView->analogClock()->setTime(QTime(0,0,0));
        
        analogDigitalView->analogClock()->setDisabled(false);
        analogDigitalView->flipClock()->setDisabled(true);
    }
}

void AnalogDigitalAdjustViewController::randomizeClockSelection()
{
    srand ((unsigned int)time(NULL));
    
    _adjustDigital = rand() % 2;
}

void AnalogDigitalAdjustViewController::clockChanged(Clock * clock)
{
    _question->setAnswer(clock->getTime());
}