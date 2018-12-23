#include "PushButton.h"

#define DEF_BTN_DELAY 100


PushButton::PushButton (int aPin):buttonPin(aPin)
{
  pinMode (buttonPin, INPUT);
  btnWait.setDelay(DEF_BTN_DELAY);
  doIt = NULL;
}

void PushButton::setDelay(unsigned long aDelay)
{
  btnWait.setDelay (aDelay);
}


void PushButton::setAction (void (*toDO)(void))
{
  doIt = toDO;
}
 
bool PushButton::isPressed()
{
  return digitalRead(buttonPin) == HIGH;
}

void PushButton::ifPressed()
{
  if (isPressed() && btnWait.isOk()) 
  {
    doIt();
  }
}
