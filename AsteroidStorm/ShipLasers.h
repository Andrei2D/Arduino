#ifndef SHIPLASERS_H

#define SHIPLASERS_H

#include "Matrix8x8.h"

class ShipLasers : public Matrix8x8
{
  byte laserTracker;
  unsigned long lastTime;
  unsigned long delayTime;  
public:
  ShipLasers(unsigned long);
  void update(unsigned long);
  bool contact(Matrix8x8&);
  void addLaser(byte);
  void setDelay(unsigned long);
  void setDelay(int);
  void resetDelay();
};

#endif /// SHIPLASERS_H
