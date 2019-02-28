#include "Menu.h"


void setup()
{
    lc.shutdown(0, false); 
    lc.setIntensity(0, 0); 
    lc.clearDisplay(0);

    livesLeft = 3;

    Exit();
}


void loop()
{
    MillisWait::readTime();

    switch (gameState)
    {
    case MENU :
        LCD.setString(0,"Asteroid Storm");
        LCD.setString(1, menuTexts[menuOpt]);

        leftBtn.ifPressed();
        rightBtn.ifPressed();
        Ctrl.checkV();
        break;

    case GAME:
        if(gameOver)
        {
            if(outofLives)
                finalScore();
            else
                lostLife();
        }
        else
                theActualGame();
        break;

    case DIFF:
        LCD.setString (0, "Select Diff");
        LCD.setString (1, diffTexts[diffOpt]);

        leftBtn.ifPressed();
        rightBtn.ifPressed();
        Ctrl.checkV();
        break;

    case SCORE:
        LCD.setString (0, "  Score record: ");


        char scoreITOA[6];
        itoa (highestScore[scoreOpt], scoreITOA, 10);

        LCD.setString (1, scoreTexts[scoreOpt]);
        LCD.setFromPos (1, strlen (scoreTexts[scoreOpt]), scoreITOA);

        leftBtn.ifPressed();
        rightBtn.ifPressed();
        Ctrl.checkV();
        break;  
            
    default:
        break;
    }
    
    if(ragazAfisaj.isOk()) LCD.printStrings();
    Mat.playOn (lc);

}
