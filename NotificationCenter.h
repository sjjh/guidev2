//
//  NotificationCenter.h
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#ifndef __guidev2__NotificationCenter__
#define __guidev2__NotificationCenter__

#include <iostream>
#include <QObject>

/**
 * Represents a notification center for distributing application wide messages between objects using signals and slots.
 */
class NotificationCenter: public QObject
{
    public:
    
        /**
        * Destroys the NotificationCenter object and performs necessary clean up.
        */
        ~NotificationCenter();
    
        /**
         * Returns the only instance of this class
         */
         static NotificationCenter* instance();
    
    private:
    
        /**
         * Creates a new NotificationCenter instance.
         */
        NotificationCenter();   
};

#endif /* defined(__guidev2__NotificationCenter__) */
