#include<stdio.h>

#include<time.h>

double mat_power(double* a[][], int n); // qのi乗を計算。何も返さない。計算するだけ。
double mat_square(double* a[][]); //行列の二乗を計算。
double mat_mul(double* a[][], double* b[][]); //行列の掛け算。



int main(void){
	double primary[2]={1, 0};
	double q_matrix[2][2] = {{1, 1}, {1, 0}};
	int i, p;
	int* ans;
	clock_t start, end;
	
	int k = 10;
	for(i = 0;i < k;i++){
		
		p = i * 1;
		start = clock();
		
		mat_power(q_matrix, p);
		ans = q_matrix[1][0];
		
		end = clock();
		printf("%d %d %d\n", p, ans, end - start);
	}
	return 0;
}


double mat_power(double* a[][], int n){
	int i;
	double c[2][2];
	if (i == 0){
		c[2][2] = {{1, 0},{0, 1}};
		
	}else if((i >> 2) && (i % 2 == 0)){
		
		c = mat_square(mat_power(a, i / 2));
		}
	else{
		c = mat_mul(a, matpower(a, i-1));
	}
	return c;
}

double mat_square(double* a[][]){
	double c[2][2];
	int i, j, k, s;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			s = 0;
			for (k=0;k<2;k++){
				s = s + a[i][k] * a[k][j];
			}
			c[i][j] = s;
		}
	}
	return c;
	
}

double mat_mul(double* a[][], double* b[][]){
	double c[2][2];
	int i, j, k, s;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			s = 0;
			for (k=0;k<2;k++){
				s = s + a[i][k] * b[k][j];
			}
			c[i][j] = s;
		}
	}
	return c;
	
}







