#include "UndoRedoView.h"
#include <QVBoxLayout>

UndoRedoView::UndoRedoView(QWidget * parent, Qt::WindowFlags f):QWidget(parent, f)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    //create views
//    labelView = new UndoRedoLabelView();
    canvasView = new UndoRedoCanvasView();


//    mainLayout->addWidget(labelView);
    mainLayout->addWidget(canvasView);


}

UndoRedoView::~UndoRedoView()
{

}


UndoRedoCanvasView* UndoRedoView::getCanvasView()
{
    return this->canvasView;
}
/**
UndoRedoLabelView* UndoRedoView::getLabelView()
{
    return this->labelView;
}*/
