#include <stdio.h>
int main(){
    float pi=3.14159,v=100000;
    int h,r;
    scanf("%d %d",&h,&r);
    int n=v/(pi*r*r*h*2);
    printf("%d",n);
    return 0;
}