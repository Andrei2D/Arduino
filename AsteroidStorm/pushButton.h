#ifndef BUTTON_H

#define BUTTON_H

#include "MillisWait.h"
#include <Arduino.h>

class PushButton
{
  const int buttonPin;
  void (*doIt)(void);   //Functie chemata in metoda ifPressed
  MillisWait btnWait;   
public:
  PushButton (int);
  void setDelay (unsigned long);  //Seteaza delay custom
  bool isPressed ();              //Verifica daca este apasat 
  void ifPressed ();              //Actioneaza daca este apasat si a trecut delay-ul necesar
  void setAction (void (*toDO)(void));  //Seteaza functia de actiune 
};

#endif /// BUTTON_H
