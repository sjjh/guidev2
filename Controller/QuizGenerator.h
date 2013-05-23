//
//  QuizGenerator.h
//  guidev2
//
//  Created by Jens Meder on 23.05.13.
//
//

#ifndef __guidev2__QuizGenerator__
#define __guidev2__QuizGenerator__

#include <iostream>
#include "Quiz.h"

class QuizGenerator
{
    public:
   
        static Quiz generateEasyQuiz();
        static Quiz generateMediumQuiz();
        static Quiz generateHardQuiz();

    private:
    
        QuizGenerator();
};

#endif /* defined(__guidev2__QuizGenerator__) */
