#include <stdio.h>
#include <math.h>
int main() {
    const double c= 2*sqrt(2)/9801;
    double sum =1103;
    double num= 24.0*(1103+26390);
    double de =(double)pow(396,4);
    sum +=num/de;
    double pi=1.0/(c*sum);
    printf("%.15f\n",pi);
    return 0;

}