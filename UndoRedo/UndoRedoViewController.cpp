//
//  UndoRedoViewController.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#include "UndoRedoViewController.h"
#include "UndoRedoView.h"
#include "Rectangle.h"
#include "Circle.h"

UndoRedoViewController::UndoRedoViewController(ClockApp* app): ViewController(app)
{
    view = new UndoRedoView();

    canvasView = (QWidget*)((UndoRedoView*)view)->getCanvasView();
    
    canvasView->connect(canvasView, SIGNAL(mouseReleased(QMouseEvent*)), this, SLOT(mouseReleased(QMouseEvent*)));
}

void UndoRedoViewController::mouseReleased(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        Rectangle* rect = new Rectangle(event->pos(), canvasView);
    
        UndoRedoCanvasView* v = (UndoRedoCanvasView*)canvasView;
    
        v->addDrawable(rect);
    }
    else
    {
        Circle* circle = new Circle(event->pos(), canvasView);
        
        UndoRedoCanvasView* v = (UndoRedoCanvasView*)canvasView;
    
        v->addDrawable(circle);
    }
}
