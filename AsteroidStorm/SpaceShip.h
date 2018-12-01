#ifndef SPACESHIP_H

#define SPACESHIP_H

#include "Matrix8x8.h"


class SpaceShip : public Matrix8x8
{
  byte defShip [2];
  byte leftGunPos, rightGunPos;
  public:
  
  SpaceShip();
  
  void moveLeft();
  void moveRight();

  byte leftGun();
  byte rightGun();

  void resetPosition();

};

#endif /// SPACESHIP_H
