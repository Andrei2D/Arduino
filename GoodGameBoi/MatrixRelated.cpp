#include "MatrixRelated.h"
/*__  __       _        _      ___      ___  
 |  \/  | __ _| |_ _ __(_)_  _( _ )_  _( _ ) 
 | |\/| |/ _` | __| '__| \ \/ / _ \ \/ / _ \ 
 | |  | | (_| | |_| |  | |>  < (_) >  < (_) |
 |_|  |_|\__,_|\__|_|  |_/_/\_\___/_/\_\___/ 
*/
#define zerO B00000000
#define MAT_SIZE 8

  Matrix8x8::Matrix8x8()
  {
    clearMatrix();
  }

  void Matrix8x8::shLeft()
  {
    for (int i = 0; i < MAT_SIZE; i++) 
      octaMat[i] = octaMat[i] << 1;  
  }
  
  void Matrix8x8::shRight()
  {
    for (int i = 0; i < 8; i ++ ) 
      octaMat[i] = octaMat [i] >> 1;
  }

  void Matrix8x8::shUp()
  {
    for (int i = 1; i < 8; i ++ )
      octaMat[i - 1] = octaMat[i] ;
    octaMat[7] = zerO;
  }
  
  void Matrix8x8::shDown()
  {
    for (int i = 7; i >= 0; i --)
      octaMat[i + 1] = octaMat[i];
    octaMat[0] = zerO;
  }
  
  Matrix8x8 Matrix8x8::operator| (const Matrix8x8& mat)
  {
    Matrix8x8 result;
    for ( int i = 0; i < 8; i++) 
      result.octaMat[i] = octaMat[i] | mat.octaMat[i];
    return result;
  }
  
  Matrix8x8 Matrix8x8::operator& (const Matrix8x8& mat)
  {
    Matrix8x8 result;
    for ( int i = 0; i < 8; i++) 
      result.octaMat[i] = octaMat[i] & mat.octaMat[i];
    return result;
  }
  
  Matrix8x8 Matrix8x8::operator^ (const Matrix8x8& mat)
  {
    Matrix8x8 result;
    for (int i = 0; i < 8; i++) 
      result.octaMat[i] = octaMat[i] ^ mat.octaMat[i];
    return result;
  }
  
  Matrix8x8 Matrix8x8::operator~ ()
  {
    Matrix8x8 result;
    for (int i = 0; i < 8; i++) 
      result.octaMat[i] = ~octaMat[i];
    return result;
  }

  bool  Matrix8x8::operator== (const Matrix8x8& mat)
  {
    for (int i = 0; i < 7; i ++)
      if (octaMat[i] != mat.octaMat[i]) return 0;
    return 1;
  }  
  
  bool  Matrix8x8::operator!= (const Matrix8x8& mat)
  {
    for (int i = 0; i < 7; i ++)
      if (octaMat[i] != mat.octaMat[i]) return 1;
    return 0;
  }

  int Matrix8x8::operator= (const Matrix8x8& mat)
  {
    if (this == &mat) return 0;

    for (int i = 0; i <  8; i ++) 
      octaMat[i] = mat.octaMat[i];
    return 1;
  }

  int Matrix8x8::operator= (const byte Mat[])
  {

    for (int i = 0; i <  8; i ++) 
      octaMat[i] = Mat[i];
    return 1;
  }

  byte& Matrix8x8::operator[](int i)
  {
    if ( i < 0) return octaMat[0];
    if( i > 7 ) return octaMat[7];
    return octaMat[i];
  }
  
  void Matrix8x8::playOn(LedControl& LC)
  {
    LC.clearDisplay(0);
    for (int i = 0; i < 8; i ++ )
      LC.setRow (0, i, octaMat[i]);
  }
  
  void Matrix8x8::clearMatrix()
  {
    for ( int i = 0; i < 8; i ++ )
      octaMat[i] = zerO;
  }
///     END OF Matrix8x8

/*
  ____                       ____  _     _       
 / ___| _ __   __ _  ___ ___/ ___|| |__ (_)_ __  
 \___ \| '_ \ / _` |/ __/ _ \___ \| '_ \| | '_ \ 
  ___) | |_) | (_| | (_|  __/___) | | | | | |_) |
 |____/| .__/ \__,_|\___\___|____/|_| |_|_| .__/ 
       |_|                                |_|    
*/


#define LEFT_GUN B00100000
#define RIGHT_GUN B00001000
#define UPPER_SHIP B00101000
#define LOWER_SHIP B00111000
#define FAR_LEFT B10000000
#define FAR_RIGHT B00000001
#define zerO B00000000
#define LAST_ROW 

SpaceShip::SpaceShip ()
{
  leftGunPos = LEFT_GUN;
  rightGunPos = RIGHT_GUN;
  resetPosition();
}

