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
#include <QMouseEvent>
#include <math.h>

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
    
    diameter = std::min(width(),height());
    radius = diameter / 2.0;
    
    draggingHourArm = false;
    draggingMinuteArm = false;
    
    this->createArms();
}

AnalogClock::~AnalogClock()
{
    
}

void AnalogClock::paintEvent(QPaintEvent *)
{
    // Calculate the size properties relative to the clocks size
    
    int hourTickHeight = fmax(MINIMUM_HOUR_TICK_HEIGHT,radius / 30.);
    int hourTickWidth = fmax(MINIMUM_HOUR_TICK_WIDTH,radius / 10.);
    int minuteTickHeight = fmax(MINIMUM_MINUTE_TICK_WIDTH,radius / 60.);
    int minuteTickWidth = fmax(MINIMUM_MINUTE_TICK_WIDTH,radius / 20.);
    int labelRectSize = fmax(10, radius / 4.);
    
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

    drawArm(&painter, radius, angle, &hourArmPath, &this->hourArmBrush);
    
    // Draw minute arm
    
    angle = 360.0 / NUMBER_OF_MINUTES * time.minute() + 90 + 6 * time.second() / 60.;
        
    drawArm(&painter, radius, angle, &minuteArmPath, &this->minuteArmBrush);
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

void AnalogClock::drawArm(QPainter *painter, int radius, float angle, QPainterPath* path, QBrush* brush)
{      
    // Adjust matrix
    
    QMatrix mat;
    mat.translate(radius, radius);
    mat.rotate(angle);
    
    // Draw arm
    
    painter->save();
    
    painter->setBrush(*brush);
    
    painter->drawPath(mat.map(*path));
    
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

void AnalogClock::createArms()
{   
    int hourTickWidth = fmax(MINIMUM_HOUR_TICK_WIDTH,radius / 10.);

    int labelRectSize = fmax(10, radius / 4.);
    
    int hourArmLength = fmax(2, radius / 3.);
    int hourArmWidth = fmax(2, radius / 20.);
    int minuteArmLength = fmax(5, radius - hourTickWidth - labelRectSize);
    int minuteArmWidth = fmax(2, radius / 30.);
    
    hourArmPath = QPainterPath();
    hourArmPath.addRect(-hourArmLength + fmax(0, radius / 50), -hourArmWidth / 2, hourArmLength, hourArmWidth);

    minuteArmPath = QPainterPath();
    minuteArmPath.addRect(-minuteArmLength + fmax(0, radius / 50), -minuteArmWidth / 2, minuteArmLength, minuteArmWidth);

}

void AnalogClock::resizeEvent (QResizeEvent* event)
{
    diameter = std::min(width(),height());
    radius = diameter / 2.0;
    
    this->createArms();
}

void AnalogClock::mousePressEvent (QMouseEvent* event)
{
    float angle = 360.0 / NUMBER_OF_HOURS * time.hour() + 90 + 30 * time.minute() / 60.;

    QMatrix mat;
    mat.translate((width() - diameter) / 2.,(height() - diameter) / 2.);
    mat.translate(radius, radius);
    mat.rotate(angle);
    
    if (mat.map(hourArmPath).contains(event->pos()))
    {
        draggingHourArm = true;
        return;
    }
    
    // Draw minute arm
    
    mat.rotate(-angle);
    angle = 360.0 / NUMBER_OF_MINUTES * time.minute() + 90 + 6 * time.second() / 60.;
    mat.rotate(angle);
    
    if (mat.map(minuteArmPath).contains(event->pos()))
    {
        draggingMinuteArm = true;
    }
}

void AnalogClock::mouseMoveEvent (QMouseEvent* event)
{
    float x1 = event->pos().x() - width() / 2.0;
    float y1 = -(event->pos().y() - height() / 2.0);    
    
    float v = x1 < 0?M_PI:0;
    float e = v + 0.5*M_PI - atanf(y1 / x1);
    
    if(draggingMinuteArm)
    {
        float a = 2 * M_PI / NUMBER_OF_MINUTES * time.minute();

        float x2 = sinf(a);
        float y2 = cosf(a);
        
        float d = acosf((x1*x2 + y1*y2) / (sqrt(x1 * x1 + y1 * y1)*sqrt(x2 * x2 + y2 * y2)));

        if((e - a > 0 && fabs(e - a) < 1) || e - a < -4)
        {
            this->setTime(time.addSecs(d/M_PI * 1800));
            emit(timeChanged(this));
        }
        else
        {
            this->setTime(time.addSecs(-d/M_PI * 1800));
            emit(timeChanged(this));
        }
    }
    else if(draggingHourArm)
    {
        float a = 2* M_PI / NUMBER_OF_HOURS * time.hour();
        float x2 = sinf(a);
        float y2 = cosf(a);
        
        float d = acosf((x1*x2 + y1*y2) / (sqrt(x1 * x1 + y1 * y1)*sqrt(x2 * x2 + y2 * y2)));
        
        std::cout << e -a  << std::endl;

        if(d > M_PI / 12.0 && (e - a > 0 || a > M_PI))
        {
            this->setTime(time.addSecs(3600));
            emit(timeChanged(this));
        }
    }
}


void AnalogClock::mouseReleaseEvent (QMouseEvent* event)
{    
    draggingHourArm = false;
    draggingMinuteArm = false;
}
