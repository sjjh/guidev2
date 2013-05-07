//
//  Created by Jens Meder on 17.04.13.
//

#ifndef __guidev2__ViewController__
#define __guidev2__ViewController__

#include <iostream>
#include <QWidget>
#include <QObject>

/**
 * Base class for all view controllers
 */
class ViewController: public QObject
{
    protected:
    
        /**
         * Creates a new ViewController instance.
         */
        ViewController();
    
    protected:
    
        QWidget* view;
    
    public:
    
        /**
         * Returns the view the viewController is responsible for.
         */
        QWidget* getView();
    
        /**
        * Destroys the ViewController object and performs necessary clean up.
        */
        ~ViewController();
};

#endif /* defined(__guidev2__ViewController__) */
