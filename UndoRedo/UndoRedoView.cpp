#include "UndoRedoView.h"
#include <QVBoxLayout>

UndoRedoView::UndoRedoView(QWidget * parent, Qt::WindowFlags f):QWidget(parent, f)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    //create views
    canvasView = new UndoRedoCanvasView();    

    mainLayout->addWidget(canvasView);

    setLayout(mainLayout);
}

UndoRedoView::~UndoRedoView()
{

}


UndoRedoCanvasView* UndoRedoView::getCanvasView()
{
    return this->canvasView;
}

