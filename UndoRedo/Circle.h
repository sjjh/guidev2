//
//  Circle.h
//  guidev2
//
//  Created by Jens Meder on 03.05.13.
//
//

#ifndef __guidev2__Circle__
#define __guidev2__Circle__

#include <iostream>
#include "Drawable.h"

/**
 * Represents a circle shape object.
 */
class Circle: public Drawable
{
    public:
    
        /**
         * Creates a new Circle instance.
         */
        Circle(QPoint, QWidget*);

        /**
         * Creates the shape to be drawn
         */
        virtual void createPath();
};

#endif /* defined(__guidev2__Circle__) */
