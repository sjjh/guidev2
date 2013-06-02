//
//  QuizViewController.h
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#ifndef __guidev2__QuizViewController__
#define __guidev2__QuizViewController__

#include <iostream>
#include "ViewController.h"
#include "Quiz.h"
#include "AnalogDigitalAdjustViewController.h"

class QuizViewController: public ViewController
{
    Q_OBJECT

    public:
    
        QuizViewController(ClockApp* app, Quiz quiz);
    
    private:
    
        Quiz _quiz;
    
        AnalogDigitalAdjustViewController* _quizQuestionViewController;
    
    public slots:
    
        void checkAnswer();
};

#endif /* defined(__guidev2__QuizViewController__) */
