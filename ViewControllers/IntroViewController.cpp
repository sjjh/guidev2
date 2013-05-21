#include "IntroViewController.h"
#include "IntroView.h"

IntroViewController::IntroViewController(ClockApp* app):ViewController(app)
{
    IntroView* introView = new IntroView();
    
    connect(introView->getStartButton(), SIGNAL(clicked()), app, SLOT(showSelectPupilView()));
    
    view = introView;
}

IntroViewController::~IntroViewController()
{
    view = NULL;
}
