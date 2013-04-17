//
//  ViewController.h
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#ifndef __guidev2__ViewController__
#define __guidev2__ViewController__

#include <iostream>
#include <QWidget>

class ViewController
{
    protected:
        ViewController();
    
    private:
        ~ViewController();
        QWidget* view;
    
    public:
        QWidget* getView();
};

#endif /* defined(__guidev2__ViewController__) */
