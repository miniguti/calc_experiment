
#include<stdio.h>

int main(void)
{

    double x;
	printf("Enter the initial value of x.\n");
	scanf("%lf", &x);
    int i, n;
    n = 100;

    for (i = 0; i <= n; i++){
        if (2 * x < 2 - 2 * x){
            x = 2 * x;
        }else{
            x = 2 - 2 * x;
        }
        printf("%d %lf\n", i, x);
    }



    return 0;
}

