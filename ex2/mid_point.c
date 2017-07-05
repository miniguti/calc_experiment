//���_�@

#include <stdio.h>
#include <math.h>
#define N 2


void mid_point(void (*func)(), double t, double x[], double h); //���_�@���s�֐�
void furiko(double k[], double t,double x[]);  //���a�U���q
void freefall(double k[], double t,double x[]);  //���R����
void damped(double k[], double t, double x[]);  //�����U��

int main(void){
  double t,x[N],h;
  double t0; 
  h = 0.1;
  x[0] = 10.0; //�����l
  x[1] = 0.0; //�����x
  for(t=0.0; t < 30.001 ; t+=h){ //30�b�܂Ń��[�v
    printf("%lf %lf\n",t, x[0]); //���Ԃƈʒu���o��
    mid_point(damped, t, x, h); //���_�@���s
  }
  return 0;
}




void mid_point(void (*func)(), double t, double x[], double h)
{
  double k1[N],k2[N],k3[N],k4[N],f[N];
  func(k1,t,x);
  f[0]=x[0]+h*k1[0]/2.0;
  f[1]=x[1]+h*k1[1]/2.0;
  func(k2,t+h/2.0,f);
  x[0] = x[0] + h * k2[0];
  x[1] = x[1] + h * k2[1];
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
  double kappa = 0.2;

  k[0] = x[1];
  k[1] = -spring_const * x[0] - kappa * x[1];
}

