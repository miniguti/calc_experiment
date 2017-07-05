//中点法

#include <stdio.h>
#include <math.h>
#define N 2


void mid_point(void (*func)(), double t, double x[], double h); //中点法実行関数
void furiko(double k[], double t,double x[]);  //調和振動子
void freefall(double k[], double t,double x[]);  //自由落下
void damped(double k[], double t, double x[]);  //減衰振動

int main(void){
  double t,x[N],h;
  double t0; 
  h = 0.1;
  x[0] = 10.0; //初期値
  x[1] = 0.0; //初速度
  for(t=0.0; t < 30.001 ; t+=h){ //30秒までループ
    printf("%lf %lf\n",t, x[0]); //時間と位置を出力
    mid_point(damped, t, x, h); //中点法実行
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

