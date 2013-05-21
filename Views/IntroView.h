#ifndef __guidev2__IntroView__
#define __guidev2__IntroView__

#include <QGridLayout>
#include <QWidget>
#include "Clocks/Clock.h"
#include <QPushButton>
#include "AnalogClock.h"
#include "FlipClock.h"

class IntroView : public QWidget
{
    Q_OBJECT
public:
    IntroView(QWidget *parent = 0);
    ~IntroView();
    
    QPushButton* getStartButton();
    
    AnalogClock* getAnalogClock();
    FlipClock* getFlipClock();

private:
    QGridLayout *mainLayout;
    AnalogClock *analogClock;
    FlipClock *flipClock;
    QPushButton *startButton;
    QPushButton *teacherButton;
    
signals:
    
public slots:
    
};

#endif // __guidev2__IntroView__
