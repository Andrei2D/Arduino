#ifndef BUTTON_H

#define BUTTON_H

#include "MillisWait.h"
#include <Arduino.h>

class PushButton
{
  const int buttonPin;
  void (*doIt)(void);

  MillisWait btnWait;
public:
  PushButton (int);
  void setDelay(unsigned long);
  bool isPressed();
  void ifPressed();
  void setAction(void (*toDO)(void));
};

#endif /// BUTTON_H
