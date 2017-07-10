  double **a;
  double *v, *c, *temp;
  double eigen_value, temp_value, diff, mother, child;


  /* initial value of vector v */
  for(i=0;i<n;i++){
  	v[i] = 0.1 * (i+1);
  }
  for(i=0;i<n;i++){
    c[i] = v[i];
  }

  /* perform power iteration */
  l = 0;
  do{
  mother = 0.0;
  child = 0.0;
  for(i=0;i<n;i++){
    temp[i] = c[i];
  }
  for(i=0;i<n;i++){
    c[i] = 0.0;
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      c[i] += a[i][j] * temp[j];
    }
  }

  for(i=0;i<n;i++){
    mother += c[i] * temp[i];
  }

  for(i=0;i<n;i++){
    child  += c[i] * c[i];
  }
  temp_value = eigen_value;
  eigen_value = child / mother;
  diff = fabs(eigen_value - temp_value);
  l = l + 1;
  }while((diff > epsilon) && (l < LMAX));