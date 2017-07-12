#include "matrix_util.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 2

/* http://www.netlib.org/lapack/explore-html/d3/d6a/dgetrf_8f.html */
extern void dgetrf_(int *M, int *N, double *A, int *LDA, int*IPIV, int *INFO);

/* http://www.netlib.org/lapack/explore-html/d6/d49/dgetrs_8f.html */
extern void dgetrs_(char *TRANS, int *N, int *NRHS, double *A, int *LDA, int *IPIV,
                    double *B, int *LDB, int *INFO);

int main(int argc, char** argv) {
  char* filename;
  FILE *fp;

  clock_t start, end;
  int i, k, j, l, m, n;
  double h, x, y, z;
  double **a;
  double *b;

  int *ipiv;
  int info;
  char trans = 'T';
  int nrhs = 1;

	for(n=1;n<NMAX;n++){
  /* allocate matrix a and vector b */
	m = n*n + 2*n +1;
  h = 1.0 / n;
  a = alloc_dmatrix(m, m);
  b = alloc_dvector(m);
  

/* calculate matrix a */
	for(i=0;i<m;i++){  //make all matrix elements 0
		for(j=0;j<m;j++){
			a[i][j] = 0;
		}
	}
	//calculate non-zero elements
	for(i=0;i<=n;i++){
		a[i][i] = 1;
	}
	
	for(k=0;k<=n;k++){
		for(l=0;l<=n;l++){
			if((k==(l+1))  && (k!=n)){
				for(i=1;i<=n-1;i++){
					a[k*(n+1) + i][l*(n+1) + i] = 1;
				}
			}else if((l==(k+1)) && (k!=0)  ){
				for(i=1;i<=n-1;i++){
					a[k*(n+1) + i][l*(n+1) + i] = 1;
				}
			}else if(k==l && (k!=0) && (k!=n)){
				a[k*(n+1)][l*(n+1)] = 1;
				a[k*(n+1) + n][l*(n+1) + n] = 1;
				for(i=1;i<=n-1;i++){
					a[k*(n+1) + i][l*(n+1) + i] = -4;
					a[k*(n+1) + i][l*(n+1) + i+1] = 1;
					a[k*(n+1) + i][l*(n+1) + i-1] = 1;
				}
			}
		}
	}
		
	
	for(i=0;i<=n;i++){
		a[n*(n+1) + i][n*(n+1) + i] = 1;
	}
	
	
	
	
	
	/* output matrix a */
	
	/*printf("%d %d\n", m, m);*/ //output the size of matrix
	
	/*for (i = 0;i < m;i++){
		for (j = 0;j < m;j++){
			if(j < m - 1){
				printf("%lf ", a[i][j]);
			}else{
				printf("%lf\n", a[i][j]);
			}
		}
	}*/
	
	/* calculate vector b */
	for(k=0;k<=n;k++){
		for(i=0;i<=n;i++){
			if(i==0){
				b[k*(n+1) + i] = sin(M_PI*h*k);
			}else{
				b[k*(n+1) + i] = 0;
			}
		}
	}
	
	
	/* output vector b */
	//printf("%d\n", m, m); //output the size of vector
	/*for (i=0;i<m;i++){
		printf("%lf\n", b[i]);
	}*/
	
  start = clock();
  /* perform Gauss elimination */
  for (k = 0; k < m; ++k) {
    for (i = k + 1; i < m; ++i) {
      for (j = k + 1; j < m; ++j) {
        a[i][j] -= a[k][j] * a[i][k] / a[k][k];
      }
      b[i] -= b[k] * a[i][k] / a[k][k];
    }
  }
  /*printf("Result of Gauss elimination (only upper triangular has meaning):\n");
  fprint_dmatrix(stdout, n, n, a);
  printf("Transformed vector B:\n");
  fprint_dvector(stdout, n, b); */

  /* backward substitution */
  for (k = m-1; k >= 0; --k) {
    for (j = k + 1; j < m; ++j) {
      b[k] -= a[k][j] * b[j];
    }
    b[k] /= a[k][k];
  }
  //printf("Solution X (transposed):\n");
  //fprint_dvector(stdout, n, b);
  end = clock();
	//printf("%d %lf\n", m, (end - start) / 1000.0);

	}
	

  /* output 3d plot data */
	n = 30; //re-definition n
	h = 1.0/n; //step
	for(k=0;k<=n;k++){
		for(i=0;i<=n;i++){
			x = h*i;
			y = h*k;
			z = b[k*(n+1) + i];
			printf("%lf %lf %lf\n", x, y, z); 
		}
	}
  

  free_dmatrix(a);
  free_dvector(b);
  free_ivector(ipiv);
}





  


