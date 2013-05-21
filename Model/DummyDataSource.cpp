#include "DummyDataSource.h"
#include "Pupil.h"
#include <QString>

DummyDataSource::DummyDataSource()
{
    pupils = new QList<Pupil*>();
    pupils->append(new Pupil("Jens"));
    pupils->append(new Pupil("Niknam"));
    pupils->append(new Pupil("Simon"));
}

DummyDataSource::~DummyDataSource()
{

}

QList<Pupil*> DummyDataSource::getAllPupils()
{
    return *this->pupils;
}

Pupil *DummyDataSource::getPupilByName(QString &name)
{
    for(int i=0; i<this->pupils->size(); i++) {
        if(this->pupils->at(i)->getName().compare(name) == 0)
            return pupils->at(i);
    }
    return NULL;
}

Pupil* DummyDataSource::getPupilById(int i)
{
    if(this->pupils->size() > i)
        return pupils->at(i);
    else
        return 0;
}
