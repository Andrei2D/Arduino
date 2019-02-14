#include "MillisWait.h"
#define THE_DEF_DELAY 50

    MillisWait::MillisWait ()
    {
        theDelay = THE_DEF_DELAY;
        readTime ();
        lastTime = millis ();
    }

    MillisWait::MillisWait (unsigned long aDelay)
    {
        theDelay = aDelay;
        readTime ();
        lastTime = millis();
    }


    unsigned long MillisWait::currentTime = millis ();
    
    void MillisWait::setDelay (unsigned long aDelay)
    {
        theDelay = aDelay;
    }
    
    void MillisWait::readTime ()
    {
       currentTime = millis (); 
    }
    
    bool MillisWait::isOk ()
    {
       if (currentTime - lastTime > theDelay)
            {
            lastTime = currentTime;
            return true;
            }
        return false;
    }
