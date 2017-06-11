#include<stdio.h>
#include<time.h>

int main(void){
	int n, m;
	clock_t start, end;
	double  a[1000];
	a[0] = 0.0;
	a[1] = 1.0;
	
	scanf("%d", &n);
	
	start = clock();
	printf("start:%d \n", start);
	
	for(m = 0; m < n; m++){
		
		a[m + 2] = a[m + 1] + a[m];
	}

	printf("20.15%lf", a[n]);
	
	end = clock();
	
	printf("end:%d \n", end);
	printf("process:%d \n", end - start);
	
	return 0;
}
