//
//  Drawable.h
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#ifndef __guidev2__Drawable__
#define __guidev2__Drawable__

#include <iostream>
#include <QPainter>
#include "Undoable.h"
#include <QStack>

class Drawable: public Undoable
{
    protected:
    
        QStack<QPoint>* undoStack;
        QStack<QPoint>* redoStack;
    
        Drawable(QPoint, QWidget*);
        
        QWidget* parent;
        QBrush* fillBrush;
        QPoint origin;
        QPainterPath path;
        virtual void createPath() = 0;
        
    
    public:
    
        virtual void draw(QPainter *painter);
        bool containsPoint(QPoint);
        void setOrigin(QPoint);
        ~Drawable();
    
        void undo();
        void redo();
        void takeSnapshot();
};

#endif /* defined(__guidev2__Drawable__) */
