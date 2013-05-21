#include "SelectPupilViewController.h"
#include "SelectPupilView.h"
#include "ClockApp.h"
#include <QList>
#include "PupilListModel.h"

SelectPupilViewController::SelectPupilViewController(ClockApp* app):ViewController(app)
{
    SelectPupilView* selectPupilView = new SelectPupilView();
    
    selectPupilView->getPupilList()->setModel(new PupilListModel(app->getDataSource()));
    
    view = selectPupilView;
}

SelectPupilViewController::~SelectPupilViewController()
{
}
