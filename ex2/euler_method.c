#include <stdio.h>
#include <math.h>

double func_x(double t,  double x, double v);

int main(void){
  double t, dt;
  double x = 10.0;
  double v = 0.0;
  int i;
   for(i = 0;i< 100;i++){
   dt = 1.0 - i * 0.001;
  for(t = 0.0 ; t < 30.0 ; t+=dt){
    //dt = 0.01;
    v += func_x(t,x, v)*dt;
    x += v*dt;
    //printf("%.15lf  %.15lf\n", t, x);
  }
   printf("%lf %.15lf\n", dt, x);
   }
  
  
  return 0;
}

double func_x(double t, double x, double v)  // acceleration
{
  double k=2.0;
  double kappa = 0.2;
  return( -k * x - kappa * v ); 
}

