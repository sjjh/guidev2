//
//  Circle.cpp
//  guidev2
//
//  Created by Jens Meder on 03.05.13.
//
//

#include "Circle.h"


Circle::Circle(QPoint origin):Drawable(origin)
{
    fillBrush = new QBrush(Qt::black);
}

void Circle::draw(QPainter *painter)
{
    painter->save();
    
    painter->setPen(Qt::transparent);
    painter->setBrush(*fillBrush);
    painter->drawEllipse(QRect(origin,QSize(20,20)));
    
    painter->restore();
}