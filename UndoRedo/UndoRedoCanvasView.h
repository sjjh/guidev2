//
//  UndoRedoView.h
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#ifndef __guidev2__UndoRedoCanvasView__
#define __guidev2__UndoRedoCanvasView__

#include <iostream>
#include <QWidget>
#include <QVector>
#include "Drawable.h"
#include <QMouseEvent>
#include "Undoable.h"
#include <QAction>

class UndoRedoCanvasView: public QWidget, public Undoable
{
    Q_OBJECT
    
    private:
    
        QAction* undoAction;
        QAction* redoAction;
        QVector<Drawable*>* drawables;
        int undoIndex;
        Drawable* hitDrawable;
    
    public:
    
        UndoRedoCanvasView(QWidget * parent = 0, Qt::WindowFlags f = 0);
        ~UndoRedoCanvasView();
    
        void addDrawable(Drawable*);
    
        bool canUndo();
        bool canRedo();
        void undo();
        void redo();
        void takeSnapshot();
    
    protected:
    
        virtual void mouseReleaseEvent(QMouseEvent * event);
        virtual void mousePressEvent(QMouseEvent* event);
        virtual void mouseMoveEvent(QMouseEvent* event);
        virtual void paintEvent(QPaintEvent*);
    
    signals:
    
        void mouseReleased(QMouseEvent*);
};

#endif /* defined(__guidev2__UndoRedoView__) */
