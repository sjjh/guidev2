#include "FlipClock.h"
#include <qpainter.h>

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
    backgroundBrush = QBrush(Qt::white);
}

FlipClock::~FlipClock()
{

}

void FlipClock::paintEvent(QPaintEvent *)
{
    // Initialize context

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

//*********************** TMP ***********************
    //just to see how big the drawing space is in total I could use...
    painter.setPen(QPen(Qt::black,0));
    painter.setBrush(QBrush(Qt::red));
    painter.drawRect(0, 0, width(), height());
//*********************** TMP ***********************

    // Draw "case" of clock 10% offset of width/height()
    painter.setPen(QPen(Qt::black,0));//TODO: create attribute+method; rename background to clockBackground; move to Clock
    painter.setBrush(backgroundBrush);
    painter.drawRect(width()/100*10, height()/100*10, width()/100*90, height()/100*90);


    // Draw flip charts for the digits
    // each digit chart has following dimensions: 17%*76% of width()
    //and the offset to the case of the clock is 2% of width()
    // distance between each charts: 1% and 6% of width() in the middle
    painter.setPen(QPen(Qt::black,0));
    painter.setBrush(QBrush(Qt::yellow));
    // first hour digit
    painter.drawRect(width()/100*12, height()/100*12, width()/100*17, height()/100*76);
    // second hour digit
    painter.drawRect(width()/100*30, height()/100*12, width()/100*17, height()/100*76);
    // first minute digit
    painter.drawRect(width()/100*53, height()/100*12, width()/100*17, height()/100*76);
    // second minute digit
    painter.drawRect(width()/100*71, height()/100*12, width()/100*17, height()/100*76);

    // Draw axis for flip charts
    painter.setPen(QPen(Qt::white,0));
    painter.setBrush(backgroundBrush);
    painter.drawRect(width()/100*12,height()/100*49,width()/100*76,height()/100*2);



}

QBrush FlipClock::getBackgroundBrush()
{
    return this->backgroundBrush;
}

void FlipClock::setBackgroundBrush(QBrush brush)
{
    this->backgroundBrush = brush;
    repaint();
}
