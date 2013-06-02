//
//  QuizViewController.cpp
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#include "QuizViewController.h"
#include "QuizView.h"
#include <QLayout>
#include <QMessageBox>

QuizViewController::QuizViewController(ClockApp* app, Quiz quiz):ViewController(app)
{
    QuizView* quizView = new QuizView();
    _quiz = quiz;
    
    view = quizView;
    
    connect(quizView->mainMenuButton(),SIGNAL(clicked()),app,SLOT(quitQuiz()));
    
    AdjustQuizQuestion* firstQuestion = static_cast<AdjustQuizQuestion*>(_quiz.currentQuestion());
    _quizQuestionViewController = new AnalogDigitalAdjustViewController(app, firstQuestion);
    quizView->layout()->addWidget(_quizQuestionViewController->getView());
    
    connect(quizView->checkAnswerButton(), SIGNAL(clicked()), this, SLOT(checkAnswer()));
}

void QuizViewController::checkAnswer()
{
    QMessageBox msgBox;
    msgBox.setText((_quiz.currentQuestion()->isAnswerCorrect() ? "correct":"wrong"));
    msgBox.exec();
    
    if(_quiz.currentQuestion()->isAnswerCorrect())
    {
        if(_quiz.numberOfQuestionsLeft() > 0)
        {
            AdjustQuizQuestion* question = static_cast<AdjustQuizQuestion*>(_quiz.nextQuestion());
            _quizQuestionViewController->setQuestion(question);
        }
        else
        {
            app->quitQuiz();
        }
    }
}
