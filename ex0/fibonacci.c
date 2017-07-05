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

double fibonacci(int n){  //����n���󂯎��n�Ԗڂ�fibonacci����̒l��Ԃ��֐�
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
            answer = temp_1 + temp_2;  //answer��a_{i+1}�Atemp_1��a_{i}�Atemp_2��a_{i-1}�ɑ���
            temp_2 = temp_1;  // temp_2��a_{i}
            temp_1 = answer;  // temp_1��a_{i+1}���i�[�����̃X�e�b�v��
        }
    }
    return answer;  // a_{n}��Ԃ�
}

	
	
	
	
	
