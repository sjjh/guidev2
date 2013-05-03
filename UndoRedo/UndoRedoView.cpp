//
//  UndoRedoView.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#include "UndoRedoView.h"
#include "UndoRedoManager.h"
#include <cmath>

UndoRedoView::UndoRedoView(QWidget * parent, Qt::WindowFlags f):QWidget(parent, f)
{
    drawables = new QVector<Drawable*>;
    undoAction = new QAction(this);
    undoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
    connect(undoAction, SIGNAL(triggered()), UndoRedoManager::instance(), SLOT(undo()));
    
    redoAction = new QAction(this);
    redoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_Z));
    connect(redoAction, SIGNAL(triggered()), UndoRedoManager::instance(), SLOT(redo()));
    
    this->addAction(undoAction);
    this->addAction(redoAction);
    
    undoIndex = -1;
}

UndoRedoView::~UndoRedoView()
{
    delete drawables;
}

void UndoRedoView::mouseReleaseEvent ( QMouseEvent * event )
{
    emit(mouseReleased(event));
}

void UndoRedoView::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    
    for(int i = 0; i <= undoIndex; i++)
    {
        Drawable* drawable = drawables->at(i);
        drawable->draw(&painter);
    }
}

void UndoRedoView::addDrawable(Drawable * drawable)
{    
    if(undoIndex != drawables->size() - 1)
    {
        for(int i = drawables->size() - 1; i > undoIndex; i--)
        {
            drawables->pop_back();
        }
    }
    
    UndoRedoManager::instance()->addUndoable(this);
    drawables->append(drawable);
    
    undoIndex = drawables->size() - 1;
    
    repaint();
}

void UndoRedoView::undo()
{    
    undoIndex = undoIndex - 1;
    
    repaint();
}

void UndoRedoView::redo()
{
    undoIndex = fmin(drawables->size() - 1, undoIndex + 1);
    
    repaint();
}