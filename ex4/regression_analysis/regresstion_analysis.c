
#include"matrix_util.h"
#include<stdio.h>
#include<math.h>


int main(void){
	
	double *a, *b;
	
	
	
	char* filename;
	FILE *fp;

	
	
	
	
	
	/* read vector x, y from a file */
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: file can not open\n");
    exit(1);
  }
  read_dvector(fp, &n, &b);
  if (m != n) {
    fprintf(stderr, "Error: inconsistent number of equations\n");
    exit(1);
  }
	
	
	
	
	return 0;
}


