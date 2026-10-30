#include <stdio.h>
#include <math.h>
int weishu(int num){
    int count=0;
    while (num>0){
        num/=10;
        count++;
    }
    return count;
}
int main(){
    int M;
    scanf("%d\n",&M);
    for (int i=0;i<M;i++){
        int num;
        scanf("%d",&num);
        int a=weishu(num);
        int temp=num;
        int sum=0;
        while(temp>0){
            int b=temp%10;
            sum+=(int)pow(b,a);
            temp/=10;
        }
        if (sum==num){
            printf("T");
        }else{
            printf("F");
        }

    }
    return 0;

}