/* Šî’êŠÖ”‚ÌŒW”‚ğ‹‚ß‚éƒvƒƒOƒ‰ƒ€ */

#include "matrix_util.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  char* filename;
  FILE *fp;

  int m, n;
  double **a;
  double *b;

  int *ipiv;
  int info;
  char trans = 'T';
  int nrhs = 1;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
    exit(1);
  }
  filename = argv[1];

  /* read design matrix and  from a file */
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: file can not open\n");
    exit(1);
  }
  read_dmatrix(fp, &m, &n, &a);
  if (m != n) {
    fprintf(stderr, "Error: inconsistent number of equations\n");
    exit(1);
  }
  read_dvector(fp, &n, &b);
  if (m != n) {
    fprintf(stderr, "Error: inconsistent number of equations\n");
    exit(1);
  }
  printf("Matrix A:\n");
  fprint_dmatrix(stdout, n, n, a);
  printf("Vector B (transposed):\n");
  fprint_dvector(stdout, n, b);

  fprint_dvector(stdout, n, b);
  
  free_dmatrix(a);
  free_dvector(b);
  free_ivector(ipiv);
}
