//gauss seidel法でlaplace方程式を解く


#include"matrix_util.h" //jacobi.cと同じ階層に置いておく

#include<stdio.h>
#include<math.h>

#define IMAX 1000
#define epsilon pow(10, -5)

int main(void){
	
	int i, j, k , l, m, n;
	n = 30; //分割数
	m = n*n + 2*n + 1;
	
	double sum_of_error; //収束条件用
	double delta, p, q, r;
	delta = 1.0 / n;
	
	/* ベクトル、行列の動的確保 */
	
	double **g;
	double **h;
	double **c;
	
	double *b;
	double *x;
	double *y;
	double *z;
	double *temp;
	
	
	g = alloc_dmatrix(m, m); //G = D^(-1)
	h = alloc_dmatrix(m, m); //H = E + F
	c = alloc_dmatrix(m, m);
	
	b = alloc_dvector(m);
	x = alloc_dvector(m);
	y = alloc_dvector(m);
	z = alloc_dvector(m);
	temp = alloc_dvector(m);
	
	
	
	
	
	//行列Gの定義
	for(i=0;i<m;i++){  //まず全成分を0にとる
		for(j=0;j<m;j++){
			g[i][j] = 0;
		}
	}
	
	//0出ない成分の計算
	
	for(i=0;i<n+1;i++){
		g[i][i] = 1;
	}
	
	for(k=0;k<n+1;k++){
		for(l=0;l<n+1;l++){
			if(k==l && (k!=0) && (k!=n)){
				g[k*(n+1)][l*(n+1)] = 1;
				g[k*(n+1) + n][l*(n+1) + n] = 1;
				for(i=1;i<=n-1;i++){
					g[k*(n+1) + i][l*(n+1) + i] = -0.25;
				}
			}
		}
	}
	
	
	
	for(i=0;i<=n;i++){
		g[n*(n+1) + i][n*(n+1) + i] = 1;
	}
	
	

	
	//行列Hの定義
	
	for(i=0;i<m;i++){  //まず全成分を0にとる
		for(j=0;j<m;j++){
			h[i][j] = 0;
		}
	}
	
	//0でない成分の計算
	
	
	for(k=0;k<=n;k++){
		for(l=0;l<=n;l++){
			if((k==(l+1))  && (k!=n)){
				for(i=1;i<=n-1;i++){
					h[k*(n+1) + i][l*(n+1) + i] = 1;
				}
			}else if((l==(k+1)) && (k!=0)  ){
				for(i=1;i<=n-1;i++){
					h[k*(n+1) + i][l*(n+1) + i] = 1;
				}
			}else if(k==l && (k!=0) && (k!=n)){
				for(i=1;i<=n-1;i++){
					h[k*(n+1) + i][l*(n+1) + i+1] = 1;
					h[k*(n+1) + i][l*(n+1) + i-1] = 1;
				}
			}
		}
	}
	
	
	
	//ベクトルbの定義
	
	for(k=0;k<=n;k++){
		for(i=0;i<=n;i++){
			if(i==0){
				b[k*(n+1) + i] = sin(M_PI*delta*k);
			}else{
				b[k*(n+1) + i] = 0;
			}
		}
	}
	
	
	
	
	
	/* perform jacobi method */
	
	//ベクトルxの初期値
	for(i=0;i<m;i++){
		x[i] = 0.0;
	}
	
	
	
	//行列g, hの掛け算
		
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			for(k=0;k<m;k++){
				c[i][j] += g[i][k] * h[k][j]; //D^(-1) * (E + F)
			}
		}
	}
	
	
	//行列gとベクトルbの掛け算

	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			z[i] += g[i][j] * b[j];  // D^(-1) * b
		}
	}
	
	
	
	
	l = 0; // ループのためのダミー変数
	
	do{
		
		
		sum_of_error = 0.0; //初期化
		//ベクトルyの初期化
		for(i=0;i<m;i++){
			y[i] = 0.0;
		}
		
		
		
		//行列cとベクトルxの掛け算
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				y[i] += c[i][j] * x[j]; // D^(-1) * (E + F) * x
			}
			x[i] = -y[i] + z[i]; //jacobiと違ってすぐに計算できるx[i]を計算する
		}
		
		
		
		l = l + 1;
		
		for(i=0;i<m;i++){
			sum_of_error += pow(x[i] - temp[i], 2);
		}
		
		
		
		
	}while((pow(sum_of_error, 0.5) > epsilon) && (l < IMAX)); //収束条件判定
	
	
	/* output 3D plot data */
	for(k=0;k<=n;k++){
		for(i=0;i<=n;i++){
			p = delta*i;
			q = delta*k;
			r = x[k*(n+1) + i];
			printf("%lf %lf %lf\n", p, q, r);
		}
	}
	
	
	
	
	
	
	
	
	free_dmatrix(g);
	free_dmatrix(h);
	free_dmatrix(c);
	
	
	free_dvector(b);
	free_dvector(x);
	free_dvector(y);
	free_dvector(z);
	free_dvector(temp);

	
	return 0;
}