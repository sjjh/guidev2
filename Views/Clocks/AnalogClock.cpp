/**
 *
 *   Created by Jens Meder on 28.03.13.
 *
 */

#define NUMBER_OF_MINUTES   60
#define NUMBER_OF_HOURS     12
#define RADIANT(x)          M_PI * 2.0 * x / 360.0
#define MINIMUM_FONT_SIZE   8

#define MINIMUM_HOUR_TICK_HEIGHT    3
#define MINIMUM_HOUR_TICK_WIDTH     6
#define MINIMUM_MINUTE_TICK_HEIGHT  1
#define MINIMUM_MINUTE_TICK_WIDTH   3

#include "AnalogClock.h"
#include <qpainter.h>
#include <math.h>
#include "BasicAnimation.h"

AnalogClock::AnalogClock()
{
    this->init();
    this->setTime(QTime::currentTime());
}

AnalogClock::AnalogClock(QTime time)
{
    this->init();
    this->setTime(time);
}

void AnalogClock::init()
{
    // Initialize the clock with default values

    hourArmBrush = QBrush(Qt::red);
    minuteArmBrush = QBrush(Qt::black);

    hourTickBrush = QBrush(Qt::black);
    minuteTickBrush = QBrush(Qt::gray);

    labelPen = QPen(Qt::black);
    backgroundBrush = QBrush(Qt::white);
    
    this->minuteArmPath = QPainterPath();
    this->hourArmPath = QPainterPath();
}

AnalogClock::~AnalogClock()
{
    
}

void AnalogClock::paintEvent(QPaintEvent *)
{
    // Calculate the size properties relative to the clocks size
    
    float diameter = std::min(width(),height());
    float radius = diameter / 2.0;
    
    int hourTickHeight = fmax(MINIMUM_HOUR_TICK_HEIGHT,radius / 30.);
    int hourTickWidth = fmax(MINIMUM_HOUR_TICK_WIDTH,radius / 10.);
    int minuteTickHeight = fmax(MINIMUM_MINUTE_TICK_WIDTH,radius / 60.);
    int minuteTickWidth = fmax(MINIMUM_MINUTE_TICK_WIDTH,radius / 20.);
    int labelRectSize = fmax(10, radius / 4.);
    int hourArmLength = fmax(2, radius / 3.);
    int hourArmWidth = fmax(2, radius / 20.);
    int minuteArmLength = fmax(5, radius - hourTickWidth - labelRectSize);
    int minuteArmWidth = fmax(2, radius / 30.);
    
    // Initialize context
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    
    // Adjust painter matrix for drawing in the center of the widget bounds
    
    painter.translate((width() - diameter) / 2.,(height() - diameter) / 2.);
    
    // Draw background
    
    painter.setPen(QPen(Qt::transparent,0));

    painter.setBrush(backgroundBrush);
    painter.drawEllipse(0, 0, diameter, diameter);
    
    // Draw hour ticks and labels
    
    for(int i = 1; i <= NUMBER_OF_HOURS; i++)
    {
        // Draw tick
        
        float angle = 360.0 / NUMBER_OF_HOURS * i - 90;
        
        drawTick(&painter, radius, angle, hourTickWidth, hourTickHeight, &this->hourTickBrush);
        
        // Draw label
        
        painter.save();
        
        // Adjust matrix
        
        painter.translate((radius - hourTickWidth - labelRectSize / 2.) * cos(RADIANT(angle)), (radius - hourTickWidth - labelRectSize / 2.) * sin(RADIANT(angle)));
        painter.translate(radius,radius);
        
        // Draw label
        
        painter.setPen(labelPen);
        QFont font(painter.font());
        font.setPointSizeF(fmax(MINIMUM_FONT_SIZE, radius / 6.));
        painter.setFont(font);
        painter.drawText(-labelRectSize / 2, -labelRectSize / 2., labelRectSize,labelRectSize,Qt::AlignVCenter | Qt::AlignHCenter,QString::number(i));
        
        painter.restore();
    }
    
    // Draw minute ticks
    
    for(int i = 0; i < NUMBER_OF_MINUTES; i++)
    {
        // Skip every 5th tick -> hour tick
        
        if(i % 5 == 0)
        {
            continue;
        }
        
        float angle = 360.0 / NUMBER_OF_MINUTES * i;
        
        drawTick(&painter, radius, angle, minuteTickWidth, minuteTickHeight, &this->minuteTickBrush);
    }
    
    // Draw hour arm
    
    float angle = 360.0 / NUMBER_OF_HOURS * time.hour() + 90 + 30 * time.minute() / 60.;
    drawArm(&painter, radius, angle, hourArmWidth, hourArmLength, &this->hourArmBrush);
    
    // Draw minute arm
    
    angle = 360.0 / NUMBER_OF_MINUTES * time.minute() + 90;
    
    drawArm(&painter, radius, angle, minuteArmWidth, minuteArmLength, &this->minuteArmBrush);
}

void AnalogClock::drawTick(QPainter *painter, int radius, float angle, int width, int height, QBrush* brush)
{
    painter->save();
    
    float angleRadiant = RADIANT(angle);
    
    // Adjust matrix
    
    painter->translate(radius * cos(angleRadiant), radius * sin(angleRadiant));
    painter->translate(radius,radius);
    painter->rotate(angle);
    painter->translate(-width, -height);
    
    // Draw tick

    painter->setBrush(*brush);
    
    painter->drawRect(0, 0, width, height);
    
    painter->restore();
}

void AnalogClock::drawArm(QPainter *painter, int radius, float angle, int width, int length, QBrush* brush)
{
    float armOffset = fmax(0, radius / 50);
    
    painter->save(); 
    
    // Adjust matrix
    
    painter->translate(radius,radius);
    painter->rotate(angle);
    
    // Draw arm
    
    painter->setBrush(*brush);
    
    painter->drawRect(-length + armOffset, -width / 2, length, width);
    
    painter->restore();
}

void AnalogClock::setHourArmBrush(QBrush brush)
{
    this->hourArmBrush = brush;
    repaint();
}

QBrush AnalogClock::getHourArmBrush()
{
    return this->hourArmBrush;
}

void AnalogClock::setMinuteArmBrush(QBrush brush)
{
    this->minuteArmBrush = brush;
    repaint();
}

QBrush AnalogClock::getMinuteArmBrush()
{
    return this->minuteArmBrush;
}

void AnalogClock::setHourTickBrush(QBrush brush)
{
    this->hourTickBrush = brush;
    repaint();
}

QBrush AnalogClock::getHourTickBrush()
{
    return this->hourTickBrush;
}

void AnalogClock::setMinuteTickBrush(QBrush brush)
{
    this->minuteTickBrush = brush;
    repaint();
}

QBrush AnalogClock::getMinuteTickBrush()
{
    return this->minuteTickBrush;
}

void AnalogClock::setLabelPen(QPen pen)
{
    this->labelPen = pen;
    repaint();
}

QPen AnalogClock::getLabelPen()
{
    return this->labelPen;
}

QBrush AnalogClock::getBackgroundBrush()
{
    return this->backgroundBrush;
}

void AnalogClock::setBackgroundBrush(QBrush brush)
{
    this->backgroundBrush = brush;
    repaint();
}

void AnalogClock::setTime(QTime time)
{
    this->setTime(time, false);
}

void AnalogClock::setTime(QTime time, bool animated)
{
    
    if(animated)
    {
        animation = new BasicAnimation(this,"time");
        ((BasicAnimation*)animation)->setEndValue(time);
        animation->start();
    }
    else
    {
        Clock::setTime(time);
    }
}
