//
//  MainMenuViewController.h
//  guidev2
//
//  Created by Jens Meder on 21.05.13.
//
//

#ifndef __guidev2__MainMenuViewController__
#define __guidev2__MainMenuViewController__

#include <iostream>
#include "ViewController.h"

class MainMenuViewController: public ViewController
{
    public:
    
        MainMenuViewController(ClockApp*);
        virtual ~MainMenuViewController();
    
    private:
    
        IntroViewController* introViewController;
        SelectPupilViewController* selectPupilViewController;
};

#endif /* defined(__guidev2__MainMenuViewController__) */
