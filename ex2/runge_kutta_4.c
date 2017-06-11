//4次のルンゲクッタ法

#include <stdio.h>
#include <math.h>
#define N 2

void rk4(void (*func)(), double t, double x[],  double h); //ルンゲクッタ実行関数
void furiko(double k[], double t,double x[]); //調和振動子
void freefall(double k[], double t,double x[]);  //自由落下
void forced(double k[], double t,double x[]);  //強制振動
void damped(double k[], double t, double x[]);  //減衰振動

int main(void){
  double t,x[N],h;
  h = 0.1; //刻み幅
  x[0] = 10.0; //初期値
  x[1] = 0.0; //初速度
  for(t=0.0; t < 30.001 ; t+=h){  //30秒までループ
    printf("%lf %lf\n",t, x[0]); //時間と位置を出力
    rk4(damped,t,x,h);  //ルンゲクッタ実行
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


void damped(double k[], double t, double x[])
{
	double spring_const = 2.0;
	double kappa = 0.2;
	
	k[0] = x[1];
	k[1] = -spring_const * x[0] - kappa * x[1];
}