#include "LedControl.h" 
#include "JoiceStick.h"
#include "SpaceShip.h"
#include "PushButton.h"
#include "ShipLasers.h"
#include "Asteroids.h"
#include "LeCeDe.h"
#include "MillisWait.h"
LedControl lc = LedControl(6,5,4,1); //DIN, CLK, LOAD, No. DRIVER


JoiceStick Ctrl;
SpaceShip Sheep;
Matrix8x8 Mat;
ShipLasers Laz;
PushButton bLf(2), bRg(3);
Asteroids myAst;
LeCeDe LCD(12,11,10,9,8,7);

/*~~~SETUP~~~*/

void mvSheepLeft () { Sheep.moveLeft(); }
void mvSheepRight () { Sheep.moveRight(); }

void shootLeft() { Laz.addLaser ( Sheep.leftGun() ); }
void shootRight() { Laz.addLaser ( Sheep.rightGun() ); }


void setup()
{
 // Serial.begin(9600);

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
  LCD.setString(0,"Score: ");
}



int cevaScor = 0;

void loop() {
    MillisWait::readTime();
    Ctrl.checkH();
    bLf.onPress();
    bRg.onPress();
    Laz.update();
    Laz.contact(myAst,cevaScor);
    myAst.addMeteors();

    char sirPtNumar[10];
    itoa(cevaScor,sirPtNumar,20);
    LCD.setString(1,sirPtNumar);
    LCD.printStrings();

    Mat = Sheep | Laz | myAst;
    Mat.playOn(lc);
}