#include "matrix_util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define RMAX 281

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

  int m, n, r;
  int rank;
  double **a, **a_origin, **u, **vt;
  double *s;
  double diff;

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
  //printf("Matrix A:\n");
  //fprint_dmatrix(stdout, m, n, a);

  /* allocate matrices and vectors */
  r = imin(m, n);
  a_origin = alloc_dmatrix(m, n);
  u = alloc_dmatrix(m, r);
  vt = alloc_dmatrix(r, n);
  s = alloc_dvector(r);
  lwork = imax(3 * r + imax(m, n), 5 * r);
  work = alloc_dvector(lwork);

  /* keep original matrix A */
  for(i = 0;i < m;i++){
    for(j = 0;j < n;j++){
      a_origin[i][j] = a[i][j];
    }
  }
  
  /* perform SVD */
  dgesvd_(&jobu, &jobvt, &n, &m, &a[0][0], &n, &s[0], &vt[0][0], &n,
          &u[0][0], &r, &work[0], &lwork, &info);
  if (info != 0) {
    fprintf(stderr, "Error: LAPACK::dgesvd failed\n");
    exit(1);
  }
  /*printf("Result of SVD U:\n");
  fprint_dmatrix(stdout, m, r, u);
  printf("Result of SVD S:\n");
  fprint_dvector(stdout, r, s);
  printf("Result of SVD Vt:\n");
  fprint_dmatrix(stdout, r, n, vt); */

  // check the result of SVD
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      a[i][j] = 0.0;
      for (k = 0; k < r; ++k) {
        a[i][j] += u[i][k] * s[k] * vt[k][j];
      }
    }
  }
  //printf("Reconstruction of the original matrix A:\n");
  //fprint_dmatrix(stdout, m, n, a);

  // approximate A by rank k( < r) matrix
  for(rank = 0;rank < RMAX;rank++){
  for(i = 0;i < rank;i++){
    s[r - 1 - i] = 0.0;
  }
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      a[i][j] = 0.0;
      for (k = 0; k < r; ++k) {
        a[i][j] += u[i][k] * s[k] * vt[k][j];
      }
    }
  }
  //printf("Rank %d( < r) approximation of A:\n", r - rank);
  //fprint_dmatrix(stdout, m, n, a);

  for(i = 0;i < m;i++){
    for(j = 0;j < n;j++){
      diff += pow(a[i][j] - a_origin[i][j], 2);
    }
  }

  printf("%d %lf\n", r - rank, pow(diff, 0.5));
  }
  
  

  
  free_dmatrix(a);
  free_dmatrix(a_origin);
  free_dmatrix(u);
  free_dmatrix(vt);
  free_dvector(s);
  free_dvector(work);
}
