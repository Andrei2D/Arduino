#ifndef MATRIX_8X8

#define MATRIX_8X8

#include <LedControl.h>

class Matrix8x8
{
protected:

  byte octaMat[8];
  
public: 

  Matrix8x8();

  void shLeft();
  void shRight();
  void shUp();
  void shDown();

  Matrix8x8 operator| (const Matrix8x8&);
  Matrix8x8 operator& (const Matrix8x8&);
  Matrix8x8 operator^ (const Matrix8x8&);
  Matrix8x8 operator~ ();
  
  bool  operator== (const Matrix8x8&);
  bool  operator!= (const Matrix8x8&);
  int operator= (const Matrix8x8&);
  byte& operator[](int i);

  void playOn(LedControl&);
  void clearMatrix();
};

#endif ///MATRIX_8X8
