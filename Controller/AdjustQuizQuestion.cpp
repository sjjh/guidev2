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
    return _answer.hour() % 12 == _correctAnswer.hour() % 12 && _answer.minute() == _correctAnswer.minute();
}

void AdjustQuizQuestion::setAnswer(QTime answer)
{
    _answer = answer;
}

AdjustQuizQuestion::AdjustQuizQuestion(QTime correctAnswer)
{
    _correctAnswer = correctAnswer;
    _answer = QTime(0,0,0);
}

AdjustQuizQuestion::~AdjustQuizQuestion()
{
}

QTime AdjustQuizQuestion::correctAnswer()
{
    return _correctAnswer;
}