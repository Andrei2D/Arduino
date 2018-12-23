#include "LedControl.h" 
#include "JoiceStick.h"
#include "SpaceShip.h"
#include "PushButton.h"
#include "ShipLasers.h"
#include "Asteroids.h"
#include "LeCeDe.h"
#include "MillisWait.h"



/*
██╗███╗   ██╗██╗████████╗██╗ █████╗ ██╗     ██╗███████╗ █████╗ ██████╗ ██╗
██║████╗  ██║██║╚══██╔══╝██║██╔══██╗██║     ██║╚══███╔╝██╔══██╗██╔══██╗██║
██║██╔██╗ ██║██║   ██║   ██║███████║██║     ██║  ███╔╝ ███████║██████╔╝██║
██║██║╚██╗██║██║   ██║   ██║██╔══██║██║     ██║ ███╔╝  ██╔══██║██╔══██╗██║
██║██║ ╚████║██║   ██║   ██║██║  ██║███████╗██║███████╗██║  ██║██║  ██║██║
╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝╚═╝  ╚═╝╚══════╝╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝
                                                                          
*/

LedControl lc = LedControl (6, 5, 4, 1);
JoiceStick Ctrl;
SpaceShip Sheep;
Matrix8x8 Mat;
ShipLasers Laz;
PushButton bLf (2), bRg (3);
PushButton replayBtn (2), exitBtn (3);
PushButton play1 (2), play2 (3);
Asteroids myAst;
LeCeDe LCD (12, 11, 10,9, 8, 7);

MillisWait ragazAfisaj(500);
MillisWait wichState(1000);


void mvSheepLeft () { Sheep.moveLeft(); }
void mvSheepRight () { Sheep.moveRight(); }

void shootLeft() { Laz.addLaser ( Sheep.leftGun() ); }
void shootRight() { Laz.addLaser ( Sheep.rightGun() ); }


int livesLeft = 3;

void initGame()
{

  Laz.clearMatrix();
  myAst.clearMatrix();

  Laz.setDelay(70);
  
  bLf.setAction (shootLeft);
  bRg.setAction (shootRight);
  
  bLf.setDelay(150);
  bRg.setDelay(190);

  Ctrl.initH ( mvSheepLeft, mvSheepRight);
  Ctrl.setDelay(120);

  LCD.setString(0,"     Score:     ");
  LCD.setString(1,"                ");
}


/*
██████╗ ███████╗███╗   ██╗████████╗██████╗ ██╗   ██╗         ██╗ ██████╗  ██████╗
██╔══██╗██╔════╝████╗  ██║╚══██╔══╝██╔══██╗██║   ██║         ██║██╔═══██╗██╔════╝
██████╔╝█████╗  ██╔██╗ ██║   ██║   ██████╔╝██║   ██║         ██║██║   ██║██║     
██╔═══╝ ██╔══╝  ██║╚██╗██║   ██║   ██╔══██╗██║   ██║    ██   ██║██║   ██║██║     
██║     ███████╗██║ ╚████║   ██║   ██║  ██║╚██████╔╝    ╚█████╔╝╚██████╔╝╚██████╗
╚═╝     ╚══════╝╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝      ╚════╝  ╚═════╝  ╚═════╝
                                                                                 
*/


int someScore[4] = {0,0,0,0};
bool gameOver = false;
bool myMenu = true;
bool outofLives = false;

void Replay()
{
    gameOver = false;
    outofLives = false;
    initGame();
}
void Exit()
{
    Mat.clearMatrix();
    gameOver = false;
    outofLives = false;
    myMenu = true;
}

void startFromMenu ()
{
    myMenu = false;
    gameOver = false;
    outofLives = false;
    initGame();
}


