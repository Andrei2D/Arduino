#ifndef SHIPLASERS_H

#define SHIPLASERS_H

#include "Matrix8x8.h"
#include "MillisWait.h"

class ShipLasers : public Matrix8x8
{
  byte laserTracker;
  MillisWait lazWait, penaltyWait;  
public:
  ShipLasers();
  void update();
  int howMuchOnes(byte toDisecate);
  void contact(Matrix8x8&,int&);
  void addLaser(byte);
  void setDelay(unsigned long);
  void resetDelay();
};

#endif /// SHIPLASERS_H
