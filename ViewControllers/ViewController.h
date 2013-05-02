//
//  Created by Jens Meder on 17.04.13.
//

#ifndef __guidev2__ViewController__
#define __guidev2__ViewController__

#include <iostream>
#include <QWidget>

/**
 * Base class for all view controllers
 */
class ViewController
{
    protected:
    
        /**
         * Creates a new ViewController instance.
         */
        ViewController();
    
    private:
    
        QWidget* view;
    
    public:
    
        /**
         * Returns the view the view controller is responsible for.
         */
        QWidget* getView();
    
        /**
        * Destroys the ViewController object and performs necessary clean up.
        */
        ~ViewController();
};

#endif /* defined(__guidev2__ViewController__) */
