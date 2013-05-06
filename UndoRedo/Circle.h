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

class Circle: public Drawable
{
    public:
    
        Circle(QPoint, QWidget*);
        virtual void createPath();
};

#endif /* defined(__guidev2__Circle__) */
