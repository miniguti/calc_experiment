//Euler�@�ŃG�l���M�[���v�Z���A���̎��ԕω������߂�v���O����
#include <stdio.h>
#include <math.h>

double func(double t,  double x, double v); //�����x�֐�

int main(void){
  double t, x, v, temp, h, energy;
  int i, m, n;
  x = 10.0; //�����l
  v = 0.0; //�����x
  n = 30;
  m = 1;
  h = 0.1;
  for(i = 0;i < n;i++){  //h*n�b�܂Ń��[�v
    if(i % m == 0){ //n��傫�����ĕb���������Ȃ��dat�t�@�C�������ӂ��̂Ńf�[�^���Ԉ���
      energy = 0.5 * v * v + 0.5 * 2.0  * x * x; //�G�l���M�[
      printf("%20.15lf %20.15lf\n", t, energy); //���ԂƃG�l���M�[���o��
      temp = x;  //�ȉ�3�seuler�@���s����
      x += v * h;
      v += func(t, temp, v) * h;
    }
    t = t + h;
  }

  return 0;
}

double func(double t, double x, double v)  // �����x
{
  double k=2.0;
  return( -k * x); 
}

