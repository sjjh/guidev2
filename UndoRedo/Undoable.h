//
//  Undoable.h
//  guidev2
//
//  Created by Jens Meder on 02.05.13.
//
//

#ifndef __guidev2__Undoable__
#define __guidev2__Undoable__

#include <iostream>

class Undoable
{    
    protected:
    
        Undoable();
    
    public:
    
        virtual void redo() = 0;
        virtual void undo() = 0;
    
};

#endif /* defined(__guidev2__Undoable__) */
