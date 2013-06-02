//
//  AnalogDigitalView.cpp
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#include "AnalogDigitalView.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

AnalogDigitalView::AnalogDigitalView()
{
    _analog = new AnalogClock();
    _flip = new FlipClock();
    
    QHBoxLayout* layout = new QHBoxLayout();
    
    layout->addWidget(_analog);
    layout->addWidget(_flip);
    
    setLayout(layout);
}

AnalogClock* AnalogDigitalView::analogClock()
{
    return _analog;
}

FlipClock* AnalogDigitalView::flipClock()
{
    return _flip;
}