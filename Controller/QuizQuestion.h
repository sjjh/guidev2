//
//  QuizQuestion.h
//  guidev2
//
//  Created by Jens Meder on 23.05.13.
//
//

#ifndef __guidev2__QuizQuestion__
#define __guidev2__QuizQuestion__

#include <iostream>
#include <QList>
#include <QTime>

class QuizQuestion
{
    protected:
    
        QuizQuestion();
    
    public:
    
        virtual bool isAnswerCorrect() = 0;
        virtual ~QuizQuestion();
};

#endif /* defined(__guidev2__QuizQuestion__) */
