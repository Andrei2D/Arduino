#ifndef JoiceStick_h

#define JoiceStick_h 


#include <Arduino.h>
#include "MillisWait.h"

  class JoiceStick
  {
  int joyX;
  int joyY;
  
    /*
     * Pointeri catre functiile ce trebuie apelate cand se misca
     *  joystickul in anumite pozitii
     */   
  void (*goLeft)(void), (*goRight)(void);
  void (*goUp)(void), (*goDown)(void);

  MillisWait joyWait;

public:
  JoiceStick();
  JoiceStick (int, int);
  
  void setDelay (unsigned long aDelay);
  
   //Resetare pointeri catre functii la NULL si delay la 100
   
  void resetVars ();

  ///Init VERTICAL
  void initV (void (*left)(), void (*right)());

  ///Init HORIZONTAL
  void initH (void (*down)(), void (*up)());

  int isX ();
  int isY ();
  
  ///Check VERTICAL
  void checkV ();
  ///Check HORIZONTAL
  void checkH ();

  /*
    HORIZONTAL si VERTICAL sunt axele joystickului carora
      le sunt atribuite anumite functii void care sunt chemate
      respectand delay-ul

  */
  

};

#endif //JoiceStick.h 
