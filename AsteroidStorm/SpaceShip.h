#ifndef SPACESHIP_H

#define SPACESHIP_H

#include "Matrix8x8.h"

/*
  Clasa care simuleaza miscarile unei navete spatiale 
    pe doua randuri ale matricii dar care este totusi
    derivata din clasa Matrix8x8
*/
class SpaceShip : public Matrix8x8
{
  byte defShip [2];             //Default ship model
  byte leftGunPos, rightGunPos; //Pozitiile armelor, returnate pentru clasa ShipLasers

  public:
  SpaceShip ();
  
  void moveLeft ();
  void moveRight ();

  byte leftGun ();
  byte rightGun ();

  void resetPosition ();
  void didCollide (bool&, Matrix8x8&);

};

#endif /// SPACESHIP_H
