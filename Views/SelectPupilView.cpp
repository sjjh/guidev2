// number of columns with buttons to select pupils
// (a flexible number, using a flow layout, would be possible too, using the screen space more efficient
//  but then the position of a given name would change, making it harder to find it)
// one extra column left an right exist
#define MAX_PUPIL_COLS   5

#include "SelectPupilView.h"
#include <QGridLayout>
#include "ClockApp.h"

SelectPupilView::SelectPupilView(QWidget *parent) :
    QWidget(parent)
{
    setLayout(new QGridLayout());

    pupilList = new QListView();
    
    layout()->addWidget(pupilList);
}

SelectPupilView::~SelectPupilView()
{
}

QListView* SelectPupilView::getPupilList()
{
    return this->pupilList;
}
