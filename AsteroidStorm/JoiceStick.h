#ifndef JoiceStick_h

#define JoiceStick_h 

#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
///Some includes so there is no " 'A0' was not delcared " error

  class JoiceStick
  {
  const int joyX;
  const int joyY;
  
    /*
     * Pointeri catre functiile ce trebuie apelate cand se misca
     *  joystickul in anumite pozitii
     */
  void (*goLeft)(void), (*goRight)(void);
  void (*goUp)(void), (*goDown)(void);
  int theDelay;

public:
  
  JoiceStick();
  JoiceStick(int, int);
  
  void setDelay (int aDelay);
  
   //Resetare pointeri catre functii la NULL si delay la 100
   
  void resetVars();

  ///Init VERTICAL
  void initV (void (*left)(), void (*right)());

  ///Init HORIZONTAL
  void initH ( void (*down)(), void (*up)());

  int isX ();
  int isY ();
  
  ///Check VERTICAL
  void checkV();
  
  ///Check HORIZONTAL
  void checkH();

};

#endif //JoiceStick.h 
