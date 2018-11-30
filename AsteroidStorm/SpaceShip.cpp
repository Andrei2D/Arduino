#include "SpaceShip.h"

#define LEFT_GUN B10000000
#define RIGHT_GUN B00100000
#define UPPER_SHIP B10100000
#define LOWER_SHIP B11100000
#define FAR_LEFT B10000000
#define FAR_RIGHT B00000001

SpaceShip::SpaceShip()
{
  leftGunPos = LEFT_GUN;
  rightGunPos = RIGHT_GUN;
  resetPosition();
}

void SpaceShip::moveLeft()
{
  if  ( octaMat[7] & FAR_LEFT == 0 )
  {
     shLeft();
     leftGunPos = leftGunPos << 1;
     rightGunPos = rightGunPos << 1;
  }
}

void SpaceShip::moveRight()
{
  if ( octaMat[7] & FAR_RIGHT == 0 )
  {
     shRight();
     leftGunPos = leftGunPos >> 1;
     rightGunPos = rightGunPos >> 1;
  }
}

byte SpaceShip::leftGun() 
{ 
  return leftGunPos; 
}

byte SpaceShip::rightGun() 
{ 
  return rightGunPos; 
}

void SpaceShip::resetPosition ()
{
  clearMatrix();
  octaMat [ 6 ] = UPPER_SHIP;
  octaMat [ 7 ] = LOWER_SHIP;
  leftGunPos = LEFT_GUN;
  rightGunPos = RIGHT_GUN;
  
}
