
/* 与えられたx-yデータから計画行列を求めるプログラム */


#include "../matrix_util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



int imin(int x, int y) { return (x < y) ? x : y; }
int imax(int x, int y) { return (x > y) ? x : y; }

int main(int argc, char** argv) {
  char* filename;
  FILE *fp;
  int i, j, k;

  int l, m, n, r;
  double **a, **mat;
  double *v, *c, *temp;
  double theo, eigen_value, diff, mother, child;


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
  l = 3;
  mat = alloc_dmatrix(m, l);
  /* generate design matrix */
  for(i = 0;i < m;i++){
    for(j = 0;j < l;j++){
      mat[i][j] = pow(a[i][0], j);
    }
  }
  /* output design matrix */ 
	fprint_dmatrix(stdout, m, l, mat);

  /* output mesurement.dat */
	fprint_dmatrix(stdout, m, n, a);
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
  free_dmatrix(mat);

}
