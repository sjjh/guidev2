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

class QuizViewController: public ViewController
{
    public:
    
        QuizViewController(ClockApp* app, Quiz quiz);
    
    private:
    
        Quiz _quiz;
};

#endif /* defined(__guidev2__QuizViewController__) */
