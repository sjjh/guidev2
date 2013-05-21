#ifndef __guidev2__DummyDataSource__
#define __guidev2__DummyDataSource__

#include <QList>
#include "Pupil.h"
#include "DataSource.h"

class DummyDataSource : public DataSource
{
public:
    DummyDataSource();
    virtual ~DummyDataSource();
    QList<Pupil *> getAllPupils();
    Pupil *getPupilByName(QString &name);
    Pupil *getPupilById(int i);

private:
    QList<Pupil*> *pupils;

};

#endif // __guidev2__DummyDataSource__
