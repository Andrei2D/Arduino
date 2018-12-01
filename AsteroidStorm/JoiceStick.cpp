#include "JoiceStick.h"

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
  theDelay = 100;
  goLeft = NULL;
  goRight = NULL;
  goUp = NULL;
  goDown = NULL;
  pinMode( joyX, INPUT );
  pinMode( joyY, INPUT );
}

void JoiceStick::setDelay (int aDelay) { theDelay = aDelay;}

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
  delay(theDelay);
  if( xx < 400 ) return 1;
  if( xx > 600 ) return -1;
  return 0;
}


int JoiceStick::isY () 
{
  int yy = analogRead(joyY);
  delay(theDelay);
  if( yy < 400 ) return 1;
  if( yy > 600 ) return -1;
  return 0;
}


void JoiceStick::checkH()
{
  if( goLeft == NULL && goRight == NULL) return;
  int wh = isY();
  if( wh < 0 )  goLeft();
  if( wh > 0 )  goRight();
}

void JoiceStick::checkV()
{
  if( goDown == NULL && goUp == NULL) return;
  int wh = isX();
  if( wh < 0 )  goDown();
  if( wh > 0 )  goUp();
}
