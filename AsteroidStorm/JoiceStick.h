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
    /*
     * Memorarea pinilor la care sunt conectati
     *  pinii corespunzatori coordonatelor modulelor
     */
  const int joyX;
  const int joyY;
  
    /*
     * Pointeri catre functiile ce trebuie apelate cand se misca
     *  joystickul in anumite pozitii
     */
  void (*goLeft)(void), (*goRight)(void);
  void (*goUp)(void), (*goDown)(void);
  
    /*
     * Delay-ul intre 2 actiuni consecutive
     */
  int theDelay;

public:
  
  JoiceStick();
  JoiceStick(int, int);

  /*
   * Setare delay custom
   */
  void setDelay (int aDelay);
  
  /*
   * Resetare pointeri catre functii la NULL si delay la 100
   */
  void resetVars();

  /*
   * Initializare functii pentru axa X
   */
  void initX(void (*left)(), void (*right)());

  /*
   * Initializare functii pentru axa Y
   */
  void initY ( void (*down)(), void (*up)());

  /*
   * Returnare pozitie axa X si Y
   *  Stanga = -1
   *  Dreapta = 1
   *  Nici una = 0
   */
  int isX ();
  int isY ();

  /*
   * Verificare pozitii ale axei X respectiv Y si chemare functie 
   *  aferenta, daca e cazul
   */
  void checkX();
  void checkY();

};

#endif //JoiceStick.h 
