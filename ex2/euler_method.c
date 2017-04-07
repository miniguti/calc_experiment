#include <stdio.h>
#include <math.h>

double func_x(double t,  double x, double v);

int main(void){
  double t, x, v, dt;
  
  printf("#time step \n"); scanf("%lf",&dt);
  printf("#_initial_values_of_x\n"); scanf("%lf",&x);
  printf("#_initial_values_of_v\n"); scanf("%lf",&v);

  for(t = 0.0 ; t < 10.0 ; t+=dt){
    printf("%lf %lf %lf \n",t, x, v);
    v += func_x(t,x, v)*dt;
    x += v*dt;
  }
  return 0;
}

double func_x(double t, double x, double v)  // acceleration
{
  double k=2.0;
  double kappa = 0.2;
  return( -k * x - kappa * v ); 
}

