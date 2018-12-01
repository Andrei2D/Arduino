#include "Matrix8x8.h"
#define zerO B00000000

  Matrix8x8::Matrix8x8()
  {
    clearMatrix();
  }

  void Matrix8x8::shLeft()
  {
    for(int i=0;i<8;i++) 
      octaMat [ i ]  = octaMat [ i ]  << 1;  
  }
  
  void Matrix8x8::shRight()
  {
    for(int i = 0; i < 8; i ++ ) 
      octaMat [ i ]  = octaMat [ i ]  >> 1;
  }
  
  void Matrix8x8::shUp()
  {
    for ( int i = 1; i < 8; i ++ )
      octaMat [ i - 1 ] = octaMat [ i ] ;
    octaMat [ 7 ] = zerO;
  }
  
  void Matrix8x8::shDown()
  {
    for(int i = 7; i >= 0; i -- )
      octaMat [ i + 1 ] = octaMat [ i ];
     octaMat[ 0 ] = zerO;
  }
  
  Matrix8x8 Matrix8x8::operator| (const Matrix8x8& mat)
  {
    Matrix8x8 result;
    for( int i = 0; i < 8; i++) 
      result.octaMat[ i ] = octaMat [ i ] | mat.octaMat [ i ];
    return result;
  }
  
  Matrix8x8 Matrix8x8::operator& (const Matrix8x8& mat)
  {
    Matrix8x8 result;
    for( int i = 0; i < 8; i++) 
      result.octaMat[ i ] = octaMat [ i ] & mat.octaMat [ i ];
    return result;
  }
  
  Matrix8x8 Matrix8x8::operator^ (const Matrix8x8& mat)
  {
    Matrix8x8 result;
    for( int i = 0; i < 8; i++) 
      result.octaMat[ i ] = octaMat [ i ] ^ mat.octaMat [ i ];
    return result;
  }
  
  Matrix8x8 Matrix8x8::operator~ ()
  {
    Matrix8x8 result;
    for( int i = 0; i < 8; i++) 
      result.octaMat[ i ] = ~ octaMat [ i ];
    return result;
  }

  bool  Matrix8x8::operator== (const Matrix8x8& mat)
  {
    for( int i = 0; i < 7; i ++ )
      if ( octaMat [ i ] != mat.octaMat [ i ] ) return 0;
    return 1;
  }  
  
  bool  Matrix8x8::operator!= (const Matrix8x8& mat)
  {
    for( int i = 0; i < 7; i ++ )
      if ( octaMat [ i ] != mat.octaMat [ i ] ) return 1;
    return 0;
  }

  int Matrix8x8::operator= (const Matrix8x8& mat)
  {
    if (this == &mat) return 0;

    for ( int i = 0; i <  8; i ++ ) 
      octaMat [ i ] = mat [ i ];
    return 1;
  }

  byte& Matrix8x8::operator[](int i)
  {
    if ( i < 0 || i > 7 ) return;

    return octaMat[i];
  }
  
  void Matrix8x8::playOn(LedControl& LC)
  {
    LC.clearDisplay(0);
    for(int i = 0; i < 8; i ++ )
      LC.setRow ( 0, i, octaMat [ i ] );
  }
  
  void Matrix8x8::clearMatrix()
  {
    for( int i = 0; i < 8; i ++ )
      octaMat [ i ] = zerO;
  }
