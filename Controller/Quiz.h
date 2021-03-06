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
        Quiz(const Quiz&);
        Quiz();
    
        QList<QuizQuestion*>* questions() const;
    
        virtual ~Quiz();
    
        Quiz& operator= (const Quiz& other);
    
        QuizQuestion* currentQuestion();
        QuizQuestion* nextQuestion();
    
        int numberOfQuestionsLeft();
    
    private:
    
        QList<QuizQuestion*>* _questions;
    
        int _currentQuestion;
};

#endif /* defined(__guidev2__Quiz__) */
