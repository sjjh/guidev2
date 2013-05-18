//
//  Created by Jens Meder on 17.04.13.
//


#include "Pupil.h"

Pupil::Pupil()
{
    
}

Pupil::Pupil(QString name)
{
    this->name = name;
}

Pupil::~Pupil()
{
    
}

QString Pupil::getName()
{
    return this->name;
}

void Pupil::setName(QString name)
{
    this->name = name;
}
