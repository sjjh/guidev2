//
//  Rectangle.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(QPoint origin):Drawable(origin)
{
    fillBrush = new QBrush(Qt::red);
}

void Rectangle::draw(QPainter *painter)
{
    painter->save();
    painter->fillRect(QRect(origin, QSize(5,5)), *fillBrush);
    painter->restore();
}