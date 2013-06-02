//
//  QuizView.cpp
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#include "QuizView.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

QuizView::QuizView()
{
    QVBoxLayout* layout = new QVBoxLayout();
    setLayout(layout);
    
    
    
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    
    _checkAnswerButton = new QPushButton("Check");
    
    _mainMenuButton = new QPushButton("Main menu");
    buttonLayout->addWidget(_mainMenuButton);
    buttonLayout->addWidget(_checkAnswerButton);
    
    layout->addLayout(buttonLayout);
}

QPushButton* QuizView::mainMenuButton()
{
    return _mainMenuButton;
}

QPushButton* QuizView::checkAnswerButton()
{
    return _checkAnswerButton;
}