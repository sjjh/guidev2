#ifndef __guidev2__SelectPupilViewController__
#define __guidev2__SelectPupilViewController__

#include "ViewController.h"
#include "ClockApp.h"

class SelectPupilViewController : public ViewController
{
public:
    SelectPupilViewController(ClockApp app);
    ~SelectPupilViewController();

private:
    ClockApp app;
};

#endif // __guidev2__SelectPupilViewController__
