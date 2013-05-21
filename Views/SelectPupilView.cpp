// number of columns with buttons to select pupils
// (a flexible number, using a flow layout, would be possible too, using the screen space more efficient
//  but then the position of a given name would change, making it harder to find it)
// one extra column left an right exist
#define MAX_PUPIL_COLS   5

#include "SelectPupilView.h"
#include <QGridLayout>
#include <QList>
#include <QPushButton>
#include "ClockApp.h"

SelectPupilView::SelectPupilView(QWidget *parent) :
    QWidget(parent)
{
    this->mainLayout = new QGridLayout();

    //current row
    int curRow = 0;
    //buttons to select pupils
    this->pupilButtons = new QList<QPushButton*>();

    //home-button
    this->homeButton = new QPushButton("");
    this->homeButton->setIcon(QIcon(":/icon/go-home"));

    //add widget bottom-left to layout (row,col,rowSpan,colspan)
    this->mainLayout->addWidget(homeButton,curRow,0,Qt::AlignLeft);
}

SelectPupilView::~SelectPupilView()
{
}
