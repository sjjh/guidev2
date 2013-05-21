//
//  NotificationCenter.cpp
//  guidev2
//
//  Created by Jens Meder on 17.04.13.
//
//

#include "NotificationCenter.h"

NotificationCenter::NotificationCenter()
{
    
}

NotificationCenter::~NotificationCenter()
{
    
}

NotificationCenter* NotificationCenter::instance()
{
    static NotificationCenter* instance = NULL;
    
    if(!instance)
    {
        instance = new NotificationCenter();
    }
    
    return instance;
}