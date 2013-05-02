//
//  Drawable.h
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#ifndef __guidev2__Drawable__
#define __guidev2__Drawable__

#include <iostream>
#include <QPainter>

class Drawable
{
    protected:
        Drawable(QPoint);
        
    
        QBrush* fillBrush;
        QPoint origin;
    
    public:
        virtual void draw(QPainter *painter);
        ~Drawable();
};

#endif /* defined(__guidev2__Drawable__) */
