#include <stdio.h>
#include <math.h>

double func_a(double t,  double x, double v);

double func_a_t(double t, double x,  double v);

double func_a_v(double t, double x, double v);

double func_v_x(double t, double x, double v);




int main(void){
  double k=2.0;
  double kappa = 0.2;
  double t, dt;
  double x = 10.0;
  double v = 0.0;
  double k_1;
  int i;
   for(i = 0;i< 100;i++){
   dt = 1.0 - i * 0.001;
  for(t = 0.0 ; t < 30.0 ; t+=dt){
    //dt = 0.01;
    v += dt * func_a(t, x, v) + 0.5 * dt * dt * (func_a_t(t, x, v) + func_a(t, x, v) * func_a_v(t, x, v));
    x += dt * v  + 0.5 * dt * dt * (func_a(t, x, v) + v * func_v_x(t, x, v));
    //printf("%.15lf  %.15lf\n", t, x);
  }
   printf("%lf %.15lf\n", dt, x);
   }
  
  
  return 0;
}

double func_a(double t, double x, double v)  // acceleration
{
  double k=2.0;
  double kappa = 0.2;
  return( -k * x - kappa * v ); 
}



double func_a_t(double t, double x, double v)
{
  double k=2.0;
  double kappa = 0.2;
  return (-k * v - kappa * func_a);
}

double func_a_v(double t, double x, double v)
{
  double k=2.0;
  double kappa = 0.2;
  return(-k / func_a * v  -kappa);
}

double func_v_x(double t, double x, double v)
{
  double k=2.0;
  double kappa = 0.2;

  return(func_a / v);
}



