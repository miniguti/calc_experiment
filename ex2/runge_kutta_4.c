#include <stdio.h>
#include <math.h>
#define N 2

void rk4(void (*func)(), double t, double x[],  double h);
void euler(void (*func)(), double t, double x[], double h); 
void furiko(double k[], double t,double x[]);
void freefall(double k[], double t,double x[]);
void forced(double k[], double t,double x[]);

int main(void){
  double t,x[N],h;
  double t0; 
  
  printf("#time step \n"); scanf("%lf",&h);
  printf("#_initial values (t,x[0],x[1])\n");
  scanf("%lf %lf %lf",&t0,&x[0],&x[1]);

  for(t=t0; t < 100.0 ; t+=h){
    printf("%lf %lf %lf \n",t, x[0], x[1]);
    /*    rk4(freefall, t,x,h); */
    /*    euler(freefall,t,x,h); */
    /*euler(forced,t,x,h);*/ 
     rk4(forced,t,x,h); 
  }
    
  return 0;
}

void rk4(void (*func)(), double t, double x[], double h)
{
  double k1[N],k2[N],k3[N],k4[N],f[N];
  func(k1,t,x);
  f[0]=x[0]+h*k1[0]/2.0;
  f[1]=x[1]+h*k1[1]/2.0;
  func(k2,t+h/2.0,f);
  f[0]=x[0]+h*k2[0]/2.0;
  f[1]=x[1]+h*k2[1]/2.0;
  func(k3,t+h/2.0,f);
  f[0]=x[0]+h*k3[0]; 
  f[1]=x[1]+h*k3[1];
  func(k4,t+h,f);
  x[0] = x[0] + h/6.0*( k1[0] + 2.0*k2[0] + 2.0*k3[0] + k4[0] );
  x[1] = x[1] + h/6.0*( k1[1] + 2.0*k2[1] + 2.0*k3[1] + k4[1] );
}

void euler(void (*func)(), double t, double x[], double h)
{
  double k[N]; 
  func(k,t,x);
  x[1] += k[1]*h; 
  x[0] += k[0]*h; 
}

void furiko(double k[], double t, double x[] )
{
  k[0] = x[1];
  k[1] = -x[0];
}

void freefall(double k[], double t, double x[] )
{
  double g=9.8; 
  k[0] = x[1];
  k[1] = -g;
}

void forced(double k[], double t, double x[] )
{
  double k1=1.0;
  double omega=0.9;
  double amp = 0.1; 
  k[0] = x[1];
  k[1] = -k1*x[0]+amp*sin(omega*t);
}
