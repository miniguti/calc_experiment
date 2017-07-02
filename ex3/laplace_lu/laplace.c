//laplace方程式の行列Aとベクトルbを計算

#include"matrix_util.h"

#include<stdio.h>
#include<math.h>

int main(void){
	
	int i, j, k, l, m, n;
	double h;
	
	n = 20;  //x, yをm等分する。
	
	m = n*n + 2*n; //格子点の数-1
	
	h = 1.0 / n; //刻み幅的な
	
	double  **a;
	
	a = alloc_dmatrix(m+1, m+1);
	
		
	//int a[m+1][m+1];
	double b[m+1];
	
	//行列Aの計算
	
	for(i=0;i<=m;i++){  //まず全成分を0にとる
		for(j=0;j<=m;j++){
			a[i][j] = 0;
		}
	}
	
	//0出ない成分の計算
	
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
	
	
	
	
	
	//行列Aの出力
	
	printf("%d %d\n", m+1, m+1); //サイズの出力
	
	for (i = 0;i <= m;i++){
		for (j = 0;j <= m;j++){
			if(j <= m - 1){
				printf("%lf ", a[i][j]);
			}else{
				printf("%lf\n", a[i][j]);
			}
		}
	}
	
	//ベクトルbの計算
	for(k=0;k<=n;k++){
		for(i=0;i<=n;i++){
			if(i==0){
				b[k*(n+1) + i] = sin(M_PI*h*k);
			}else{
				b[k*(n+1) + i] = 0;
			}
		}
	}
	
	
	//ベクトルbの出力
	printf("%d\n", m+1, m+1); //サイズの出力
	for (i=0;i<=m;i++){
		printf("%lf\n", b[i]);
	}
	
	
	free_dmatrix(a);

	
	return 0;
}

