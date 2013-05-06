//
//  Rectangle.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(QPoint origin, QWidget* parent):Drawable(origin, parent)
{
    createPath();
}

void Rectangle::createPath()
{
    path = QPainterPath();
    path.addRect(origin.x() - 5, origin.y() - 5, 10, 10);
    path.closeSubpath();
}