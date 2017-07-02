/* calculate theoretical value of vandermonde determinant */

#include<stdio.h>

int main(void){
	
	int i, j, n;
	
	double determinant;
	determinant = 1.0;
	
	double x[] = {1.9, 2.0, 3.1, 4.2, 5.4}; //choose numbers you like
	
	n = sizeof(x) / 8; //n is the size of x[]
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			
			determinant *= x[j] - x[i]; //calculate the determinant following useful formula
			
		}
	}
	
	printf("%lf\n", determinant); //output the value of the determinant
	
	return 0;
}

