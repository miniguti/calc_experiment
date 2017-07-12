/* べき乗法により与えられた行列の第一固有値を求めるプログラム */


#include "../matrix_util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define LMAX 1000
#define epsilon pow(10, -7)

int imin(int x, int y) { return (x < y) ? x : y; }
int imax(int x, int y) { return (x > y) ? x : y; }

int main(int argc, char** argv) {
  char* filename;
  FILE *fp;
  int i, j, k, l;

  int m, n, r;
  double **a;
  double *v, *c, *temp;
  double v_norm, theo, eigen_value, temp_value, diff, mother, child;


  if (argc < 2) {
    fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
    exit(1);
  }
  filename = argv[1];

  /* read matrix A from a file */
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: file can not open\n");
    exit(1);
  }
  read_dmatrix(fp, &m, &n, &a);
  //printf("Matrix A:\n");
  //fprint_dmatrix(stdout, m, n, a);

  /* allocate matrices and vectors */
  v = alloc_dvector(n);
  c = alloc_dvector(n);
  temp = alloc_dvector(n);
  /* calc theoretical value */
  theo = 0.5 / (1 - cos(M_PI/(2 * n + 1)));


  /* initial value of vector v */
  for(i=0;i<n;i++){
  	v[i] = i + 1;
  }
	for(i = 0;i < n;i++){
		v_norm += pow(v[i], 2);
	}
	v_norm = pow(v_norm, 0.5);
  for(i=0;i<n;i++){
    c[i] = v[i] / v_norm;
  }

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
  temp_value = eigen_value;
  eigen_value = child / mother;
  diff = fabs(eigen_value - temp_value);
  	printf("%d %20.15lf\n", l+1, eigen_value);
  l += 1;
  }while((diff > epsilon) && (l < LMAX));



	//printf("theoretical value is %lf\n", theo);

  free_dmatrix(a);
  free_dvector(v);
  free_dvector(c);
  free_dvector(temp);

}
