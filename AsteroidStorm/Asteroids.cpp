#include "Asteroids.h"
#define zerO B00000000

/*
  Dificultati: 
    -Easy (0)   - 2,3,4 numar asteroizi
    -Medium (1) - 4,5,6 numar asteroizi 
    -Hard (2)   - 6,7,8 numar asteroizi
*/
Asteroids::Asteroids()
{
  diff = 0;
  speed = 1;
}

Asteroids::Asteroids(short theDifficulty = 0, short theSpeed = 1)
{
  diff = theDifficulty;
  speed = theSpeed;
}

void Asteroids::setDiff(short newDiff)
{
  diff = newDiff;
}

byte Asteroids::intToByte(int uglyInt)
{
  char mehChar = uglyInt % 256;
  byte handsomeByte;
  
  
}

byte Asteroids::twoPower(short Power)
{
  if(Power <= 0 ) return B1;
  byte wichOne = 1;
  while(Power > 0)
  {
    wichOne = wichOne << 1;
    Power--;
  }
  return wichOne;
}


byte Asteroids::genField (short howMany)
{
  if(howMany == 8) return 255;
  
  byte toGo, toAdd;
  toGo = zerO;
  toAdd = zerO;
  bool extraStep = false;

  if(howMany > 4)
  {
    extraStep = true;
    howMany = 8 - howMany;
  }
  
  while ( howMany > 0 )
  {
    int pw = random(8);
    toAdd = (byte)twoPower(pw);
    
    byte toComp = toGo & toAdd;
    if( toComp == zerO)
    {
    
      toGo = toGo | toAdd;
      howMany--;
    }
  }
  if(extraStep) return ~toGo;
  return toGo;
}

void Asteroids::addMeteors ()
{
  short randAst = random(3);
  short howMany = 2 + diff + randAst;
  shDown();
  octaMat[0] = genField ( howMany );
}
