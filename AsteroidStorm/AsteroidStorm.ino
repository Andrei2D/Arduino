#include "LedControl.h" //  need the library
#include "JoiceStick.h"
#include "SpaceShip.h"
#include "PushButton.h"
#include "ShipLasers.h"
#include "Asteroids.h"

LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER

/*
 * DE SCOS DELAY-URILE DIN JOYSTICK CPP
 */

JoiceStick Ctrl;
SpaceShip Sheep;
Matrix8x8 Mat;
ShipLasers Laz;
PushButton bLf(2), bRg(3);
Asteroids myAst;

/*~~~SETUP~~~*/

void mvSheepLeft () { Sheep.moveLeft(); }
void mvSheepRight () { Sheep.moveRight(); }

void shootLeft() { Laz.addLaser ( Sheep.leftGun() ); }
void shootRight() { Laz.addLaser ( Sheep.rightGun() ); }


void setup()
{
  Serial.begin(9600);

  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 0); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen

  Laz.setDelay(70);
  
  bLf.setAction (shootLeft);
  bRg.setAction (shootRight);
  
  bLf.setDelay(150);
  bRg.setDelay(190);

  Ctrl.initH ( mvSheepLeft, mvSheepRight);
  Ctrl.setDelay(120);

  pinMode(13,OUTPUT);

}


/*
void loop() {
    Ctrl.checkH();
    bLf.onPress();
    bRg.onPress();
    Laz.update();

    Mat = Sheep | Laz;
    Mat.playOn(lc);
}
*/
short cateFacem = 2;

void loop ()
{
  myAst.setDiff(0);
  byte myByte;
  for(int i=1; i<=8; i++)
  {
    Serial.print("\t#");
    Serial.println(i);
    
    for(int j=1; j<= 3; j++)
    { 
    myByte = myAst.genField(i);
    Serial.println(myByte,BIN);
    delay(1000);
    }
  }
  delay(3000);
}
