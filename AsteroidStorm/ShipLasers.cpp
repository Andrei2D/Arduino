#include "ShipLasers.h"

#include <avr/pgmspace.h>
#include <Arduino.h>

#define zerO B00000000
#define DEF_DELAY 50

ShipLasers :: ShipLasers (unsigned long currTime) 
{
  lastTime = currTime;
  delayTime = DEF_DELAY;
}

void ShipLasers::update(unsigned long currTime)
{
  if ( currTime - lastTime > delayTime )
    {
      lastTime = currTime; 
      shUp();
    }
}

void ShipLasers::addLaser (byte lasPos)
{
  octaMat [ 6 ] = lasPos;
}

bool ShipLasers::contact(Matrix8x8& alta)
{
  for ( int i = 0; i < 7; i ++ )
    if ( octaMat [ i ] & alta [ i ] != zerO)
    {
      octaMat [ i ] = zerO;
      return true;
    }
  return false;
}

void ShipLasers::setDelay(unsigned long aDelay)
{
  delayTime = aDelay;
}

void ShipLasers::setDelay(int aDelay)
{
  unsigned long okDelay = (unsigned long)aDelay;
  delayTime = okDelay;
}

void ShipLasers::resetDelay() 
{
  delayTime = DEF_DELAY;
}
