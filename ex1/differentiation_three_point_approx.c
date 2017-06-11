#include<stdio.h>
#include<math.h>

double func(double x); // given fuction.

double diff(double x, double h); // derivative of given function.

double gap(double x, double h); // the gap between the value of calculated derivatives and one 

double absolute(double y); 


int main(void){

    double x = 0.3 * M_PI;
    double h;
    int i;

    for (i = 0; i < 50; i++){
        h = pow(2, -i);
        printf("%20.15lf %20.15lf\n", h, gap(x, h));
    }


    return 0;
}



double func(double x){

    return sin(x);
}

double diff(double x, double h){

    return (func(x + h) - func(x - h)) / (2 * h);
}

double absolute(double y){

    if(y < 0){
        return -y;
    } else {
        return y;
    }
}


double gap(double x, double h){

    return absolute(diff(x, h) - cos(x));
}

