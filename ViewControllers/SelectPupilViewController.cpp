#include "SelectPupilViewController.h"
#include "SelectPupilView.h"
#include "ClockApp.h"

SelectPupilViewController::SelectPupilViewController(ClockApp* app):ViewController(app)
{
    SelectPupilView* selectPupilView = new SelectPupilView();
    
    connect(selectPupilView->getHomeButton(), SIGNAL(clicked()), app, SLOT(showIntroView()));
    
    view = selectPupilView;
}

SelectPupilViewController::~SelectPupilViewController()
{

}
