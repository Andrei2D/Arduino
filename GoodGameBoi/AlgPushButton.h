#ifndef ANALOG_PUSH_BUTTON

#define ANALOG_PUSH_BUTTON
#include "Periferics.h"

#define JOY_BTN 1
#define PUSH_BTN 0

class AlgPushButton: public PushButton
{
    int type;
public:
    AlgPushButton(int Analog_Pin, int theType = PUSH_BTN ):PushButton(Analog_Pin)
    {
        type = theType;
    }
    void init (int Analog_Pin, int theType = PUSH_BTN )
    {
        buttonPin = Analog_pin;
        type = theType;
    }

    bool isPressed()
    {
        if(type == PUSH_BTN)
            return (analogRead(buttonPin) > 900) ? true : false;
        else return (analogRead(buttonPin) < 10) ? true : false;
    }
};

#endif // ANALOG_PUSH_BUTTON