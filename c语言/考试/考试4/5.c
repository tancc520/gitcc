#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int count=0;
    for (int i=6;i<=n;i++){
        int num=i;
        while (num>0){
            if (num%10==6){
                count++;
            }
            num=num/10;
        }
    }
    printf("%d",count);
    return 0;
}