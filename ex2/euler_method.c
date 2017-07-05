//Euler法

#include <stdio.h>
#include <math.h>

double func(double t,  double x, double v); //加速度の関数を宣言

int main(void){
<<<<<<< HEAD
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
  
  
=======
  double t, x, v, temp, h, theo;
  x = 10.0; //初期値 10[m]
  v = 0.0;  //初速度 0[m/s]
	theo = ;
	int i, n;
	n = 10;
	//刻み幅(ここをいろいろいじって精度を調べる)
	for(i=0;i<n;i++){
		h = pow(2, -i);
		x = 10.0;
		v = 0.0;
  for(t = 0.0 ; t <= 3.00000 ; t+=h){ // 30sまでループ
    //printf("%lf %lf\n",t, x); //時間と位置を出力
    temp = x;
    x = x + v * h;
    v = v + func(t,temp, v) * h;
  }
		printf("%lf %lf\n", h, x - theo);
	}
	
		
>>>>>>> f04cc360e9f8e6ee1fa170e3841424da5efca10f
  return 0;
}

double func(double t, double x, double v)  // 減衰振動の加速度
{
  double k=2.0;
  double kappa = 0.2;
	double g = 9.8;
  return( -g );  //加速度を返す
}

