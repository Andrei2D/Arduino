#ifndef BUTTON_H

#define BUTTON_H

#include <Arduino.h>

class PushButton
{
  const int buttonPin;
  void (*doIt)(void);

  bool goodToGo;
  unsigned long delayTime;
  unsigned long lastTime;

  unsigned long currTime, calcTime;
public:
  PushButton (int);
  void setDelay(unsigned long);
  void checkDelay();
  void onPress();
  void setAction(void (*toDO)(void));
};

#endif /// BUTTON_H
