#ifndef SHIPLASERS_H

#define SHIPLASERS_H

#include "Matrix8x8.h"

class ShipLasers : public Matrix8x8
{
  unsigned long lastTime;
  unsigned long delayTime;  
public:
  /*
   * Functie care muta laserul in sus in functie de 
   *  un delay care poate fi setat
   */
  void update(unsigned long);
  
  /*
   * Functi care verifica contactul cu 
   *  obiectele altei matrici
   */
  bool contact(Matrix8x8&);
  
  /*
   * Functie care adauga un laser pe penultima linie
   *  in functie de o coloana data printr-o variabila
   *  de tip byte
   */
  void addLaser(byte);

  /*
   * Functie de setat un delay custom de tip unsigned long
   */
  void setDelay(unsigned long);

  /*
   * Supraincarcarea functiei de mai sus pentru int
   */
  void setDelay(int);

  /*
   * Resetarea delay-ului la un default
   */
  void resetDelay();
};

#endif /// SHIPLASERS_H
