#include <stdio.h>
#include <math.h>
int main(){
    double e;
    printf("qingshuruzhengshu:");
    scanf("%lf",&e);

    int i=1,sign=1;
    double s,sum=0;

    while (1) {
        s=sign*1.0/i; //用1.0确保浮点数运算
        if (fabs(s)<=e) break;
        sum+=s;
        sign=-sign;
        i+=3;
    }
    printf("%.6lf\n",sum);
    return 0;
}