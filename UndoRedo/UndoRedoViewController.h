//
//  UndoRedoViewController.h
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#ifndef __guidev2__UndoRedoViewController__
#define __guidev2__UndoRedoViewController__

#include <iostream>
#include <QWidget>
#include "ViewController.h"

class UndoRedoViewController: public ViewController
{
    Q_OBJECT
    
    public:
    
        UndoRedoViewController(ClockApp* app);

    private:
        QWidget* canvasView;

    private slots:
    
        void mouseReleased(QMouseEvent* event);
};

#endif /* defined(__guidev2__UndoRedoViewController__) */
