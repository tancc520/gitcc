#include <stdio.h>
int main(){
    double a,b,c,d;
    scanf("%lf,%lf,%lf,%lf",&a,&b,&c,&d);
    double s=a*b+c*d;
    double v=s/(b+d);
    printf("%.1lf\n%.1lf",s,v);
    return 0;
}