#include "SelectPupilViewController.h"
#include "SelectPupilView.h"

SelectPupilViewController::SelectPupilViewController()
{
    view = new SelectPupilView();
}

SelectPupilViewController::~SelectPupilViewController()
{
    view = NULL;
}
