#ifndef __guidev2__IntroViewController__
#define __guidev2__IntroViewController__

#include "ViewController.h"

class IntroViewController : public ViewController
{
    Q_OBJECT

public:
    IntroViewController(ClockApp*);
    ~IntroViewController();
};

#endif // __guidev2__IntroViewController__