void SpaceShip::moveLeft ()
{
  
  byte positionStatus = octaMat [ 7 ] & FAR_LEFT;
  if  ( positionStatus == zerO )
  {
     shLeft();;
     leftGunPos = leftGunPos << 1;
     rightGunPos = rightGunPos << 1;
  }
}

void SpaceShip::moveRight ()
{
  
 byte positionStatus = octaMat [ 7 ] & FAR_RIGHT;
  if (  positionStatus == zerO )
  {
     shRight();
     leftGunPos = leftGunPos >> 1;
     rightGunPos = rightGunPos >> 1;
  }
}

byte SpaceShip::leftGun () 
{ 
  return leftGunPos; 
}

byte SpaceShip::rightGun () 
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

bool SpaceShip::didCollide (Matrix8x8& whatMat)
{
  byte secLastLine = octaMat[6] & whatMat[6];
  byte lastLine =  octaMat[7] & whatMat[7];
  
  if(secLastLine != zerO || lastLine != zerO)
     return true;
  return false;
  
}
//      END OF SpaceShip

/*
  ____  _     _       _                            
 / ___|| |__ (_)_ __ | |    __ _ ___  ___ _ __ ___ 
 \___ \| '_ \| | '_ \| |   / _` / __|/ _ \ '__/ __|
  ___) | | | | | |_) | |__| (_| \__ \  __/ |  \__ \
 |____/|_| |_|_| .__/|_____\__,_|___/\___|_|  |___/
               |_|                                 
*/


#define DEF_DELAY 50
#define DEF_PEN 750

ShipLasers :: ShipLasers () 
{
  laserTracker = zerO;
  lazWait.setDelay(DEF_DELAY);
  penaltyWait.setDelay(0);
}

void ShipLasers::update()
{
  if ( (laserTracker != zerO) && lazWait.isOk())
    {
        laserTracker = laserTracker >> 1;
        if(octaMat[0] != zerO) penaltyWait.setDelay (DEF_PEN);
        shUp();
    }
}

void ShipLasers::addLaser (byte lasPos)
{
  if(penaltyWait.isOk())
  {
  octaMat [ 6 ] = lasPos;
  laserTracker = laserTracker | B01000000;
  penaltyWait.setDelay(0);
  }
} 

int ShipLasers::howMuchOnes ( byte toDisecate )
{
  byte aMask = 1;
  int theOnes = 0;
  while( toDisecate != zerO)
  {
    if( (aMask & toDisecate) != zerO) theOnes++;
    toDisecate >>= 1;
  }
  return theOnes;
}

int ShipLasers::contact(Matrix8x8& asteroMat)
{
  int astHit = 0;
  for ( int i = 0; i < 7; i ++ )
   {
    byte meetUp = octaMat [ i ] & asteroMat [ i ];
    if ( meetUp != zerO)
      {
        asteroMat [i] ^= octaMat [i];
        octaMat [i] -= meetUp;
        astHit += howMuchOnes(meetUp);
      }
   }
   return astHit;
}

void ShipLasers::setDelay(unsigned long aDelay)
{
  lazWait.setDelay (aDelay) ;
}


void ShipLasers::resetDelay() 
{
  lazWait.setDelay (DEF_DELAY);
}
//  END OF ShipLasers

/*
     _        _                 _     _     
    / \   ___| |_ ___ _ __ ___ (_) __| |___ 
   / _ \ / __| __/ _ \ '__/ _ \| |/ _` / __|
  / ___ \\__ \ ||  __/ | | (_) | | (_| \__ \
 /_/   \_\___/\__\___|_|  \___/|_|\__,_|___/
                                            
*/
#define AST_DELAY(x) (1500 - 150 * x)
/*
  Difficulties: 
    -Easy (0)   - 2,3,4 numar asteroizi
    -Medium (1) - 4,5,6 numar asteroizi 
    -Hard (2)   - 5,6,7 numar asteroizi

    2 3 4
    4 5 6
    5 6 7
*/
Asteroids::Asteroids()
{
  diff = 0;
  astWait.setDelay (AST_DELAY(diff));
}

void Asteroids::setDiff (short aDiff)
{
  diff = aDiff;
  astWait.setDelay (AST_DELAY(diff));
}

byte Asteroids::twoPower (short Power)
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

bool Asteroids::addMeteors ()
{
  
if(!astWait.isOk()) return false;
  
  int lower;

  if(diff == 2) lower = 5;
  else lower = 2 + 2 * diff;

  short howMany = random (lower, lower + 3);

  if (octaMat[7] != zerO) return true;
  shDown();
  byte neww = genField ( howMany );

  octaMat[0] = neww;
  return false;

}

void Asteroids::setDelay(unsigned long aDelay)
{
  astWait.setDelay(aDelay);
}
///     END OF Asteroids