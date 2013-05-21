#include "IntroView.h"
#include "Clocks/AnalogClock.h"
#include "Clocks/FlipClock.h"
#include <QIcon>
#include <QString>

IntroView::IntroView(QWidget *parent) :
    QWidget(parent)
{
    this->mainLayout = new QGridLayout();

    //create views
    this->analogClock = new AnalogClock();
    this->flipClock = new FlipClock();
    this->startButton = new QPushButton("Start");
    this->startButton->setDefault(true); //hit via Enter
    this->teacherButton = new QPushButton("");
    this->teacherButton->setIcon(QIcon(":/icon/preferences"));

    //add widgets to layout (row,col,rowSpan,ColSpan)
    this->mainLayout->setColumnMinimumWidth(0,10);//TODO:same width than right col
    this->mainLayout->addWidget(analogClock,0,1);
    this->mainLayout->addWidget(flipClock,0,2);
    this->mainLayout->addWidget(startButton,1,1,1,2);
    this->mainLayout->addWidget(teacherButton,1,3,Qt::AlignRight);
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
    this->startButton = NULL;
    this->teacherButton = NULL;
}

QPushButton* IntroView::getStartButton()
{
    return this->startButton;
}
