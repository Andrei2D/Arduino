#include "LeCeDe.h"

    
    LeCeDe::LeCeDe(uint8_t Res, uint8_t Enb, uint8_t de0, uint8_t de1, uint8_t de2, uint8_t de3):LiquidCrystal(Res, Enb, de0, de1, de2, de3)
    {
        defHW();
        begin(MAX_WIDTH_LCD,2);
        printStrings();
    }
    
    void LeCeDe::defHW()
    {
        strcpy(leStrings[0]," Asteroid      ");
        strcpy(leStrings[1],"        Storm   ");
    }

    void LeCeDe::printStrings()
    {
        clear();
        setCursor(0,0);
        print(leStrings[0]);
        setCursor(0,1);
        print(leStrings[1]);
    }

    void LeCeDe::setFromPos (short wichOne, short wichPos, char* wichString)
    {
        strncpy( leStrings [wichOne%2] + wichPos, wichString,  MAX_WIDTH_LCD - wichPos);
        leStrings [wichOne%2][MAX_WIDTH_LCD] = '\0';
        
    }

    void LeCeDe::setString(short wichOne, char* wichString)
    {
        setFromPos(wichOne,0,wichString);
    }

    void LeCeDe::clearStrings()
    {
        setString(0,"                ");
        setString(1,"                ");
    }

   void LeCeDe::initArrows()
   {
     byte upAndDown[] = {
    B00100,
    B01010,
    B10001,
    B00000,
    B00000,
    B10001,
    B01010,
    B00100
    };

byte onlyUp[] = {
    B00100,
    B01010,
    B10001,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
    };
    
byte onlyDown[] = {
    B00100,
    B01010,
    B10001,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
    };

    createChar(0,upAndDown);
    createChar(1,onlyUp);
    createChar(2,onlyDown);
   }
