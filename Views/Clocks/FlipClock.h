#ifndef __guidev2__FlipClock__
#define __guidev2__FlipClock__

#include "Clock.h"

/**
 * @brief The FlipClock class
 * @author Simon
 * Represents a flip clock, that has four cards that can be flipped to display a time
 */
class FlipClock : public Clock
{
public:
    /**
     * @brief FlipClock constructor
     */
    FlipClock();

    /**
     * @brief FlipClock constructor
     */
    FlipClock(QTime time);

    /**
     * @brief FlipClock destructor
     */
    ~FlipClock();

protected:

  void init();
};

#endif // __guidev2__FlipClock__
