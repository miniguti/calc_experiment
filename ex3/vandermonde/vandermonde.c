/* output vandermonde matrix */

#include<stdio.h>
#include<math.h>

int main(void){

  double x[5] = {1.0, 2.0, 3.0, 4.0, 5.0}; //choose numbers you like
  double a[5][5];  // depends on the size of x[]
  int i, j, n;
  n = 5; // depends on the size of x[]


  printf("%d %d\n", n, n); //output the size of matrix

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


