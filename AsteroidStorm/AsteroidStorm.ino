#include "LedControl.h" //  need the library
#include "JoiceStick.h"
#include "SpaceShip.h"


LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER

JoiceStick Ctrl;
SpaceShip Sheep;

/*~~~SETUP~~~*/

void mvSheepLeft () { Sheep.moveLeft(); };
void mvSheepRight () { Sheep.moveRight(); };


void setup()
{
  Serial.begin(9600);
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 0); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  
  
  Ctrl.initY ( mvSheepLeft, mvSheepRight);
  
  Ctrl.setDelay(125);
  Sheep[6] |= B10100000;
  Sheep[7] |= B11100000;
}



void loop() {
  Ctrl.checkY();
  Sheep.playOn(lc);
}
