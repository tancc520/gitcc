#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a=n/100;
    int b=n/10%10;
    int c=n%10;
    int sum1=a+b+c;
    int sum2=(a+b+c)*(a+b+c);
    int sum3=(a+b+c)*(a+b+c)*(a+b+c);
    printf("%d %d %d",sum1,sum2,sum3);
    return 0;

}