//
//  Created by Jens Meder on 17.04.13.
//

#ifndef __guidev2__DataSource__
#define __guidev2__DataSource__

#include <iostream>
#include <QList>
#include "Pupil.h"

/**
 * Base class for all data sources that can be used to store application data.
 */
class DataSource
{
    protected:
    
        /**
         * Creates a new DataSource instance.
         */
        DataSource() {};
        virtual ~DataSource() {};

        /**
         * @brief getAllPupils
         * @return a QList with all pupils
         * @author Simon
         */
        virtual QList<Pupil*> getAllPupils() = 0;
        /**
         * @brief getPupilByName
         * @param name the name of a pupil as QString
         * @return a Pupil or NULL if no matching item was found
         * @author Simon
         */
        virtual Pupil* getPupilByName(QString *name) = 0;
        /**
         * @brief getPupilById
         * @param i the index of the pupil we want
         * @return a Pupil or NULL if no matching item was found
         * @author Simon
         */
        virtual Pupil* getPupilById(int i) = 0;

        /**
         * @brief getNumberOfPupils
         * @return returns number of errors
         * @author Simon
         */
        virtual int getNumberOfPupils() = 0;

};

#endif /* defined(__guidev2__DataSource__) */
