#include "SelectPupilViewController.h"
#include "SelectPupilView.h"
#include "ClockApp.h"
#include <QList>
#include "PupilListModel.h"
#include "QuizGenerator.h"

SelectPupilViewController::SelectPupilViewController(ClockApp* app):ViewController(app)
{
    SelectPupilView* selectPupilView = new SelectPupilView();
    
    selectPupilView->getPupilList()->setModel(new PupilListModel(app->getDataSource()));
    connect(selectPupilView->getPupilList(), SIGNAL(clicked(const QModelIndex &)), this, SLOT(selectionChanged( const QModelIndex & )));
    
    view = selectPupilView;
    
    if(app->getDataSource()->getAllPupils().count() > 0)
    {
        _selectedPupil = app->getDataSource()->getAllPupils().at(0);
        selectPupilView->getPupilList()->selectionModel()->select(selectPupilView->getPupilList()->model()->index(0, 0), QItemSelectionModel::Select);
    }
    
    connect(selectPupilView->easyButton(),SIGNAL(clicked()),this,SLOT(startEasyQuiz()));
    connect(selectPupilView->mediumButton(), SIGNAL(clicked()), this, SLOT(startMediumQuiz()));
    connect(selectPupilView->hardButton(), SIGNAL(clicked()), this, SLOT(startHardQuiz()));
}

SelectPupilViewController::~SelectPupilViewController()
{
}

void SelectPupilViewController::selectionChanged( const QModelIndex & index )
{
    _selectedPupil = app->getDataSource()->getAllPupils().at(index.row());
    
    std::cout << _selectedPupil->getName().toStdString() << std::endl;
}

void SelectPupilViewController::startEasyQuiz()
{
    app->showQuiz(QuizGenerator::generateEasyQuiz());
}

void SelectPupilViewController::startMediumQuiz()
{
    app->showQuiz(QuizGenerator::generateMediumQuiz());
}

void SelectPupilViewController::startHardQuiz()
{
    app->showQuiz(QuizGenerator::generateHardQuiz());
}
