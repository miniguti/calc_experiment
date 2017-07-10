  double **a;  // input matrix A

  double det = 1.0; // det of martix A
  double sgn = 1.0;  // sign fn

  a = alloc_dmatrix(n, n);

  /* perform LU decomposition */
  ipiv = alloc_ivector(n);
  dgetrf_(&n, &n, &a[0][0], &n, &ipiv[0], &info);
  if (info != 0) {
    fprintf(stderr, "Error: LAPACK::dgetrf failed\n");
    exit(1);
  }
  printf("Result of LU decomposition:\n");
  fprint_dmatrix(stdout, n, n, a);
  printf("Pivot for LU decomposition:\n");
  fprint_ivector(stdout, n, ipiv);

  /* calculate the determinant of given matrix */
  for(i = 0;i < n;i++){
    if((i+1) != ipiv[i]){
      sgn *= -1.0;  // the eigen value of matrix P
    }
  }
  det *= sgn;
  for(i = 0;i < n;i++){
    det *= a[i][i]; // the eigen value of matrix A
  }