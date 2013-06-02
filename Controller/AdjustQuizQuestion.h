//
//  AdjustQuizQuestion.h
//  guidev2
//
//  Created by Jens Meder on 23.05.13.
//
//

#ifndef __guidev2__AdjustQuizQuestion__
#define __guidev2__AdjustQuizQuestion__

#include <iostream>
#include "QuizQuestion.h"

class AdjustQuizQuestion: public QuizQuestion
{
    private:
    
        QTime _answer;
        QTime _correctAnswer;
    
    public:
    
        AdjustQuizQuestion(QTime);
        bool isAnswerCorrect();
        void setAnswer(QTime);
        QTime correctAnswer();
        virtual ~AdjustQuizQuestion();
};

#endif /* defined(__guidev2__AdjustQuizQuestion__) */
