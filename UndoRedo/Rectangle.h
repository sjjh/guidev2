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

/**
 * Represents a Rectangle shape object.
 */
class Rectangle: public Drawable
{
    public:
    
        /**
        * Creates a new Rectangle instance.
        */
        Rectangle(QPoint, QWidget*);

    protected:

        /**
         * Creates the shape to be drawn
         */
        virtual void createPath();
};

#endif /* defined(__guidev2__Rectangle__) */
