#ifndef __guidev2__IntroView__
#define __guidev2__IntroView__

#include <QGridLayout>
#include <QWidget>
#include "Clocks/Clock.h"
#include <QPushButton>

class IntroView : public QWidget
{
    Q_OBJECT
public:
    IntroView(QWidget *parent = 0);
    ~IntroView();

private:
    QGridLayout *mainLayout;
    Clock *analogClock;
    Clock *flipClock;
    QPushButton *startButton;
    QPushButton *teacherButton;
    
signals:
    
public slots:
    
};

#endif // __guidev2__IntroView__
