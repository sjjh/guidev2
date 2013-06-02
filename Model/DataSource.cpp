//
//  DataSource.cpp
//  guidev2
//
//  Created by Jens Meder on 22.05.13.
//
//

#include "DataSource.h"

DataSource::DataSource()
{
    pupils = new QList<Pupil*>();
    isLoaded = false;
}

DataSource::~DataSource()
{
    delete pupils;
}

QList<Pupil*>& DataSource::getAllPupils()
{
    if(!isLoaded)
    {
        load();
        isLoaded = true;
    }
    return *this->pupils;
}

Pupil *DataSource::getPupilByName(QString *name)
{
    if(!isLoaded)
    {
        load();
        isLoaded = true;
    }
    
    for(int i=0; i<this->pupils->size(); i++)
    {
        if(this->pupils->at(i)->getName().compare(name) == 0)
            return pupils->at(i);
    }
    return NULL;
}

Pupil* DataSource::getPupilById(int i)
{
    if(!isLoaded)
    {
        load();
        isLoaded = true;
    }
    
    if(this->pupils->size() > i)
        return pupils->at(i);
    else
        return 0;
}

int DataSource::getNumberOfPupils()
{
    if(!isLoaded)
    {
        load();
        isLoaded = true;
    }
    
    return this->pupils->size();
}