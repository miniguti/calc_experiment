#include<stdio.h>

int main(void)
{
    double answer, temp_1, temp_2;
	int m, n;
    temp_1 = 1;
    temp_2 = 0;

	scanf("%d", &n);

	if(n == 0){
		printf("0\n");
	} else if(n == 1){
		printf("1\n");
	}else{
        for(m = 1; m < n; m++){
            answer = temp_1 + temp_2;
            temp_2 = temp_1;
            temp_1 = answer;
        }
        printf("%f\n", answer);
    }
    return 0;
}
