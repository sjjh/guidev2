#include "IntroViewController.h"
#include "IntroView.h"

IntroViewController::IntroViewController(ClockApp* app):ViewController(app)
{
    IntroView* introView = new IntroView();
    
    connect(introView->getAnalogClock(), SIGNAL(timeChanged(Clock*)), this, SLOT(adjustTime(Clock*)));
    connect(introView->getFlipClock(), SIGNAL(timeChanged(Clock*)), this, SLOT(adjustTime(Clock*)));
    
    view = introView;
}

IntroViewController::~IntroViewController()
{
    view = NULL;
}

void IntroViewController::adjustTime(Clock * clock)
{
    IntroView* introView = (IntroView*) view;
    
    if(clock == introView->getAnalogClock())
    {
        introView->getFlipClock()->setTime(clock->getTime());
    }
    else
    {
        introView->getAnalogClock()->setTime(clock->getTime());
    }
}
