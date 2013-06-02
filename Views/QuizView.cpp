//
//  QuizView.cpp
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#include "QuizView.h"
#include <QVBoxLayout>

QuizView::QuizView()
{
    QVBoxLayout* layout = new QVBoxLayout();
    setLayout(layout);
    
    _mainMenuButton = new QPushButton("Main menu");
    layout->addWidget(_mainMenuButton);
}

QPushButton* QuizView::mainMenuButton()
{
    return _mainMenuButton;
}