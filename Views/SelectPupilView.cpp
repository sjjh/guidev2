// number of columns with buttons to select pupils
// (a flexible number, using a flow layout, would be possible too, using the screen space more efficient
//  but then the position of a given name would change, making it harder to find it)
// one extra column left an right exist
#define MAX_PUPIL_COLS   5

#include "SelectPupilView.h"
#include <QGridLayout>
#include "ClockApp.h"
#include <QLabel>

SelectPupilView::SelectPupilView(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout* gridLayout = new QGridLayout();
    QVBoxLayout* boxLayout = new QVBoxLayout();
    
    pupilList = new QListView();
    pupilList->setMaximumWidth(200);
    pupilList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    gridLayout->addWidget(pupilList, 0, 0, Qt::AlignLeft);
    gridLayout->addLayout(boxLayout,0, 1, Qt::AlignLeft);
    
    boxLayout->addWidget(new QLabel("Your points"), Qt::AlignTop);
    
    setLayout(gridLayout);
}

SelectPupilView::~SelectPupilView()
{
}

QListView* SelectPupilView::getPupilList()
{
    return this->pupilList;
}
