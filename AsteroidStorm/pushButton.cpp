#include "PushButton.h"

#define DEF_DEL 75

PushButton::PushButton (int aPin):buttonPin(aPin)
{
  pinMode (buttonPin, INPUT);
  lastTime = millis();
  delayTime = DEF_DEL;
  goodToGo = true;
  doIt = NULL;
}


void PushButton::setDelay(unsigned long aDelay)
{
  delayTime = aDelay;
}

void PushButton::checkDelay()
{
  currTime = millis();
  calcTime = currTime - lastTime;
  if( calcTime >= delayTime )
  {
    Serial.print("Passed time :");
    Serial.println(calcTime);
    goodToGo = true;
    lastTime = currTime;
  }
}

void PushButton::setAction (void (*toDO)(void))
{
  doIt = toDO;
}


void PushButton::onPress()
{
  if (digitalRead(buttonPin) == HIGH) 
  {
    checkDelay();
    if (goodToGo == false) return;
    
    doIt();
    goodToGo = false;   
  }
}
