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
}

Quiz::Quiz(const Quiz& quiz)
{
    _questions = new QList<QuizQuestion*>(*quiz.questions());
}

Quiz::Quiz()
{
    _questions = new QList<QuizQuestion*>();
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