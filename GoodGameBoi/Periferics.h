#ifndef LECEDE_H

#define LECEDE_H

#include "LiquidCrystal.h"
#include <Arduino.h>
#include <string.h>
#define MAX_WIDTH_LCD 16
#define BLANK_ARR "                "

/*
    Clasa ce se ocupa cu modificarea a doua siruri de caractere
    pentru a fi afisate pe LCD 
*/

class LeCeDe: public LiquidCrystal
{
    char leStrings[2][MAX_WIDTH_LCD + 1];
public:
    LeCeDe(uint8_t Res, uint8_t Enb, uint8_t de0, uint8_t de1, uint8_t de2, uint8_t de3);

    void defHW();
    void printStrings();
    void setFromPos (short wichOne, short wichPos, char* wichString);
    void setString(short wichOne, char* wichString);
    void clearStrings();
    void initArrows();

};


#endif ///LECEDE_H


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
  void initV (void (*down)(), void (*up)());

  ///Init HORIZONTAL
  void initH (void (*left)(), void (*right)());

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



#ifndef BUTTON_H

#define BUTTON_H

#include "MillisWait.h"
#include <Arduino.h>

class PushButton
{
protected:
  int buttonPin;
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
