#include <stdio.h>
#include <math.h>

double func_x(double t,  double x, double v);

int main(void){
  double t, x, v, temp, dt;
  int i, n;
  //printf("#time step \n"); scanf("%lf",&dt);
  //printf("#_initial_values_of_x\n"); scanf("%lf",&x);
  //printf("#_initial_values_of_v\n"); scanf("%lf",&v);
  x = 10.0;
  v = 0.0;
	double energy;
	n = 20;
	dt = 0.1;
		for(i = 0;i < 300;i++){
			t = t + dt;
			if(i % 1 == 0){
				
			energy = 0.5 * v * v + 0.5 * 2.0  * x * x;
			printf("%20.15lf %20.15lf\n", t, energy);
			//printf("%lf %lf %lf \n",t, x, v);
			temp = x;
			x += v*dt;
			v += func_x(t,temp, v)*dt;
			}
			
		}
		
	
	return 0;
}

double func_x(double t, double x, double v)  // acceleration
{
  double k=2.0;
  //double kappa = 0.2;
  return( -k * x); 
}