//
//  UndoRedoWindow.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#define HEIGHT  300
#define WIDTH   300

#include "UndoRedoWindow.h"
#include <QHBoxLayout>

UndoRedoWindow::UndoRedoWindow(QWidget * parent):QWidget(parent,Qt::Window)
{
    setLayout(new QHBoxLayout());

    setMinimumSize(WIDTH, HEIGHT);
}
