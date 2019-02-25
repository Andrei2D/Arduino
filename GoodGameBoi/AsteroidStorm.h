#ifndef ASTEROID_STORM

#define ASTEROID_STORM
#include "MatrixRelated.h"
#include "Periferics.h"
#include "GameControl.h"

#define INIT_GAME 0
#define UPDATE 1

#define LOSE_COND 30
#define WARN_LOSE_COND 31

#define GAME_OVER 9
#define FINAL_SCORE 10
#define EXIT_GAME 13

class AsteroidStorm: public MiniGame
{
    ShipLasers Laz;
    SpaceShip Sheep;
    Asteroids myAst;

        // Wheather it got hit by asteroids or it missed some of them, when losing a life
    bool hit_or_miss;

//urmatoarele 3 merg in clasa MiniGame

    void cfgInputs();
    void disableInputs();
    void xMatrix();    
    void resetStats();
public:
    AsteroidStorm() 
    {
        hit_or_miss = true;
        resetStats();
    }

        // INTRE Laz & myAst, score++
    int contact(); 
        // Intre Sheep & myAst, lives--
    bool didCollide();  
    void loseCond();
    void warnLosing();

        //  Initializing method
    void init();      
        // Method that updates the state of the game
    void update();      
    void gameOver();
    void finalScore();

    friend void mvLeft_AS ();
    friend void mvRight_AS ();
    friend void shootLeft_AS ();
    friend void shootRight_AS ();

}Ast_Storm;

void mvLeft_AS () { Ast_Storm.Sheep.moveLeft(); }
void mvRight_AS () { Ast_Storm.Sheep.moveRight(); }

void shootLeft_AS () { Ast_Storm.Laz.addLaser ( Ast_Storm.Sheep.leftGun() ); }
void shootRight_AS () { Ast_Storm.Laz.addLaser ( Ast_Storm.Sheep.rightGun() ); }

void AsteroidStorm::cfgInputs()
{
    Ctrl->set_buttons_actions (shootLeft_AS, shootRight_AS);
    Ctrl->set_buttons_delay(190,190);

    Ctrl->Joy->initH (mvLeft_AS, mvRight_AS);
    Ctrl->Joy->setDelay(120);
}

void AsteroidStorm::disableInputs()
{
    Ctrl->set_buttons_actions ();
    Ctrl->Joy->initH(NULL, NULL);
}

    // Method that initializing a new game then switches to the update state
void AsteroidStorm::init()
{
    Laz.clearMatrix();
    myAst.clearMatrix();    
    myAst.setDiff(livesLeft);
    Laz.setDelay(70);

    cfgInputs();

    Ctrl->setLCDtext("     Score:     ", "                ");
    Serial.println("Got inited");
    Serial.print("B4: "); Serial.println(currState);
    currState = UPDATE;
    Serial.print("Aftah: "); Serial.println(currState);
}

bool AsteroidStorm::didCollide()
{
  byte secLastLine = Sheep[6] & myAst[6];
  byte lastLine =  Sheep[7] & myAst[7];
  if(secLastLine != zerO || lastLine != zerO) 
    return true;
  return false;
}


int AsteroidStorm::contact()
{
    int hits = 0;
    for ( int i = 0; i < 7; i ++ )
    {
        byte meetUp = Laz [ i ] & myAst [ i ];
        if ( meetUp != zerO)
            {
            myAst [i] ^= Laz [i];
            Laz [i] -= meetUp;
            hits ++;
            }
    }
    return hits;
}

void AsteroidStorm::update()
{
    Serial.println("Z");
    Serial.println("Started updating");
    Ctrl->checkAll ();

    score[livesLeft] += contact ();

    Serial.println("Contacted");    
    
    if (myAst.addMeteors()) 
        {
            Serial.println("Meteoor");
            currState = LOSE_COND;
            hit_or_miss = true;
        }
    if (didCollide()) 
        {
            Serial.println("Colided");
            currState = LOSE_COND;
            hit_or_miss = false;
        }
    
    Serial.println("Got updated");

    char sirPtNumar[10];
    itoa(score[livesLeft],sirPtNumar,10);
    Ctrl->LCD->setFromPos(1,5,sirPtNumar);
    Ctrl->Mat = Sheep | Laz | myAst;
}


void AsteroidStorm::xMatrix ()
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
AsteroidStorm::Ctrl->Mat = Sheep | theX;
}

    //LOSE CONDITION
void AsteroidStorm::loseCond()
{
    livesLeft--;
    disableInputs();
    timer.initDelay(1000);
    if(livesLeft == 0)
    {
        currState = GAME_OVER;
        score[0] = 0;
        for (int i=1; i<=3; i++)
        {
            score[0] += score[i];
        }
    }
    else 
        currState = WARN_LOSE_COND;
}

void AsteroidStorm::resetStats()
{
    livesLeft = 3;
    for(int i = 0; i< 4; i++) score[i] = 0;
}

void Replay_AS () { Ast_Storm.setState(INIT_GAME);}

void Exit_AS () { Ast_Storm.setState(EXIT_GAME);}

void AsteroidStorm::gameOver()
{
    xMatrix();
    Ctrl->setLCDtext("#     GAME     #", "##    OVER!   ##");
    
    if(timer.isOk()) 
    {
            // Reseting score and lives
        Ast_Storm.resetStats();
        currState = FINAL_SCORE;

        Ctrl->set_buttons_actions(Replay_AS, Exit_AS);
        Ctrl->Mat.clearMatrix();

        char scorr[5];
        itoa(score[0],scorr,10);
        char Scr[20];
        strcat(Scr,"Final score: ");
        strcat(Scr, scorr);
        char Opt[20] = " Replay    Exit ";
        
        Ctrl->setLCDtext(Scr, Opt);
        delay(200);
    }

    Serial.println("Game over");
}

    // LOSE CONDITION
void AsteroidStorm::warnLosing()
{
    xMatrix();
    char Hit[] = "  You got hit!  ";
    char Pass[] = "Missed asteroids";
    char Ll[3]; 
    itoa(livesLeft, Ll, 10);
    Ctrl->setLCDtext ( hit_or_miss ? Hit : Pass, strcat("Lives left:     ", Ll));
    if(timer.isOk()) currState = INIT_GAME;
}

    // FINAL SCORE
void AsteroidStorm::finalScore()
{
    Ctrl->checkAll();
}


#endif // ASTEROID_STORM

