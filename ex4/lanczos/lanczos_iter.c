/* lanczos法により与えられた行列の第一固有値(ritz値)を求めるプログラム */


#include "../matrix_util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define LMAX 10
#define epsilon pow(10, -7)

/* http://www.netlib.org/lapack/explore-html/dd/d4c/dsyev_8f.html */
void dsyev_(char *JOBZ, char *UPLO, int *N, double *A, int *LDA, double *W,
            double *WORK, int *LWORK, int *INFO);


int imin(int x, int y) { return (x < y) ? x : y; }
int imax(int x, int y) { return (x > y) ? x : y; }

double normv(double vector[], int n);

int main(int argc, char** argv) {
  char* filename;
  FILE *fp;
  int i, j, k, l;

  int m, n, r;
  double **a, **c, **q, **god, **eigen_vector;
  double *v, *temp;
  double v_norm, norm, test, s_0, s_1, t, theo, eigen_value, temp_value, diff;

  double *w;
  double *work;
	
  int lwork, info;
  char jobz = 'V'; /* Compute eigenvalues and eigenvectors */
  char uplo = 'U'; /* Upper triangle of A is stored */


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

	for(l = 1;l < LMAX;l++){
		
	
	
	
  /* allocate matrices and vectors */
  q = alloc_dmatrix(n, l);
  c = alloc_dmatrix(n, l);
  eigen_vector = alloc_dmatrix(n, l);
  god = alloc_dmatrix(l, l);
  v = alloc_dvector(n);
  temp = alloc_dvector(n);
  /* calc theoretical value */
  theo = 0.5 / (1 - cos(M_PI/(2 * n + 1)));


  /* initial value of vector v */
  for(i=0;i<n;i++){
  	v[i] = i*i;
  }
  norm = normv(v, n);
  for(i=0;i<n;i++){
    q[i][0] = v[i] / norm;
  }

   /* perform lanczos method */
	
	
	
	for(k = 0;k < (l - 1);k++){
		for(i = 0;i < n;i++){
			temp[i] = 0.0;
		}
		t = 0.0;
		norm = 0.0;

	 	for(i = 0;i < n;i++){
			for(j = 0;j < n;j++){
				temp[i] += a[i][j] * q[j][k];
			}
		}
		for(i = 0;i < n;i++){
			t += q[i][k] * temp[i];
		}
		
		
		if(k == 0){
			for(i = 0;i < n;i++){
				temp[i] = temp[i] - t * q[i][k];
			}
		}else{
			for(i = 0;i < n;i++){
				temp[i] = temp[i] - s_0 * q[i][k - 1] - t * q[i][k];
			}
		}
		
	 	for(i = 0;i < n;i++){
	 		norm += pow(temp[i], 2);
	 	}
	 	norm = pow(norm, 0.5);
	 	
		s_1 = norm;
		s_0 = s_1;
		for(i = 0;i < n;i++){
			q[i][k+1] = temp[i] / s_1;
		}
		
		
	}
	for(i = 0;i < n;i++){
		test += pow(q[i][5], 2);
	}
	
	//printf("%lf\n", test);
	
	
	
	//fprint_dmatrix(stdout, n, l, q);
	/* calculate 3 diag matrix */
	for(i = 0;i < n;i++){
		for(j = 0;j < l;j++){
			for(k = 0;k < n;k++){
				c[i][j] += a[i][k] * q[k][j];
			}
		}
	}
	
	for(i = 0;i < l;i++){
		for(j = 0;j < l;j++){
			for(k = 0;k < n;k++){
				god[i][j] += q[k][i] * c[k][j];
			}
		}
	}
	
	//fprint_dmatrix(stdout, l, l, god);
	
	
	
  /* perform eigenvalue decomposition */
  w = alloc_dvector(l);
  lwork = 3*l - 1;
  work = alloc_dvector(lwork);
  dsyev_(&jobz, &uplo, &l, &god[0][0], &l, &w[0], &work[0], &lwork, &info);
  if (info != 0) {
    fprintf(stderr, "Error: LAPACK::dsyev failed\n");
    exit(1);
  }
  //printf("Eigenvalues:\n");
  //fprint_dvector(stdout, l, w);
  //printf("Eigenvectors [each row (not column) represents each eigenvector]:\n");
  //fprint_dmatrix(stdout, l, l, god);
	
	

	/* generate eigen vector */
	for(i = 0;i < n;i++){
		for(j = 0;j < l;j++){
			for(k = 0;k < l;k++){
				eigen_vector[i][j] += q[i][k] * god[j][k];
;
			}
		}
	}
		printf("%d %lf\n", l, w[l-1]);
		
	}
	
	
	//printf("Eigen vectors [each column represents each eigenvector]:\n");
	//fprint_dmatrix(stdout, n, l, eigen_vector);
	




	//printf("theoretical value is %lf\n", theo);

  free_dmatrix(a);
  free_dmatrix(q);
  free_dmatrix(c);
  free_dmatrix(eigen_vector);
  free_dmatrix(god);
  free_dvector(v);
  free_dvector(temp);
  free_dvector(w);

}


double normv(double vector[], int n){
	int i;
	double norm;
	double norm_temp;
	for(i = 0;i < n;i++){
		norm_temp += pow(vector[i], 2);
	}
	norm = pow(norm_temp, 0.5);
	return norm;
}



