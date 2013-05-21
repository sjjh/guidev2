#include "FlipClock.h"
#include <qpainter.h>
#include <QMouseEvent>

FlipClock::FlipClock()
{
    this->init();
}

FlipClock::FlipClock(QTime time)
{
    this->init();
    Clock::setTime(time);
}

void FlipClock::init()
{
    //Initialize the clock with default values
    backgroundBrush = QBrush(Qt::black);
    font = QFont();
}

FlipClock::~FlipClock()
{

}

void FlipClock::paintEvent(QPaintEvent *)
{
    // Initialize context

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Draw "case" of clock 10% offset of width/height()
    painter.setPen(QPen(Qt::black,0));//TODO: create attribute+method; rename background to clockBackground; move to Clock
    painter.setBrush(backgroundBrush);
    painter.drawRect(0, 0, width(), height());
    
    // Clip context
    
    QPainterPath path;
    path.addRect(QRect(digitXOffset, height()/2.0 - height()/100.0 * 0.5,width()/100.0*76,digitHeight / 60));
    
    QPainterPath rect;
    rect.addRect(this->rect());

    painter.setClipPath(rect.subtracted(path));


    // Draw flip charts for the digits
    // each digit chart has following dimensions: 17%*76% of width()
    //and the offset to the case of the clock is 2% of width()
    // distance between each charts: 1% and 6% of width() in the middle
    
    QLinearGradient digitBackgroundGradient;
    digitBackgroundGradient.setStart(0, digitYOffset);
    digitBackgroundGradient.setFinalStop(0, digitYOffset + digitHeight);
    digitBackgroundGradient.setColorAt(0, QColor("#585858"));
    digitBackgroundGradient.setColorAt(0.5, QColor("#282828"));
    digitBackgroundGradient.setColorAt(0.50000001, QColor("#454545"));
    digitBackgroundGradient.setColorAt(1, QColor("#2e2e2e"));
    
    QBrush digitBackgroundBrush(digitBackgroundGradient);
    painter.setBrush(digitBackgroundBrush);
    
    painter.drawPath(hourDigit1Path);
    painter.drawPath(hourDigit2Path);
    painter.drawPath(minuteDigit1Path);
    painter.drawPath(minuteDigit2Path);


    // Draw the numbers of the given time
    // Font configuration
    painter.setPen(QPen(Qt::white,0));

    // create FontMetrics for resized font

    painter.setFont(font);

    //first digit of hour
    painter.drawText(firstDigitRect,Qt::AlignCenter | Qt::AlignVCenter, QString::number(this->getTime().hour()/10));

    //second digit of hour

    painter.drawText(secondDigitRect, Qt::AlignCenter | Qt::AlignVCenter, QString::number(this->getTime().hour()%10));

    //colon between hh:mm
    QRect colonRect(secondDigitRect.x() + secondDigitRect.width(), digitYOffset, thirdDigitRect.x() - secondDigitRect.x() - secondDigitRect.width(), digitHeight);
    painter.drawText(colonRect, Qt::AlignCenter | Qt::AlignVCenter, ":");

    //first digit of minute
    // Calculate text center position into the screen using QFontMetrics class
    painter.drawText(thirdDigitRect, Qt::AlignCenter | Qt::AlignVCenter, QString::number(this->getTime().minute()/10));
    //second digit of minute
    // Calculate text center position into the screen using QFontMetrics class

    painter.drawText(forthDigitRect, Qt::AlignCenter | Qt::AlignVCenter, QString::number(this->getTime().minute()%10));


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

void FlipClock::setTime(QTime time, bool animated)
{
    if(animated)
    {
        Clock::setTime(time);
    }
    else
    {
        Clock::setTime(time);
    }
}

void FlipClock::resizeEvent(QResizeEvent * event)
{
    digitWidth = width()/100.0*17;
    digitHeight = 2* digitWidth;
    digitYOffset = height() / 2.0 - digitHeight / 2.0;
    digitXOffset = width()/100.0*12;
    digitCornerRadius = digitWidth / 20.0;
    digitSpacing = digitWidth / 10;
    
    hourDigit1Path = QPainterPath();
    hourDigit2Path = QPainterPath();
    minuteDigit1Path = QPainterPath();
    minuteDigit2Path = QPainterPath();
    
    firstDigitRect = QRect(digitXOffset, digitYOffset, digitWidth, digitHeight);
    hourDigit1Path.addRoundedRect(firstDigitRect, digitCornerRadius, digitCornerRadius);
    
    // second hour digit
    secondDigitRect = QRect(firstDigitRect.x() + digitWidth + digitSpacing, digitYOffset, digitWidth, digitHeight);
    hourDigit2Path.addRoundedRect(secondDigitRect, digitCornerRadius, digitCornerRadius);
    
    // first minute digit
    thirdDigitRect = QRect(secondDigitRect.x() + digitWidth + digitSpacing * 3, digitYOffset, digitWidth, digitHeight);
    minuteDigit1Path.addRoundedRect(thirdDigitRect, digitCornerRadius, digitCornerRadius);
    
    // second minute digit
    forthDigitRect = QRect(thirdDigitRect.x() + digitWidth + digitSpacing, digitYOffset, digitWidth, digitHeight);
    minuteDigit2Path.addRoundedRect(forthDigitRect, digitCornerRadius, digitCornerRadius);
    
    QFontMetrics fm(font);

    int pointSize = font.pointSizeF() * digitWidth / fm.width("0");

    font.setPointSize(pointSize);
}

void FlipClock::mouseReleaseEvent(QMouseEvent *event)
{ 
    int multiplier = -1;
    int numberOfSecondsToAdd = 0;
    
    if(event->pos().y() - digitYOffset < digitHeight / 2.0)
    {
        multiplier = 1;
    }
    
    if(hourDigit1Path.contains(event->pos()))
    {        
        numberOfSecondsToAdd = multiplier * 36000;
    }
    else if(hourDigit2Path.contains(event->pos()))
    {
        numberOfSecondsToAdd = multiplier * 3600;
    }
    else if(minuteDigit1Path.contains(event->pos()))
    {
        numberOfSecondsToAdd = multiplier * 600;
    }
    else if(minuteDigit2Path.contains(event->pos()))
    {
        numberOfSecondsToAdd = multiplier * 60;
    }
    
    time = time.addSecs(numberOfSecondsToAdd);
    repaint();
    
    emit(timeChanged(this));
}
