//
//  Created by Jens Meder on 17.04.13.
//

#ifndef __guidev2__Pupil__
#define __guidev2__Pupil__

#include <iostream>
#include <QString>

/**
 * Represents a pupil.
 */
class Pupil
{
    private:
    
        QString* name;
        ~Pupil();
    
    public:
    
        /**
         * Creates a new Pupil instance.
         */
        Pupil();
    
        /**
         * Returns the name of the pupil.
         */
        QString* getName();
};

#endif /* defined(__guidev2__Pupil__) */
