//Euler�@

#include <stdio.h>
#include <math.h>

double func(double t,  double x, double v); //�����x�̊֐���錾

int main(void){
  double t, x, v, temp, h, theo;
  x = 10.0; //�����l 10[m]
  v = 0.0;  //�����x 0[m/s]
	theo = ;
	int i, n;
	n = 10;
	//���ݕ�(���������낢�낢�����Đ��x�𒲂ׂ�)
	for(i=0;i<n;i++){
		h = pow(2, -i);
		x = 10.0;
		v = 0.0;
  for(t = 0.0 ; t <= 3.00000 ; t+=h){ // 30s�܂Ń��[�v
    //printf("%lf %lf\n",t, x); //���Ԃƈʒu���o��
    temp = x;
    x = x + v * h;
    v = v + func(t,temp, v) * h;
  }
		printf("%lf %lf\n", h, x - theo);
	}
	
		
  return 0;
}

double func(double t, double x, double v)  // �����U���̉����x
{
  double k=2.0;
  double kappa = 0.2;
	double g = 9.8;
  return( -g );  //�����x��Ԃ�
}

