//
//  UndoRedoView.h
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#ifndef __guidev2__UndoRedoView__
#define __guidev2__UndoRedoView__

#include <iostream>
#include <QWidget>
#include <QVector>
#include "Drawable.h"
#include <QMouseEvent>
#include "Undoable.h"
#include <QAction>

class UndoRedoView: public QWidget, public Undoable
{
    Q_OBJECT
    
    private:
    
        QAction* undoAction;
        QAction* redoAction;
        QVector<Drawable*>* drawables;
        int undoIndex;
    
    public:
    
        UndoRedoView(QWidget * parent = 0, Qt::WindowFlags f = 0);
        ~UndoRedoView();
    
        void addDrawable(Drawable*);
    
        bool canUndo();
        bool canRedo();
        void undo();
        void redo();
        void takeSnapshot();
    
    protected:
    
        virtual void mouseReleaseEvent(QMouseEvent * event);
        virtual void paintEvent(QPaintEvent*);
    
    signals:
    
        void mouseReleased(QMouseEvent*);
};

#endif /* defined(__guidev2__UndoRedoView__) */
