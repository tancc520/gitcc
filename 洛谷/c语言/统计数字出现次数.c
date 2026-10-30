#include <stdio.h>
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int count=0;
    for (int i=1;i<=n;i++){
        int num=i;
        while(num!=0){
            int m=num%10;
            if (m==x){
                count++;
            }
            num=num/10;
        }
    }
    printf("%d",count);
    return 0;
}