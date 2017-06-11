#include<stdio.h>
#include<time.h>

int fibonacci(int n){
	if (n == 0){
		return 0;
	}else if (n == 1){
		return 1;
	}else{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}


int main(void){
	int i, n, ans;
	clock_t start, end;
	n = 46;
	printf("#n   process time\n");
	
	for (i = 0;i<n;i++){
		
		start = clock();
		ans = fibonacci(i);
		end = clock();
		printf("%d %lf\n", i, (end - start) / 1000.0);
	}
	
	return 0;
}

