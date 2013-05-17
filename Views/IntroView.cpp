#include "IntroView.h"
#include "Clocks/AnalogClock.h"
#include "Clocks/FlipClock.h"
#include <QIcon>
#include <QString>

IntroView::IntroView(QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QGridLayout();

    //create views
    analogClock = new AnalogClock();
    flipClock = new FlipClock();
    startButton = new QPushButton("Start");
    startButton->setDefault(true); //hit via Enter
    teacherButton = new QPushButton("");
    teacherButton->setIcon(QIcon(":/icon/preferences"));

    //add widget to layout (row,col,rowSpan,ColSpan)
    mainLayout->setColumnMinimumWidth(0,10);//TODO:same width than right col
    mainLayout->addWidget(analogClock,0,1);
    mainLayout->addWidget(flipClock,0,2);
    mainLayout->addWidget(startButton,1,1,1,2);
    mainLayout->addWidget(teacherButton,1,3,Qt::AlignRight);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(1,2);
    mainLayout->setColumnStretch(2,2);
    mainLayout->setColumnStretch(3,1);

    setLayout(mainLayout);
}

IntroView::~IntroView() {

}
