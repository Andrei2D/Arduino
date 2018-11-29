#ifndef JoiceStick_h

#define JoiceStick_h 

#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
///Some includes so there is no " 'A0' was not delcared " error

class JoiceStick
{
const int joyX;
const int joyY;
void (*goLeft)(void), (*goRight)(void);
void (*goUp)(void), (*goDown)(void);
int theDelay;
public:

JoiceStick();
JoiceStick(int, int);

void setDelay (int aDelay);
void resetVars();

void initX(void (*left)(), void (*right)());
void initY ( void (*down)(), void (*up)());

int isX ();
int isY ();

void checkX();
void checkY();

};

#endif //JoiceStick.h 
