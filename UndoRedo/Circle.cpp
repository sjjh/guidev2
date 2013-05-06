//
//  Circle.cpp
//  guidev2
//
//  Created by Jens Meder on 03.05.13.
//
//

#include "Circle.h"


Circle::Circle(QPoint origin, QWidget* parent):Drawable(origin, parent)
{
    fillBrush = new QBrush(Qt::black);
    
    createPath();
}

void Circle::createPath()
{
    path = QPainterPath();
    path.addEllipse(origin.x() - 10, origin.y() - 10, 20, 20);
    path.closeSubpath();
}