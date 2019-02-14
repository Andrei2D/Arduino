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
