#include "UndoRedoView.h"
#include <QVBoxLayout>

UndoRedoView::UndoRedoView(QWidget * parent, Qt::WindowFlags f):QWidget(parent, f)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    //create views
    canvasView = new UndoRedoCanvasView();
    transparencySlider = new QSlider();
    transparencySlider->setOrientation(Qt::Horizontal);
    connect(transparencySlider, SIGNAL(valueChanged(int)), this, SLOT(transparencyChanged(int)));

    mainLayout->addWidget(canvasView);
    mainLayout->addWidget(transparencySlider);

    setLayout(mainLayout);
}

UndoRedoView::~UndoRedoView()
{

}


UndoRedoCanvasView* UndoRedoView::getCanvasView()
{
    return this->canvasView;
}

void UndoRedoView::transparencyChanged(int value)
{

}

