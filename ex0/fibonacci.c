#include<stdio.h>
#include<time.h>

double fibonacci(int j);

int main(void)
{
	clock_t start, end;
	int k = 20;
	int j, p;
	double hoge;
	for(j=0;j<k;j++){
		start = clock();
		p = j * 50000000;
		hoge = fibonacci(p);
		end = clock();
			printf("%d %lf\n", p,  (end - start) / 1000.0);
		}
	
	
    return 0;
}

double fibonacci(int n){  //整数nを受け取りn番目のfibonacci数列の値を返す関数
    double answer, temp_1, temp_2;
    int i;
    temp_1 = 1.0;
    temp_2 = 0.0;
    if(n == 0){
        answer = 0;  // a_{0} = 0
    } else if(n == 1){
        answer = 1;  // a_{1} = 1
    }else{
        for(i = 1;i < n;i++){
            answer = temp_1 + temp_2;  //answerがa_{i+1}、temp_1がa_{i}、temp_2がa_{i-1}に相当
            temp_2 = temp_1;  // temp_2にa_{i}
            temp_1 = answer;  // temp_1にa_{i+1}を格納し次のステップへ
        }
    }
    return answer;  // a_{n}を返す
}

	
	
	
	
	
