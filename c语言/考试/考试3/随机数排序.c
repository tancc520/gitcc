#include <stdio.h>
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if (a>b) swap(&a,&b);
    if (a>c) swap(&a,&c);
    if (a>d) swap(&a,&d);
    if (b>c) swap(&b,&c);
    if (b>d) swap(&d,&b);
    if (c>d) swap(&c,&d);
    printf("%d %d %d %d",a,b,c,d);
    return 0;


}