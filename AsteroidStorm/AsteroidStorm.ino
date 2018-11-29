
#include "LedControl.h" //  need the library
LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER
const int joyX = A0;
const int joyY = A1;

//0x0705000000000000

byte Sheep[] = {B00000000,
                B00000000,
                B00000000,
                B00000000,
                B00000000,
                B00000000,
                B01010000,
                B01110000 };


int isY () 
{
  int yy = analogRead(joyY);
  delay(150);
  if( yy < 400 ) return -1;
  if( yy > 600 ) return 1;
  return 0;
}

void leftSheep ()
{
  byte tooFar = B10000000;
  byte zeroB = B00000000;
  byte lRez = tooFar & Sheep[7];
  Serial.println(lRez);
  if( lRez == zeroB)
    {
      Sheep[6] = Sheep[6] << 1;
      Sheep[7] = Sheep[7] << 1;
    }
}

void rightSheep ()
{
  byte tooFar = B00000001;
  byte zeroB = B00000000;
  byte rRez = tooFar & Sheep[7];
  Serial.println(rRez);
  if( rRez == zeroB)
    {
      Sheep[6] = Sheep[6] >> 1;
      Sheep[7] = Sheep[7] >> 1;
    }
}

/*~~~SETUP~~~*/
void setup()
{
  Serial.begin(9600);
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 0); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  pinMode (joyX, INPUT);
  pinMode (joyY, INPUT);
}

void check()
{
  int wh = isY();
  if( wh < 0 ) 
    {
      Serial.println("LEFT");
      leftSheep();
    }
  if( wh > 0 ) 
    {
      Serial.println("RIGHT");
      rightSheep();
    }
}

void fillMatrix()
{
  lc.clearDisplay(0);
  for(int i=0; i<8; i++)
    lc.setRow(0,i,Sheep[i]);
    
}


void loop() {
  check();
  fillMatrix();
}
