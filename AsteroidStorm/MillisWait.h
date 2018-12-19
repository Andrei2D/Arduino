#ifndef MILLISWAIT_H

#define MILLISWAIT_H
#include <Arduino.h>

class MillisWait
{
    static unsigned long currentTime;
    unsigned long lastTime;
    unsigned long theDelay;
public:
    MillisWait();
    void setDelay(unsigned long aDelay);
    static void readTime();
    bool isOk ();
};

#endif ///MILLISWAIT_H