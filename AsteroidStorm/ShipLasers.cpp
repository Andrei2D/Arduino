#include "ShipLasers.h"

#include <avr/pgmspace.h>
#include <Arduino.h>

#define zerO B00000000
#define DEF_DELAY 25

ShipLasers :: ShipLasers () 
{
  laserTracker = zerO;
  lastTime = millis();
  delayTime = DEF_DELAY;
}

void ShipLasers::update()
{
  if ( (laserTracker != zerO))
    {
      currTime = millis();
      if( currTime - lastTime >= delayTime )
        {
          lastTime = currTime; 
          laserTracker = laserTracker >> 1;
          shUp();
        } 
    }
}

void ShipLasers::addLaser (byte lasPos)
{
  octaMat [ 6 ] = lasPos;
  laserTracker = laserTracker | B01000000;
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
