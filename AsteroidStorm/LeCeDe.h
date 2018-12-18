#ifndef LECEDE_H

#define LECEDE_H

#include <LiquidCrystal.h>
#include <Arduino.h>
#include <string.h>
#define MAX_WIDTH_LCD 16


class LeCeDe: public LiquidCrystal
{
    char leStrings[2][MAX_WIDTH_LCD + 1];
public:
    LeCeDe(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t , uint8_t);

    void defHW();
    void printStrings();
    void setFromPos (short wichOne, short wichPos, char* wichString);
    void setString(short wichOne, char* wichString);
    void initArrows();

};


#endif ///LECEDE_H