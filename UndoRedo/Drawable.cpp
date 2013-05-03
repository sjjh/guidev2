//
//  Drawable.cpp
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#include "Drawable.h"

Drawable::Drawable(QPoint origin)
{
    this->origin = origin;
    fillBrush = new QBrush(Qt::red);
}

Drawable::~Drawable()
{
    delete fillBrush;
}

void Drawable::draw(QPainter *painter)
{
    
}