#include <stdio.h>
double pfg(double a){
    double x0=a/2.0;
    double x1;
    do{
        x1=0.5*(x0+a/x0);
        if (x1-x0<0.000001&&x1-x0>-0.000001){
            break;
        }
        x0=x1;
    }while(1);
    return x1;
}
int main() {
    double a;
    scanf("%lf", &a);
    double result = pfg(a);
    printf("%lf的平方根是%lf\n", a, result);
    return 0;
}