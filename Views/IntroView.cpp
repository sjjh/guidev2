#include "IntroView.h"
#include <QIcon>
#include <QString>

IntroView::IntroView(QWidget *parent) :
    QWidget(parent)
{
    this->mainLayout = new QGridLayout();

    //create views
    this->analogClock = new AnalogClock();
    this->flipClock = new FlipClock();

    //add widgets to layout (row,col,rowSpan,ColSpan)
    this->mainLayout->setColumnMinimumWidth(0,10);//TODO:same width than right col
    this->mainLayout->addWidget(analogClock,0,1);
    this->mainLayout->addWidget(flipClock,0,2);
    this->mainLayout->setColumnStretch(0,1);
    this->mainLayout->setColumnStretch(1,2);
    this->mainLayout->setColumnStretch(2,2);
    this->mainLayout->setColumnStretch(3,1);

    this->setLayout(mainLayout);
}

IntroView::~IntroView() {
    this->mainLayout = NULL;
    this->analogClock = NULL;
    this->flipClock = NULL;
}

AnalogClock* IntroView::getAnalogClock()
{
    return this->analogClock;
}

FlipClock* IntroView::getFlipClock()
{
    return this->flipClock;
}
