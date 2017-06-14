#include<stdio.h>
#include<math.h>

double func(double x); // given fuction.

double diff_two_point(double x, double h); // derivative of given function.(two point)

double diff_three_point(double x, double h); // derivative of given function.(three point)

double gap_two_point(double x, double h); // the gap between the value of calculated derivatives and one

double gap_three_point(double x, double h); // the gap between the value of calculated derivatives and one 

double absolute(double y); 


int main(void){

    double x = 0.3 * M_PI;
    double h;
    int i;

    for (i = 0; i < 50; i++){
        h = pow(2, -i);
        printf("%20.15lf %20.15lf %20.15lf\n", h, gap_two_point(x, h), gap_three_point(x, h));
    }


    return 0;
}



double func(double x){

    return sin(x);
}

double diff_two_point(double x, double h){

    return (func(x + h) - func(x)) / h;
}

double diff_three_point(double x, double h){

  return (func(x + h) - func(x -h)) / (2 * h);
}



double absolute(double y){

    if(y < 0){
        return -y;
    } else {
        return y;
    }
}



double gap_two_point(double x, double h){

    return absolute(diff_two_point(x, h) - cos(x));
}

double gap_three_point(double x, double h){

    return absolute(diff_three_point(x, h) - cos(x));
}

