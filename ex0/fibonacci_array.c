#include<stdio.h>

int main(void){
	int n, m;
	int a[65];
	a[0] = 0;
	a[1] = 1;
	
	scanf("%d", &n);
	
	for(m = 0; m < 60; m++){
		
		a[m + 2] = a[m + 1] + a[m];
	}

	printf("%d", a[n]);
	
	return 0;
}
