//vandermonde�s���datfile�쐬

#include<stdio.h>
#include<math.h>

int main(void){

  double x[5] = {1.0, 2.0, 3.0, 4.0, 5.0}; //���R�Ɍ��߂��
  double a[5][5];  //x�̃T�C�Y�ɂ�荶�E
  int i, j, n;
  n = 5;//x�̃T�C�Y�ɂ�荶�E


  printf("%d %d\n", n, n);

  for (i = 0;i < n;i++){
    for (j = 0;j < n;j++){
      a[i][j] = pow(x[j], i);
      if(j < n - 1){
        printf("%lf ", a[i][j]);
      }else{
        printf("%lf\n", a[i][j]);
      }
    }
  }

  return 0;
}


