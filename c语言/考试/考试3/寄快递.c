#include <stdio.h>
int main(){
    float w,price;
    printf("请输入你的物品重量(KG):");
    scanf("%f,%f",&w,&price);
    if(w<=1){
        price=10;
        printf("%.2f",price);
    }
    if (w>1){
        while ((w-1)/0.5){
            price+=(10+2.2*((w-1)/0.5));
            printf("%.2f",price);
            break;
        }
    }
    return 0;

}