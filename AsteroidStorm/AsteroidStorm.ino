#include "LedControl.h" //  need the library
#include "JoiceStick.h"
#include "Matrix8x8.h"
LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER

JoiceStick Ctrl;
Matrix8x8 Sheep;


//0x0705000000000000


void leftSheep ()
{
  byte tooFar = B10000000;
  byte zeroB = B00000000;
  byte lRez = tooFar & Sheep[7];
  if( lRez == zeroB) Sheep.shLeft();
}

void rightSheep ()
{
  byte tooFar = B00000001;
  byte zeroB = B00000000;
  byte rRez = tooFar & Sheep[7];
  Serial.println(rRez);
  if( rRez == zeroB) Sheep.shRight();
}

/*~~~SETUP~~~*/
void setup()
{
  Serial.begin(9600);
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 0); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  Ctrl.initY(leftSheep,rightSheep);
  Ctrl.setDelay(125);
  Sheep[6] |= B10100000;
  Sheep[7] |= B11100000;
}



void loop() {
  Ctrl.checkY();
  Sheep.playOn(lc);
}
