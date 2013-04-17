//
//  Pupil.h
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#ifndef __guidev2__Pupil__
#define __guidev2__Pupil__

#include <iostream>
#include <QString>

class Pupil
{
    private:
        QString* name;
        ~Pupil();
    
    public:
        Pupil();
        QString* getName();
};

#endif /* defined(__guidev2__Pupil__) */
