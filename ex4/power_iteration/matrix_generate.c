/* �^����ꂽ�s��𐶐�����v���O����(�낤��) */

#include<stdio.h>
#include<math.h>
#include"../matrix_util.h"

int min(int a,int b);

int main(void)
{
	
	int i, j, n;
	n = 10;
	double **a;
	
	a = alloc_dmatrix(n, n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			
			a[i][j] = min(i+1, j+1);
			
		}
	}
	
	//�s��A�̏o��
	
	printf("%d %d\n", n, n); //�T�C�Y�̏o��
	
	for (i = 0;i < n;i++){
		for (j = 0;j < n;j++){
			if(j < n - 1){
				printf("%lf ", a[i][j]);
			}else{
				printf("%lf\n", a[i][j]);
			}
		}
	}
	
	
	
	
	free_dmatrix(a);
	
	return 0;
}

int min(int a, int b){
	
	if(a>b){
		return b;
	}else{
		return a;
	}
	
}

