//
//  QuizGenerator.cpp
//  guidev2
//
//  Created by Jens Meder on 23.05.13.
//
//

#define NUMBER_OF_QUESTIONS 10

#include "QuizGenerator.h"
#include "AdjustQuizQuestion.h"
#include <stdlib.h>
#include <time.h>

Quiz QuizGenerator::generateEasyQuiz()
{
    QList<QuizQuestion*>* questions = new QList<QuizQuestion*>();
    
    srand ((unsigned int)time(NULL));
    
    for (int i = 0; i < NUMBER_OF_QUESTIONS; i++)
    {       
        int hour = rand() % 12 + 1;
        QTime correctAnswer(hour,0,0);
        AdjustQuizQuestion* question = new AdjustQuizQuestion(correctAnswer);
        
        questions->append(question);
    }
    
    return questions;
}

Quiz QuizGenerator::generateMediumQuiz()
{    
    QList<QuizQuestion*>* questions = new QList<QuizQuestion*>();
    
    srand ((unsigned int)time(NULL));
    
    for (int i = 0; i < NUMBER_OF_QUESTIONS; i++)
    {  
        int hour = rand() % 24;
        int minute = (rand() % 4) * 15;
        QTime correctAnswer(hour,minute,0);
        AdjustQuizQuestion* question = new AdjustQuizQuestion(correctAnswer);
        
        questions->append(question);
    }
    
    return questions;
}

Quiz QuizGenerator::generateHardQuiz()
{
    QList<QuizQuestion*>* questions = new QList<QuizQuestion*>();
    
    srand ((unsigned int)time(NULL));
    
    for (int i = 0; i < NUMBER_OF_QUESTIONS; i++)
    {
        int hour = rand() % 24;
        int minute = rand() % 60;
        QTime correctAnswer(hour,minute,0);
        AdjustQuizQuestion* question = new AdjustQuizQuestion(correctAnswer);
        
        questions->append(question);
    }
    
    return questions;
}
