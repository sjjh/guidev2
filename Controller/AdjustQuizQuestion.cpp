//
//  AdjustQuizQuestion.cpp
//  guidev2
//
//  Created by Jens Meder on 23.05.13.
//
//

#include "AdjustQuizQuestion.h"

bool AdjustQuizQuestion::isAnswerCorrect()
{
    return _answer != NULL && _answer->secsTo(_correctAnswer) == 0;
}

void AdjustQuizQuestion::setAnswer(QTime* answer)
{
    _answer = answer;
}

AdjustQuizQuestion::AdjustQuizQuestion(QTime correctAnswer)
{
    _correctAnswer = correctAnswer;
    _answer = NULL;
}

AdjustQuizQuestion::~AdjustQuizQuestion()
{
}

QTime AdjustQuizQuestion::correctAnswer()
{
    return _correctAnswer;
}