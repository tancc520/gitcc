#include <stdio.h>
int main(){
    int k,n=0;
    double s=0.0;
    scanf("%d",&k);
    while(s<=k){
        n++;
        s+=1.0/n; //使用1.0变成小数运算。。
    }
    printf("%d",n);
    return 0;
}