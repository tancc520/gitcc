#include <stdio.h>
#include <math.h>
double Pi2(int n){
    double sum=0;
    for (int i=1;i<=n;i++){
        sum+=1/pow(i,2);
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    double sum=Pi2(n);
    double pi=sqrt(sum*6);
    printf("%.6lf",pi);
    return 0;
}