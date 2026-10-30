#include <stdio.h>
int main(){
    int n;
    scanf("%d\n",&n);
    int a;
    int count=0;
    for (int i=0;i<n;i++){
        scanf("%d",&a);
        int g=a%10;
        int q=a/1000;
        int b=a/100%10;
        int s=a/10%10;
        if(g-q-b-s>0){
            count++;
        }
    }
    printf("%d",count);
    return 0;


}