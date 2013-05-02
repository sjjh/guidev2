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

UndoRedoViewController::UndoRedoViewController()
{
    view = new UndoRedoView();
    
    view->connect(view, SIGNAL(mouseReleased(QMouseEvent*)), this, SLOT(mouseReleased(QMouseEvent*)));
}

void UndoRedoViewController::mouseReleased(QMouseEvent *event)
{
    Rectangle* rect = new Rectangle(QPoint(event->pos()));
    
    UndoRedoView* v = (UndoRedoView*)view;
    
    v->addDrawable(rect);
}