/*__  __       _        _      ___      ___  
 |  \/  | __ _| |_ _ __(_)_  _( _ )_  _( _ ) 
 | |\/| |/ _` | __| '__| \ \/ / _ \ \/ / _ \ 
 | |  | | (_| | |_| |  | |>  < (_) >  < (_) |
 |_|  |_|\__,_|\__|_|  |_/_/\_\___/_/\_\___/ 
*/
#ifndef MATRIX_8X8

#define MATRIX_8X8

#include <LedControl.h>

/* Simulare matrice de leduri cu un vector
    cu 8 elemente de tip byte */
class Matrix8x8
{
protected:

  byte octaMat[8];
  
public: 

  Matrix8x8();

  void shLeft();    //Shiftare stanga
  void shRight();   //Shiftare dreapta
  void shUp();      //Shiftare in sus, inlocuire ultimul elemente cu 0
  void shDown();    //Shiftare in jos, inlocuire primul elemente cu 0

  //Operatori logici pe biti pentru matrice
  Matrix8x8 operator| (const Matrix8x8&);
  Matrix8x8 operator& (const Matrix8x8&);
  Matrix8x8 operator^ (const Matrix8x8&);
  Matrix8x8 operator~ ();
  
  //Operatori logici si atributionari
  bool  operator== (const Matrix8x8&);
  bool  operator!= (const Matrix8x8&);
  int operator= (const Matrix8x8&);
  int operator= (const byte Mat[]);
  byte& operator[](int i);   
                                //Metoda de transpunere a continutului pe o matrice
  void playOn(LedControl&);       //prin-un element din libraria LedControl
  void clearMatrix();
};

#endif ///MATRIX_8X8


/*
  ____                       ____  _     _       
 / ___| _ __   __ _  ___ ___/ ___|| |__ (_)_ __  
 \___ \| '_ \ / _` |/ __/ _ \___ \| '_ \| | '_ \ 
  ___) | |_) | (_| | (_|  __/___) | | | | | |_) |
 |____/| .__/ \__,_|\___\___|____/|_| |_|_| .__/ 
       |_|                                |_|    
*/
#ifndef SPACESHIP_H

#define SPACESHIP_H


/*
  Clasa care simuleaza miscarile unei navete spatiale 
    pe doua randuri ale matricii dar care este totusi
    derivata din clasa Matrix8x8
*/
class SpaceShip : public Matrix8x8
{
  byte defShip [2];             //Default ship model
  byte leftGunPos, rightGunPos; //Pozitiile armelor, returnate pentru clasa ShipLasers

  public:
  SpaceShip ();
  
  void moveLeft ();
  void moveRight ();

  byte leftGun ();
  byte rightGun ();

  void resetPosition ();
  void didCollide (bool&, Matrix8x8&);

};

#endif /// SPACESHIP_H

/*
  ____  _     _       _                            
 / ___|| |__ (_)_ __ | |    __ _ ___  ___ _ __ ___ 
 \___ \| '_ \| | '_ \| |   / _` / __|/ _ \ '__/ __|
  ___) | | | | | |_) | |__| (_| \__ \  __/ |  \__ \
 |____/|_| |_|_| .__/|_____\__,_|___/\___|_|  |___/
               |_|                                 
*/
#ifndef SHIPLASERS_H

#define SHIPLASERS_H

#include "MillisWait.h"

class ShipLasers : public Matrix8x8
{
  byte laserTracker;
  MillisWait lazWait, penaltyWait;  
public:
  ShipLasers();
  void update();
  int howMuchOnes(byte toDisecate);
  void contact(Matrix8x8&,int&);
  void addLaser(byte);
  void setDelay(unsigned long);
  void resetDelay();
};

#endif /// SHIPLASERS_H


/*
     _        _                 _     _     
    / \   ___| |_ ___ _ __ ___ (_) __| |___ 
   / _ \ / __| __/ _ \ '__/ _ \| |/ _` / __|
  / ___ \\__ \ ||  __/ | | (_) | | (_| \__ \
 /_/   \_\___/\__\___|_|  \___/|_|\__,_|___/
                                            
*/
#ifndef ASTEROIDS_H

#define ASTEROIDS_H

#include "MillisWait.h"


class Asteroids : public Matrix8x8
{
  short diff;
  MillisWait astWait;
 public:
  Asteroids();
  Asteroids(short,short);
  byte twoPower(short);
  void raiseDiff();
  void setDiff(unsigned long aDiff);
   byte intToByte(int);
  byte genField (short);
  void addMeteors (bool& gameOver);
  void setDelay(unsigned long aDelay);

};

#endif ///ASTEROIDS_H
