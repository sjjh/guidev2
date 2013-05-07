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
    painter.drawRect(width()/100.0*10, height()/100.0*10, width()/100.0*80, height()/100.0*80);


    // Draw flip charts for the digits
    // each digit chart has following dimensions: 17%*76% of width()
    //and the offset to the case of the clock is 2% of width()
    // distance between each charts: 1% and 6% of width() in the middle
    painter.setPen(QPen(Qt::black,0));
    painter.setBrush(QBrush(Qt::yellow));
    // first hour digit
    painter.drawRect(width()/100.0*12, height()/100.0*12, width()/100.0*17, height()/100.0*76);
    // second hour digit
    painter.drawRect(width()/100.0*30, height()/100.0*12, width()/100.0*17, height()/100.0*76);
    // first minute digit
    painter.drawRect(width()/100.0*53, height()/100.0*12, width()/100.0*17, height()/100.0*76);
    // second minute digit
    painter.drawRect(width()/100.0*71, height()/100.0*12, width()/100.0*17, height()/100.0*76);


    // Draw the numbers of the given time
    // Font configuration
    painter.setPen(QPen(Qt::black,0));
    QFont font(painter.font());

    // calculating loop to calculate max. fontSize that fits into the flipChart
    for (int i = 1; i < 500; i++)
    {
        font.setPointSize(i);
        // create FontMetrics for resized font
        QFontMetrics fm(font);
        // get text width for current font size
        int x = fm.width("0"); // "0" should be the widest digit
        // get text height for current font size
        int y = fm.height();
        // check if text fits widget
        if ((x > width()/100.0*17) || (y > height()/100.0*76))
        {
            // saving maximum possible size of font
            font.setPointSize(i-1);
            break;
        }
    }

    // create FontMetrics for resized font
    QFontMetrics fm(font);
    painter.setFont(font);
    QPointF point;
    //first digit of hour
    if((this->getTime()).hour() > 9)
    {
        // Calculate text center position into the screen using QFontMetrics class
        point = QPointF( ( (width()/100.0*17)-fm.width(QString::number(this->getTime().hour()/10)))/2.0+(width()/100.0*12),
                                ( height() )/2.0 + height()/100.0*12);
        painter.drawText(point,QString::number(this->getTime().hour()/10));
    }
    //second digit of hour
    // Calculate text center position into the screen using QFontMetrics class
    point = QPointF( ( (width()/100.0*17)-fm.width(QString::number(this->getTime().hour()%10)))/2.0+(width()/100.0*30),
                            ( height() )/2.0 + height()/100.0*12);
    painter.drawText(point,QString::number(this->getTime().hour()%10));

    //colon between hh:mm
    point = QPointF( ( (width()/100.0*6)-fm.width(":"))/2.0+(width()/100.0*47),
                            ( height() )/2.0 + height()/100.0*12);
    painter.drawText(point,":");

    //first digit of minute
    // Calculate text center position into the screen using QFontMetrics class
    point = QPointF( ( (width()/100.0*17)-fm.width(QString::number(this->getTime().minute()/10)))/2.0+(width()/100.0*53),
                            ( height() )/2.0 + height()/100.0*12);
    painter.drawText(point,QString::number(this->getTime().minute()/10));
    //second digit of minute
    // Calculate text center position into the screen using QFontMetrics class
    point = QPointF( ( (width()/100.0*17)-fm.width(QString::number(this->getTime().minute()%10)))/2.0+(width()/100.0*71),
                            ( height() )/2.0 + height()/100.0*12);
    painter.drawText(point,QString::number(this->getTime().minute()%10));

    // Draw axis for flip charts
    painter.setPen(QPen(Qt::white,0));
    painter.setBrush(backgroundBrush);
    painter.drawRect(width()/100.0*12,height()/100.0*49,width()/100.0*76,height()/100.0*2);


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
