#include "Periferics.h"    
#include <Arduino.h>
    //  >>> LeCeDe  <<<
LeCeDe::LeCeDe(uint8_t Res, uint8_t Enb, uint8_t de0, uint8_t de1, uint8_t de2, uint8_t de3):LiquidCrystal(Res, Enb, de0, de1, de2, de3)
    {
        defHW();
        begin(MAX_WIDTH_LCD,2);
        printStrings();
    }
    
    void LeCeDe::defHW()
    {
        strcpy(leStrings[0],"                ");
        strcpy(leStrings[1],"                ");
    }

    void LeCeDe::printStrings()
    {
        clear();
        setCursor(0,0);
        print(leStrings[0]);
        setCursor(0,1);
        print(leStrings[1]);
    }

    void LeCeDe::setFromPos (short wichOne, short wichPos, char* wichString)
    {
        strncpy( leStrings [wichOne%2] + wichPos, wichString,  MAX_WIDTH_LCD - wichPos);
        leStrings [wichOne%2][MAX_WIDTH_LCD] = '\0';
        
    }

    void LeCeDe::setString(short wichOne, char* wichString)
    {
        setFromPos(wichOne,0,wichString);
    }

    void LeCeDe::clearStrings()
    {
        setString(0,"                ");
        setString(1,"                ");
    }

   void LeCeDe::initArrows()
   {
     byte upAndDown[] = {
    B00100,
    B01010,
    B10001,
    B00000,
    B00000,
    B10001,
    B01010,
    B00100
    };

byte onlyUp[] = {
    B00100,
    B01010,
    B10001,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
    };
    
byte onlyDown[] = {
    B00100,
    B01010,
    B10001,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
    };

    createChar(0,upAndDown);
    createChar(1,onlyUp);
    createChar(2,onlyDown);
   }

//  END OF LeCeDe

    //  >>> JoiceStick  <<<

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

JoiceStick::JoiceStick()
{
  joyX = A0;
  joyY = A1;
  resetVars();
}

JoiceStick::JoiceStick (int anlInputX, int anlInputY): joyX (anlInputX), joyY (anlInputY)
{
  resetVars ();
}

void JoiceStick::resetVars ()
{
  joyWait.setDelay (DEF_JOY_DELAY);
  goLeft = NULL;
  goRight = NULL;
  goUp = NULL;
  goDown = NULL;
  pinMode (joyX, INPUT);
  pinMode (joyY, INPUT);
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
void JoiceStick::initV (void (*up)(), void (*down)())
{
  goDown = down;
  goUp = up;
}


void Joicestick::initPins (int anlX, anlY)
{
  joyX = anlX;
  joyY = anlY;
  resetVars();
}

/*
  Ok... stiu ca ar trebui sa inlocuiesc
*/

int JoiceStick::isX () 
{
    int xx = analogRead (joyX);
    if (xx < 400) return 1;
    if (xx > 600) return -1;
    return 0;
}


int JoiceStick::isY () 
{
  
    int yy = analogRead (joyY);
    if (yy < 400) return 1;
    if (yy > 600) return -1;
    return 0;
}


void JoiceStick::checkH()
{
  
  int wh;
  if (goLeft == NULL || goRight == NULL) return;
  else
  {
    wh = isY ();
     if( wh == 0) return;
  }
  if (wh < 0 && joyWait.isOk())  goLeft ();
  if (wh > 0 && joyWait.isOk())  goRight ();

}

void JoiceStick::checkV()
{
  
  int wh;
  if (goUp == NULL || goDown == NULL) return;
  else
  {
    wh = isX ();
     if( wh == 0) return;
  }
  if (wh < 0 && joyWait.isOk ())  goDown ();
  if (wh > 0 && joyWait.isOk ())  goUp ();

}
///     END OF  JoiceStick

    //  >>> PushButton  <<<

#define DEF_BTN_DELAY 100


PushButton::PushButton (int aPin):buttonPin(aPin)
{
  pinMode (buttonPin, INPUT);
  btnWait.setDelay (DEF_BTN_DELAY);
  doIt = NULL;
}

void PushButton::setDelay (unsigned long aDelay)
{
  btnWait.setDelay (aDelay);
}


void PushButton::setAction (void (*toDO)(void))
{
  doIt = toDO;
}
 
bool PushButton::isPressed ()
{
  return digitalRead (buttonPin) == HIGH;
}

void PushButton::ifPressed ()
{
  if (isPressed() && btnWait.isOk ()) 
  {
    doIt ();
  }
}
///     END OF PushButton