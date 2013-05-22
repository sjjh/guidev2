//
//  JSONDataSource.h
//  guidev2
//
//  Created by Jens Meder on 22.05.13.
//
//

#ifndef __guidev2__JSONDataSource__
#define __guidev2__JSONDataSource__

#include <iostream>
#include "DataSource.h"
#include <QJsonObject>

class JSONDataSource: public DataSource
{
    public:
    
        JSONDataSource();
        virtual ~JSONDataSource();
    
        void save();
    
        void load();
    
    private:
    
        QJsonObject encodePupil(Pupil*);
        Pupil* decode(QJsonObject);
};

#endif /* defined(__guidev2__JSONDataSource__) */
