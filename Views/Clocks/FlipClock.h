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
    Q_OBJECT
    
    signals:
    
        void timeChanged(Clock*);

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

        /**
         * Sets the brush used to draw the background of the clock.
         */
        void setBackgroundBrush(QBrush brush);

        /**
         * Returns the brush used to draw background of the clock.
         */
        QBrush getBackgroundBrush();
    
        virtual void setTime(QTime, bool = false);

        virtual void paintEvent(QPaintEvent*);
    
        void resizeEvent(QResizeEvent * event);
    
        void mouseReleaseEvent(QMouseEvent * event);

    private:
        QBrush  backgroundBrush;
        QFont font;
        qreal digitWidth;
        qreal digitHeight;
        qreal digitYOffset;
        qreal digitXOffset;
        qreal digitCornerRadius;
        qreal digitSpacing;
        QRect firstDigitRect;
        QRect secondDigitRect;
        QRect thirdDigitRect;
        QRect forthDigitRect;
    
        QPainterPath hourDigit1Path;
        QPainterPath hourDigit2Path;
        QPainterPath minuteDigit1Path;
        QPainterPath minuteDigit2Path;

    protected:

        void init();
};

#endif // __guidev2__FlipClock__
