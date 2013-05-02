//
//  UndoRedoView.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#include "UndoRedoView.h"

UndoRedoView::UndoRedoView(QWidget * parent, Qt::WindowFlags f):QWidget(parent, f)
{
    drawables = new QVector<Drawable*>;
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
    
    for(int i = 0; i < drawables->size(); i++)
    {
        Drawable* drawable = drawables->at(i);
        drawable->draw(&painter);
    }
}

void UndoRedoView::addDrawable(Drawable * drawable)
{
    drawables->append(drawable);
    repaint();
}