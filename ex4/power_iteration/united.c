/* べき乗法により与えられた行列の第一固有値を求めるプログラム */


#include "../matrix_util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LMAX 1000
#define epsilon pow(10, -3)
#define NMAX 1000
int imin(int x, int y) { return (x < y) ? x : y; }
int imax(int x, int y) { return (x > y) ? x : y; }

int main(int argc, char** argv) {
  char* filename;
  FILE *fp;
  int i, j, k, l;

  int m, n, r;
  double **a;
  double *v, *c, *temp;
  double theo_1, theo_2, eigen_value, temp_eigen_value, diff, mother, child;
  clock_t start, end;

  for(n=1;n<NMAX;n++){

  /* allocate matrices and vectors */
  v = alloc_dvector(n);
  c = alloc_dvector(n);
  temp = alloc_dvector(n);
  a = alloc_dmatrix(n, n);
 
  /* generate matrix A */
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j] = imin(i+1, j+1);
    }
  }


  /* calc theoretical value */
  theo_1 = 0.5 / (1 - cos(M_PI/(2 * n + 1)));
  theo_2 = 0.5 / (1 - cos(3*M_PI/(2 * n + 1)));

  /* initial value of vector v */
  for(i=0;i<n;i++){
  	v[i] = 1.0 * pow((i - 10), 2);
  }
  for(i=0;i<n;i++){
    c[i] = v[i];
  }
  start = clock();
  /* perform power iteration */
  l = 0;
  do{
  mother = 0.0;
  child = 0.0;
  for(i=0;i<n;i++){
    temp[i] = c[i];
  }
  for(i=0;i<n;i++){
    c[i] = 0.0;
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      c[i] += a[i][j] * temp[j];
    }
  }

  for(i=0;i<n;i++){
    mother += c[i] * temp[i];
  }

  for(i=0;i<n;i++){
    child  += c[i] * c[i];
  }
  temp_eigen_value = eigen_value;
  eigen_value = child / mother;
  diff = fabs(eigen_value - temp_eigen_value);
  //printf("%d %20.15lf %lf\n", l+1, eigen_value, theo_1);
  l += 1;
  }while((diff > epsilon) && (l < LMAX));
  end = clock();
  if(n % 10 == 0){
    printf("%d %d %lf %lf %lf %lf\n", n, l, theo_1 ,theo_1 / theo_2, eigen_value, 1.0 / log(theo_1/theo_2));
  }
  }
/*
  //行列Aの出力
	
	printf("%d %d\n", n, n); //サイズの出力
	
	for (i = 0;i < n;i++){
		for (j = 0;j < n;j++){
			if(j < n - 1){
				printf("%lf ", a[i][j]);
			}else{
				printf("%lf\n", a[i][j]);
			}
		}
	}
*/
  free_dmatrix(a);
  free_dvector(v);
  free_dvector(c);
  free_dvector(temp);

}
