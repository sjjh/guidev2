//
//  Drawable.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#include "Drawable.h"
#include <QWidget>

Drawable::Drawable(QPoint origin, QWidget* parent)
{
    this->parent = parent;
    this->origin = origin;
    fillBrush = new QBrush(Qt::red);
    
    undoStack = new QStack<QPoint>();
    redoStack = new QStack<QPoint>();
}

Drawable::~Drawable()
{
    delete fillBrush;
    delete redoStack;
    delete undoStack;
}

void Drawable::draw(QPainter *painter)
{
    painter->setBrush(*fillBrush);
    painter->setPen(Qt::transparent);
    painter->drawPath(path);
}

bool Drawable::containsPoint(QPoint point)
{
    return path.contains(point);
}

void Drawable::setOrigin(QPoint point)
{
    origin = point;
    createPath();
}

void Drawable::takeSnapshot()
{
    redoStack->empty();
    
    undoStack->push(origin);
}

void Drawable::undo()
{
    redoStack->push(origin);
    origin = undoStack->pop();
    
    createPath();
    
    parent->repaint();
}

void Drawable::redo()
{
    undoStack->push(origin);
    origin = redoStack->pop();
    
    createPath();
    
    parent->repaint();
}