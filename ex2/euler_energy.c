//Euler法でエネルギーを計算し、その時間変化を求めるプログラム
#include <stdio.h>
#include <math.h>

double func(double t,  double x, double v); //加速度関数

int main(void){
  double t, x, v, temp, h, energy;
  int i, m, n;
  x = 10.0; //初期値
  v = 0.0; //初速度
  n = 30;
  m = 1;
  h = 0.1;
  for(i = 0;i < n;i++){  //h*n秒までループ
    if(i % m == 0){ //nを大きくして秒数が長くなるとdatファイルがあふれるのでデータを間引く
      energy = 0.5 * v * v + 0.5 * 2.0  * x * x; //エネルギー
      printf("%20.15lf %20.15lf\n", t, energy); //時間とエネルギーを出力
      temp = x;  //以下3行euler法実行部分
      x += v * h;
      v += func(t, temp, v) * h;
    }
    t = t + h;
  }

  return 0;
}

double func(double t, double x, double v)  // 加速度
{
  double k=2.0;
  return( -k * x); 
}

