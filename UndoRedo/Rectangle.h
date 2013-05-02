//
//  Rectangle.h
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#ifndef __guidev2__Rectangle__
#define __guidev2__Rectangle__

#include <iostream>
#include "Drawable.h"

class Rectangle: public Drawable
{
    public:
    
        Rectangle(QPoint);
    
        virtual void draw(QPainter *painter);
};

#endif /* defined(__guidev2__Rectangle__) */