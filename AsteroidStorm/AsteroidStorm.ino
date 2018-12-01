#include "LedControl.h" //  need the library
#include "JoiceStick.h"
#include "SpaceShip.h"
#include "PushButton.h"

LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER

/*
 * DE SCOS DELAY-URILE DIN JOYSTICK CPP
 */

JoiceStick Ctrl;
SpaceShip Sheep;
Matrix8x8 Mat;
PushButton bLf(2), bRg(3);

/*~~~SETUP~~~*/

void mvSheepLeft () { Sheep.moveLeft(); }
void mvSheepRight () { Sheep.moveRight(); }

void setup()
{
  Serial.begin(9600);
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 0); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen

  bLf.setAction (mvSheepLeft);
  bRg.setAction (mvSheepRight);
  Ctrl.initH ( mvSheepLeft, mvSheepRight);
  Ctrl.setDelay(150);

}



void loop() {
    Ctrl.checkHwDelay();
    bLf.onPress();
    bRg.onPress();
    Sheep.playOn(lc);
}
