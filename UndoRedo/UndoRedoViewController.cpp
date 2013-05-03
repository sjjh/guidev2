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

UndoRedoViewController::UndoRedoViewController()
{
    view = new UndoRedoView();
    
    view->connect(view, SIGNAL(mouseReleased(QMouseEvent*)), this, SLOT(mouseReleased(QMouseEvent*)));
}

void UndoRedoViewController::mouseReleased(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        Rectangle* rect = new Rectangle(event->pos());
    
        UndoRedoView* v = (UndoRedoView*)view;
    
        v->addDrawable(rect);
    }
    else
    {
        Circle* circle = new Circle(event->pos());
        
        UndoRedoView* v = (UndoRedoView*)view;
    
        v->addDrawable(circle);
    }
}