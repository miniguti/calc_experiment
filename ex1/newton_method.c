// Newton's method.


#include <stdio.h>
#include <math.h>

#define EPS pow(10.0,-15)
#define KMAX 1000

double func(double x);
double derf(double x);

int main()
{
  int k=0;
  double x, d;
  printf("#Initial value of x\n");
  scanf("%lf", &x);

  do{
    d = -func(x)/derf(x);
    x = x + d;
    printf("%d %20.15lf 2.154434690031884\n", k, x);
    k++;
  }while( fabs(d) > EPS && k < KMAX); 

  if( k == KMAX ){
    printf("The answer could not be found.\n" );
  }
  return 0; 
}

double func( double x){
  return ( pow(x, 3.0) - 10.0 );
}
double derf(double x){
  return( pow(x, 3.0) );
}
