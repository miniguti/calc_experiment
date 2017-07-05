// Newton's method.


#include <stdio.h>
#include <math.h>

#define EPS pow(10.0,-15)
#define KMAX 100

double func(double x); //関数
double derf(double x); //その導関数

int main()
{
<<<<<<< HEAD
  int k=0;
  double x_0 = 2.154434690031884;
=======
  int k=1;
>>>>>>> f04cc360e9f8e6ee1fa170e3841424da5efca10f
  double x, d;
  x = 3.0;
  printf("%d %20.15lf\n", 0, x - 2.154434690031884); //初期の真値との差を出力
  do{
    d = -func(x) / derf(x);
    x = x + d;
<<<<<<< HEAD
    printf("%d %20.15lf \n", k, x - x_0);
=======
    printf("%d %20.15lf\n", k, x - 2.154434690031884); //反復回数と真値との差をループ毎に出力
>>>>>>> f04cc360e9f8e6ee1fa170e3841424da5efca10f
    k++;
  }while( fabs(d) > EPS && k < KMAX); //このように条件づけることでループが終わらなくなること防ぐ

  if( k == KMAX ){
    printf("The answer could not be found.\n" );
  }
  return 0; 
}

double func( double x){
  return ( pow(x, 3.0) - 10.0 );
}
double derf(double x){
<<<<<<< HEAD
  return( 3 * pow(x, 2.0) );
=======
  return( 3.0 * pow(x, 2.0) );
>>>>>>> f04cc360e9f8e6ee1fa170e3841424da5efca10f
}
