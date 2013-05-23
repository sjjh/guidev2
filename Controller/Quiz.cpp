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

QList<QuizQuestion*>* Quiz::questions()
{
    return _questions;
}

Quiz::~Quiz()
{
    delete _questions;
}