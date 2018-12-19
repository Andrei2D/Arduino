#include "JoiceStick.h"

#define DEF_JOY_DELAY 150
/*
 * COUNTERINTUITIVE, BUT:
 *        X(VRx) IS FOR VERTICAL
 *        Y(VRy) IS FOR HORIZONTAL
 *        
 * LEFT   ->   Y = 0
 * RIGHT  ->   Y = 1024
 * 
 * UP     ->   X = 0
 * DOWN   ->   X = 1024
 */



JoiceStick::JoiceStick():joyX(A0),joyY(A1)
{
  resetVars();
}

JoiceStick::JoiceStick(int anlInputX, int anlInputY):joyX(anlInputX),joyY(anlInputY)
{
  resetVars();
}

void JoiceStick::resetVars()
{
  joyWait.setDelay(DEF_JOY_DELAY);
  goLeft = NULL;
  goRight = NULL;
  goUp = NULL;
  goDown = NULL;
  pinMode( joyX, INPUT );
  pinMode( joyY, INPUT );
}

void JoiceStick::setDelay (unsigned long aDelay) 
{ 
  joyWait.setDelay (aDelay);
}

///HORIZONTAL
void JoiceStick::initH (void (*left)(), void (*right)())
{
  goLeft = left;
  goRight = right;
}

///VERTICAL
void JoiceStick::initV ( void (*down)(), void (*up)())
{
  goDown = down;
  goUp = up;
}


int JoiceStick::isX () 
{
    int xx = analogRead(joyX);
    if ( xx < 400 ) return 1;
    if ( xx > 600 ) return -1;
    return 0;
}


int JoiceStick::isY () 
{
  
    int yy = analogRead(joyY);
    if ( yy < 400 ) return 1;
    if ( yy > 600 ) return -1;
    return 0;
}


void JoiceStick::checkH()
{
  
  int wh = isY();
  if ( goLeft == NULL || goRight == NULL || wh == 0) return;
  if ( wh < 0 && joyWait.isOk() )  goLeft();
  if ( wh > 0 && joyWait.isOk() )  goRight();

}

void JoiceStick::checkV()
{
  
  int wh = isX();
  if (goLeft == NULL || goRight == NULL || wh == 0) return;
  if ( wh < 0 && joyWait.isOk() )  goDown();
  if ( wh > 0 && joyWait.isOk() )  goUp();

}
