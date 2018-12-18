#ifndef SHIPLASERS_H

#define SHIPLASERS_H

#include "Matrix8x8.h"

class ShipLasers : public Matrix8x8
{
  byte laserTracker;
  unsigned long currTime;
  unsigned long lastTime;
  unsigned long delayTime;  
public:
  ShipLasers();
  void update();
  int howMuchOnes(byte toDisecate);
  void contact(Matrix8x8&,int&);
  void addLaser(byte);
  void setDelay(unsigned long);
  void setDelay(int);
  void resetDelay();
};

#endif /// SHIPLASERS_H
