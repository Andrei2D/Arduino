#include "MillisWait.h"
#include "Periferics.h"
#include "MatrixRelated.h"
#include "AsteroidStorm.h"
#include "GameControl.h"
#include "Menu.h"

#define DATA_PIN 8
#define CLK_PIN 7
#define CS_PIN 6

#define RS_PIN 12
#define ENB_PIN 11
#define D3_PIN_M 2
#define D2_PIN_M 3
#define D1_PIN_M 4
#define D0_PIN_M 5

#define X_PIN_SEC A7
#define Y_PIN_SEC A6
#define JOY_BTN_SEC A5

#define X_PIN_PRIM A4
#define Y_PIN_PRIM A3
#define JOY_BTN_PRIM A2

#define LEFT_BTN_PIN A1
#define RIGHT_BTN_PIN A0

GameControl Ctrl_IO;
MiniGame* Game[2];
void setup()
{
    Serial.begin(9600);
    Ctrl_IO.init_LED (DATA_PIN,CLK_PIN, CS_PIN, 1);
    Ctrl_IO.init_LCD (RS_PIN, ENB_PIN, D0_PIN_M, D1_PIN_M, D2_PIN_M, D3_PIN_M);
    Ctrl_IO.init_PushBtns (LEFT_BTN_PIN, RIGHT_BTN_PIN);
    Ctrl_IO.init_Joy (X_PIN_PRIM, Y_PIN_PRIM, JOY_BTN_PRIM);
    Ctrl_IO.init_JoySec (X_PIN_SEC, Y_PIN_SEC, JOY_BTN_SEC);
    Ctrl_IO.LCD->initArrows();

    M.setIO(&Ctrl_IO);

    Game[0] = &M;
    Game[1] = &Ast_Storm;

}

void loop ()
{
    MillisWait::readTime();

    
    switch (Game[game_index]->checkState())
    {
        case INIT_GAME:
            Game[game_index]->init();
            break;
        
        case UPDATE:
            Game[game_index]->update();
            break;

        case LOSE_COND:
            Game[game_index]->loseCond();
            break;

        case WARN_LOSE_COND:
            Game[game_index]->warnLosing();
            break;

        case GAME_OVER:
            Game[game_index]->gameOver();
            break;

        case FINAL_SCORE:
            Game[game_index]->finalScore();

        default:
            game_index = 0;
            M.setState(INIT_GAME);
            break;
    }

    Ctrl_IO.play();
}


//  ~~INITIALIZARI~~
/*
LedControl lc = LedControl (6, 5, 4, 1);
LeCeDe LCD (12, 11, 10,9, 8, 7);
JoiceStick Ctrl;
PushButton leftBtn (2), rightBtn (3);

Matrix8x8 Mat;

ShipLasers Laz;
SpaceShip Sheep;
Asteroids myAst;

MillisWait ragazAfisaj(500);


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
  
  leftBtn.setAction (shootLeft);
  rightBtn.setAction (shootRight);
  
  leftBtn.setDelay(190);
  rightBtn.setDelay(190);

  Ctrl.initH ( mvSheepLeft, mvSheepRight);
  Ctrl.setDelay(120);

  LCD.setString(0,"     Score:     ");
  LCD.setString(1,"                ");
}


//  ~~PENTRU JOC~~


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
    leftBtn.setAction(startFromMenu);
    rightBtn.setAction(startFromMenu);
    delay(200);
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
    leftBtn.ifPressed();
    rightBtn.ifPressed();
    Laz.update();

    Laz.contact(myAst,someScore[livesLeft]);
    myAst.addMeteors(gameOver);
    Sheep.didCollide(gameOver,myAst);

    char sirPtNumar[10];
    itoa(someScore[livesLeft],sirPtNumar,10);
    LCD.setFromPos(1,5,sirPtNumar);

    Mat = Sheep | Laz | myAst;
}



//  ~~~GAME OVER~~~

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
*/
                        //  ~~SETUP~~



// ~~LOOP~~
/*
void loop()
{
    MillisWait::readTime();

    if(myMenu)
    {
        ///MY MENU FUNCTION
    LCD.setString(0,"Asteroid Storm");
    LCD.setString(1,"Press to START");

    leftBtn.ifPressed();
    rightBtn.ifPressed();
    }
    else
    {
        if(gameOver)
        {       ///GAME FINISH CONDITION
            if(outofLives)
            {
                ///GAME'S ENDING METOD
                char sirScor[7];
                itoa(someScore[0],sirScor,10);

                LCD.setString (0, "Final score:    ");
                LCD.setFromPos (0, 13, sirScor );
                LCD.setString (1, " Replay    Exit ");

                leftBtn.ifPressed();
                rightBtn.ifPressed();
                
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

                    leftBtn.setAction(Replay);
                    rightBtn.setAction(Exit);

                    someScore[0] = 0;
                    for(int i=1;i<=3;i++) 
                        {
                            someScore[0] += someScore[i];
                            someScore[i] = 0;
                        }
                    delay(250);
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
                    //  GAME UPDATE FUNCTION
    }

    if(ragazAfisaj.isOk()) LCD.printStrings();
    Mat.playOn(lc);

}*/