void theActualGame() {
    
    
    myAst.setDiff(livesLeft);

    Ctrl.checkH();
    bLf.ifPressed();
    bRg.ifPressed();
    Laz.update();

    Laz.contact(myAst,someScore[livesLeft]);
    myAst.addMeteors(gameOver);
    Sheep.didCollide(gameOver,myAst);

    char sirPtNumar[10];
    itoa(someScore[livesLeft],sirPtNumar,10);
    LCD.setFromPos(1,5,sirPtNumar);

    Mat = Sheep | Laz | myAst;
}



/*
 ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ 
██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗
██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝
██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗
╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║
 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝
                                                                          
*/

void xMatrix()
{
byte anX[] = {  B01000010,
                B00100100,
                B00011000,
                B00011000,
                B00100100,
                B01000010,
                B00000000,
                B00000000};

Matrix8x8 theX;
theX = anX;

Mat = Sheep | theX;
}

void lostLife()
{

    LCD.setString(0,"  You got hit!  ");
    LCD.setString(1,"Lives left:     "); 

    char auxMat[5];
    itoa(livesLeft,auxMat,10);
    if (someScore[0] >= 1000 )
        LCD.setFromPos(1,12,auxMat);
    LCD.setFromPos(1,13,auxMat);
    LCD.printStrings();

    gameOver = false;

    xMatrix();
    Mat.playOn(lc);
    delay(2000);
}

void gameOverLCD()
{

    LCD.clearStrings();
    LCD.printStrings();
    delay(500);

    LCD.setString(0,"#     GAME     #");
    LCD.setString(1,"##    OVER!   ##");
    LCD.printStrings();
    delay(1500);
}

/*
███████╗███████╗████████╗██╗   ██╗██████╗ 
██╔════╝██╔════╝╚══██╔══╝██║   ██║██╔══██╗
███████╗█████╗     ██║   ██║   ██║██████╔╝
╚════██║██╔══╝     ██║   ██║   ██║██╔═══╝ 
███████║███████╗   ██║   ╚██████╔╝██║     
╚══════╝╚══════╝   ╚═╝    ╚═════╝ ╚═╝                            
*/

void setup()
{

  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 0); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen

  replayBtn.setAction(Replay);
  exitBtn.setAction(Exit);

  play1.setAction(startFromMenu);
  play2.setAction(startFromMenu);

  Mat.clearMatrix();
//   initGame();
}

/*
██╗      ██████╗  ██████╗ ██████╗ 
██║     ██╔═══██╗██╔═══██╗██╔══██╗
██║     ██║   ██║██║   ██║██████╔╝
██║     ██║   ██║██║   ██║██╔═══╝ 
███████╗╚██████╔╝╚██████╔╝██║     
╚══════╝ ╚═════╝  ╚═════╝ ╚═╝     
*/

void loop()
{
MillisWait::readTime();

if(myMenu)
{
    LCD.setString(0,"Asteroid Storm");
    LCD.setString(1,"Press to START");

    delay(200);
    play1.ifPressed();
    play2.ifPressed();
}
else
    {
        if(gameOver)
        {
            if(outofLives)
            {

                char sirScor[7];
                itoa(someScore[0],sirScor,10);

                LCD.setString (0, "Final score:    ");
                LCD.setFromPos (0, 13, sirScor );
                LCD.setString (1, " Replay    Exit ");

                if(replayBtn.isPressed()) Replay();
                if(exitBtn.isPressed()) Exit();
               
            }
            else
            {
                livesLeft--;
                if(livesLeft == 0)
                {
                    xMatrix();
                    gameOverLCD();
                    livesLeft = 3;
                    outofLives = true;

                    someScore[0] = 0;
                    for(int i=1;i<=3;i++) 
                        {
                            someScore[0] += someScore[i];
                            someScore[i] = 0;
                        }
                }
                else
                {
                    lostLife();
                    initGame();
                }   
            }
        }
        else
                theActualGame();
    }


    if(ragazAfisaj.isOk()) LCD.printStrings();
    Mat.playOn(lc);

}
