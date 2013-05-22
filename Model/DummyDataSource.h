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

    void save();
    void load();

};

#endif // __guidev2__DummyDataSource__
