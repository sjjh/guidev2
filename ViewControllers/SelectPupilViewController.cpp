#include "SelectPupilViewController.h"
#include "SelectPupilView.h"
#include "ClockApp.h"

SelectPupilViewController::SelectPupilViewController(ClockApp* app)
{
    this->app = app;
}

SelectPupilViewController::~SelectPupilViewController()
{
    view = NULL;
}
