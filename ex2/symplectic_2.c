#include <stdio.h>
#include <math.h>
#define N 2

void rk4(void (*func)(), double t, double x[],  double h);
void symplectic(void (*func)(), double t, double x[], double h);
void euler(void (*func)(), double t, double x[], double h);
void furiko(double k[], double t,double x[]);
void freefall(double k[], double t,double x[]);
void forced(double k[], double t,double x[]);
void damped(double k[], double t, double x[]);

int main(void){
  double t,x[N],h, energy;
	int i, n;
  double t0; 
	n = 20;
	t = 0.0;
	x[0] = 10.0;
	x[1] = 0.0;
		h = 0.1;
  for(i=0; i < 10000000 ; i++){
  	t = t + h;
  	if(i % 10000 == 0){
  	energy = 0.5 * x[1] * x[1] + 0.5 * 2.0 * x[0] * x[0];
    printf("%20.15lf %20.15lf\n",0.00001 * t, energy);
  	}
  	
    //    rk4(freefall, t,x,h); 
    //    euler(freefall,t,x,h); 
    //euler(damped,t,x,h);
     //rk4(furiko,t,x,h); 
  	symplectic(damped, t, x, h);
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

void symplectic(void (*func)(), double t, double x[], double h)
{
  double k1[N];
  func(k1,t,x);
  x[0]=x[0]+h*x[1];
	x[1]= x[1] - h * 2.0 * x[0];
}


void euler(void (*func)(), double t, double x[], double h)
{
	double k1[N];
	func(k1, t, x);
	x[0] = x[0] + h * k1[0];
	x[1] = x[1] + h * k1[1];
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

void damped(double k[], double t, double x[])
{
	double spring_const = 2.0;
	double kappa = 0.0;
	
	k[0] = x[1];
	k[1] = -spring_const * x[0] - kappa * x[1];
}

void forced(double k[], double t, double x[] )
{
  double k1=1.0;
  double omega=0.9;
  double amp = 0.1; 
  k[0] = x[1];
  k[1] = -k1*x[0]+amp*sin(omega*t);
}
