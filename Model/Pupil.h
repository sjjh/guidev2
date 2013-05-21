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
    
        QString name;
    
    public:
    
        /**
         * Creates a new Pupil instance.
         */
        Pupil();

        /**
         * @brief constructor which sets the name
         * @param name the name of the pupil as QString
         */
        Pupil(QString name);

        ~Pupil();
    
        /**
         * Returns the name of the pupil.
         */
        QString getName();

        /**
         * @brief setName
         * @param name the name to set as QString
         */
        void setName(QString name);
};

#endif /* defined(__guidev2__Pupil__) */
