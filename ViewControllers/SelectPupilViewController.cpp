#include "SelectPupilViewController.h"
#include "SelectPupilView.h"
#include "ClockApp.h"

SelectPupilViewController::SelectPupilViewController(ClockApp* app):ViewController(app)
{
    view = new SelectPupilView();
}

SelectPupilViewController::~SelectPupilViewController()
{

}
