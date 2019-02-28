#ifndef THE_GAME
#define THE_GAME

#include "Declarations.h"


void mvSheepLeft () { Sheep.moveLeft(); }
void mvSheepRight () { Sheep.moveRight(); }

void shootLeft() { Laz.addLaser ( Sheep.leftGun() ); }
void shootRight() { Laz.addLaser ( Sheep.rightGun() ); }


void Replay();
void Exit();



void initGame()
{
    Laz.clearMatrix();
    myAst.clearMatrix();

    Laz.setDelay(70);    
    myAst.setDiff (difficulty); 

    leftBtn.setAction (shootLeft);
    rightBtn.setAction (shootRight);

    leftBtn.setDelay (190);
    rightBtn.setDelay (190);

    Ctrl.initH ( mvSheepLeft, mvSheepRight);
    Ctrl.initV (NULL, NULL);
    Ctrl.setDelay (120);

    LCD.setString (0, "     Score:     ");
    LCD.setString (1, BLANK_ARR);

}

    //update
void theActualGame() 
{
    
    Ctrl.checkH();
    leftBtn.ifPressed();
    rightBtn.ifPressed();
    Laz.update();

    someScore[livesLeft] += Laz.contact (myAst) * (difficulty + 1);
    gameOver = myAst.addMeteors ();
    gameOver = Sheep.didCollide (myAst);

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

void lostLifeWarn()
{

    LCD.setString(0,"You lost a life!");
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

void finalScore ()
{
    char sirScor[7];
    itoa(someScore[0],sirScor,10);

    highestScore[difficulty] = max (highestScore[difficulty], someScore[0]);

    LCD.setString (0, "Final score:    ");
    LCD.setFromPos (0, 13, sirScor );
    LCD.setString (1, " Replay    Exit ");

    leftBtn.ifPressed();
    rightBtn.ifPressed();
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


void lostLife()
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
        lostLifeWarn();
        initGame();
    }
}


#endif //THE_GAME
