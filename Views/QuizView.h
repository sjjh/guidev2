//
//  QuizView.h
//  guidev2
//
//  Created by Jens Meder on 02.06.13.
//
//

#ifndef __guidev2__QuizView__
#define __guidev2__QuizView__

#include <iostream>
#include <QWidget>
#include <QPushButton>

class QuizView: public QWidget
{
    public:
    
        QuizView();
    
        QPushButton* mainMenuButton();
    
    private:
    
        QPushButton* _mainMenuButton;
};

#endif /* defined(__guidev2__QuizView__) */
