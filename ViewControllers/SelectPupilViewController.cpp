#include "SelectPupilViewController.h"
#include "SelectPupilView.h"
#include "ClockApp.h"

SelectPupilViewController::SelectPupilViewController(ClockApp app)
{
    this->app = app;
    this->view = new SelectPupilView(this->app);
}

SelectPupilViewController::~SelectPupilViewController()
{
    view = NULL;
}
