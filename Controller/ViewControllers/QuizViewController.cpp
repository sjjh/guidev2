//
//  QuizViewController.cpp
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#include "QuizViewController.h"
#include "QuizView.h"

QuizViewController::QuizViewController(ClockApp* app, Quiz quiz):ViewController(app)
{
    QuizView* quizView = new QuizView();
    _quiz = quiz;
    
    view = quizView;
    
    connect(quizView->mainMenuButton(),SIGNAL(clicked()),app,SLOT(quitQuiz()));
}
