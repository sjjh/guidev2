#include "SelectPupilViewController.h"
#include "SelectPupilView.h"
#include "ClockApp.h"
#include <QList>
#include "PupilListModel.h"

SelectPupilViewController::SelectPupilViewController(ClockApp* app):ViewController(app)
{
    SelectPupilView* selectPupilView = new SelectPupilView();
    
    selectPupilView->getPupilList()->setModel(new PupilListModel(app->getDataSource()));
    connect(selectPupilView->getPupilList(), SIGNAL(clicked(const QModelIndex &)), this, SLOT(selectionChanged( const QModelIndex & )));
    
    view = selectPupilView;
}

SelectPupilViewController::~SelectPupilViewController()
{
}

void SelectPupilViewController::selectionChanged( const QModelIndex & index )
{
    std::cout << index.row() << std::endl;
}
