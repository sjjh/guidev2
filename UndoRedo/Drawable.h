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

/**
 * Base class for all drawable objects.
 */
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
    
        /**
         * Draws the shape object.
         */
        virtual void draw(QPainter *painter);

        /**
         * Return true if a Drawable object contains the current mouse pointer position
         */
        bool containsPoint(QPoint);

        /**
         * Contains the locations of a Drawable object.
         */
        void setOrigin(QPoint);

        /**
         * Destroys the Drawable object and performs necessary clean up.
         */
        ~Drawable();
    
        /**
         * Undo an action.
         */
        void undo();

        /**
         * Redo an action.
         */
        void redo();

        /**
         * Saves information about object amount and location at a given time.
         */
        void takeSnapshot();
};

#endif /* defined(__guidev2__Drawable__) */
