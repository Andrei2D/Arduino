#ifndef GAME_CONTROL

#define GAME_CONTROL


#include <LedControl.h>
#include "MatrixRelated.h"
#include "AlgPushButton.h"

#define INIT_GAME 0
#define UPDATE 1

#define LOSE_COND 30
#define WARN_LOSE_COND 31

#define GAME_OVER 9
#define FINAL_SCORE 10
#define EXIT_GAME 13

struct GameControl
{
  Matrix8x8 Mat;
  LedControl* LED;
  LeCeDe* LCD;
  JoiceStick* Joy;
  JoiceStick* JoySec;
  AlgPushButton* leftBtn;
  AlgPushButton* rightBtn;
  AlgPushButton* JoyBtn;
  AlgPushButton* JoySecBtn;
  MillisWait wait_LCD;

//~~~~~~
  GameControl()
  {
      LED = NULL;
      LCD = NULL;
      Joy = NULL; JoySec = NULL;
      leftBtn = NULL; rightBtn = NULL;
      JoyBtn = NULL;  JoySecBtn = NULL;
      Mat.clearMatrix();
  }

  void init_LED (int dataPin, int clkPin, int csPin, int numDevices)
  {
    LED = new LedControl(dataPin, clkPin, csPin, numDevices);
    
    LED -> shutdown(0, false); 
    LED -> setIntensity(0, 0); 
    LED -> clearDisplay(0);
  }

  void init_LCD (short Res, short Enb, short de0, short de1, \
    short de2, short de3, unsigned long ragaz = 500)
  {
    LCD = new LeCeDe(Res, Enb, de0, de1, de2, de3);
    wait_LCD.setDelay(ragaz);
  }

  void init_Joy(int anlX, int anlY, int btnPin)
  {
    Joy = new JoiceStick(anlX, anlY);
    JoyBtn = new AlgPushButton(btnPin);
  }


  void init_JoySec(int anlX, int anlY, int btnPin)
  {
    JoySec = new JoiceStick(anlX, anlY);
    JoySecBtn = new AlgPushButton(btnPin);
  }

  void init_PushBtns (int left, int right)
  {
    leftBtn = new AlgPushButton(left);
    rightBtn = new AlgPushButton(right);
  }

  void setLCDtext(char* upperText, char* lowerText)
  {
    LCD->setString (0, upperText);
    LCD->setString (1, lowerText);
  }

  void set_buttons_delay(unsigned long left, unsigned long right)
  {
    leftBtn->setDelay(left);
    rightBtn->setDelay(right);
  }

  void set_joy_buttons_delay(unsigned long prim, unsigned long sec = 0)
  {
    if(prim) JoyBtn->setDelay(prim);
    if(sec) JoySecBtn->setDelay(sec);
  }

  void set_buttons_actions (void (*left)() = NULL, void(*right)() = NULL)
  {
    leftBtn->setAction(left);
    leftBtn->setAction(right);
  }
    
  void set_joy_buttons_actions (void (*prim)() = NULL, void(*sec)() = NULL)
  {
    JoyBtn->setAction(prim);
    JoySecBtn->setAction(sec);
  }

  void checkAll()
  {
    Joy -> checkH();
    Joy -> checkV();
    Joy -> checkH();
    JoySec -> checkV();

    leftBtn -> ifPressed(); rightBtn -> ifPressed();
    JoyBtn -> ifPressed();  JoySecBtn -> ifPressed();
  }

  void play()
  {
    if(wait_LCD.isOk()) GameControl::LCD->printStrings();
    Mat.playOn(*LED);
  }
};


class MiniGame
{
protected:
    int livesLeft, score[4];
    // Timer to be used within functions
    MillisWait timer;
    // Current state of the game
    int currState;   
    GameControl* Ctrl;
public:
    MiniGame() {currState = INIT_GAME; }
    void setIO(GameControl* Ctr) {Ctrl = Ctr;}
    void setState(int STATE) {currState = STATE;}
    int checkState() {return currState;}
    virtual void init() = 0;      //  INITIALIZATING FUNCTION
    virtual void update() = 0;      //  UPDATE FUNCTION 
    virtual void gameOver() = 0;
    virtual void loseCond() {}
    virtual void warnLosing() {}
    virtual void finalScore() {}
    
};


#endif //GAME_CONTROL