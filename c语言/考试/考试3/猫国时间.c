#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int ws=24*3600;
    int w=t/ws+1;
    int remain=t%ws;
    int h=remain/3600;
    remain%=3600;
    int m=remain/60;
    int s=remain%60;
    printf("%d:%d:%d:%d",w,h,m,s);
    return 0;

       
}