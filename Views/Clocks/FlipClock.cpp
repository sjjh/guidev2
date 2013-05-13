#include "FlipClock.h"
#include <qpainter.h>

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
}

FlipClock::~FlipClock()
{

}

void FlipClock::paintEvent(QPaintEvent *)
{
    qreal digitWidth = width()/100.0*17;
    qreal digitHeight = 2* digitWidth;
    qreal digitYOffset = height() / 2.0 - digitHeight / 2.0;
    qreal digitXOffset = width()/100.0*12;
    qreal digitCornerRadius = digitWidth / 20.0;
    qreal digitSpacing = digitWidth / 10;

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
    
    // first hour digit
    QRect firstDigitRect(digitXOffset, digitYOffset, digitWidth, digitHeight);
    painter.drawRoundedRect(firstDigitRect, digitCornerRadius, digitCornerRadius);
    
    // second hour digit
    QRect secondDigitRect(firstDigitRect.x() + digitWidth + digitSpacing, digitYOffset, digitWidth, digitHeight);
    painter.drawRoundedRect(secondDigitRect, digitCornerRadius, digitCornerRadius);
    
    // first minute digit
    QRect thirdDigitRect(secondDigitRect.x() + digitWidth + digitSpacing * 3, digitYOffset, digitWidth, digitHeight);
    painter.drawRoundedRect(thirdDigitRect, digitCornerRadius, digitCornerRadius);
    
    // second minute digit
    QRect forthDigitRect(thirdDigitRect.x() + digitWidth + digitSpacing, digitYOffset, digitWidth, digitHeight);
    painter.drawRoundedRect(forthDigitRect, digitCornerRadius, digitCornerRadius);


    // Draw the numbers of the given time
    // Font configuration
    painter.setPen(QPen(Qt::white,0));
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
        if ((x > digitWidth) || (y > digitHeight))
        {
            // saving maximum possible size of font
            font.setPointSize(i-1);
            break;
        }
    }

    // create FontMetrics for resized font
    QFontMetrics fm(font);
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
