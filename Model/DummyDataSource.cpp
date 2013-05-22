#include "DummyDataSource.h"
#include "Pupil.h"
#include <QString>

DummyDataSource::DummyDataSource():DataSource()
{
}

DummyDataSource::~DummyDataSource()
{
}

void DummyDataSource::save()
{
}

void DummyDataSource::load()
{
    pupils->append(new Pupil("Jens"));
    pupils->append(new Pupil("Niknam"));
    pupils->append(new Pupil("Simon"));
}
