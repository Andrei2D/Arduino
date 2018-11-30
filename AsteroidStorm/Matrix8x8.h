#ifndef MATRIX_8X8

#define MATRIX_8X8

#include "LedControl.h"

class Matrix8x8
{
protected:

  /*
   * Masca de biti pentru a fi proiectata pe o
   *  o matrice de 8x8 LED-uri
   */
  byte octaMat[8];
  
public: 

  /*
   * Initializare cu o matrice goala
   */
  Matrix8x8();

  /*
   * Shiftare continut matrice la stanga
   */
  void shLeft();

  /*
   * Shiftare continut matrice la dreapta
   */
  void shRight();

  /*
   * Shiftare continut matrice in sus
   */
  void shUp();

  /*
   * Shiftare continut matrice in jos
   */
  void shDown();

  /*
   * Operator 'sau' pe biti 
   */
  Matrix8x8 operator| (const Matrix8x8&);

  /*
   * Operator 'si' pe biti 
   */
  Matrix8x8 operator& (const Matrix8x8&);

  /*
   * Operator 'xor'  pe biti 
   */
  Matrix8x8 operator^ (const Matrix8x8&);

  /* 
   *  Complementara matricei
   */
  Matrix8x8 operator~ ();

  /*
   * Operator logic 'egal'
   */
  bool  operator== (const Matrix8x8&);

  /*
   * Operator logic 'diferit'
   */
  bool  operator!= (const Matrix8x8&);

  /*
   * Operator 'egal'
   */
  int operator= (const Matrix8x8&);

  /*
   * Operator de acces al alementelor vectorului
   */
  byte& operator[](int i);

  /*
   * Metoda de imprimare a mastii de biti pe o matrice 
   *  printr-un parametru LedControl dat
   */
  void playOn(LedControl&);

  /*
   * Stergere continut matrice
   */
  void clearMatrix();
};

#endif ///MATRIX_8X8
