	double **g; // D^(-1)
	double **h; // E + F
	double **c; // D^(-1) * (E + F)
	
	double *z; // D^(-1) * b
	double *b; // vector b
	double *x; // vector x
	double *temp;
	
	do{
		/* initialize */
		sum_of_error = 0.0; 
		for(i=0;i<m;i++){
			y[i] = 0.0;
		}
		
		/* multiply matrix c and vector x */
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				y[i] += c[i][j] * x[j]; // D^(-1) * (E + F) * x
			}
		}
		
		/* keep current x[i] */
		for(i=0;i<m;i++){
			temp[i] = x[i];
		}
		
		/* calc next x[i] , -D^(-1) * (E + F)*x + D^(-1) * b */
		for(i=0;i<m;i++){
			x[i] = -y[i] + z[i]; 
		}
		
		/* count iteration */
		l = l + 1;
		
		/* calc diff of temp[i] and x[i] */
		for(i=0;i<m;i++){
			sum_of_error += pow(x[i] - temp[i], 2);
		}
	}while((pow(sum_of_error, 0.5) > epsilon) && (l < LMAX)); // test for convergence and set a limit in case