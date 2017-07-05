#include <stdio.h>
#include <math.h>
#define N 2

void euler(void (*func)(), double t, double x[],  double h);
void furiko(double k[], double t,double x[]);
void freefall(double k[], double t,double x[]);
void forced(double k[], double t,double x[]);
void damped(double k[], double t, double x[]);

int main(void){
  double t,x[N],h;
	int i, n;
  double t0; 
	n = 20;
	t = 0.0;
//	for(i=0;i < n;i++){
		h = 0.05;;
		x[0] = 10.0;
		x[1] = 0.0;
  for(t=0.0; t <= 30.0000001 ; t+=h){
    printf("%lf %lf %lf \n",t, x[0], x[1]);
     //   rk4(freefall, t,x,h); 
      //  euler(freefall,t,x,h); 
    //euler(forced,t,x,h);
     euler(damped,t,x,h); 
  }
    
//		printf("%.20lf %.20lf\n", h, x[0]);
//	}
	
  return 0;
}

void euler(void (*func)(), double t, double x[], double h)
{
  double k1[N];
  func(k1,t,x);
  x[0]=x[0]+h*k1[0];
  x[1]=x[1]+h*k1[1];
}

void furiko(double k[], double t, double x[] )
{
  k[0] = x[1];
  k[1] = -x[0];
}


void damped(double k[], double t, double x[])
{
	double spring_const = 2.0;
	double kappa = 0.2;
	
	k[0] = x[1];
	k[1] = -spring_const * x[0] - kappa * x[1];
}


void freefall(double k[], double t, double x[] )
{
  double g=10.0; 
  k[0] = x[1];
  k[1] = -g;
}


