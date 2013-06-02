//
//  Quiz.cpp
//  guidev2
//
//  Created by Jens Meder on 23.05.13.
//
//

#include "Quiz.h"

Quiz::Quiz(QList<QuizQuestion*>* questions)
{
    _questions = questions;
    _currentQuestion = 0;
}

Quiz::Quiz(const Quiz& quiz)
{
    _questions = new QList<QuizQuestion*>(*quiz.questions());
    _currentQuestion = 0;
}

Quiz::Quiz()
{
    _questions = new QList<QuizQuestion*>();
    _currentQuestion = 0;
}

QList<QuizQuestion*>* Quiz::questions() const
{
    return _questions;
}

Quiz::~Quiz()
{
    delete _questions;
}

Quiz& Quiz::operator=(const Quiz &other)
{
    _questions->empty();
    _questions->append(*other.questions());
    return *this;
}

QuizQuestion* Quiz::nextQuestion()
{
    _currentQuestion++;
    _currentQuestion %= _questions->count();
    
    return _questions->at(_currentQuestion);
}

QuizQuestion* Quiz::currentQuestion()
{
    return _questions->at(_currentQuestion);
}

int Quiz::numberOfQuestionsLeft()
{
    return _questions->count() - _currentQuestion - 1;
}