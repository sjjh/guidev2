#include "FlipClock.h"

FlipClock::FlipClock()
{
    this->init();
}

FlipClock::FlipClock(QTime time)
{
    this->init();
    this->setTime(time);
}

void FlipClock::init()
{
    //Initialize the clock with default values
}

FlipClock::~FlipClock()
{

}
