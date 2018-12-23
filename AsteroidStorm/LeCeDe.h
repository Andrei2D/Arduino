#ifndef LECEDE_H

#define LECEDE_H

#include "LiquidCrystal.h"
#include <Arduino.h>
#include <string.h>
#define MAX_WIDTH_LCD 16


class LeCeDe: public LiquidCrystal
{
    char leStrings[2][MAX_WIDTH_LCD + 1];
public:
    LeCeDe(uint8_t Res, uint8_t Enb, uint8_t de0, uint8_t de1, uint8_t de2, uint8_t de3);

    void defHW();
    void printStrings();
    void setFromPos (short wichOne, short wichPos, char* wichString);
    void setString(short wichOne, char* wichString);
    void clearStrings();
    void initArrows();

};


#endif ///LECEDE_H