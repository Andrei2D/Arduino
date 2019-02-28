#ifndef MAIN_MENU

#define MAIN_MENU

#include "Game.h"

//Highes scores
char scoreTexts [][17] = { "E:   ", "M:   ", "H:   "};
byte scoreOpt = 0;

//Difficulty select
char diffTexts [][17] = {"Easy", "Medium", "Hard"};
byte diffOpt = 0;

    //High scores menu functions
void prevScr () 
{
    if (scoreOpt > 0)
        scoreOpt -- ;
}

void nextScr ()
{
    if (scoreOpt < 2)
        scoreOpt ++;
}

void initScore ()
{            
    Ctrl.initV (nextScr, prevScr);
    leftBtn.setAction (Exit);
    rightBtn.setAction (Exit);
}

    //Difficulty menu functions
void prevDiff ()
{
    if (diffOpt > 0)
        diffOpt -- ;
}
void nextDiff ()
{
    if (diffOpt < 2)
        diffOpt ++ ;
}


void selectDiff ()
{
    difficulty = diffOpt;
    myAst.setDiff (diffOpt); 
    Exit ();
}


void initDiff ()
{
    Ctrl.initV (nextDiff, prevDiff);
    leftBtn.setAction (selectDiff);
    rightBtn.setAction (Exit);
}


//MENU
char menuTexts [][17] = {"Start game", "Set Dificulty", "High score"};
byte menuOpt = 0;

    ///change state from menu to game
void startFromMenu ()
{
    gameOver = false;
    outofLives = false;
    initGame();
}

void menuUp () 
{
    if (menuOpt > 0)
        menuOpt -- ;
}

void menuDown ()
{
    if (menuOpt < 2)
        menuOpt ++ ;
}


void menuBtnSelect ()
{
    switch (menuOpt + 1)
    {
        case GAME:
            startFromMenu ();
            gameState = GAME;
            Serial.print ("Game state: ");
            Serial.println (gameState);
            break;
        
        case DIFF:
            initDiff();
            gameState = DIFF;
            break;
        
        case SCORE:
            initScore ();
            gameState = SCORE;
            break;

        default:
            Serial.println("Selected something");
            break;
    }  
    delay(250); 
}


    //reinit game (replay)
void Replay()
{
    gameOver = false;
    outofLives = false;
    initGame();
}

    //init menu
void Exit()
{
    gameState = MENU;

    Mat.clearMatrix();
    gameOver = false;
    outofLives = false;
    //myMenu = true;

    Ctrl.initV(menuDown, menuUp);
    Ctrl.setDelay(200);
    leftBtn.setAction (menuBtnSelect);
    rightBtn.setAction (menuBtnSelect);
    Serial.println("Exit");
    delay(200);
}

#endif //MAIN_MENU