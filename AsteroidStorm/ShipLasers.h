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
  bool contact(Matrix8x8&);
  void addLaser(byte);
  void setDelay(unsigned long);
  void setDelay(int);
  void resetDelay();
};

#endif /// SHIPLASERS_H
