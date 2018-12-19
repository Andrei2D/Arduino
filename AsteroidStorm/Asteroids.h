#ifndef ASTEROIDS_H

#define ASTEROIDS_H

#include "Matrix8x8.h"
#include "MillisWait.h"

class Asteroids : public Matrix8x8
{
  short diff;
  short speed;
  MillisWait astWait;
 public:
  Asteroids();
  Asteroids(short,short);
  byte twoPower(short);
  void setDiff(short);
  void update();
  byte intToByte(int);
  byte genField (short);
  void addMeteors ();
  void setDelay(unsigned long aDelay);

};

#endif ///ASTEROIDS_H
