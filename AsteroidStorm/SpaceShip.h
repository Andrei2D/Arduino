#ifndef SPACESHIP_H

#define SPACESHIP_H

#include "Matrix8x8.h"


class SpaceShip : public Matrix8x8
{
  /*
   * Nava pe pozitia din stanga a matricii
   */
  byte defShip [2];

  /*
   * Pozitiile armelor, pentru clasa ShipLasers
   */
  byte leftGunPos, rightGunPos;
  public:
  
  SpaceShip();
  
  /*
   * Mutare nava spatiala daca nu se afla in margine
   */
  void moveLeft();
  void moveRight();

  /*
   * Returnare pozitii arme
   */
  byte leftGun();
  byte rightGun();

  /*
   * Revenire la pozitia intiala
   */
  void resetPosition();

};

#endif /// SPACESHIP_H
