#ifndef DECLARATIONS

#define DECLARATIONS

#include "MillisWait.h"
#include "Periferics.h"
#include "MatrixRelated.h"
#include "AlgPushButton.h"

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

#define BLANK_ARR "                "

LedControl lc = LedControl (DATA_PIN, CLK_PIN, CS_PIN, 1);
LeCeDe LCD (RS_PIN, ENB_PIN, D0_PIN_M, D1_PIN_M, D2_PIN_M, D3_PIN_M);
JoiceStick Ctrl (X_PIN_PRIM, Y_PIN_PRIM);
AlgPushButton leftBtn (LEFT_BTN_PIN);
AlgPushButton rightBtn (RIGHT_BTN_PIN);
AlgPushButton JoyBtn (JOY_BTN_PRIM);

SpaceShip Sheep;
Matrix8x8 Mat;
ShipLasers Laz;
Asteroids myAst;

MillisWait ragazAfisaj(500);

//game 
int someScore[4] = {0,0,0,0};

//flow control
bool gameOver = false;
bool outofLives = false;

//The states
const short MENU = 0;
const short GAME = 1;
const short DIFF = 2;
const short SCORE = 3;

short gameState = 0;  

// Game related
byte livesLeft = 3;
short difficulty = 0;
int highestScore[3] = {0, 0, 0};


#endif // DECLARATIONS