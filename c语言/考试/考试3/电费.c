#include <stdio.h>
int main(){
    float total;
    float price;
    scanf("%f",&total);
    if (total<3120&&total>0){
        price=total*0.75*0.617+total*0.25*0.307;
        printf("%.2f",price);
    }    
    else if (total<4800&&total>3121){
        float remain1=total-3120;
        price=remain1*0.75*0.667+remain1*0.25*0.337+3120*0.75*0.617+3120*0.25*0.307;
        printf("%.2f",price);
    }
    else if (total>4801){
        float remain2=total-4800;
        price=remain2*0.75*0.917+remain2*0.25*0.617+1680*0.75*0.667+1680*0.25*0.337+3120*0.75*0.617+3120*0.25*0.307;
        printf("%.2f",price);
    }
    return 0;
}