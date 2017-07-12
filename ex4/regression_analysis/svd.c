#include "../matrix_util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* http://www.netlib.org/lapack/explore-html/d8/d2d/dgesvd_8f.html */
void dgesvd_(char *JOBU, char* JOBVT, int *M, int *N, double* A,
             int* LDA, double* S, double* U, int* LDU, double* VT, int* LDVT ,
             double* WORK, int* LWORK, int* INFO);

int imin(int x, int y) { return (x < y) ? x : y; }
int imax(int x, int y) { return (x > y) ? x : y; }

int main(int argc, char** argv) {
  char* filename;
  FILE *fp;
  int i, j, k;

  int m, n, r, c, d;
  double **a, **y, **u, **ut, **v, **vt, **temp, **god;
  double *s, *w;

  int lwork;
  double *work;
  int info;
  char jobu = 'S';
  char jobvt = 'S';

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
	read_dmatrix(fp, &c, &d, &y);
  //printf("Matrix A:\n");
  //fprint_dmatrix(stdout, m, n, a);

  /* allocate matrices and vectors */
  r = imin(m, n);
  u = alloc_dmatrix(m, r);
  ut = alloc_dmatrix(r, m);
  v = alloc_dmatrix(n, r);
  vt = alloc_dmatrix(r, n);
  s = alloc_dvector(r);
  w = alloc_dvector(r);
  temp = alloc_dmatrix(n, r);
  god = alloc_dmatrix(n, m);
  
  lwork = imax(3 * r + imax(m, n), 5 * r);
  work = alloc_dvector(lwork);
  
  /* perform SVD */
  dgesvd_(&jobu, &jobvt, &n, &m, &a[0][0], &n, &s[0], &vt[0][0], &n,
          &u[0][0], &r, &work[0], &lwork, &info);
  if (info != 0) {
    fprintf(stderr, "Error: LAPACK::dgesvd failed\n");
    exit(1);
  }
  //printf("Result of SVD U:\n");
  //fprint_dmatrix(stdout, m, r, u);
  //printf("Result of SVD S:\n");
  //fprint_dvector(stdout, r, s);
  //printf("Result of SVD Vt:\n");
  //fprint_dmatrix(stdout, r, n, vt);

  /* untranspose matrix u and v */
  for(i = 0;i < r;i++){
    for(j = 0;j < m;j++){
      ut[i][j] = u[j][i];
    }
  }

  for(i = 0;i < n;i++){
    for(j = 0;j < r;j++){
      v[i][j] = vt[j][i];
    }
  }



  /* calculate that matrix */
  
	for(i = 0;i < n;i++){
		for(j = 0;j < r;j++){
			temp[j][i] = v[j][i] / s[i];
		}
	}
	
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++){
			for(k = 0;k < r;k++){
				god[i][j] += temp[i][k] * ut[k][j];
			}
		}
	}
	
	fprint_dmatrix(stdout, n, m, god);
	fprint_dmatrix(stdout, c, d, y);
	for(i = 0;i < r;i++){
		for(j = 0;j < m;j++){
			w[i] += god[i][j] * y[j][1]; 
		}
	}
	
  fprint_dvector(stdout, r, w);
	printf("%lf ", w[0]);
	for(i = 0;i < r - 1;i++){
			printf(" + %lf x^%d ", w[i+1], i+1);
	}
	
	
  free_dmatrix(a);
  free_dmatrix(y);
  free_dmatrix(u);
  free_dmatrix(ut);
  free_dmatrix(v);
  free_dmatrix(vt);
  free_dvector(s);
  free_dvector(w);
  free_dvector(work);
  free_dmatrix(temp);
  free_dmatrix(god);
}
