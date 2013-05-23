//
//  Quiz.h
//  guidev2
//
//  Created by Jens Meder on 23.05.13.
//
//

#ifndef __guidev2__Quiz__
#define __guidev2__Quiz__

#include <iostream>
#include "QuizQuestion.h"
#include <QList>

class Quiz
{
    public:
    
        Quiz(QList<QuizQuestion*>*);
    
        QList<QuizQuestion*>* questions();
    
        virtual ~Quiz();
    
    private:
    
        QList<QuizQuestion*>* _questions;
};

#endif /* defined(__guidev2__Quiz__) */
