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

class UndoRedoView: public QWidget
{
    Q_OBJECT
    
    private:
        QVector<Drawable*>* drawables;
    
    public:
        UndoRedoView(QWidget * parent = 0, Qt::WindowFlags f = 0);
        ~UndoRedoView();
    
        void addDrawable(Drawable*);
    
    protected:
    
        virtual void mouseReleaseEvent(QMouseEvent * event);
        virtual void paintEvent(QPaintEvent*);
    
    signals:
    
        void mouseReleased(QMouseEvent*);
};

#endif /* defined(__guidev2__UndoRedoView__) */
